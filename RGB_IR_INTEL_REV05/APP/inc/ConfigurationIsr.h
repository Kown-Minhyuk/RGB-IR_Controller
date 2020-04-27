/**
 * \file ConfigurationIsr.h
 * \brief Interrupts configuration.
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
 * \defgroup IfxLld_Demo_AsclinAsc_SrcDoc_InterruptConfig Interrupt configuration
 * \ingroup IfxLld_Demo_AsclinAsc_SrcDoc
 */

#ifndef CONFIGURATIONISR_H
#define CONFIGURATIONISR_H

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Build the ISR configuration object
 * \param no interrupt priority
 * \param cpu assign CPU number
 */
#define ISR_ASSIGN(no, cpu)  ((no << 8) + cpu)

/** \brief extract the priority out of the ISR object */
#define ISR_PRIORITY(no_cpu) (no_cpu >> 8)

/** \brief extract the service provider  out of the ISR object */
#define ISR_PROVIDER(no_cpu) (no_cpu % 8)

/**
 * \addtogroup IfxLld_Demo_AsclinAsc_SrcDoc_InterruptConfig
 * \{ */

/**
 * \name Interrupt priority configuration.
 * The interrupt priority range is [1,255]
 * \{ */

#define ISR_PRIORITY_TIMER_1MS      1  /**< \brief Define the 1ms timer interrupt priority.  */



#define ISR_PRIORITY_IGN_OFF       	2 	/**< \brief Define the SCU ERU interrupt priority.  */
#define ISR_PRIORITY_REC_INPUT      3 	/**< \brief Define the SCU ERU interrupt priority.  */
#define ISR_PRIORITY_BAT_OUT		4	/* BAT_OUT 	*/

#define ISR_PRIORITY_SCUERU_0       5 /**< \brief Define the SCU ERU interrupt priority.  */
#define ISR_PRIORITY_AX_SENS		7	/* AX_SENSOR 	*/

//#define ISR_PRIORITY_ASCLIN1_TX     7   /**< \brief Define the ASCLIN1 transmit interrupt priority.  */
//#define ISR_PRIORITY_ASCLIN1_RX     8   /**< \brief Define the ASCLIN1 receive interrupt priority.  */
//#define ISR_PRIORITY_ASCLIN1_ER     12  /**< \brief Define the ASCLIN1 error interrupt priority.  */

#define ISR_PRIORITY_QSPI1_TX       10   /**< \brief Define the Qspi0 transmit interrupt priority.  */
#define ISR_PRIORITY_QSPI1_RX       20   /**< \brief Define the Qspi0 receive interrupt priority.  */
#define ISR_PRIORITY_QSPI1_ER       30 /**< \brief Define the Qspi0 error interrupt priority.  */

//#define ISR_PRIORITY_QSPI0_TX       9   /**< \brief Define the Qspi0 transmit interrupt priority.  */
//#define ISR_PRIORITY_QSPI0_RX       6   /**< \brief Define the Qspi0 receive interrupt priority.  */
#define ISR_PRIORITY_QSPI0_ER       31 /**< \brief Define the Qspi0 error interrupt priority.  */

#define ISR_PRIORITY_DMA_CH1        9 /**< \brief Define the Dma channel1 interrupt priority.  */
#define ISR_PRIORITY_DMA_CH2        6 /**< \brief Define the Dma channel2 interrupt priority.  */



#define ISR_PRIORITY_STM_INT0       40 /**< \brief Define the System Timer Interrupt priority.  */




/** \} */

/**
 * \name Interrupt service provider configuration.
 * \{ */


//#define ISR_PROVIDER_ASCLIN1_TX     IfxSrc_Tos_cpu0 /**< \brief Define the ASCLIN1 transmit interrupt provider.  */
//#define ISR_PROVIDER_ASCLIN1_RX     IfxSrc_Tos_cpu0 /**< \brief Define the ASCLIN1 receive interrupt provider.  */
//#define ISR_PROVIDER_ASCLIN1_ER     IfxSrc_Tos_cpu0 /**< \brief Define the ASCLIN1 error interrupt provider.  */
#define ISR_PROVIDER_STM_INT0       IfxSrc_Tos_cpu0         /**< \brief Define the System Timer interrupt provider.  */

#define ISR_PROVIDER_IGN_OFF       	IfxSrc_Tos_cpu0  /**< \brief Define the SCU ERU interrupt provider.  */
#define ISR_PROVIDER_REC_INPUT      IfxSrc_Tos_cpu0  /**< \brief Define the SCU ERU interrupt provider.  */
#define ISR_PROVIDER_BAT_OUT		IfxSrc_Tos_cpu0
#define ISR_PROVIDER_AX_SENS		IfxSrc_Tos_cpu0

#define ISR_PROVIDER_QSPI1_TX       IfxSrc_Tos_cpu0      /**< \brief Define the Qspi0 transmit interrupt provider.  */
#define ISR_PROVIDER_QSPI1_RX       IfxSrc_Tos_cpu0      /**< \brief Define the Qspi0 receive interrupt provider.  */
#define ISR_PROVIDER_QSPI1_ER       IfxSrc_Tos_cpu0      /**< \brief Define the Qspi0 error interrupt provider.  */

