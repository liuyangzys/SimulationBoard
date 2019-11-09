#ifndef _SOFT_DAC_H_
#define _SOFT_DAC_H_

#include <stdint.h>

void DAC_InitConfig(void);

void DAC_SetCHVolt(uint8_t ch, float voltage);

float DAC_GetCHVolt(uint8_t ch);


#endif
