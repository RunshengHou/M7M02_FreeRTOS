/******************************************************************************
Filename    : Filename
Author      : The RVM project generator.
Date        : 05/09/2024 21:43:07
License     : Unlicense; see COPYING for details.
Description : The top-half handler file for vector Tim4.
******************************************************************************/

/* Include *******************************************************************/
#define __HDR_DEF__
#include "Platform/A7M/rme_platform_a7m.h"
#include "Kernel/rme_kernel.h"
#undef __HDR_DEF__

#define __HDR_STRUCT__
#include "Platform/A7M/rme_platform_a7m.h"
#include "Kernel/rme_kernel.h"
#undef __HDR_STRUCT__

#define __HDR_PUBLIC__
#include "Platform/A7M/rme_platform_a7m.h"
#include "Kernel/rme_kernel.h"
#undef __HDR_PUBLIC__

#include "rme_boot.h"
/* End Include ***************************************************************/

/* Public Function ***********************************************************/
rme_ptr_t RME_Vct_Tim4_Handler(struct RME_Reg_Struct* Reg);
/* End Public Function *******************************************************/

/* Begin Function:RME_Vct_Tim4_Handler ****************************************
Description : The user top-half interrupt handler for vector.
Input       : struct RME_Reg_Struct* Reg - The register set.
Output      : None.
Return      : rme_ptr_t - Decides what endpoints to send to (see manual).
******************************************************************************/
rme_ptr_t RME_Vct_Tim4_Handler(struct RME_Reg_Struct* Reg)
{
#define RME_TEST_TIM4_HANDLER
#include "rme_test.h"
#undef RME_TEST_TIM4_HANDLER
}
/* End Function:RME_Vct_Tim4_Handler *****************************************/

/* End Of File ***************************************************************/

/* Copyright (C) Evo-Devo Instrum. All rights reserved ***********************/

