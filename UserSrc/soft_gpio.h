#ifndef _SOFT_GPIO_H_
#define _SOFT_GPIO_H_

#include "stm32f4xx_hal.h"

GPIO_PinState GPIO_ReadInput(uint8_t in_ch);

void GPIO_SetOutput(uint8_t out_ch, GPIO_PinState state);


#endif
