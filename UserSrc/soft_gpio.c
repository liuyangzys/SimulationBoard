#include "soft_gpio.h"
#include "gpio.h"
#include "driver_74hc595d.h"

uint8_t hc595d_databyte = 0XFF;

/**
 * @brief 读取 GPIO 输入的电平状态
 * @param in_ch 输入的通道号 0~5
 * 
 * @return GPIO_PinState 
 */
GPIO_PinState GPIO_ReadInput(uint8_t in_ch)
{
    GPIO_PinState state = GPIO_PIN_RESET;

    switch (in_ch)
    {
    case 0:
        state = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12);
        break;

    case 1:
        state = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13);
        break;

    case 2:
        state = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14);
        break;

    case 3:
        state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
        break;

    case 4:
        state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_14);
        break;

    case 5:
        state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15);
        break;

    default:
        break;
    }
    return state;
}

/**
 * @brief 设置 io 输出口电平状态
 * 
 * @param out_ch io 输出口序号，0～3
 * @param state 电平状态
 */
void GPIO_SetOutput(uint8_t out_ch, GPIO_PinState state)
{
    if (out_ch < 4)
    {
        switch (state)
        {
        case GPIO_PIN_SET:
            hc595d_databyte = hc595d_databyte | (1 << out_ch);
            HC595D_SendByte(hc595d_databyte);
            HC595D_CS();
            break;

        case GPIO_PIN_RESET:
            hc595d_databyte &= ~(1 << out_ch);
            HC595D_SendByte(hc595d_databyte);
            HC595D_CS();
            break;

        default:
            break;
        }
    }
}
