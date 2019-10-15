#include "tim.h"
#include "soft_pwmin.h"

/* pwm 周期 */
static uint32_t _PwmPeriod[16] = {0};
/* pwm 高电平时间 */
static uint32_t _PwmHighLevelPeriod[16] = {0};

static uint32_t _PwmHighLevelTime[16] = {0};
static uint32_t _PwmLowLevelTime[16] = {0};

/**
 * @brief pwm 输入捕获配置
 * 
 */
void PwmCapture_Config(void)
{
    HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_1);

    HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);
    HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_2);
    HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_3);
    HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_4);

    HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_1);
    HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_2);
    HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_3);
    HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_4);

    HAL_TIM_IC_Start_IT(&htim4, TIM_CHANNEL_1);
    HAL_TIM_IC_Start_IT(&htim4, TIM_CHANNEL_2);
    HAL_TIM_IC_Start_IT(&htim4, TIM_CHANNEL_3);
    HAL_TIM_IC_Start_IT(&htim4, TIM_CHANNEL_4);

    HAL_TIM_IC_Start_IT(&htim8, TIM_CHANNEL_3);
    HAL_TIM_IC_Start_IT(&htim8, TIM_CHANNEL_4);

    HAL_TIM_IC_Start_IT(&htim12, TIM_CHANNEL_2);
}

/**
 * @brief 定时器输入捕获回调函数
 * 
 * @param htim 
 */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    GPIO_TypeDef *GPIOx = 0;
    uint16_t GPIO_PIN_x = 0;
    uint8_t index = 0;

    if (htim->Instance == TIM1)
    {
        switch (htim->Channel)
        {
        case HAL_TIM_ACTIVE_CHANNEL_1:
            GPIOx = GPIOA;
            GPIO_PIN_x = GPIO_PIN_8;
            index = 0;
            break;

        default:
            break;
        }
    }
    else if (htim->Instance == TIM2)
    {
        switch (htim->Channel)
        {
        case HAL_TIM_ACTIVE_CHANNEL_1:
            GPIOx = GPIOB;
            GPIO_PIN_x = GPIO_PIN_10;
            index = 1;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_2:
            GPIOx = GPIOB;
            GPIO_PIN_x = GPIO_PIN_11;
            index = 2;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_3:
            GPIOx = GPIOA;
            GPIO_PIN_x = GPIO_PIN_15;
            index = 3;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_4:
            GPIOx = GPIOB;
            GPIO_PIN_x = GPIO_PIN_3;
            index = 4;
            break;

        default:
            break;
        }
    }
    else if (htim->Instance == TIM3)
    {
        switch (htim->Channel)
        {
        case HAL_TIM_ACTIVE_CHANNEL_1:
            GPIOx = GPIOB;
            GPIO_PIN_x = GPIO_PIN_0;
            index = 5;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_2:
            GPIOx = GPIOB;
            GPIO_PIN_x = GPIO_PIN_1;
            index = 6;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_3:
            GPIOx = GPIOB;
            GPIO_PIN_x = GPIO_PIN_4;
            index = 7;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_4:
            GPIOx = GPIOB;
            GPIO_PIN_x = GPIO_PIN_5;
            index = 8;
            break;

        default:
            break;
        }
    }
    else if (htim->Instance == TIM4)
    {
        switch (htim->Channel)
        {
        case HAL_TIM_ACTIVE_CHANNEL_1:
            GPIOx = GPIOB;
            GPIO_PIN_x = GPIO_PIN_6;
            index = 9;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_2:
            GPIOx = GPIOB;
            GPIO_PIN_x = GPIO_PIN_7;
            index = 10;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_3:
            GPIOx = GPIOB;
            GPIO_PIN_x = GPIO_PIN_8;
            index = 11;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_4:
            GPIOx = GPIOB;
            GPIO_PIN_x = GPIO_PIN_9;
            index = 12;
            break;

        default:
            break;
        }
    }
    else if (htim->Instance == TIM8)
    {
        switch (htim->Channel)
        {
        case HAL_TIM_ACTIVE_CHANNEL_3:
            GPIOx = GPIOC;
            GPIO_PIN_x = GPIO_PIN_8;
            index = 13;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_4:
            GPIOx = GPIOC;
            GPIO_PIN_x = GPIO_PIN_9;
            index = 14;
            break;

        default:
            break;
        }
    }
    else if (htim->Instance == TIM12)
    {
        switch (htim->Channel)
        {
        case HAL_TIM_ACTIVE_CHANNEL_2:
            GPIOx = GPIOB;
            GPIO_PIN_x = GPIO_PIN_15;
            index = 15;
            break;

        default:
            break;
        }
    }

    if (GPIOx)
    {
        switch (HAL_GPIO_ReadPin(GPIOx, GPIO_PIN_x))
        {
        case GPIO_PIN_SET:
        {
            uint32_t highLevelTime = HAL_TIM_ReadCapturedValue(htim, htim->Channel);
            if (highLevelTime > _PwmHighLevelTime[index])
            {
                _PwmPeriod[index] = highLevelTime - _PwmHighLevelTime[index];
            }
            _PwmHighLevelTime[index] = highLevelTime;
        }
        break;

        case GPIO_PIN_RESET:
            _PwmLowLevelTime[index] = HAL_TIM_ReadCapturedValue(htim, htim->Channel);
            if (_PwmLowLevelTime[index] > _PwmHighLevelTime[index])
            {
                _PwmHighLevelPeriod[index] = _PwmLowLevelTime[index] - _PwmHighLevelTime[index];
            }
            break;

        default:
            break;
        }
    }
}