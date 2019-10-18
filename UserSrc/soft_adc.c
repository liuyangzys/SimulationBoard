#include "soft_adc.h"
#include "adc.h"

#define _ADC_CH_NUM 3
#define _ADC_SAMPLE_NUM 50

static uint16_t adcBuffer[_ADC_SAMPLE_NUM][_ADC_CH_NUM];

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
    uint32_t lastTime = 0;
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
}
