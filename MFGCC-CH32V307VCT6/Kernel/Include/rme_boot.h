/******************************************************************************
Filename    : rme_boot.h
Author      : The RVM project generator.
Date        : 30/07/2024 23:59:31
License     : Unlicense; see COPYING for details.
Description : The boot-time initialization file header.
******************************************************************************/

/* Define ********************************************************************/
/* Capability table maximum capacity */
#define RME_MAIN_CPT_SIZE                               (128U)
/* Boot-time capability table */
#define RME_BOOT_CPT_OBJ                                (RME_RV32P_CPT)

/* Vector endpoint capability tables */

/* Vector endpoints */

/* Receive endpoint capability tables - created by RVM later */
#define RME_BOOT_SIG_0                                  (15U)

/* Receive endpoints - created by RVM later */
#define RME_RCV_RECV1_PRC_PROC1                         (RME_CID(RME_BOOT_SIG_0,0U))
#define RME_RCV_RECV1_PRC_PROC2                         (RME_CID(RME_BOOT_SIG_0,1U))
/* End Define ****************************************************************/

/* End Of File ***************************************************************/

/* Copyright (C) Evo-Devo Instrum. All rights reserved ***********************/
