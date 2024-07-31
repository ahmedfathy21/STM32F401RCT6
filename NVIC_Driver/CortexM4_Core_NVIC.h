/**
 ******************************************************************************
 * @file           : CortexM4_Core_NVIC.h
 * @author         : Ahmed Fathy
 * @brief          :

 ******************************************************************************
 */

#ifndef CORTEXM4_CORE_NVIC_H_
#define CORTEXM4_CORE_NVIC_H_

/*--------------------------Includes Start----------------------- */
#include "Shared STDTYPES/STD_TYPES.h"



/*--------------------------Macro declarations Start----------------------- */
#define  BASE_NVIC    (0xE000E100UL)
#define  NVIC         ((NVIC_TYPE *)BASE_NVIC)
#define  NVIC_PRIORITY_BUTS     4U

/*--------------------------Macro Functions Start----------------------- */



/*--------------------------Data type declaration Start----------------------- */

typedef enum{
	/*   Cortex m4 exceptions numbers  */
	NMI_IRQn                         = -14,          /* Non maskable interrupt, Clock Security System  */
	HardFault_IRQn                   = -13,          /* All class of fault  */
	MemManage_IRQn                   = -12,          /* Memory management  */
	BusFault_IRQn                    = -11,          /* Pre-fetch fault, memory access fault  */
	UsageFault_IRQn                  = -10,          /* Undefined instruction or illegal state  */
	SVCall_IRQn                      = -5,          /* System Service call via SWI instruction  */
	DebugMonitor_IRQn                = -4,         /* DebugMonitor  */
	    PendSV_IRQn                  = -2,        /* Pendable request for system service  */
	    Systick_IRQn                 = -1,        /* System tick timer  */

	/*   Cortex m4 Interrupts numbers  */
	    WWDG_IRQn 				= 0,		 /* Window WatchDog                             */
		PVD_IRQn				= 1,         /* PVD through EXTI Line detection             */
		TAMP_STAMP_IRQn 		= 2,         /* Tamper and TimeStamps through the EXTI line */
		RTC_WKUP_IRQn			= 3,         /* RTC Wakeup through the EXTI line            */
		FLASH_IRQn 				= 4,         /* FLASH                                       */
		RCC_IRQn				= 5,         /* RCC                                         */
		EXTI0_IRQn 				= 6,         /* EXTI Line0                                  */
		EXTI1_IRQn				= 7,         /* EXTI Line1                                  */
		EXTI2_IRQn 				= 8,         /* EXTI Line2                                  */
		EXTI3_IRQn				= 9,         /* EXTI Line3                                  */
		EXTI4_IRQn 				= 10,        /* EXTI Line4                                  */
		DMA1_Stream0_IRQn		= 11,        /* DMA1 Stream 0                               */
		DMA1_Stream1_IRQn		= 12,        /* DMA1 Stream 1                               */
		DMA1_Stream2_IRQn		= 13,        /* DMA1 Stream 2                               */
		DMA1_Stream3_IRQn		= 14,        /* DMA1 Stream 3                               */
		DMA1_Stream4_IRQn		= 15,        /* DMA1 Stream 4                               */
		DMA1_Stream5_IRQn		= 16,        /* DMA1 Stream 5                               */
		DMA1_Stream6_IRQn		= 17,        /* DMA1 Stream 6                               */
		ADC_IRQn				= 18,        /* ADC1, ADC2 and ADC3s                        */
		EXTI9_5_IRQn			= 23,        /* External Line[9:5]s                         */
		TIM1_BRK_TIM9_IRQn		= 24,        /* TIM1 Break and TIM9                         */
		TIM1_UP_TIM10_IRQn		= 25,        /* TIM1 Update and TIM10                       */
		TIM1_TRG_COM_TIM11_IRQn	= 26,        /* TIM1 Trigger and Commutation and TIM11      */
		TIM1_CC_IRQn			= 27,        /* TIM1 Capture Compare                        */
		TIM2_IRQn				= 28,        /* TIM2                                        */
		TIM3_IRQn				= 29,        /* TIM3                                        */
		TIM4_IRQn				= 30,        /* TIM4                                        */
		I2C1_EV_IRQn			= 31,        /* I2C1 Event                                  */
		I2C1_ER_IRQn			= 32,        /* I2C1 Error                                  */
		I2C2_EV_IRQn			= 33,        /* I2C2 Event                                  */
		I2C2_ER_IRQn			= 34,        /* I2C2 Error                                  */
		SPI1_IRQn				= 35,        /* SPI1                                        */
		SPI2_IRQn				= 36,        /* SPI2                                        */
		USART1_IRQn				= 37,        /* USART1                                      */
		USART2_IRQn				= 38,        /* USART2                                      */
		EXTI15_10_IRQn			= 40,        /* External Line[15:10]s                       */
		RTC_Alarm_IRQn			= 41,        /* RTC Alarm (A and B) through EXTI Line       */
		OTG_FS_WKUP_IRQn		= 42,        /* USB OTG FS Wakeup through EXTI line         */
		DMA1_Stream7_IRQn		= 47,        /* DMA1 Stream7                                */
		SDIO_IRQn				= 49,        /* SDIO                                        */
		TIM5_IRQn				= 50,        /* TIM5                                        */
		SPI3_IRQn				= 51,        /* SPI3                                        */
		DMA2_Stream0_IRQn		= 56,        /* DMA2 Stream 0                               */
		DMA2_Stream1_IRQn		= 57,        /* DMA2 Stream 1                               */
		DMA2_Stream2_IRQn		= 58,        /* DMA2 Stream 2                               */
		DMA2_Stream3_IRQn		= 59,        /* DMA2 Stream 3                               */
		DMA2_Stream4_IRQn		= 60,        /* DMA2 Stream 4                               */
		OTG_FS_IRQn				= 67,        /* USB OTG FS                                  */
		DMA2_Stream5_IRQn		= 68,        /* DMA2 Stream 5                               */
		DMA2_Stream6_IRQn		= 69,        /* DMA2 Stream 6                               */
		DMA2_Stream7_IRQn		= 70,        /* DMA2 Stream 7                               */
		USART6_IRQn				= 71,        /* USART6                                      */
		I2C3_EV_IRQn			= 72,        /* I2C3 event                                  */
		I2C3_ER_IRQn			= 73,        /* I2C3 error                                  */
		FPU_IRQn				= 81,        /* FPU                                         */
		SPI4_IRQn				= 84,        /* SPI4                                        */


}NVIC_IRQ;
typedef struct
{
	volatile uint32_t  ISER[8U];
	uint32_t Reserved1[24U];
	volatile uint32_t  ICER[8U];
	uint32_t Reserved2[24U];
	volatile uint32_t  ISPR[8U];
	uint32_t Reserved3[24U];
	volatile uint32_t  ICPR[8U];
	uint32_t Reserved4[24U];
	volatile uint32_t  IABR[8U];
	uint32_t Reserved5[56U];
	volatile uint8_t  IPR[60U];
	uint32_t Reserved6[644U];
	volatile uint32_t  STIR;
}NVIC_TYPE;



