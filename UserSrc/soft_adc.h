#ifndef _SOFT_ADC_H_
#define _SOFT_ADC_H_

#include <stdint.h>

void ADC_Config(void);

void ADC_VoltageUpdate(void);

float ADC_GetVoltage(uint8_t ch);

void ADC_SetVoltCalibParams(uint8_t ch, float kp, float offset);

#endif
