#include "delay.h"
#include "tim.h"
#include "stm32f4xx_hal.h"

#define MICROS_TIM_HANDLE htim2

/**
 * @brief 微秒级的计时
 * 
 * @return uint32_t 
 */
uint32_t micros(void)
{
    return __HAL_TIM_GetCounter(&MICROS_TIM_HANDLE);
}

/**
 * @brief 微秒级的延时
 * 
 * @param us 延时的微秒数
 */
void delay_us(uint32_t us)
{
    uint32_t start_time = micros();
    while (micros() - start_time < us)
    {
    }
    return;
}

/**
 * @brief 毫秒级的延时
 * 
 * @param ms 延时的毫秒数
 */
void delay_ms(uint32_t ms)
{
    HAL_Delay(ms);
}