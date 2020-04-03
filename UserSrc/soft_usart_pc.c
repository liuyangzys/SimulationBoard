#include "soft_usart_pc1.h"
#include "soft_pwmin.h"
#include "soft_adc.h"
#include "soft_gpio.h"
#include "usart.h"
#include <string.h>

typedef enum
{
    MSG_ACK = 1,                      /* 应答消息 */
    MSG_BOARD_INTERFACE_STATUS = 2,   /* 输入信号接口状态 */
    MSG_BOARD_DATA_RETRANSSMISION = 3 /* 串口 CAN 数据转发 */
} MsgSendToPCEnumType;

/**
 * @brief 发送信号输入状态数据
 * 
 * @param pdata 发送数据的 buffer
 * @param USARTx 使用的串口
 */
void SendPC_BoardInterfaceStatusMsg(uint8_t *pdata, USART_TypeDef *USARTx)
{
    uint16_t index = 0;
    uint16_t payloadLength = 0;
    /* 帧头 */
    pdata[index++] = 0xEB;
    pdata[index++] = 0x90;
    /* 长度 */
    pdata[index++] = 0;
    pdata[index++] = 0;
    /* 指令字 */
    pdata[index++] = MSG_BOARD_INTERFACE_STATUS;

    /* 16 通道 PWM 输入 */
    uint32_t *pwm = Pwm_GetHighLevelPeriod();
    for (uint8_t i = 0; i < 16; ++i)
    {
        uint16_t pwmch = pwm[i];
        memcpy(pdata + index, &pwmch, 2);
        index += 2;
    }
    /* 6 通道 IO 输入 */
    for (uint8_t i = 0; i < 6; ++i)
    {
        pdata[index++] = GPIO_ReadInput(i);
    }
    /* 4 通道 IO 输出 */
    for (uint8_t i = 0; i < 4; ++i)
    {
        pdata[index++] = (hc595d_databyte >> i) & 0x01;
    }
    /* AD 输入电压 */
    for (uint8_t i = 0; i < 2; ++i)
    {
        uint16_t volt = ADC_GetVoltage(i) * 10;
        memcpy(pdata + index, &volt, 2);
        index += 2; 
    }
    /* DA 输出电压 */
}
