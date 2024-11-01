/******************************************************************************
Filename    : portmacro.h
Author      : rsh
Date        : 14/07/2024
Licence     : The Unlicense; see LICENSE for details.
Description : The ARMv7-M FreeRTOS guest OS support header. This supports all
              compilers that the RVM supports.
              This file is NOT a part of the FreeRTOS distribution!
******************************************************************************/
#ifndef PORTMACRO_H
#define PORTMACRO_H

/* Include *******************************************************************/
#include "rvm_guest.h"
/* End Include ***************************************************************/

/* Define ********************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#define portCHAR		                        char
#define portFLOAT		                        float
#define portDOUBLE		                        double
#define portLONG		                        long
#define portSHORT		                        short
#define portSTACK_TYPE	                        uint32_t
#define portBASE_TYPE	                        long

typedef portSTACK_TYPE                          StackType_t;
typedef long                                    BaseType_t;
typedef unsigned long                           UBaseType_t;

#if(configUSE_16_BIT_TICKS==1)
typedef uint16_t                                TickType_t;
#define portMAX_DELAY                           0xFFFFU
#else
typedef uint32_t                                TickType_t;
#define portMAX_DELAY                           0xFFFFFFFFUL
#define portTICK_TYPE_IS_ATOMIC                 1
#endif

#define portSTACK_GROWTH			            (-1)
#define portTICK_PERIOD_MS			            ((TickType_t)1000/configTICK_RATE_HZ)
#define portBYTE_ALIGNMENT			            8

//#define portYIELD()                             RVM_Virt_Yield()
RVM_EXTERN void _FreeRTOS_A7M_RVM_Yield(void);
#define portYIELD()                             RVM_Virt_Yield()
#define portEND_SWITCHING_ISR(xSwitchRequired) \
do \
{ \
    if(xSwitchRequired!=pdFALSE ) \
        RVM_Virt_Yield(); \
} \
while(0)
#define portYIELD_FROM_ISR(x)                   portEND_SWITCHING_ISR(x)

extern void vPortEnterCritical( void );
extern void vPortExitCritical( void );
#define portSET_INTERRUPT_MASK_FROM_ISR()		ulPortRaiseBASEPRI()
#define portCLEAR_INTERRUPT_MASK_FROM_ISR(x)	vPortSetBASEPRI(x)
#define portDISABLE_INTERRUPTS()				RVM_Virt_Int_Mask()
#define portENABLE_INTERRUPTS()					RVM_Virt_Int_Unmask()
#define portENTER_CRITICAL()					vPortEnterCritical()
#define portEXIT_CRITICAL()						vPortExitCritical()


#define portTASK_FUNCTION_PROTO(vFunction,pvParameters) \
                                                void vFunction(void *pvParameters)
#define portTASK_FUNCTION(vFunction,pvParameters) \
                                                void vFunction(void *pvParameters)

#ifndef portSUPPRESS_TICKS_AND_SLEEP
extern void vPortSuppressTicksAndSleep(TickType_t xExpectedIdleTime);
#define portSUPPRESS_TICKS_AND_SLEEP(xExpectedIdleTime) \
                                                vPortSuppressTicksAndSleep(xExpectedIdleTime)
#endif

#ifndef configUSE_PORT_OPTIMISED_TASK_SELECTION
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 0
#endif

#if configUSE_PORT_OPTIMISED_TASK_SELECTION == 1

/* Generic helper function. */
__attribute__( ( always_inline ) ) static inline uint8_t ucPortCountLeadingZeros( uint32_t ulBitmap )
{
uint8_t ucReturn;

    __asm volatile ( "clz %0, %1" : "=r" ( ucReturn ) : "r" ( ulBitmap ) );
    return ucReturn;
}

/* Check the configuration. */
#if( configMAX_PRIORITIES > 32 )
#error configUSE_PORT_OPTIMISED_TASK_SELECTION can only be set to 1 when configMAX_PRIORITIES is less than or equal to 32.  It is very rare that a system requires more than 10 to 15 difference priorities as tasks that share a priority will time slice.
#endif

/* Store/clear the ready priorities in a bit map. */
#define portRECORD_READY_PRIORITY( uxPriority, uxReadyPriorities ) ( uxReadyPriorities ) |= ( 1UL << ( uxPriority ) )
#define portRESET_READY_PRIORITY( uxPriority, uxReadyPriorities ) ( uxReadyPriorities ) &= ~( 1UL << ( uxPriority ) )

#define portGET_HIGHEST_PRIORITY( uxTopPriority, uxReadyPriorities ) uxTopPriority = ( 31UL - ( uint32_t ) ucPortCountLeadingZeros( ( uxReadyPriorities ) ) )

#endif /* configUSE_PORT_OPTIMISED_TASK_SELECTION */

#ifdef configASSERT
void vPortValidateInterruptPriority( void );
#define portASSERT_IF_INTERRUPT_PRIORITY_INVALID() 	vPortValidateInterruptPriority()
#endif

#define portNOP()
#define portINLINE	/* __inline */

#ifndef portFORCE_INLINE
#define portFORCE_INLINE /* inline __attribute__(( always_inline)) */
#endif

portFORCE_INLINE static BaseType_t xPortIsInsideInterrupt( void )
{
	if(RVM_STATE->Vct_Act==0U)
		return pdFALSE;

	return pdTRUE;
}

portFORCE_INLINE static void vPortRaiseBASEPRI( void )
{
    
}

portFORCE_INLINE static uint32_t ulPortRaiseBASEPRI( void )
{
	return 0U;
}

portFORCE_INLINE static void vPortSetBASEPRI(uint32_t ulNewMaskValue)
{
    
}

#ifdef __cplusplus
}
#endif
/* End Define ****************************************************************/

/* End Of File ***************************************************************/
#endif /* PORTMACRO_H */
/* Copyright (C) Evo-Devo Instrum. All rights reserved ***********************/


