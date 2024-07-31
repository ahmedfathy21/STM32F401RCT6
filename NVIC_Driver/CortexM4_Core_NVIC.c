/**
 ******************************************************************************
 * @file           : CortexM4_Core_NVIC.c
 * @author         : Ahmed Fathy
 * @brief          :

 ******************************************************************************
 */
#include "CortexM4/CortexM4_Core_NVIC.h"
/*********************************************************************************************
 * \brief :      Enable interrupt                                                            *
 * \details :    Enables a device specific interrupt in the NVIC interrupt controller        *
 * \param [in] : IRQn device specific interrupt number
 * \note : IRQn must not be negative                                 *
 *********************************************************************************************/
void NVIC_EnableIRQ(NVIC_IRQ IRQn){
    if((uint32_t)IRQn >= 0 ){
    	NVIC->ISER[(uint32_t) IRQn >> 5 ] = (1UL	 << (((uint32_t)IRQn)& 0X1F));

    }
    else {
    	/* Nothing */
    }


}

/*********************************************************************************************
 * \brief :      Disable interrupt                                                           *
 * \details :    Disables a device specific interrupt in the NVIC interrupt controller       *
 * \param [in] : IRQn device specific interrupt number                                       *
 *********************************************************************************************/
void NVIC_DisableIRQ(NVIC_IRQ IRQn){
	if((uint32_t)IRQn >= 0 ){
	    	NVIC->ICER[(uint32_t) IRQn >> 5 ] = (1UL	 << (((uint32_t)IRQn)& 0X1F));

	    }
	    else {
	    	/* Nothing */
	    }


}

/*********************************************************************************************
 * \brief :      Set Pending interrupt                                                       *
 * \details :    Set Pending bit of a specific interrupt in the NVIC interrupt controller    *
 * \param [in] : IRQn device specific interrupt number                                       *
 *********************************************************************************************/
void NVIC_SetPendingIRQ(NVIC_IRQ IRQn){
	if((uint32_t)IRQn >= 0 ){
		    	NVIC->ISPR[(uint32_t) IRQn >> 5 ] = (1UL	 << (((uint32_t)IRQn)& 0X1F));

		    }
		    else {
		    	/* Nothing */
		    }


}

/*********************************************************************************************
 * \brief :      Clear pending interrupt                                                     *
 * \details :    Clear Pending bit of a specific interrupt in the NVIC interrupt controller  *
 * \param [in] : IRQn device specific interrupt number                                       *
 *********************************************************************************************/
void NVIC_ClearPendingIRQ(NVIC_IRQ IRQn){

	if((uint32_t)IRQn >= 0 ){
		    	NVIC->ICPR[(uint32_t) IRQn >> 5 ] = (1UL	 << (((uint32_t)IRQn)& 0X1F));

		    }
		    else {
		    	/* Nothing */
		    }

}

/*********************************************************************************************
 * \brief      : Get active interrupt                                                        *
 * \details    : return active status of IRQn in the NVIC interrupt controller               *
 * \return     : 0 -> interrupt status is not active                                         *
 * \return     : 1 -> interrupt status is active                                             *
 * \param [in] : IRQn device specific interrupt number                                       *
 *********************************************************************************************/
uint8_t NVIC_GetActiveIRQ(NVIC_IRQ IRQn){
	if((uint32_t)IRQn >= 0 ){
return 	((NVIC->IABR[((uint32_t) IRQn) >> 5 ] & (1UL	 << (((uint32_t)IRQn)& 0X1F)))  != ((uint32_t)0) ? 1UL : 0UL );
	}
	else {
		/*    Nothing     */
	}
}

/*********************************************************************************************
 * \brief      : Set Priority of an interrupt                                                *
 * \details    : Set priority of an interrupt                                        	     *
 * \param [in] : IRQn device specific interrupt number                                       *
 * \param [in] : priority of interrupt				                                         *
 *********************************************************************************************/
void NVIC_SetPriorityIRQ(NVIC_IRQ IRQn, uint32_t priority){
	if((uint32_t)IRQn >= 0 ){
			    	NVIC->IPR[((uint32_t)IRQn)] =  (uint8_t)((priority << 8U - NVIC_PRIORITY_BUTS)& (uint32_t)0xFF);

			    }
			    else {
			    	/* Nothing */
			    }


}

/*********************************************************************************************
 * \brief      : Get Priority of an interrupt                                                *
 * \details    : reads the priority of an interrupt                                          *
 * \return     : priority {3,4,5,6,7}														 *
 * \param [in] : IRQn device specific interrupt number                                       *
 *********************************************************************************************/
uint8_t NVIC_GetPriorityIRQ(NVIC_IRQ IRQn){
	if((uint32_t)IRQn >= 0 ){
		return ((NVIC->IPR[(uint32_t)IRQn]) >> (8U - NVIC_PRIORITY_BUTS));

			    }
			    else {
			    	/* Nothing */
			    }


}
