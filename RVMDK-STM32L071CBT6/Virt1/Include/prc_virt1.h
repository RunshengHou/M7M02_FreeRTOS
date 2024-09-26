/******************************************************************************
Filename    : prc_virt1.h
Author      : The RVM project generator.
Date        : 26/09/2024 10:23:18
License     : Unlicense; see COPYING for details.
Description : The user kernel object header.
******************************************************************************/

/* Define ********************************************************************/
#ifndef __PRC_VIRT1__
#define __PRC_VIRT1__

/* Process capability table frontier & size */
#define CPT_SIZE                                        (5U)
#define CPT_FRONT                                       (5U)

/* Ports */

/* Receive endpoints */

/* Send endpoints */
#define SND_RECV1_PRC_PROC1                             (2U)
#define SND_RECV1_PRC_PROC2                             (3U)

/* Vector endpoints */

/* Kernel functions */
#define KFN_INT_LOCAL_MOD                               (4U)

/* Code memory blocks */
#define CODE_CODE1_BASE                                 (0x8018000U)
#define CODE_CODE1_SIZE                                 (0x8000U)

/* Data memory blocks */
#define DATA_DATA1_BASE                                 (0x20003000U)
#define DATA_DATA1_SIZE                                 (0x1000U)
#define DATA_SHARED_SHARED1_BASE                        (0x20004800U)
#define DATA_SHARED_SHARED1_SIZE                        (0x100U)

/* Device memory blocks */
#define DEVICE_SHARED_DEVICE1_BASE                      (0x40000000U)
#define DEVICE_SHARED_DEVICE1_SIZE                      (0x20000000U)

/* Total priority number */
#define RVM_PREEMPT_PRIO_NUM                            (32U)
/* Total VM priority number */
#define RVM_PREEMPT_VPRIO_NUM                           (32U)
/* The kernel memory allocation granularity order */
#define RVM_KOM_SLOT_ORDER                              (4U)

/* Virtual machine library enable */
#define RVM_VIRT_LIB_ENABLE                             (1U)
/* Virtual vector total number */
#define RVM_VIRT_VCT_NUM                                (4U)
/* State block base address & size */
#define RVM_VIRT_STATE_BASE                             (0x20003BC0U)
#define RVM_VIRT_STATE_SIZE                             (0x40U)
/* Virtual register base address & size */
#define RVM_VIRT_REG_BASE                               (0x20003B90U)
#define RVM_VIRT_REG_SIZE                               (0x30U)

/* Debugging settings */
#define RVM_ASSERT_ENABLE                               (1U)
#define RVM_DBGLOG_ENABLE                               (1U)

/* Coprocessor options */
#define RVM_COP_NUM                                     (0U)
#endif /* __PRC_VIRT1__ */
/* End Define ****************************************************************/

/* End Of File ***************************************************************/

/* Copyright (C) Evo-Devo Instrum. All rights reserved ***********************/


