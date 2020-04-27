/*
 * AIS328DQ_REG.c
 *
 *  Created on: 2018. 11. 28.
 *      Author: junseok.lee
 */
#include "AIS328DQ_REG.h"
#include <Qspi/SpiMaster/IfxQspi_SpiMaster.h>
#include "QspiCpuDemo.h"

uint8 spi_test = 0;
//uint8 Ax_Sensor_Write(uint8 addr, uint8 *data)
//{
////	Ax_Sensor_SPI_Cfg spi_cfg;
////	spi_cfg.RW = 0;
////	spi_cfg.MS = 0;
////	spi_cfg.ADDR = addr;
//	uint8 cmd = addr;
//
//	g_QspiCpu.qspiBuffer.spi0TxBuffer[0] = cmd;
//	g_QspiCpu.qspiBuffer.spi0TxBuffer[1] = data;
//
//    /* Master transfer */
//    while (IfxQspi_SpiMaster_getStatus(&g_QspiCpu.drivers.spiMasterChannel)
//           == SpiIf_Status_busy)
//    {}
//
//    IfxQspi_SpiMaster_exchange(&g_QspiCpu.drivers.spiMasterChannel, &g_QspiCpu.qspiBuffer.spi0TxBuffer[0],
//        &g_QspiCpu.qspiBuffer.spi0RxBuffer[0], 2);
//
//    return 0;
//
//}

//uint8 Ax_Sensor_Read(uint8 addr)
//{
////	Ax_Sensor_SPI_Cfg spi_cfg;
////	spi_cfg.RW = 1;
////	spi_cfg.MS = 0;
////	spi_cfg.ADDR = addr;
//	uint8 cmd = 0x80 | addr ;
//
//	g_QspiCpu.qspiBuffer.spi0TxBuffer[0] = (uint8)cmd;
//
//    /* Master transfer */
//    while (IfxQspi_SpiMaster_getStatus(&g_QspiCpu.drivers.spiMasterChannel)
//           == SpiIf_Status_busy)
//    {}
//
//    IfxQspi_SpiMaster_exchange(&g_QspiCpu.drivers.spiMasterChannel, &g_QspiCpu.qspiBuffer.spi0TxBuffer[0],
//        &g_QspiCpu.qspiBuffer.spi0RxBuffer[0], SPI_BUFFER_SIZE);
//
//    return g_QspiCpu.qspiBuffer.spi0RxBuffer[1];
//
//}

//void ax_read(void)
//{
//	static uint8 spi_msg = 0;
//	spi_msg = 0;
//	spi_msg = Ax_Sensor_Read(0x0F);
//
//	spi_test = spi_msg;
//}

int gsensor_read_reg(uint8 addr, uint8 *data) {
	uint8 cmd = 0x80 | addr; /*	RW = 1, MS = 0, 	*/

	g_QspiCpu.qspiBuffer.spi1TxBuffer[0] = (uint8) cmd;
	g_QspiCpu.qspiBuffer.spi1TxBuffer[1] = 0;

	/* Master transfer */
	while (IfxQspi_SpiMaster_getStatus(&g_QspiCpu.drivers.spiMasterChannel)
			== SpiIf_Status_busy) {
	}

	if (IfxQspi_SpiMaster_exchange(&g_QspiCpu.drivers.spiMasterChannel, &g_QspiCpu.qspiBuffer.spi1TxBuffer[0],
			&g_QspiCpu.qspiBuffer.spi1RxBuffer[0], 2) != SpiIf_Status_ok) {
		return -1;
	}

	while (IfxQspi_SpiMaster_getStatus(&g_QspiCpu.drivers.spiMasterChannel)
			== SpiIf_Status_busy) {
	}

	*data = g_QspiCpu.qspiBuffer.spi1RxBuffer[1];
	//*data = g_QspiCpu.qspiBuffer.spi1RxBuffer[0];

	return 0;
}

