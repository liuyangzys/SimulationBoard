#include "driver_ad5504.h"
#include "spi.h"
#include "stm32f4xx_hal.h"

/** 
 * SPI MSB 传输，最高不超过 16MHz 
 * 每次传输二字节数据 最高位 bit15 0 为写，1 为读
 * bit14 ~ bit12 000-none 001-1通道 010-2通道 011-3通道 100-4通道 111-控制状态字 
 * bit11 ~ bit0  数据位 databit, 电压计算为  vref * (databit / 0x0fff)
 */

#define WRITE_MASK 0x0000 
#define READ_MASK 0x8000
#define CTL_MASK 0x7000
/*

 */

/**
 * @brief 设置输出电压
 *
 * @param ch 通道号 0～3
 * @param voltage 电压值 单位 V
 */
void AD5504_SetAnalogVolt(AD5504_HandleType *hAD5504, AD5504_AnalogCH ch,
                          float voltage)
{
    uint16_t sendData = WRITE_MASK | (ch << 12);
    uint16_t volt_bit = (voltage * 1000 / hAD5504->vref_mv) * 4096;
    sendData |= (volt_bit & 0x0FFF);
    hAD5504->SYNC_SetPin(0);
    HAL_SPI_Transmit(&hspi1, (uint8_t*)&sendData, 1, 5);
    hAD5504->SYNC_SetPin(1);

    hAD5504->LDAC_SetPin(0);
    hAD5504->delay_us(10);
    hAD5504->LDAC_SetPin(1);
}

/**
 * @brief 设置输出电压
 *
 * @param ch 通道号 0～3
 * @param voltage 电压值 单位 V
 */
float AD5504_GetAnalogVolt(AD5504_HandleType *hAD5504, AD5504_AnalogCH ch)
{
    uint16_t sendData = READ_MASK | (ch << 12);
    uint16_t recvData = 0;

    hAD5504->SYNC_SetPin(0);
    HAL_SPI_Transmit(&hspi1, (uint8_t *)&sendData, 1, 5);
    HAL_SPI_Receive(&hspi1, (uint8_t *)&recvData, 1, 5);
    hAD5504->SYNC_SetPin(1);

    float volt = ((recvData & 0x0FFF) / 4096.0f) * (hAD5504->vref_mv / 1000.0f);
    return volt;
}
