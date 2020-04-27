/*
 * Qspi_Dma.c
 *
 *  Created on: 2019. 12. 24.
 *      Author: junseok.lee
 */
#include "Qspi_Dma.h"
#include "ConfigurationIsr.h"
#include "Spisoc.h"
#include "util.h"

#define IFX_QSPI0_TX_CHANNELID (IfxDma_ChannelId_1) /**< \brief Dma channel used for Slave Qspi2 Transmit */
#define IFX_QSPI0_RX_CHANNELID (IfxDma_ChannelId_2) /**< \brief Dma channel used for Slave Qspi2 receive */

App_QspiDma g_QspiDma; /**< \brief Qspi global data */

IFX_INTERRUPT(ISR_qspi0_Er, 0, ISR_PRIORITY_QSPI0_ER);
IFX_INTERRUPT(ISR_dma_ch1, 0, ISR_PRIORITY_DMA_CH1);
IFX_INTERRUPT(ISR_dma_ch2, 0, ISR_PRIORITY_DMA_CH2);


void ISR_qspi0_Er(void)
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiMaster_isrError(&g_QspiDma.drivers.spiMaster);
}

void ISR_dma_ch1(void)
{
    IfxCpu_enableInterrupts();

    IfxQspi_SpiSlave_isrDmaTransmit(&g_QspiDma.drivers.spiSlave);
}


void ISR_dma_ch2(void)
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiSlave_isrDmaReceive(&g_QspiDma.drivers.spiSlave);
}

static void IfxQspi_Dma_Slaveinit(void)
{
    IfxQspi_SpiSlave_Config spiSlaveConfig;
    Ifx_QSPI               *qspi2SFR;

    {
        /* create module config */
        IfxQspi_SpiSlave_initModuleConfig(&spiSlaveConfig, &MODULE_QSPI0);

        /* set the maximum baudrate */
        spiSlaveConfig.base.maximumBaudrate = 10000000;

        /* ISR priorities and interrupt target */
        spiSlaveConfig.base.txPriority    = ISR_PRIORITY_DMA_CH1;
        spiSlaveConfig.base.rxPriority    = ISR_PRIORITY_DMA_CH2;
        spiSlaveConfig.base.erPriority    = ISR_PRIORITY_QSPI0_ER;
        spiSlaveConfig.base.isrProvider   = (IfxSrc_Tos)IfxCpu_getCoreIndex();
        spiSlaveConfig.dma.txDmaChannelId = IFX_QSPI0_TX_CHANNELID;
        spiSlaveConfig.dma.rxDmaChannelId = IFX_QSPI0_RX_CHANNELID;
        spiSlaveConfig.dma.useDma         = 1;

        /* pin configuration */
        const IfxQspi_SpiSlave_Pins slavePins = {&IfxQspi0_SCLKA_P20_11_IN,                               /* SCLK Pin */
                                                 IfxPort_InputMode_pullDown,
                                                 &IfxQspi0_MTSRA_P20_14_IN,  IfxPort_InputMode_pullDown,  /* MTSR Pin */
                                                 &IfxQspi0_MRST_P20_12_OUT,  IfxPort_OutputMode_pushPull, /* MRST Pin */
                                                 &IfxQspi0_SLSIA_P20_13_IN,  IfxPort_InputMode_noPullDevice,  /* SLSI Pin */
                                                 IfxPort_PadDriver_cmosAutomotiveSpeed3                  /* pad driver mode */
        };
        spiSlaveConfig.pins = &slavePins;

        spiSlaveConfig.protocol.shiftClock = SpiIf_ClockPolarity_idleLow;
        spiSlaveConfig.protocol.clockPolarity = SpiIf_ShiftClock_shiftTransmitDataOnLeadingEdge;

        /* initialize module */
        IfxQspi_SpiSlave_initModule(&g_QspiDma.drivers.spiSlave, &spiSlaveConfig);

        {
            qspi2SFR = spiSlaveConfig.qspi;

            volatile Ifx_SRC_SRCR *src = IfxQspi_getErrorSrc(qspi2SFR);
            IfxSrc_init(src, (IfxSrc_Tos)IfxCpu_getCoreIndex(), ISR_PRIORITY_QSPI0_ER);
            IfxSrc_enable(src);
        }
    }
}

void IfxQspiDma_init(void)
{
    /* disable interrupts */
    boolean interruptState = IfxCpu_disableInterrupts();

    IfxQspi_Dma_Slaveinit();

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);
}

void Qspi_Dma_transfer(void)
{

	uint32 current_time = 0;
	uint32 sample_time = 0;
//	uint32 Time_const = 10000000;	/* 500ms	*/
	uint32 Time_const = 20000;	/* 10ms	*/


	sample_time = IfxStm_getLower(stmSfr1);
    while (IfxQspi_SpiSlave_getStatus(&g_QspiDma.drivers.spiSlave) == SpiIf_Status_busy)
    {
    	current_time = IfxStm_getLower(stmSfr1);
		if( current_time - sample_time >= Time_const )
		{
			sample_time += Time_const;
			goto end;
		}
    }

//    IfxQspi_SpiSlave_exchange(&g_QspiDma.drivers.spiSlave, &g_QspiDma.qspiBuffer.spi0TxBuffer[0],
//        &g_QspiDma.qspiBuffer.spi0RxBuffer[0], SPI_DMA_BUFFER_SIZE);
    IfxQspi_SpiSlave_exchange(&g_QspiDma.drivers.spiSlave, &g_spi_msg.spi_data_tx[0],
    		&g_spi_msg.spi_data_rx[0], SPI_DMA_BUFFER_SIZE);

    /* wait until slave received all data */
    sample_time = IfxStm_getLower(stmSfr1);
    while (IfxQspi_SpiSlave_getStatus(&g_QspiDma.drivers.spiSlave) == SpiIf_Status_busy)
    {
    	current_time = IfxStm_getLower(stmSfr1);
		if( current_time - sample_time >= Time_const )
		{
			sample_time += Time_const;
			goto end;
		}
    }

    end:
	{}

}
