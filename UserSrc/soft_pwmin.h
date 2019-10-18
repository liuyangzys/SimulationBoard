#ifndef _SOFT_PWMIN_H_
#define _SOFT_PWMIN_H_

#include <stdint.h>

typedef enum
{
    PWM_CH0 = 0,
    PWM_CH1,
    PWM_CH2,
    PWM_CH3,
    PWM_CH4,
    PWM_CH5,
    PWM_CH6,
    PWM_CH7,
    PWM_CH8,
    PWM_CH9,
    PWM_CH10,
    PWM_CH11,
    PWM_CH12,
    PWM_CH13,
    PWM_CH14,
    PWM_CH15
} PwmCHType;

void PwmCapture_Config(void);

uint32_t *Pwm_GetPeriod(void);

uint32_t *Pwm_GetHighLevelPeriod(void);

#endif
