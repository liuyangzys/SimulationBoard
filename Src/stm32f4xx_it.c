/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    stm32f4xx_it.c
 * @brief   Interrupt Service Routines.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usart.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_adc1;
extern CAN_HandleTypeDef hcan1;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim8;
extern TIM_HandleTypeDef htim12;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */ 
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles DMA1 stream0 global interrupt.
  */
void DMA1_Stream0_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream0_IRQn 0 */

  /* USER CODE END DMA1_Stream0_IRQn 0 */
  
  /* USER CODE BEGIN DMA1_Stream0_IRQn 1 */

  /* USER CODE END DMA1_Stream0_IRQn 1 */
}

/**
  * @brief This function handles DMA1 stream1 global interrupt.
  */
void DMA1_Stream1_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream1_IRQn 0 */

  /* USER CODE END DMA1_Stream1_IRQn 0 */
  
  /* USER CODE BEGIN DMA1_Stream1_IRQn 1 */

  /* USER CODE END DMA1_Stream1_IRQn 1 */
}

/**
  * @brief This function handles DMA1 stream2 global interrupt.
  */
void DMA1_Stream2_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream2_IRQn 0 */

  /* USER CODE END DMA1_Stream2_IRQn 0 */
  
  /* USER CODE BEGIN DMA1_Stream2_IRQn 1 */

  /* USER CODE END DMA1_Stream2_IRQn 1 */
}

/**
  * @brief This function handles DMA1 stream3 global interrupt.
  */
void DMA1_Stream3_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream3_IRQn 0 */
    LL_DMA_ClearFlag_TC3(DMA1);
    LL_DMA_ClearFlag_TE3(DMA1);
    LL_DMA_DisableStream(DMA1, LL_DMA_STREAM_3);
    LL_USART_DisableDMAReq_TX(USART3);
  /* USER CODE END DMA1_Stream3_IRQn 0 */
  
  /* USER CODE BEGIN DMA1_Stream3_IRQn 1 */

  /* USER CODE END DMA1_Stream3_IRQn 1 */
}

/**
  * @brief This function handles DMA1 stream4 global interrupt.
  */
void DMA1_Stream4_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream4_IRQn 0 */
    LL_DMA_ClearFlag_TC4(DMA1);
    LL_DMA_ClearFlag_TE4(DMA1);
    LL_DMA_DisableStream(DMA1, LL_DMA_STREAM_4);
    LL_USART_DisableDMAReq_TX(UART4);
  /* USER CODE END DMA1_Stream4_IRQn 0 */
  
  /* USER CODE BEGIN DMA1_Stream4_IRQn 1 */

  /* USER CODE END DMA1_Stream4_IRQn 1 */
}

/**
  * @brief This function handles DMA1 stream5 global interrupt.
  */
void DMA1_Stream5_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream5_IRQn 0 */

  /* USER CODE END DMA1_Stream5_IRQn 0 */
  
  /* USER CODE BEGIN DMA1_Stream5_IRQn 1 */

  /* USER CODE END DMA1_Stream5_IRQn 1 */
}

/**
  * @brief This function handles DMA1 stream6 global interrupt.
  */
void DMA1_Stream6_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream6_IRQn 0 */
    LL_DMA_ClearFlag_TC6(DMA1);
    LL_DMA_ClearFlag_TE6(DMA1);
    LL_DMA_DisableStream(DMA1, LL_DMA_STREAM_6);
    LL_USART_DisableDMAReq_TX(USART2);
  /* USER CODE END DMA1_Stream6_IRQn 0 */
  
  /* USER CODE BEGIN DMA1_Stream6_IRQn 1 */

  /* USER CODE END DMA1_Stream6_IRQn 1 */
}

/**
  * @brief This function handles CAN1 RX0 interrupts.
  */
void CAN1_RX0_IRQHandler(void)
{
  /* USER CODE BEGIN CAN1_RX0_IRQn 0 */

  /* USER CODE END CAN1_RX0_IRQn 0 */
  HAL_CAN_IRQHandler(&hcan1);
  /* USER CODE BEGIN CAN1_RX0_IRQn 1 */

  /* USER CODE END CAN1_RX0_IRQn 1 */
}

/**
  * @brief This function handles TIM1 capture compare interrupt.
  */
void TIM1_CC_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_CC_IRQn 0 */

  /* USER CODE END TIM1_CC_IRQn 0 */
  HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_CC_IRQn 1 */

  /* USER CODE END TIM1_CC_IRQn 1 */
}

