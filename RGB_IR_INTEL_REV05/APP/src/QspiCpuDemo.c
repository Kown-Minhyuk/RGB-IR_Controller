/**
 * \file QspiCpuDemo.c
 * \brief Qspi Master & Slave Demo (using cpu)
 *
 * \version iLLD_Demos_1_0_1_3_0
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
//#include "Cpu0_Main.h"
#include "ConfigurationIsr.h"

#include "QspiCpuDemo.h"

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
App_QspiCpu g_QspiCpu; /**< \brief Qspi global data */

spi_reg qspi_slave_reg_st;

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/
/** \name Interrupts for Qspi Master (QSPI0) & Slave (QSPI2) drivers
 * \{ */
IFX_INTERRUPT(ISR_qspi1_Tx, 0, ISR_PRIORITY_QSPI1_TX);
IFX_INTERRUPT(ISR_qspi1_Rx, 0, ISR_PRIORITY_QSPI1_RX);
IFX_INTERRUPT(ISR_qspi1_Er, 0, ISR_PRIORITY_QSPI1_ER);
/** \} */



void ISR_qspi1_Tx(void)
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiMaster_isrTransmit(&g_QspiCpu.drivers.spiMaster);
}


/** \brief Handle qspi0_Rx interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_QSPI0_RX
 * \isrPriority \ref ISR_PRIORITY_QSPI0_RX
 *
 */
void ISR_qspi1_Rx(void)
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiMaster_isrReceive(&g_QspiCpu.drivers.spiMaster);
}


/** \brief Handle qspi0_Er interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_QSPI0_ER
 * \isrPriority \ref ISR_PRIORITY_QSPI0_ER
 *
 */
void ISR_qspi1_Er(void)
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiMaster_isrError(&g_QspiCpu.drivers.spiMaster);
}




/** \brief Qspi Master initilisation
 *
 * This function initialises Qspi0 in master mode.
 */
void IfxQspi_Masterinit(void)
{
    uint32                          i;
    IfxQspi_SpiMaster_Config        spiMasterConfig;
    IfxQspi_SpiMaster_ChannelConfig spiMasterChannelConfig;

    {
        /* create module config */
        IfxQspi_SpiMaster_initModuleConfig(&spiMasterConfig, &MODULE_QSPI1);

        /* set the maximum baudrate */
        spiMasterConfig.base.maximumBaudrate = 10000000;

        /* ISR priorities and interrupt target */
        spiMasterConfig.base.txPriority  = ISR_PRIORITY_QSPI1_TX;
        spiMasterConfig.base.rxPriority  = ISR_PRIORITY_QSPI1_RX;
        spiMasterConfig.base.erPriority  = ISR_PRIORITY_QSPI1_ER;
        spiMasterConfig.base.isrProvider = (IfxSrc_Tos)IfxCpu_getCoreIndex();

        /* pin configuration */
        const IfxQspi_SpiMaster_Pins pins = {&IfxQspi1_SCLK_P11_6_OUT,                               /* SCLK */
        									IfxPort_OutputMode_pushPull,
                                             &IfxQspi1_MTSR_P11_9_OUT,  IfxPort_OutputMode_pushPull, /* MTSR */
                                             &IfxQspi1_MRSTB_P11_3_IN,  IfxPort_InputMode_pullDown,  /* MRST */
                                             IfxPort_PadDriver_cmosAutomotiveSpeed3                   /* pad driver mode */
        };
        spiMasterConfig.pins = &pins;

        /* initialize module */
        IfxQspi_SpiMaster_initModule(&g_QspiCpu.drivers.spiMaster, &spiMasterConfig);
    }

    {
        /* create channel config */
        IfxQspi_SpiMaster_initChannelConfig(&spiMasterChannelConfig,
            &g_QspiCpu.drivers.spiMaster);

        /* set the baudrate for this channel */
        spiMasterChannelConfig.base.baudrate = 5000000;

        const IfxQspi_SpiMaster_Output slsOutput = {&IfxQspi1_SLSO3_P11_10_OUT,
                                                    IfxPort_OutputMode_pushPull,
                                                    IfxPort_PadDriver_cmosAutomotiveSpeed1};

        spiMasterChannelConfig.sls.output.pin    = slsOutput.pin;
        spiMasterChannelConfig.sls.output.mode   = slsOutput.mode;
        spiMasterChannelConfig.sls.output.driver = slsOutput.driver;

        spiMasterChannelConfig.base.mode.clockPolarity 	= SpiIf_ClockPolarity_idleHigh;
        spiMasterChannelConfig.base.mode.shiftClock 	= SpiIf_ShiftClock_shiftTransmitDataOnLeadingEdge;
        spiMasterChannelConfig.base.mode.csInactiveDelay = 3;


        //spiMasterChannelConfig.base.mode.autoCS = 0;



        /* initialize channel */
        IfxQspi_SpiMaster_initChannel(&g_QspiCpu.drivers.spiMasterChannel,
            &spiMasterChannelConfig);
    }

    /* init tx buffer area */
    for (i = 0; i < SPI_BUFFER_SIZE; i++)
    {
        g_QspiCpu.qspiBuffer.spi1TxBuffer[i] = (uint8)(0);

        g_QspiCpu.qspiBuffer.spi1RxBuffer[i] = (uint8)(0);

    }
}


/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void IfxQspiCpuDemo_init(void)
{
    /* disable interrupts */
    boolean interruptState = IfxCpu_disableInterrupts();


    IfxQspi_Masterinit();

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);
}




