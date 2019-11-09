#include "soft_dac.h"
#include "delay.h"
#include "driver_74hc595d.h"
#include "driver_ad5504.h"
#include "soft_gpio.h"
#include "spi.h"

AD5504_HandleType hAD5504;

/**
 * @brief AD5504 线设置状态
 *
 * @param state 0-低电平 1-高电平
 */
static void AD5504_LDAC_SetState(uint8_t state)
{
    switch (state)
    {
    case 1:
        hc595d_databyte |= (1 << 6);
        HC595D_SendByte(hc595d_databyte);
        HC595D_CS();
        break;
    case 0:
        hc595d_databyte &= ~(1 << 6);
        HC595D_SendByte(hc595d_databyte);
        HC595D_CS();
        break;
    default:
        break;
    }
}

/**
 * @brief AD5504 SYNC 线设置状态
 *
 * @param state 0-低电平 1-高电平
 */
static void AD5504_SYNC_SetState(uint8_t state)
{
    switch (state)
    {
    case 1:
        hc595d_databyte |= (1 << 5);
        HC595D_SendByte(hc595d_databyte);
        HC595D_CS();
        break;
    case 0:
        hc595d_databyte &= ~(1 << 5);
        HC595D_SendByte(hc595d_databyte);
        HC595D_CS();
        break;
    default:
        break;
    }
}

/**
 * @brief AD5504 CLR 线设置电平状态
 *
 * @param state 0-低电平 1-高电平
 */
static void AD5504_CLR_SetState(uint8_t state)
{
    switch (state)
    {
    case 1:
        hc595d_databyte |= (1 << 4);
        HC595D_SendByte(hc595d_databyte);
        HC595D_CS();
        break;
    case 0:
        hc595d_databyte &= ~(1 << 4);
        HC595D_SendByte(hc595d_databyte);
        HC595D_CS();
        break;
    default:
        break;
    }
}

/**
 * @brief DAC 初始化配置
 *
 */
void DAC_InitConfig(void)
{
    hAD5504.LDAC_SetPin = AD5504_LDAC_SetState;
    hAD5504.CLR_SetPin = AD5504_CLR_SetState;
    hAD5504.SYNC_SetPin = AD5504_SYNC_SetState;
    hAD5504.delay_us = delay_us;
    hAD5504.vref_mv = 60000;

    hAD5504.LDAC_SetPin(1);
    hAD5504.SYNC_SetPin(1);
    hAD5504.CLR_SetPin(0);
    delay_ms(5);
    hAD5504.CLR_SetPin(1);
}

/**
 * @brief DAC 设置通道电压
 *
 */
void DAC_SetCHVolt(uint8_t ch, float voltage)
{
    AD5504_AnalogCH aCH;
    if (ch < 4)
    {
        switch (ch)
        {
        case 0:
            aCH = AD5504_ANALOG_CHA;
            break;
        case 1:
            aCH = AD5504_ANALOG_CHB;
            break;
        case 2:
            aCH = AD5504_ANALOG_CHC;
            break;
        case 3:
            aCH = AD5504_ANALOG_CHD;
            break;

        default:
            break;
        }

        AD5504_SetAnalogVolt(&hAD5504, aCH, voltage);
    }
}

/**
 * @brief DAC 读取通道电压
 *
 */
float DAC_GetCHVolt(uint8_t ch)
{
    float voltage = 0.0f;
    AD5504_AnalogCH aCH;
    if (ch < 4)
    {
        switch (ch)
        {
        case 0:
            aCH = AD5504_ANALOG_CHA;
            break;
        case 1:
            aCH = AD5504_ANALOG_CHB;
            break;
        case 2:
            aCH = AD5504_ANALOG_CHC;
            break;
        case 3:
            aCH = AD5504_ANALOG_CHD;
            break;

        default:
            break;
        }

        voltage = AD5504_GetAnalogVolt(&hAD5504, aCH);
    }

    return voltage;
}
