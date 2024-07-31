/**
 ******************************************************************************
 * @file           : CortexM4_Core_SCB.c
 * @author         : Ahmed Fathy
 * @brief          :  System control block

 ******************************************************************************
 */
#include "CortexM4/CortexM4_Core_SCB.h"
/**
 * \brief set priority grouping
 *
 */

void SCB_SetPriorityGroup(uint32_t PrirityGroup )
{
	uint32_t Register_Value = 0;

	Register_Value = SCB->AIRCR;

	Register_Value &=~((uint32_t)SCB_AIRCR_VECTORKEY_MASK | SCB_AIRCR_GROUP_PRI_MASK );


	Register_Value |= ((((uint32_t)VECTKEY) << SCB_AIRCR_VECTORKEY_POS)  | ( Group2_SUB2 << SCB_AIRCR_GROUP_PRI_POS ));

	SCB->AIRCR = Register_Value;


}

/**
 * \brief 	Get PriorityGroup
 * \details Reads the priority grouping filed from NVIC interrupt controller.
 * \return  priority grouping field (SCB->AIRCR [10 : 8])
 */
uint32_t SCB_getPriorityGroup(void){



	return  (((uint32_t)SCB->AIRCR & (uint32_t)SCB_AIRCR_GROUP_PRI_MASK )  >> SCB_AIRCR_GROUP_PRI_POS);
}
