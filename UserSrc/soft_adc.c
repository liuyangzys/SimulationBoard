#include "soft_adc.h"
#include "adc.h"

#define _ADC_CH_NUM 3
#define _ADC_SAMPLE_NUM 50

/* 采集的电压 */
static float adVolt[3] = {0.0};

/* 电压线性校准系数 */
static float _vParam_Kp[2] = {1.0f, 1.0f};
static float _vParam_Offset[2] = {0.0f, 0.0f};

static uint16_t adcBuffer[_ADC_SAMPLE_NUM][_ADC_CH_NUM];

/**
 * @brief 启动 ADC 采集
 * 
 */
void ADC_Config(void)
{
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adcBuffer, _ADC_CH_NUM * _ADC_SAMPLE_NUM);
}

/**
 * @brief 更新电压采集
 * 
 */
void ADC_VoltageUpdate(void)
{
    static uint32_t lastTime = 0;
    if (HAL_GetTick() - lastTime < 500)
        return;
    lastTime = HAL_GetTick();

    /* 计算 adc 采样平准值 */
    float adcAverageValue[_ADC_CH_NUM] = {0.0f};
    for (uint8_t i = 0; i < _ADC_CH_NUM; i++)
    {
        for (uint8_t j = 0; j < _ADC_SAMPLE_NUM; j++)
        {
            adcAverageValue[i] +=
                (float)adcBuffer[j][i] / _ADC_SAMPLE_NUM;
        }
    }

    /* 根据参考电压 vrefint 的采样值，分压电路的放大倍数 voltratio 计算电压值 */
    const float vrefint = 1.2f, voltratio = 17.3f;
    adVolt[2] = vrefint;
    for (uint8_t i = 0; i < 2; ++i)
    {
        float voltBeforeCalib = vrefint * voltratio * adcAverageValue[i] / adcAverageValue[2];
        adVolt[i] = _vParam_Kp[i] * voltBeforeCalib + _vParam_Offset[i];
    }
}

/**
 * @brief 获取电压
 * 
 * @param ch ad 通道，0～1
 * @return float 电压值，单位 V
 */
float ADC_GetVoltage(uint8_t ch)
{
    float voltage = 0.0f;
    if (ch < 2)
        voltage = adVolt[ch];
    return voltage;
}

/**
 * @brief 设置电压校准系数
 * 
 * @param ch ad 通道，0～1
 * @param kp 比例系数
 * @param offset 偏移量，单位 V
 */
void ADC_SetVoltCalibParams(uint8_t ch, float kp, float offset)
{
    if (ch < 2)
    {
        _vParam_Kp[ch] = kp;
        _vParam_Offset[ch] = offset;
    }
}
