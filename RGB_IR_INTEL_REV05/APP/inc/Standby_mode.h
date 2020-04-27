/**
 * \file StmDemo.h
 * \brief Demo Template
 * \version iLLD_Demos_1_0_0_11_0
 * \copyright Copyright (c) 2014 Infineon Technologies AG. All rights reserved.
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup IfxLld_Demo_StmDemo_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_StmDemo_SrcDoc
 * \defgroup IfxLld_Demo_StmDemo_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_StmDemo_SrcDoc_Main
 */

#ifndef STMDEMO_H
#define STMDEMO_H 1
/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "swplatform.h"
#include "Cpu/Std/Ifx_Types.h"
#include "SysSe/Bsp/Bsp.h"

//#include <Ifx_Types.h>
#include <stdio.h>

#include "ConfigurationIsr.h"
#include "Cpu/Irq/IfxCpu_Irq.h"
//#include "IfxPort.h"
//#include "Cpu0_Main.h"
#include "Cpu/Irq/IfxCpu_Irq.h"
//#include "IfxScuWdt.h"
#include "IfxScu_reg.h"
#include "IfxStm_reg.h"
#include "IfxPort_reg.h"
#include "IfxSrc_reg.h"
#include "IfxDma_reg.h"
//#include "Bsp.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/
/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
extern void set_Standby_mode(void);
extern void ready_to_standby(void);
IFX_EXTERN void DisableModules(void);
IFX_EXTERN void ClearInterruptFlags(void);
IFX_EXTERN void Pin_Tristate(void);
IFX_EXTERN void Standby_Wakup_Timer(void);
IFX_EXTERN void ClearWakeupFlage(uint32 Wakeup_Bit);
IFX_EXTERN void Mcu_SetStandbyCtrlReg(uint32 PMSWCR0_RegVal);

#endif
