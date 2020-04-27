/**
 * \file AsclinLinDemo.c
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include <stdio.h>
#include "AsclinLinDemo.h"
#include "util.h"

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


App_AsclinLin g_AsclinLin; /**< \brief Demo information */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/





/** \addtogroup IfxLld_Demo_AsclinLin_SrcDoc_Main_Interrupt
 * \{ */

/** \} */

/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void AsclinLinDemo_init(void)
{
    /* disable interrupts */
    boolean              interruptState = IfxCpu_disableInterrupts();

    /* create module config */
    IfxAsclin_Lin_Config linConfig;
    IfxAsclin_Lin_initModuleConfig(&linConfig, &MODULE_ASCLIN1);

    /* set the desired baudrate */
#ifdef SIMULATION
    linConfig.brg.baudrate     = 1000000;
#else
    linConfig.brg.baudrate     = 19200;      /* FDR values will be calculated in initModule */
#endif
    linConfig.btc.oversampling = IfxAsclin_OversamplingFactor_4;

    /* pin configuration */
    const IfxAsclin_Lin_Pins pins = {
        &IfxAsclin1_RXG_P02_3_IN, IfxPort_InputMode_pullUp,      /* Rx pin */
        &IfxAsclin1_TX_P02_2_OUT, IfxPort_OutputMode_pushPull,   /* Tx pin */
        IfxPort_PadDriver_cmosAutomotiveSpeed1
    };
    linConfig.pins = &pins;
    linConfig.clockSource = IfxAsclin_ClockSource_oscillatorClock;




    linConfig.bsc.medianFilter = IfxAsclin_SamplesPerBit_three;
    linConfig.bsc.samplePointPosition = IfxAsclin_SamplePointPosition_8;
    linConfig.btc.oversampling = IfxAsclin_OversamplingFactor_16;






    /* initialize module */
    IfxAsclin_Lin_initModule(&g_AsclinLin.drivers.lin, &linConfig);

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);



}


//void Lin_send_Header_receive_Response(IfxAsclin_Lin *asclin, uint8 *id, uint8 *rxdata, uint32 length){
//	Ifx_ASCLIN *asclinSFR = asclin->asclin;            /* getting the pointer to ASCLIN registers from module handler*/
//	IfxAsclin_clearAllFlags(asclinSFR);                /* clearing all flags*/
//	if (asclin->receiveIdEnable)                       /* if receiving the sent id byte into its own Rx FIFO is selected*/
//	{
//		IfxAsclin_flushRxFifo(asclinSFR);              /* flushing Rx FIFO*/
//		IfxAsclin_enableRxFifoInlet(asclinSFR, TRUE);  /* enabling Rx FIFO */
//	}
//	else
//	{
//		IfxAsclin_flushRxFifo(asclinSFR);              /* flushing Rx FIFO */
//		IfxAsclin_enableRxFifoInlet(asclinSFR, FALSE); /* disabling Rx FIFO */
//	}
//	IfxAsclin_flushTxFifo(asclinSFR);                  /* flushing Tx FIFO */
//	IfxAsclin_enableTxFifoOutlet(asclinSFR, TRUE);     /* enabling Tx FIFO for transmitting*/
//	IfxAsclin_write8(asclinSFR, id, 1U);               /* writing the ID byte */
//	IfxAsclin_setTransmitHeaderRequestFlag(asclinSFR); /* setting THRQS flag */
//	IfxAsclin_Lin_waitForTransmittedHeader(asclin);    /* waiting until transmit header end acknowledgemnet */
//	IfxAsclin_setDataLength(asclinSFR, length - 1);   /* set number of bytes to be received*/
//	IfxAsclin_enableTxFifoOutlet(asclinSFR, FALSE);   /* enable Tx FIFO for transmitting */
//	IfxAsclin_enableRxFifoInlet(asclinSFR, TRUE);     /* enable Rx FIFO for receiving */
//	IfxAsclin_Lin_waitForReceivedResponse(asclin);    /* wait until receive response end acknowledgemnet or an error is occured*/
//	IfxAsclin_read8(asclinSFR, rxdata, length);         /* read the data bytes; */
//}


