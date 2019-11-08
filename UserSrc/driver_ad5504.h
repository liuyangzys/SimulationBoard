#ifndef _DRIVER_AD5504_H_
#define _DRIVER_AD5504_H_

#include <stdint.h>

typedef struct 
{
    /* CLR 线设置电平 */
    void (*CLR_SetPin)(uint8_t pinState);

    /* SYNC 线设置电平 */
    void (*SYNC_SetPin)(uint8_t pinState);

    /* LDAC 线设置电平 */
    void (*LDAC_SetPin)(uint8_t pinState);

    


}AD5504_HandleType;


#endif