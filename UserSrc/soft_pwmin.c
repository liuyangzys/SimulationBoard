#include "soft_pwmin.h"
#include "tim.h"

/* pwm 周期 */
uint32_t _PwmPeriod[16] = {0};
/* pwm 高电平时间 */
uint32_t _PwmHighLevelPeriod[16] = {0};

static uint8_t _PwmICpolarity[16] = {0};

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
    PwmCHType pwm_ch = PWM_CH0;
    uint32_t Channelx = 0;

    if (htim->Instance == TIM1)
    {
        switch (htim->Channel)
        {
        case HAL_TIM_ACTIVE_CHANNEL_1:

            Channelx = TIM_CHANNEL_1;
            pwm_ch = PWM_CH15;
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
            pwm_ch = PWM_CH0;
            Channelx = TIM_CHANNEL_1;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_2:
            pwm_ch = PWM_CH1;
            Channelx = TIM_CHANNEL_2;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_3:
            pwm_ch = PWM_CH10;
            Channelx = TIM_CHANNEL_3;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_4:
            pwm_ch = PWM_CH11;
            Channelx = TIM_CHANNEL_4;
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
            pwm_ch = PWM_CH2;
            Channelx = TIM_CHANNEL_1;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_2:
            pwm_ch = PWM_CH3;
            Channelx = TIM_CHANNEL_2;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_3:
            pwm_ch = PWM_CH8;
            Channelx = TIM_CHANNEL_3;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_4:
            pwm_ch = PWM_CH9;
            Channelx = TIM_CHANNEL_4;
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
            pwm_ch = PWM_CH4;
            Channelx = TIM_CHANNEL_1;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_2:
            pwm_ch = PWM_CH5;
            Channelx = TIM_CHANNEL_2;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_3:
            pwm_ch = PWM_CH6;
            Channelx = TIM_CHANNEL_3;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_4:
            pwm_ch = PWM_CH7;
            Channelx = TIM_CHANNEL_4;
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
            pwm_ch = PWM_CH13;
            Channelx = TIM_CHANNEL_3;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_4:
            pwm_ch = PWM_CH14;
            Channelx = TIM_CHANNEL_4;
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
            pwm_ch = PWM_CH12;
            Channelx = TIM_CHANNEL_2;
            break;

        default:
            break;
        }
    }

    if (_PwmICpolarity[pwm_ch] == 0)
    {
        uint32_t time = HAL_TIM_ReadCapturedValue(htim, Channelx);

        if (time > _PwmHighLevelTime[pwm_ch])
        {
            _PwmPeriod[pwm_ch] = time - _PwmHighLevelTime[pwm_ch];
        }
        _PwmHighLevelTime[pwm_ch] = time;

        _PwmICpolarity[pwm_ch] = 1;
        __HAL_TIM_SET_CAPTUREPOLARITY(htim, Channelx,
                                      TIM_INPUTCHANNELPOLARITY_FALLING);
    }
    else
    {
        _PwmLowLevelTime[pwm_ch] = HAL_TIM_ReadCapturedValue(htim, Channelx);
        if (_PwmLowLevelTime[pwm_ch] > _PwmHighLevelTime[pwm_ch])
        {
            _PwmHighLevelPeriod[pwm_ch] =
                _PwmLowLevelTime[pwm_ch] - _PwmHighLevelTime[pwm_ch];
        }

        _PwmICpolarity[pwm_ch] = 0;
        __HAL_TIM_SET_CAPTUREPOLARITY(htim, Channelx,
                                      TIM_INPUTCHANNELPOLARITY_RISING);
    }
}

/**
 * @brief 获取各通道的周期
 * 
 * @return uint32_t* 各通道周期数据指针
 */
uint32_t* Pwm_GetPeriod(void)
{
    return _PwmPeriod;
}

/**
 * @brief 获取各通道的高电平时间
 * 
 * @return uint32_t* 各通道高电平时间数据指针
 */
uint32_t* Pwm_GetHighLevelPeriod(void)
{
    return _PwmHighLevelPeriod;
}
