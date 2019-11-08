#ifndef _DRIVER_74HC595D_H_
#define _DRIVER_74HC595D_H_

#include <stdint.h>

void HC595D_SendByte(uint8_t data);

void HC595D_CS(void);

void HC595D_SendData(uint8_t* pdata, uint32_t len);


#endif
