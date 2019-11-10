#ifndef _DRIVER_AD5504_H_
#define _DRIVER_AD5504_H_

#include <stdint.h>

typedef enum
{
    AD5504_ANALOG_CHA = 1,
    AD5504_ANALOG_CHB,
    AD5504_ANALOG_CHC,
    AD5504_ANALOG_CHD
} AD5504_AnalogCH;

typedef struct
{
    /* CLR 线设置电平，CLR 低电平，则输出清零 */
    void (*CLR_SetPin)(uint8_t pinState);

    /* SYNC 线设置电平，SYNC 为 AD5504 的片选线，进行 SPI 传输时拉低 */
    void (*SYNC_SetPin)(uint8_t pinState);

    /* LDAC 线设置电平，LDAC 为输出刷新线，拉低则将模拟口输出电压刷新为寄存器的值 */
    void (*LDAC_SetPin)(uint8_t pinState);

    void (*delay_us)(uint32_t ms);

    uint32_t vref_mv;

} AD5504_HandleType;

void AD5504_SetAnalogVolt(AD5504_HandleType *hAD5504, AD5504_AnalogCH ch,
                          float voltage);

float AD5504_GetAnalogVolt(AD5504_HandleType *hAD5504, AD5504_AnalogCH ch);

#endif
