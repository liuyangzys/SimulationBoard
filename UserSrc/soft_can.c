#include "can.h"
#include "soft_can.h"

/**
 * @brief can 总线过滤器配置
 * 
 */
void CAN_Bus_FilterConfig(void)
{
   CAN_FilterTypeDef sFilterConfig;
    sFilterConfig.FilterActivation = ENABLE;
    sFilterConfig.FilterBank = 0;
    sFilterConfig.FilterFIFOAssignment = CAN_FILTER_FIFO0;

    sFilterConfig.FilterIdHigh = (uint16_t)(0x0000 >> 16);
    sFilterConfig.FilterIdLow =
        (uint16_t)((0x0000 & 0x0000FFFF) | CAN_ID_EXT);
    sFilterConfig.FilterMaskIdHigh = (uint16_t)(0x0000 >> 16);
    sFilterConfig.FilterMaskIdLow = (uint16_t)(0x0000 & 0x0000FFFF);

    sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
    sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;

    if (HAL_CAN_ConfigFilter(&hcan1, &sFilterConfig) != HAL_OK)
    {
        Error_Handler();
    }

    if (HAL_CAN_Start(&hcan1) != HAL_OK)
    {
        Error_Handler();
    }

    if (HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING) !=
        HAL_OK)
    {
        Error_Handler();
    }
}

/**
 * @brief can 总线相关服务函数，轮询调用
 * 
 */
void CAN_Bus_Service(void)
{
    uint32_t lastTime = 0;
    /* 每 200 ms 发送一次 */
    if (HAL_GetTick() - lastTime > 200)
    {
        lastTime = HAL_GetTick();

        CAN_TxHeaderTypeDef TxMsg;
        uint8_t CanSendBuff[8] = {'c', 'a', 'n'};
        TxMsg.ExtId = 0x0AB0 >> 3;
        TxMsg.RTR = CAN_RTR_DATA;
        TxMsg.IDE = CAN_ID_EXT;
        TxMsg.DLC = 3;
        TxMsg.TransmitGlobalTime = DISABLE;
        while(HAL_CAN_GetTxMailboxesFreeLevel(&hcan1) == 0);
        uint32_t TxMailBox;
        HAL_CAN_AddTxMessage(&hcan1, &TxMsg, CanSendBuff, &TxMailBox);
    }
}

/**
 * @brief CAN fifo0 消息挂起中断回调函数
 * 
 * @param hcan
 */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef* hcan)
{
    CAN_RxHeaderTypeDef RxMsg;
    uint8_t CanRxBuffer[8];

    if (HAL_CAN_GetRxFifoFillLevel(hcan, CAN_RX_FIFO0))
    {
        HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxMsg, CanRxBuffer);
    }
}