/**
  * @brief This function handles TIM2 global interrupt.
  */
void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */

  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */

  /* USER CODE END TIM2_IRQn 1 */
}

/**
  * @brief This function handles TIM3 global interrupt.
  */
void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM3_IRQn 0 */

  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */

  /* USER CODE END TIM3_IRQn 1 */
}

/**
  * @brief This function handles TIM4 global interrupt.
  */
void TIM4_IRQHandler(void)
{
  /* USER CODE BEGIN TIM4_IRQn 0 */

  /* USER CODE END TIM4_IRQn 0 */
  HAL_TIM_IRQHandler(&htim4);
  /* USER CODE BEGIN TIM4_IRQn 1 */

  /* USER CODE END TIM4_IRQn 1 */
}

/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */
    if (LL_USART_IsActiveFlag_IDLE(USART1))
    {
        // clear idle flag
        LL_USART_ClearFlag_IDLE(USART1);
        // disable uart rx dma
        LL_DMA_DisableStream(DMA2, LL_DMA_STREAM_2);

        // calculate the length of received datas
        uint32_t length = sizeof(U1_DMA_RxBuffer) -
                          LL_DMA_GetDataLength(DMA2, LL_DMA_STREAM_2);

        // Usart1_IDLE_CallBack(Usart1_DMA_RxBuffer, length);

        // enable rx dma
        LL_DMA_SetPeriphAddress(DMA2, LL_DMA_STREAM_2,
                                LL_USART_DMA_GetRegAddr(USART1));
        LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_2, sizeof(U1_DMA_RxBuffer));
        LL_DMA_EnableStream(DMA2, LL_DMA_STREAM_2);

        USART1->SR;
        USART1->DR;
    }
    else
    {
        USART1->SR;
        USART1->DR;
    }
  /* USER CODE END USART1_IRQn 0 */
  /* USER CODE BEGIN USART1_IRQn 1 */

  /* USER CODE END USART1_IRQn 1 */
}

/**
  * @brief This function handles USART2 global interrupt.
  */
void USART2_IRQHandler(void)
{
  /* USER CODE BEGIN USART2_IRQn 0 */
    if (LL_USART_IsActiveFlag_IDLE(USART2))
    {
        // clear idle flag
        LL_USART_ClearFlag_IDLE(USART2);
        // disable uart rx dma
        LL_DMA_DisableStream(DMA1, LL_DMA_STREAM_5);

        // calculate the length of received datas
        uint32_t length = sizeof(U2_DMA_RxBuffer) -
                          LL_DMA_GetDataLength(DMA1, LL_DMA_STREAM_5);

        // USART2_IDLE_CallBack(USART2_DMA_RxBuffer, length);

        // enable rx dma
        LL_DMA_SetPeriphAddress(DMA1, LL_DMA_STREAM_5,
                                LL_USART_DMA_GetRegAddr(USART2));
        LL_DMA_SetDataLength(DMA1, LL_DMA_STREAM_5, sizeof(U2_DMA_RxBuffer));
        LL_DMA_EnableStream(DMA1, LL_DMA_STREAM_5);

        USART2->SR;
        USART2->DR;
    }
    else
    {
        USART2->SR;
        USART2->DR;
    }
  /* USER CODE END USART2_IRQn 0 */
  /* USER CODE BEGIN USART2_IRQn 1 */

  /* USER CODE END USART2_IRQn 1 */
}

/**
  * @brief This function handles USART3 global interrupt.
  */
void USART3_IRQHandler(void)
{
  /* USER CODE BEGIN USART3_IRQn 0 */
    if (LL_USART_IsActiveFlag_IDLE(USART3))
    {
        // clear idle flag
        LL_USART_ClearFlag_IDLE(USART3);
        // disable uart rx dma
        LL_DMA_DisableStream(DMA1, LL_DMA_STREAM_1);

        // calculate the length of received datas
        uint32_t length = sizeof(U3_DMA_RxBuffer) -
                          LL_DMA_GetDataLength(DMA1, LL_DMA_STREAM_1);

        // USART3_IDLE_CallBack(USART3_DMA_RxBuffer, length);

        // enable rx dma
        LL_DMA_SetPeriphAddress(DMA1, LL_DMA_STREAM_1,
                                LL_USART_DMA_GetRegAddr(USART3));
        LL_DMA_SetDataLength(DMA1, LL_DMA_STREAM_1, sizeof(U3_DMA_RxBuffer));
        LL_DMA_EnableStream(DMA1, LL_DMA_STREAM_1);

        USART3->SR;
        USART3->DR;
    }
    else
    {
        USART3->SR;
        USART3->DR;
    }
  /* USER CODE END USART3_IRQn 0 */
  /* USER CODE BEGIN USART3_IRQn 1 */

  /* USER CODE END USART3_IRQn 1 */
}

