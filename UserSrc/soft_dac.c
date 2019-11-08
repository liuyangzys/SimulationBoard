#include "soft_dac.h"
#include "spi.h"
#include "delay.h"
#include "soft_gpio.h"
#include "driver_74hc595d.h"
#include "driver_ad5504.h"

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
void DAC_AD5504_Init(void)
{
    hAD5504.LDAC_SetPin = AD5504_LDAC_SetState;
    hAD5504.CLR_SetPin = AD5504_CLR_SetState;
    hAD5504.SYNC_SetPin = AD5504_SYNC_SetState;

    hAD5504.LDAC_SetPin(1);
    hAD5504.SYNC_SetPin(1);
    hAD5504.CLR_SetPin(0);
    delay_ms(5);
    hAD5504.CLR_SetPin(1);
}