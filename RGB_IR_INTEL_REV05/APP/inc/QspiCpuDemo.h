/**
 * \file Template.h
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
 *
 * \defgroup IfxLld_Demo_QspiCpuDemo_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_QspiCpuDemo_SrcDoc
 * \defgroup IfxLld_Demo_QspiCpuDemo_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_QspiCpuDemo_SrcDoc_Main
 */

#ifndef QSPICPUDEMO_H
#define QSPICPUDEMO_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "Cpu/Std/Ifx_Types.h"

#include <Qspi/SpiMaster/IfxQspi_SpiMaster.h>
#include <Qspi/SpiSlave/IfxQspi_SpiSlave.h>

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define SPI_BUFFER_SIZE 32   /**< \brief Tx/Rx Buffer size */

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/
typedef struct
{
    uint8 spi1TxBuffer[SPI_BUFFER_SIZE];                   /**< \brief Qspi0 Transmit buffer */
    uint8 spi1RxBuffer[SPI_BUFFER_SIZE];                   /**< \brief Qspi0 receive buffer */

    uint8 spi0TxBuffer[SPI_BUFFER_SIZE];
    uint8 spi0RxBuffer[SPI_BUFFER_SIZE];
    uint8 spi0RxBuffer_temp[SPI_BUFFER_SIZE];


} AppQspiBuffer;

/** \brief QspiCpu global data */
typedef struct
{
    AppQspiBuffer qspiBuffer;                       /**< \brief Qspi buffer */
    struct
    {
        IfxQspi_SpiMaster         spiMaster;        /**< \brief Spi Master handle */
        IfxQspi_SpiMaster_Channel spiMasterChannel; /**< \brief Spi Master Channel handle */
        IfxQspi_SpiSlave          spiSlave;         /**< \brief Spi Slave handle */
    }drivers;
} App_QspiCpu;

typedef struct
{
	uint32 reg0[10];
}spi_reg;

extern uint32 stat_Reg;
extern uint32 stat_Reg2;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
extern App_QspiCpu g_QspiCpu;
extern spi_reg qspi_slave_reg_st;



/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
extern void IfxQspiCpuDemo_init(void);
extern void IfxQspiCpuDemo_run(void);

extern void IfxQspi_Masterinit(void);

#endif