/*--------------------------Software interface declaration Start----------------------- */
/*********************************************************************************************
 * \brief :      Enable interrupt                                                            *
 * \details :    Enables a device specific interrupt in the NVIC interrupt controller        *
 * \param [in] : IRQn device specific interrupt number
 * \note : IRQn must not be negative                                          *
 *********************************************************************************************/
void NVIC_EnableIRQ(NVIC_IRQ IRQn);

/*********************************************************************************************
 * \brief :      Disable interrupt                                                           *
 * \details :    Disables a device specific interrupt in the NVIC interrupt controller       *
 * \param [in] : IRQn device specific interrupt number
 * \note : IRQn must not be negative                                     *
 *********************************************************************************************/
void NVIC_DisableIRQ(NVIC_IRQ IRQn);

/*********************************************************************************************
 * \brief :      Set Pending interrupt                                                       *
 * \details :    Set Pending bit of a specific interrupt in the NVIC interrupt controller    *
 * \param [in] : IRQn device specific interrupt number
 * \note : IRQn must not be negative                                          *
 *********************************************************************************************/
void NVIC_SetPendingIRQ(NVIC_IRQ IRQn);

/*********************************************************************************************
 * \brief :      Clear pending interrupt                                                     *
 * \details :    Clear Pending bit of a specific interrupt in the NVIC interrupt controller  *
 * \param [in] : IRQn device specific interrupt number
 * \note : IRQn must not be negative                                          *
 *********************************************************************************************/
void NVIC_ClearPendingIRQ(NVIC_IRQ IRQn);

/*********************************************************************************************
 * \brief      : Get active interrupt                                                        *
 * \details    : return active status of IRQn in the NVIC interrupt controller               *
 * \return     : 0 -> interrupt status is not active                                         *
 * \return     : 1 -> interrupt status is active                                             *
 * \param [in] : IRQn device specific interrupt number
 * \note : IRQn must not be negative                                          *
 *********************************************************************************************/
uint8_t NVIC_GetActiveIRQ(NVIC_IRQ IRQn);

/*********************************************************************************************
 * \brief      : Set Priority of an interrupt                                                *
 * \details    : Set priority of an interrupt                                        	     *
 * \param [in] : IRQn device specific interrupt number                                       *
 * \param [in] : priority of interrupt
 * \note : IRQn must not be negative   			                                         *
 *********************************************************************************************/
void NVIC_SetPriorityIRQ(NVIC_IRQ IRQn, uint32_t priority);

/*********************************************************************************************
 * \brief      : Get Priority of an interrupt                                                *
 * \details    : reads the priority of an interrupt                                          *
 * \return     : priority {3,4,5,6,7}														 *
 * \param [in] : IRQn device specific interrupt number                                       *
 *********************************************************************************************/
uint8_t NVIC_GetPriorityIRQ(NVIC_IRQ IRQn);

#endif /* CORTEXM4_CORE_NVIC_H_ */