int gsensor_write_reg(uint8 addr, uint8 *data) {
	uint8 cmd = 0x00 | addr; /*	RW = 0, MS = 0, 	*/

	g_QspiCpu.qspiBuffer.spi1TxBuffer[0] = (uint8) cmd;
	g_QspiCpu.qspiBuffer.spi1TxBuffer[1] = *data;

	/* Master transfer */
	while (IfxQspi_SpiMaster_getStatus(&g_QspiCpu.drivers.spiMasterChannel)
			== SpiIf_Status_busy) {
	}

	if (IfxQspi_SpiMaster_exchange(&g_QspiCpu.drivers.spiMasterChannel,
			&g_QspiCpu.qspiBuffer.spi1TxBuffer[0],
			&g_QspiCpu.qspiBuffer.spi1RxBuffer[0], 2) != SpiIf_Status_ok) {
		return -1;
	}

	return 0;
}

int gsensor_device_id_get(uint8 *data) {
	return gsensor_read_reg(WHO_AM_I, data);
}

int gsensor_axis_xen_set(uint8 value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG1, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg1.Xen = value;

	if (gsensor_write_reg(CTRL_REG1, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_axis_yen_set(uint8 value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG1, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg1.Yen = value;

	if (gsensor_write_reg(CTRL_REG1, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_axis_zen_set(uint8 value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG1, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg1.Zen = value;

	if (gsensor_write_reg(CTRL_REG1, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_power_mode_set(Ax_Sensor_PM value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG1, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg1.PM = value;

	if (gsensor_write_reg(CTRL_REG1, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_data_rate_set(Ax_Senor_DR value) {
	Ax_Sensor_Reg reg;


	if (gsensor_read_reg(CTRL_REG1, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg1.DR = value;

	if (gsensor_write_reg(CTRL_REG1, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_boot_mode_set(Ax_Sensor_BM value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG2, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg2.BOOT = value;

	if (gsensor_write_reg(CTRL_REG2, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_HP_filter_mode_set(Ax_Sensor_HPM value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG2, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg2.HPM = value;

	if (gsensor_write_reg(CTRL_REG2, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_internal_filter_set(Ax_Sensor_FDS value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG2, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg2.FDS = value;

	if (gsensor_write_reg(CTRL_REG2, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_HPF_enable_set(Ax_Sensor_HPen value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG2, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg2.HPen1 = value & 0x01;
	reg.Ctrl_Reg2.HPen2 = value & 0x02;

	if (gsensor_write_reg(CTRL_REG2, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_HPF_cutoff_set(Ax_Sensor_HPCF value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG2, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg2.HPCF = value;

	if (gsensor_write_reg(CTRL_REG2, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

/* CTRL REG 3	*/

int gsensor_int1_pad_set(Ax_Sensor_INT_CFG value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG3, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg3.I1_CFG = value;

	if (gsensor_write_reg(CTRL_REG3, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_int1_latch_set(Ax_Sensor_Lir value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG3, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg3.LIR1 = value;

	if (gsensor_write_reg(CTRL_REG3, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_int2_pad_set(Ax_Sensor_INT_CFG value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG3, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg3.I2_CFG = value;

	if (gsensor_write_reg(CTRL_REG3, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_int2_latch_set(Ax_Sensor_Lir value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG3, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg3.LIR2 = value;

	if (gsensor_write_reg(CTRL_REG3, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_pin_pad_set(Ax_Sensor_PP_OD value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG3, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg3.PP_OD = value;

	if (gsensor_write_reg(CTRL_REG3, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_pin_polarity_set(Ax_Sensor_IHL value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG3, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg3.IHL = value;

	if (gsensor_write_reg(CTRL_REG3, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

/*	CTRL REG4	*/
int gsensor_block_data_update_set(uint8 value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG4, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg4.BDU = value;

	if (gsensor_write_reg(CTRL_REG4, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_data_format_set(Ax_Sensor_BLE value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG4, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg4.BLE = value;

	if (gsensor_write_reg(CTRL_REG4, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_full_scale_set(Ax_Sensor_FS value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG4, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg4.FS = value;

	if (gsensor_write_reg(CTRL_REG4, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_self_test_sign_set(Ax_Sensor_STsign value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG4, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg4.STsign = value;

	if (gsensor_write_reg(CTRL_REG4, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_self_test_set(Ax_Sensor_STE value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG4, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg4.ST = value;

	if (gsensor_write_reg(CTRL_REG4, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_spi_mode_set(Ax_Sensor_SIM value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG4, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg4.SIM = value;

	if (gsensor_write_reg(CTRL_REG4, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

/*	CTRL REG5	*/
int gsensor_sleep_to_wakeup_set(Ax_Sensor_TurnOn value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(CTRL_REG5, &reg.byte) != 0) {
		return -1;
	}

	reg.Ctrl_Reg5.TurnON = value;

	if (gsensor_write_reg(CTRL_REG5, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

/*	INT1 CFG	*/

int gsensor_INT1_Int_mode_set(Ax_Sensor_INT_6D value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(INT1_CFG, &reg.byte) != 0) {
		return -1;
	}

	reg.Int1_Cfg.AOI_6D = value;

	if (gsensor_write_reg(INT1_CFG, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_INT1_threshold_level_set(INT_TH_LEVEL value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(INT1_CFG, &reg.byte) != 0) {
		return -1;
	}

	reg.Int1_Cfg.XHIE = value.int_xhie;
	reg.Int1_Cfg.XLIE = value.int_xlie;
	reg.Int1_Cfg.YHIE = value.int_yhie;
	reg.Int1_Cfg.YLIE = value.int_ylie;
	reg.Int1_Cfg.ZHIE = value.int_zhie;
	reg.Int1_Cfg.ZLIE = value.int_zlie;

	if (gsensor_write_reg(INT1_CFG, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_INT1_event_get(Ax_Sensor_Int1_Src *value) {
	return gsensor_read_reg(INT1_SRC, (uint8 *) value);
}

int gsensor_INT1_threshold_set(uint8 value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(INT1_THS, &reg.byte) != 0) {
		return -1;
	}

	reg.Int1_Ths.THS = value;

	if (gsensor_write_reg(INT1_THS, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_INT1_duration_set(uint8 value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(INT1_DURATION, &reg.byte) != 0) {
		return -1;
	}

	reg.Int1_Duration.Duration = value;

	if (gsensor_write_reg(INT1_DURATION, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

/*	INT2	*/

int gsensor_INT2_Int_mode_set(Ax_Sensor_INT_6D value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(INT2_CFG, &reg.byte) != 0) {
		return -1;
	}

	reg.Int2_Cfg.AOI_6D = value;

	if (gsensor_write_reg(INT2_CFG, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_INT2_threshold_level_set(INT_TH_LEVEL value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(INT2_CFG, &reg.byte) != 0) {
		return -1;
	}

	reg.Int2_Cfg.XHIE = value.int_xhie;
	reg.Int2_Cfg.XLIE = value.int_xlie;
	reg.Int2_Cfg.YHIE = value.int_yhie;
	reg.Int2_Cfg.YLIE = value.int_ylie;
	reg.Int2_Cfg.ZHIE = value.int_zhie;
	reg.Int2_Cfg.ZLIE = value.int_zlie;

	if (gsensor_write_reg(INT2_CFG, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_INT2_event_get(Ax_Sensor_Int2_Src *value) {
	return gsensor_read_reg(INT2_SRC, (uint8 *) value);
}

int gsensor_INT2_threshold_set(uint8 value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(INT2_THS, &reg.byte) != 0) {
		return -1;
	}

	reg.Int2_Ths.THS = value;

	if (gsensor_write_reg(INT2_THS, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

int gsensor_INT2_duration_set(uint8 value) {
	Ax_Sensor_Reg reg;

	if (gsensor_read_reg(INT2_DURATION, &reg.byte) != 0) {
		return -1;
	}

	reg.Int2_Duration.Duration = value;

	if (gsensor_write_reg(INT2_DURATION, &reg.byte) != 0) {
		return -1;
	}

	return 0;
}

