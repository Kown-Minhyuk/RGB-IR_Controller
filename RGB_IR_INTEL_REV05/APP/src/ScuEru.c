/*
 * ScuEru.c
 *
 *  Created on: 2019. 9. 2.
 *      Author: junseok.lee
 */
/**
 * \file ScuEruDemo.c
 * \brief Demo ScuEruDemo
 *
 * \version iLLD_Demos_1_0_1_5_0
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
#include "APP/inc/ScuEru.h"
#include "Src/Std/IfxSrc.h"
#include "Spisoc.h"
#include "Standby_mode.h"


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

App_ScuEru g_ScuEru; /**< \brief Demo information */
Ifx_SCU *scu = &MODULE_SCU;


/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Demo_ScuEru_SrcDoc_Main_Interrupt
 * \{ */

/** \name Interrupts for input state change
 * \{ */

IFX_INTERRUPT(ISR_ScuEru, 0, ISR_PRIORITY_SCUERU_0);
IFX_INTERRUPT(ISR_EVENT_REC_INT, 0, ISR_PRIORITY_AX_SENS);
IFX_INTERRUPT(ISR_Ignition_Detection, 0, ISR_PRIORITY_IGN_OFF);
IFX_INTERRUPT(ISR_Battery_out, 0, ISR_PRIORITY_BAT_OUT);

/** \} */

/** \} */

/** \brief Handle Timer interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_SCUERU_0
 * \isrPriority \ref ISR_PRIORITY_SCUERU_0
 *
 */

void ISR_Ignition_Detection(void)
{
    IfxCpu_enableInterrupts();
//
//    /* EMG 모드 구현 필요 */
//    ready_to_standby();

//    if( EMG_Mode_Flag != 1 )
//    {
//    	ready_to_sleep();
//    }

}

void ISR_ScuEru(void)
{
    IfxCpu_enableInterrupts();


}

void ISR_EVENT_REC_INT(void)
{
    IfxCpu_enableInterrupts();

    soc_spi_union.byte = g_spi_msg.spi_data_tx[6];
    soc_spi_union.data4.Impact_rec = 1;

    g_spi_msg.spi_data_tx[6] = soc_spi_union.byte;


}

void ISR_Battery_out(void)
{
    IfxCpu_enableInterrupts();

#if defined(USE_LIN)
	    					sub_batt_status = Sub_Batt_Control(SUB_BATT_STANDBY);
#endif

    soc_spi_union.byte = g_spi_msg.spi_data_tx[6];
    soc_spi_union.data4.Veh_bat_out = 1;

    g_spi_msg.spi_data_tx[6] = soc_spi_union.byte;




}


/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void ScuEru_init(void)
{
    /* disable interrupts */
    boolean        interruptState = IfxCpu_disableInterrupts();

    /* select external request pin */
    IfxScu_Req_In *reqPin = &IfxScu_REQ6_P02_0_IN;
    IfxScu_Req_In *reqPin3 = &IfxScu_REQ13_P15_5_IN;
    IfxScu_Req_In *reqPin2 = &IfxScu_REQ14_P02_1_IN;

    /* initialize this pin with pull-up enabled */
    /* this function will also configure the input multiplexers of the ERU (EICRm.EXISx) */
    IfxScuEru_initReqPin(reqPin, IfxPort_InputMode_noPullDevice);
    IfxScuEru_initReqPin(reqPin3, IfxPort_InputMode_noPullDevice);
    IfxScuEru_initReqPin(reqPin2, IfxPort_InputMode_noPullDevice);

    /* ESR1 pin select */
    scu->EICR[3].B.EXIS1 = 1;

    IfxScuEru_InputChannel inputChannel;
    IfxScuEru_InputNodePointer triggerSelect;
    IfxScuEru_OutputChannel    outputChannel;

    /*---------------------------------------------------------------------------------------------------- 	*/
        /* ECR1 PIN, IGN Off Interrupt																						*/
        /*----------------------------------------------------------------------------------------------------	*/

        /* determine input channel EICRm depending on input pin */
        //inputChannel = (IfxScuEru_InputChannel)reqPin->channelId;
        inputChannel = 7;

        /* signal destination */
        triggerSelect = IfxScuEru_InputNodePointer_1;                           /* TRx0 */
        outputChannel = IfxScuEru_OutputChannel_1;                              /* OGU channel 0 */

        /* input channel configuration */
    //    IfxScuEru_disableFallingEdgeDetection(inputChannel);                                               /* EICRm.FENn */
    //    IfxScuEru_enableRisingEdgeDetection(inputChannel);                                                 /* EICRm.RENn */
        IfxScuEru_enableFallingEdgeDetection(inputChannel);                                               /* EICRm.FENn */
        IfxScuEru_disableRisingEdgeDetection(inputChannel);                                                 /* EICRm.RENn */

        //IfxScuEru_enableAutoClear(inputChannel);                                                           /* EICRm.LDENn */
        IfxScuEru_disableAutoClear(inputChannel);                                                           /* EICRm.LDENn */

        /* Connecting Matrix, Event Trigger Logic ETL block */
        IfxScuEru_enableTriggerPulse(inputChannel);                                                        /* EICRm.EIENn */
        IfxScuEru_connectTrigger(inputChannel, triggerSelect);                                             /* EICRm.INPn */

        /* output channels, OutputGating Unit OGU block */
        IfxScuEru_setFlagPatternDetection(outputChannel, inputChannel, TRUE);                              /* IGCRm.IPENn */
        IfxScuEru_enablePatternDetectionTrigger(outputChannel);                                            /* IGCRm.GEENn */
        IfxScuEru_setInterruptGatingPattern(outputChannel, IfxScuEru_InterruptGatingPattern_alwaysActive); /* IGCEm.IGPn */

        /* service request configuration */
        {
            volatile Ifx_SRC_SRCR *src2 = &MODULE_SRC.SCU.SCU.ERU[(int)outputChannel % 4];
            IfxSrc_init(src2, IfxSrc_Tos_cpu0, ISR_PRIORITY_IGN_OFF);
            IfxSrc_enable(src2);
        }



    /*---------------------------------------------------------------------------------------------------- 	*/
    /* P2.0 PIN, I2C Clock Interrupt																						*/
    /*----------------------------------------------------------------------------------------------------	*/

    /* determine input channel EICRm depending on input pin */
    inputChannel = (IfxScuEru_InputChannel)reqPin->channelId;

    /* signal destination */
    triggerSelect = IfxScuEru_InputNodePointer_0;                           /* TRx0 */
    outputChannel = IfxScuEru_OutputChannel_0;                              /* OGU channel 0 */

    /* input channel configuration */
    IfxScuEru_enableFallingEdgeDetection(inputChannel);                                               /* EICRm.FENn */
    IfxScuEru_disableRisingEdgeDetection(inputChannel);                                                 /* EICRm.RENn */
    //IfxScuEru_enableAutoClear(inputChannel);                                                           /* EICRm.LDENn */
    IfxScuEru_disableAutoClear(inputChannel);                                                           /* EICRm.LDENn */

    /* Connecting Matrix, Event Trigger Logic ETL block */
    IfxScuEru_enableTriggerPulse(inputChannel);                                                        /* EICRm.EIENn */
    IfxScuEru_connectTrigger(inputChannel, triggerSelect);                                             /* EICRm.INPn */

    /* output channels, OutputGating Unit OGU block */
    IfxScuEru_setFlagPatternDetection(outputChannel, inputChannel, TRUE);                              /* IGCRm.IPENn */
    IfxScuEru_enablePatternDetectionTrigger(outputChannel);                                            /* IGCRm.GEENn */
    IfxScuEru_setInterruptGatingPattern(outputChannel, IfxScuEru_InterruptGatingPattern_alwaysActive); /* IGCEm.IGPn */

    /* service request configuration */
    {
        volatile Ifx_SRC_SRCR *src = &MODULE_SRC.SCU.SCU.ERU[(int)outputChannel % 4];
        IfxSrc_init(src, IfxSrc_Tos_cpu0, ISR_PRIORITY_SCUERU_0);
        IfxSrc_enable(src);
    }


    /*---------------------------------------------------------------------------------------------------- 	*/
        /* P15.5 PIN, Ax Sensor Interrupt																								*/
        /*----------------------------------------------------------------------------------------------------	*/

        /* determine input channel EICRm depending on input pin */
        inputChannel = (IfxScuEru_InputChannel)reqPin3->channelId;

        //IfxScuEru_selectExternalInput(inputChannel,3);

        /* signal destination */
        triggerSelect = IfxScuEru_InputNodePointer_2;                           /* TRx0 */
        outputChannel = IfxScuEru_OutputChannel_2;                              /* OGU channel 0 */

        /* input channel configuration */
    //    IfxScuEru_disableFallingEdgeDetection(inputChannel);                                               /* EICRm.FENn */
    //    IfxScuEru_enableRisingEdgeDetection(inputChannel);                                                 /* EICRm.RENn */
        IfxScuEru_enableFallingEdgeDetection(inputChannel);                                               /* EICRm.FENn */
        IfxScuEru_disableRisingEdgeDetection(inputChannel);                                                 /* EICRm.RENn */

        //IfxScuEru_enableAutoClear(inputChannel);                                                           /* EICRm.LDENn */
        IfxScuEru_disableAutoClear(inputChannel);                                                           /* EICRm.LDENn */

        /* Connecting Matrix, Event Trigger Logic ETL block */
        IfxScuEru_enableTriggerPulse(inputChannel);                                                        /* EICRm.EIENn */
        IfxScuEru_connectTrigger(inputChannel, triggerSelect);                                             /* EICRm.INPn */

        /* output channels, OutputGating Unit OGU block */
        IfxScuEru_setFlagPatternDetection(outputChannel, inputChannel, TRUE);                              /* IGCRm.IPENn */
        IfxScuEru_enablePatternDetectionTrigger(outputChannel);                                            /* IGCRm.GEENn */
        IfxScuEru_setInterruptGatingPattern(outputChannel, IfxScuEru_InterruptGatingPattern_alwaysActive); /* IGCEm.IGPn */

        /* service request configuration */
        {
            volatile Ifx_SRC_SRCR *src4 = &MODULE_SRC.SCU.SCU.ERU[(int)outputChannel % 4];
            IfxSrc_init(src4, IfxSrc_Tos_cpu0, ISR_PRIORITY_AX_SENS);
            IfxSrc_enable(src4);
        }


        /*---------------------------------------------------------------------------------------------------- 	*/
            /* P2.1 PIN, BAT Out Interrupt																								*/
            /*----------------------------------------------------------------------------------------------------	*/

            /* determine input channel EICRm depending on input pin */
            inputChannel = (IfxScuEru_InputChannel)reqPin2->channelId;

            /* signal destination */
            triggerSelect = IfxScuEru_InputNodePointer_3;                           /* TRx0 */
            outputChannel = IfxScuEru_OutputChannel_3;                              /* OGU channel 0 */

            /* input channel configuration */
        //    IfxScuEru_disableFallingEdgeDetection(inputChannel);                                               /* EICRm.FENn */
        //    IfxScuEru_enableRisingEdgeDetection(inputChannel);                                                 /* EICRm.RENn */
            IfxScuEru_enableFallingEdgeDetection(inputChannel);                                               /* EICRm.FENn */
            IfxScuEru_disableRisingEdgeDetection(inputChannel);                                                 /* EICRm.RENn */

            //IfxScuEru_enableAutoClear(inputChannel);                                                           /* EICRm.LDENn */
            IfxScuEru_disableAutoClear(inputChannel);                                                           /* EICRm.LDENn */

            /* Connecting Matrix, Event Trigger Logic ETL block */
            IfxScuEru_enableTriggerPulse(inputChannel);                                                        /* EICRm.EIENn */
            IfxScuEru_connectTrigger(inputChannel, triggerSelect);                                             /* EICRm.INPn */

            /* output channels, OutputGating Unit OGU block */
            IfxScuEru_setFlagPatternDetection(outputChannel, inputChannel, TRUE);                              /* IGCRm.IPENn */
            IfxScuEru_enablePatternDetectionTrigger(outputChannel);                                            /* IGCRm.GEENn */
            IfxScuEru_setInterruptGatingPattern(outputChannel, IfxScuEru_InterruptGatingPattern_alwaysActive); /* IGCEm.IGPn */

            /* service request configuration */
            {
                volatile Ifx_SRC_SRCR *src3 = &MODULE_SRC.SCU.SCU.ERU[(int)outputChannel % 4];
                IfxSrc_init(src3, IfxSrc_Tos_cpu0, ISR_PRIORITY_BAT_OUT);
                IfxSrc_enable(src3);
            }




    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);

}