#define ISR_PROVIDER_QSPI0_TX       IfxSrc_Tos_cpu0      /**< \brief Define the Qspi0 transmit interrupt provider.  */
#define ISR_PROVIDER_QSPI0_RX       IfxSrc_Tos_cpu0      /**< \brief Define the Qspi0 receive interrupt provider.  */
#define ISR_PROVIDER_QSPI0_ER       IfxSrc_Tos_cpu0      /**< \brief Define the Qspi0 error interrupt provider.  */

#define ISR_PROVIDER_TIMER_1MS      IfxSrc_Tos_cpu0 /**< \brief Define the 1ms timer interrupt provider.  */

#define ISR_PROVIDER_SCUERU_0       IfxSrc_Tos_cpu0  /**< \brief Define the SCU ERU interrupt provider.  */

#define ISR_PROVIDER_DMA_CH1        IfxSrc_Tos_cpu0     /**< \brief Define the Dma Channel1 interrupt provider.  */
#define ISR_PROVIDER_DMA_CH2        IfxSrc_Tos_cpu0     /**< \brief Define the Dma Channel2 interrupt provider.  */

/** \} */

/**
 * \name Interrupt configuration.
 * \{ */


//#define INTERRUPT_ASCLIN1_TX        ISR_ASSIGN(ISR_PRIORITY_ASCLIN1_TX, ISR_PROVIDER_ASCLIN1_TX)         /**< \brief Install the ASCLIN1 transmit interrupt handler.  */
//#define INTERRUPT_ASCLIN1_RX        ISR_ASSIGN(ISR_PRIORITY_ASCLIN1_RX, ISR_PROVIDER_ASCLIN1_RX)         /**< \brief Install the ASCLIN1 receive interrupt handler.  */
//#define INTERRUPT_ASCLIN1_ER        ISR_ASSIGN(ISR_PRIORITY_ASCLIN1_ER, ISR_PROVIDER_ASCLIN1_ER)         /**< \brief Install the ASCLIN1 error interrupt handler.  */
#define INTERRUPT_STM_INT0          ISR_ASSIGN(ISR_PRIORITY_STM_INT0, ISR_PROVIDER_STM_INT0)                            /**< \brief Define the System Timer interrupt priority.  */

#define INTERRUPT_ERU_IGNOFF        ISR_ASSIGN(ISR_PRIORITY_IGN_OFF, ISR_PROVIDER_IGN_OFF)             /**< \brief Define the SCU ERU interrupt priority.  */
#define INTERRUPT_ERU_RECSW	        ISR_ASSIGN(ISR_PRIORITY_REC_INPUT, ISR_PROVIDER_REC_INPUT)             /**< \brief Define the SCU ERU interrupt priority.  */
#define INTERRUPT_ERU_BATOUT        ISR_ASSIGN(ISR_PRIORITY_BAT_OUT, ISR_PROVIDER_BAT_OUT)             /**< \brief Define the SCU ERU interrupt priority.  */
#define INTERRUPT_ERU_AXSENS        ISR_ASSIGN(ISR_PRIORITY_AX_SENS, ISR_PROVIDER_AX_SENS)

#define INTERRUPT_QSPI1_TX          ISR_ASSIGN(ISR_PRIORITY_QSPI1_TX, ISR_PROVIDER_QSPI1_TX)             /**< \brief Define the QSPI0 transmit interrupt priority.  */
#define INTERRUPT_QSPI1_RX          ISR_ASSIGN(ISR_PRIORITY_QSPI1_RX, ISR_PROVIDER_QSPI1_RX)             /**< \brief Define the QSPI0 receive interrupt priority.  */
#define INTERRUPT_QSPI1_ER          ISR_ASSIGN(ISR_PRIORITY_QSPI1_ER, ISR_PROVIDER_QSPI1_ER)             /**< \brief Define the QSPI0 error interrupt priority.  */

#define INTERRUPT_QSPI0_TX          ISR_ASSIGN(ISR_PRIORITY_QSPI0_TX, ISR_PROVIDER_QSPI0_TX)             /**< \brief Define the QSPI0 transmit interrupt priority.  */
#define INTERRUPT_QSPI0_RX          ISR_ASSIGN(ISR_PRIORITY_QSPI0_RX, ISR_PROVIDER_QSPI0_RX)             /**< \brief Define the QSPI0 receive interrupt priority.  */
#define INTERRUPT_QSPI0_ER          ISR_ASSIGN(ISR_PRIORITY_QSPI0_ER, ISR_PROVIDER_QSPI0_ER)             /**< \brief Define the QSPI0 error interrupt priority.  */

#define INTERRUPT_TIMER_1MS         ISR_ASSIGN(ISR_PRIORITY_TIMER_1MS, ISR_PROVIDER_TIMER_1MS)           /**< \brief Define the 1ms timer interrupt priority.  */
#define INTERRUPT_SCUERU_0          ISR_ASSIGN(ISR_PRIORITY_SCUERU_0, ISR_PROVIDER_SCUERU_0)             /**< \brief Define the SCU ERU interrupt priority.  */

#define INTERRUPT_DMA_CH1           ISR_ASSIGN(ISR_PRIORITY_DMA_CH1, ISR_PROVIDER_DMA_CH1)               /**< \brief Define the Dma channel1 interrupt priority.  */
#define INTERRUPT_DMA_CH2           ISR_ASSIGN(ISR_PRIORITY_DMA_CH2, ISR_PROVIDER_DMA_CH2)               /**< \brief Define the Dma channel2 interrupt priority.  */
/** \} */

/** \} */
//------------------------------------------------------------------------------

#endif