/**
  * @brief This function handles TIM8 break interrupt and TIM12 global interrupt.
  */
void TIM8_BRK_TIM12_IRQHandler(void)
{
  /* USER CODE BEGIN TIM8_BRK_TIM12_IRQn 0 */

  /* USER CODE END TIM8_BRK_TIM12_IRQn 0 */
  HAL_TIM_IRQHandler(&htim8);
  HAL_TIM_IRQHandler(&htim12);
  /* USER CODE BEGIN TIM8_BRK_TIM12_IRQn 1 */

  /* USER CODE END TIM8_BRK_TIM12_IRQn 1 */
}

/**
  * @brief This function handles TIM8 capture compare interrupt.
  */
void TIM8_CC_IRQHandler(void)
{
  /* USER CODE BEGIN TIM8_CC_IRQn 0 */

  /* USER CODE END TIM8_CC_IRQn 0 */
  HAL_TIM_IRQHandler(&htim8);
  /* USER CODE BEGIN TIM8_CC_IRQn 1 */

  /* USER CODE END TIM8_CC_IRQn 1 */
}

/**
  * @brief This function handles DMA1 stream7 global interrupt.
  */
void DMA1_Stream7_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream7_IRQn 0 */
    LL_DMA_ClearFlag_TC7(DMA1);
    LL_DMA_ClearFlag_TE7(DMA1);
    LL_DMA_DisableStream(DMA1, LL_DMA_STREAM_7);
    LL_USART_DisableDMAReq_TX(UART5);
  /* USER CODE END DMA1_Stream7_IRQn 0 */
  
  /* USER CODE BEGIN DMA1_Stream7_IRQn 1 */

  /* USER CODE END DMA1_Stream7_IRQn 1 */
}

/**
  * @brief This function handles UART4 global interrupt.
  */
void UART4_IRQHandler(void)
{
  /* USER CODE BEGIN UART4_IRQn 0 */
    if (LL_USART_IsActiveFlag_IDLE(UART4))
    {
        // clear idle flag
        LL_USART_ClearFlag_IDLE(UART4);
        // disable uart rx dma
        LL_DMA_DisableStream(DMA1, LL_DMA_STREAM_2);

        // calculate the length of received datas
        uint32_t length = sizeof(U4_DMA_RxBuffer) -
                          LL_DMA_GetDataLength(DMA1, LL_DMA_STREAM_2);

        // UART4_IDLE_CallBack(UART4_DMA_RxBuffer, length);

        // enable rx dma
        LL_DMA_SetPeriphAddress(DMA1, LL_DMA_STREAM_2,
                                LL_USART_DMA_GetRegAddr(UART4));
        LL_DMA_SetDataLength(DMA1, LL_DMA_STREAM_2, sizeof(U4_DMA_RxBuffer));
        LL_DMA_EnableStream(DMA1, LL_DMA_STREAM_2);

        UART4->SR;
        UART4->DR;
    }
    else
    {
        UART4->SR;
        UART4->DR;
    }
  /* USER CODE END UART4_IRQn 0 */
  /* USER CODE BEGIN UART4_IRQn 1 */

  /* USER CODE END UART4_IRQn 1 */
}

/**
  * @brief This function handles UART5 global interrupt.
  */
