/**
 ******************************************************************************
 * @file           : CortexM4_Core_SCB.h
 * @author         : Ahmed Fathy
 * @brief          :  System control block

 ******************************************************************************
 */

#ifndef CORTEXM4_CORE_SCB_H_
#define CORTEXM4_CORE_SCB_H_
/*--------------------------Includes Start----------------------- */
#include "Shared STDTYPES/STD_TYPES.h"
/*--------------------------Macro declarations Start----------------------- */
#define  VECTKEY                     0x05FA                      /* The key to write on Application interrupt and reset control register  */
#define  SCB_BASE_ADDRESS         (0xE000ED00UL)                 /*System control block base address */
#define  SCB                      ((SCB_TYPE *)(SCB_BASE_ADDRESS))

#define  Group4_SUB0                  0x00000003U                      /*  Group priorities bits 4    Sub priorities bits 0 */
#define  Group3_SUB1                  0x00000004U                      /*  Group priorities bits 3    Sub priorities bits 1 */
#define  Group2_SUB2                  0x00000005U                      /*  Group priorities bits 2    Sub priorities bits 2 */
#define  Group1_SUB3                  0x00000006U                      /*  Group priorities bits 1    Sub priorities bits 3 */
#define  Group0_SUB4                  0x00000007U                      /*  Group priorities bits 0    Sub priorities bits 4 */

#define  SCB_AIRCR_GROUP_PRI_POS          8U                  /*  Set group priority position       */
#define  SCB_AIRCR_GROUP_PRI_MASK         (7UL  <<  SCB_AIRCR_GROUP_PRI_POS)


#define  SCB_AIRCR_VECTORKEY_POS           16U                  /*  Set VECTORKEY_POS      */
#define  SCB_AIRCR_VECTORKEY_MASK          (0xFFFF  << SCB_AIRCR_VECTORKEY_POS )   /*  */
/*--------------------------Macro Functions Start----------------------- */


/*--------------------------Data type declaration Start----------------------- */

typedef struct {
	volatile uint32_t CPUID;   /*     offset :0x00 (R/)  CPUID Base Register*/
	volatile uint32_t ICSR;    /*     offset :0x04 (R/W)   Interrupt Control and State Register*/
	volatile uint32_t VTOR;    /*     offset :0x08 (R/W)   IVector Table Offset Register*/
	volatile uint32_t AIRCR;    /*     offset :0x0c (R/W)   Application Interrupt and Reset Control Register*/
	volatile uint32_t SCR;    /*     offset :0x10 (R/W)  System Control Register*/
	volatile uint32_t CCR;    /*     offset :0x14 (R/W)   Configuration and Control Register*/
	volatile uint32_t SHPR1;    /*     offset :0x18 (R/W)   System Handler Priority Register 1*/
	volatile uint32_t SHPR2;    /*     offset :0x1c (R/W)   System Handler Priority Register 2*/
	volatile uint32_t SHPR3;    /*     offset :0x20 (R/W)   System Handler Priority Register 3*/
	volatile uint32_t SHCRS;    /*     offset :0x24 (R/W)    System Handler Control and State Register*/
	volatile uint32_t CFSR;    /*     offset :0x28 (R/W)    Configurable Fault Status Register*/
	volatile uint32_t MMSRb;    /*     offset :0x2c (R/W)   MemManage Fault Status Register*/
	volatile uint32_t BFSRb;    /*     offset :0x30 (R/W)   BusFault Status Register*/
	volatile uint32_t UFSRb;    /*     offset :0x34 (R/W)   UsageFault Status Register*/
	volatile uint32_t HFSR;    /*     offset :0x38 (R/W)   HardFault Status Register*/
	volatile uint32_t MMAR;    /*     offset :0x3c (R/W)   MemManage Fault Address Register*/
	volatile uint32_t BFAR;    /*     offset :0x40 (R/W)    BusFault Address Register*/
	volatile uint32_t AFSR;    /*     offset :0x44 (R/W)   Auxiliary Fault Status Register*/

}SCB_TYPE;

/*--------------------------Software interface declaration Start----------------------- */
void SCB_SetPriorityGroup(uint32_t PrirityGroup );
/**
 * \brief 	Get PriorityGroup
 * \details Reads the priority grouping filed from NVIC interrupt controller.
 * \return  priority grouping field (SCB->AIRCR [10 : 8])
 */
uint32_t SCB_getPriorityGroup(void);
#endif /* CORTEXM4_CORE_SCB_H_ */
