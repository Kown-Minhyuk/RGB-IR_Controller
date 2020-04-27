/**
 * \file AsclinLinDemo.h
 * \brief Demo AsclinLinDemo
 *
 * \version iLLD_Demos_1_0_1_10_0
 * \copyright Copyright (c) 2014 Infineon Technologies AG. All rights reserved.
 *
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
 * \defgroup IfxLld_Demo_AsclinLin_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_AsclinLin_SrcDoc
 * \defgroup IfxLld_Demo_AsclinLin_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_AsclinLin_SrcDoc_Main
 */

#ifndef ASCLINLINDEMO_H
#define ASCLINLINDEMO_H 1

//#define USE_LIN

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include <Cpu/std/Ifx_Types.h>
#include <Asclin/Lin/IfxAsclin_Lin.h>

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief Asc information */
typedef struct
{
    struct
    {
        IfxAsclin_Lin lin;                      /**< \brief ASC interface */
    }      drivers;

    uint8  txData[8];
    uint8  rxData[8];
    uint32 size;
} App_AsclinLin;


/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

IFX_EXTERN App_AsclinLin g_AsclinLin;


/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

IFX_EXTERN void AsclinLinDemo_init(void);
//extern void Lin_send_Header_receive_Response(IfxAsclin_Lin *asclin, uint8 *id, uint8 *rxdata, uint32 length);

#endif