void UART5_IRQHandler(void)
{
  /* USER CODE BEGIN UART5_IRQn 0 */
    if (LL_USART_IsActiveFlag_IDLE(UART5))
    {
        // clear idle flag
        LL_USART_ClearFlag_IDLE(UART5);
        // disable uart rx dma
        LL_DMA_DisableStream(DMA1, LL_DMA_STREAM_0);

        // calculate the length of received datas
        uint32_t length = sizeof(U5_DMA_RxBuffer) -
                          LL_DMA_GetDataLength(DMA1, LL_DMA_STREAM_0);

        // UART5_IDLE_CallBack(UART5_DMA_RxBuffer, length);

        // enable rx dma
        LL_DMA_SetPeriphAddress(DMA1, LL_DMA_STREAM_0,
                                LL_USART_DMA_GetRegAddr(UART5));
        LL_DMA_SetDataLength(DMA1, LL_DMA_STREAM_0, sizeof(U5_DMA_RxBuffer));
        LL_DMA_EnableStream(DMA1, LL_DMA_STREAM_0);

        UART5->SR;
        UART5->DR;
    }
    else
    {
        UART5->SR;
        UART5->DR;
    }
  /* USER CODE END UART5_IRQn 0 */
  /* USER CODE BEGIN UART5_IRQn 1 */

  /* USER CODE END UART5_IRQn 1 */
}

/**
  * @brief This function handles DMA2 stream0 global interrupt.
  */
void DMA2_Stream0_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream0_IRQn 0 */

  /* USER CODE END DMA2_Stream0_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_adc1);
  /* USER CODE BEGIN DMA2_Stream0_IRQn 1 */

  /* USER CODE END DMA2_Stream0_IRQn 1 */
}

/**
  * @brief This function handles DMA2 stream1 global interrupt.
  */
void DMA2_Stream1_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream1_IRQn 0 */

  /* USER CODE END DMA2_Stream1_IRQn 0 */
  
  /* USER CODE BEGIN DMA2_Stream1_IRQn 1 */

  /* USER CODE END DMA2_Stream1_IRQn 1 */
}

/**
  * @brief This function handles DMA2 stream2 global interrupt.
  */
void DMA2_Stream2_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream2_IRQn 0 */

  /* USER CODE END DMA2_Stream2_IRQn 0 */
  
  /* USER CODE BEGIN DMA2_Stream2_IRQn 1 */

  /* USER CODE END DMA2_Stream2_IRQn 1 */
}

/**
  * @brief This function handles DMA2 stream6 global interrupt.
  */
void DMA2_Stream6_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream6_IRQn 0 */
    LL_DMA_ClearFlag_TC6(DMA2);
    LL_DMA_ClearFlag_TE6(DMA2);
    LL_DMA_DisableStream(DMA2, LL_DMA_STREAM_6);
    LL_USART_DisableDMAReq_TX(USART6);
  /* USER CODE END DMA2_Stream6_IRQn 0 */
  
  /* USER CODE BEGIN DMA2_Stream6_IRQn 1 */

  /* USER CODE END DMA2_Stream6_IRQn 1 */
}

/**
  * @brief This function handles DMA2 stream7 global interrupt.
  */
void DMA2_Stream7_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream7_IRQn 0 */
    LL_DMA_ClearFlag_TC7(DMA2);
    LL_DMA_ClearFlag_TE7(DMA2);
  /* USER CODE END DMA2_Stream7_IRQn 0 */
  
  /* USER CODE BEGIN DMA2_Stream7_IRQn 1 */
    LL_DMA_DisableStream(DMA2, LL_DMA_STREAM_7);
    LL_USART_DisableDMAReq_TX(USART1);
  /* USER CODE END DMA2_Stream7_IRQn 1 */
}

/**
  * @brief This function handles USART6 global interrupt.
  */
void USART6_IRQHandler(void)
{
  /* USER CODE BEGIN USART6_IRQn 0 */
    if (LL_USART_IsActiveFlag_IDLE(USART6))
    {
        // clear idle flag
        LL_USART_ClearFlag_IDLE(USART6);
        // disable uart rx dma
        LL_DMA_DisableStream(DMA2, LL_DMA_STREAM_1);

        // calculate the length of received datas
        uint32_t length = sizeof(U6_DMA_RxBuffer) -
                          LL_DMA_GetDataLength(DMA2, LL_DMA_STREAM_1);

        // USART6_IDLE_CallBack(USART6_DMA_RxBuffer, length);

        // enable rx dma
        LL_DMA_SetPeriphAddress(DMA2, LL_DMA_STREAM_1,
                                LL_USART_DMA_GetRegAddr(USART6));
        LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_1, sizeof(U6_DMA_RxBuffer));
        LL_DMA_EnableStream(DMA2, LL_DMA_STREAM_1);

        USART6->SR;
        USART6->DR;
    }
    else
    {
        USART6->SR;
        USART6->DR;
    }
  /* USER CODE END USART6_IRQn 0 */
  /* USER CODE BEGIN USART6_IRQn 1 */

  /* USER CODE END USART6_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
