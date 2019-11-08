#include "driver_74hc595d.h"
#include "stm32f4xx_hal.h"
#include "delay.h"

/*------------------------ Macro ---------------------------------------------*/

#define STCP_GPIOx GPIOC
#define STCP_GPIO_PINx GPIO_PIN_2

#define SHCP_GPIOx GPIOC
#define SHCP_GPIO_PINx GPIO_PIN_3

#define DS_GPIOx GPIOA
#define DS_GPIO_PINx GPIO_PIN_4


/*------------------------ Function ------------------------------------------*/
/**
 * @brief 设置 STCP 线电平
 * 
 * @param state 电平状态
 */
static void HC595D_SetSTCP(GPIO_PinState state)
{
    HAL_GPIO_WritePin(STCP_GPIOx, STCP_GPIO_PINx, state);
}

/**
 * @brief 设置 SHCP 线电平
 * 
 * @param state 电平状态
 */
static void HC595D_SetSHCP(GPIO_PinState state)
{
    HAL_GPIO_WritePin(SHCP_GPIOx, SHCP_GPIO_PINx, state);
}

/**
 * @brief 设置 DS 线电平
 * 
 * @param state 电平状态
 */
static void HC595D_SetDs(GPIO_PinState state)
{
    HAL_GPIO_WritePin(DS_GPIOx, DS_GPIO_PINx, state);
}

/**
 * @brief 往 hc595d 发送一个字节
 *        串行收入一个字节
 * 
 * @param data 要发送的字节数据
 */
void HC595D_SendByte(uint8_t data)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        /* 从高到低 bit 发送, DS 线根据 bit 置位电平*/
        if (data & 0x80)
        {   
            HC595D_SetDs(GPIO_PIN_SET);
        }
        else
        {
            HC595D_SetDs(GPIO_PIN_RESET);
        }

        /* SHCP 线上产生一个上升沿 */
        HC595D_SetSHCP(GPIO_PIN_RESET);
        delay_us(5);
        HC595D_SetSHCP(GPIO_PIN_SET);

        data = data >> 1;
    }
}

/**
 * @brief hc595d 输出锁存
 *        在调用 HC595D_SendByte 后，需要调用此函数，HC595D 才会将数据并行输出
 */
void HC595D_CS(void)
{
    HC595D_SetSTCP(GPIO_PIN_RESET);
    delay_us(5);
    HC595D_SetSTCP(GPIO_PIN_SET);
}

/**
 * @brief 往 HC595D 发送数据
 *        适用于多个 HC595D 级联情况使用
 * 
 * @param pdata 数据内容
 * @param len 长度
 */
void HC595D_SendData(uint8_t* pdata, uint32_t len)
{
    for (uint32_t i = 0; i < len; i++)
    {
        HC595D_SendByte(pdata[i]);
    }
    HC595D_CS();
}
