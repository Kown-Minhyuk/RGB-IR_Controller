/*
 * Qspi_Dma.h
 *
 *  Created on: 2019. 12. 24.
 *      Author: junseok.lee
 */

#ifndef APP_INC_QSPI_DMA_H_
#define APP_INC_QSPI_DMA_H_

//#include <Ifx_Types.h>
#include "Cpu/Std/Ifx_Types.h"
//#include "Configuration.h"
#include <Qspi/SpiMaster/IfxQspi_SpiMaster.h>
#include <Qspi/SpiSlave/IfxQspi_SpiSlave.h>

#define SPI_DMA_BUFFER_SIZE 16   /**< \brief Tx/Rx Buffer size */

//typedef struct
//{
////    uint8 IFX_ALIGN(64) spi0TxBuffer[SPI_DMA_BUFFER_SIZE];                               /**< \brief Qspi0 Transmit buffer */
////    uint8 IFX_ALIGN(64) spi0RxBuffer[SPI_DMA_BUFFER_SIZE];                               /**< \brief Qspi0 receive buffer */
//
//} AppQspiBuffer;

typedef struct
{
//    AppQspiBuffer qspiBuffer;                       /**< \brief Qspi buffer */
    struct
    {
        IfxQspi_SpiMaster         spiMaster;        /**< \brief Spi Master handle */
        IfxQspi_SpiMaster_Channel spiMasterChannel; /**< \brief Spi Master Channel handle */
        IfxQspi_SpiSlave          spiSlave;         /**< \brief Spi Slave handle */
    }drivers;
} App_QspiDma;

extern  App_QspiDma g_QspiDma;


extern void IfxQspiDma_init(void);
extern void Qspi_Dma_transfer(void);


#endif /* APP_INC_QSPI_DMA_H_ */
