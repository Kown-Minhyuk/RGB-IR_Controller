/*
 * AIS328DQ_REG.h
 *
 *  Created on: 2018. 11. 28.
 *      Author: junseok.lee
 */

#ifndef AIS328DQ_REG_H_
#define AIS328DQ_REG_H_

#include "Cpu/Std/Ifx_Types.h"

/* Register Address	*/
#define WHO_AM_I		0x0F

#define CTRL_REG1		0x20
#define CTRL_REG2		0x21
#define CTRL_REG3		0x22
#define CTRL_REG4		0x23
#define CTRL_REG5		0x24

#define HP_FILTER_RESET	0x25
#define REFERENCE		0x26
#define STATUS_REG		0x27
#define OUT_X_L			0x28
#define OUT_X_H			0x29
#define OUT_Y_L			0x2A
#define OUT_Y_H			0x2B
#define OUT_Z_L			0x2C
#define OUT_Z_H			0x2D

#define INT1_CFG		0x30
#define INT1_SRC		0x31
#define INT1_THS		0x32
#define INT1_DURATION	0x33
#define INT2_CFG		0x34
#define INT2_SRC		0x35
#define INT2_THS		0x36
#define INT2_DURATION	0x37

typedef struct
{
	uint8 Xen	:1;
	uint8 Yen	:1;
	uint8 Zen	:1;
	uint8 DR	:2;
	uint8 PM	:3;
}Ax_Sensor_Ctrl_Reg1;

typedef struct
{
	uint8 HPCF	:2;
	uint8 HPen1	:1;
	uint8 HPen2	:1;
	uint8 FDS	:1;
	uint8 HPM	:2;
	uint8 BOOT	:1;
}Ax_Sensor_Ctrl_Reg2;

typedef struct
{
	uint8 I1_CFG	:2;
	uint8 LIR1		:1;
	uint8 I2_CFG	:2;
	uint8 LIR2		:1;
	uint8 PP_OD		:1;
	uint8 IHL		:1;
}Ax_Sensor_Ctrl_Reg3;

typedef struct
{
	uint8 SIM 		:1;
	uint8 ST		:1;
	uint8 reserved	:1;
	uint8 STsign	:1;
	uint8 FS		:2;
	uint8 BLE		:1;
	uint8 BDU		:1;
}Ax_Sensor_Ctrl_Reg4;

typedef struct
{
	uint8 TurnON	:2;
	uint8 reserved	:6;
}Ax_Sensor_Ctrl_Reg5;

typedef struct
{
	uint8 XDA		:1;
	uint8 YDA		:1;
	uint8 ZDA		:1;
	uint8 ZYXDA		:1;
	uint8 XOR		:1;
	uint8 YOR		:1;
	uint8 ZOR		:1;
	uint8 ZYXOR		:1;
}Ax_Sensor_Status_Reg;

typedef struct
{
	uint8 XLIE		:1;
	uint8 XHIE		:1;
	uint8 YLIE		:1;
	uint8 YHIE		:1;
	uint8 ZLIE		:1;
	uint8 ZHIE		:1;
	uint8 AOI_6D	:2;
}Ax_Sensor_Int1_Cfg;

typedef struct
{
	uint8 XL		:1;
	uint8 XH		:1;
	uint8 YL		:1;
	uint8 YH		:1;
	uint8 ZL		:1;
	uint8 ZH		:1;
	uint8 IA		:1;
	uint8 Reserved	:1;
}Ax_Sensor_Int1_Src;

typedef struct
{
	uint8 THS		:7;
	uint8 Reserved	:1;
}Ax_Sensor_Int1_Ths;

typedef	struct
{
	uint8 Duration	:7;
	uint8 Reserved	:1;
}Ax_Sensor_Int1_Duration;

typedef struct
{
	uint8 XLIE		:1;
	uint8 XHIE		:1;
	uint8 YLIE		:1;
	uint8 YHIE		:1;
	uint8 ZLIE		:1;
	uint8 ZHIE		:1;
	uint8 AOI_6D	:2;
}Ax_Sensor_Int2_Cfg;

typedef struct
{
	uint8 XL		:1;
	uint8 XH		:1;
	uint8 YL		:1;
	uint8 YH		:1;
	uint8 ZL		:1;
	uint8 ZH		:1;
	uint8 IA		:1;
	uint8 Reserved	:1;
}Ax_Sensor_Int2_Src;

typedef struct
{
	uint8 THS		:7;
	uint8 Reserved	:1;
}Ax_Sensor_Int2_Ths;

typedef	struct
{
	uint8 Duration	:7;
	uint8 Reserved	:1;
}Ax_Sensor_Int2_Duration;

typedef	struct
{
	uint8 RW	:1;
	uint8 MS	:1;
	uint8 ADDR	:6;
}Ax_Sensor_SPI_Cfg;


typedef union
{
	Ax_Sensor_Ctrl_Reg1		Ctrl_Reg1;
	Ax_Sensor_Ctrl_Reg2		Ctrl_Reg2;
	Ax_Sensor_Ctrl_Reg3		Ctrl_Reg3;
	Ax_Sensor_Ctrl_Reg4		Ctrl_Reg4;
	Ax_Sensor_Ctrl_Reg5		Ctrl_Reg5;
	Ax_Sensor_Status_Reg	Status_Reg;
	Ax_Sensor_Int1_Cfg		Int1_Cfg;
	Ax_Sensor_Int1_Src		Int1_Src;
	Ax_Sensor_Int1_Ths		Int1_Ths;
	Ax_Sensor_Int1_Duration	Int1_Duration;
	Ax_Sensor_Int2_Cfg		Int2_Cfg;
	Ax_Sensor_Int2_Src		Int2_Src;
	Ax_Sensor_Int2_Ths		Int2_Ths;
	Ax_Sensor_Int2_Duration	Int2_Duration;
	uint8					byte;
}Ax_Sensor_Reg;

typedef enum
{
	POWER_DOWN=0,
	NORMAL_MODE =1,
	LOW_POWER_0_5HZ,
	LOW_POWER_1HZ,
	LOW_POWER_2HZ,
	LOW_POWER_5HZ,
	LOW_POWER_10HZ
}Ax_Sensor_PM;

typedef enum
{
	NORMAL_MODE_50HZ =0,
	NORMAL_MODE_100HZ=1,
	NORMAL_MODE_400HZ,
	NORMAL_MODE_1000HZ
}Ax_Senor_DR;

typedef enum
{
	AX_NORMAL_BOOT =0,
	MEMORY_BOOT
}Ax_Sensor_BM;

typedef enum
{
	AX_NORMAL_MODE =0,
	REFERENCE_MODE
}Ax_Sensor_HPM;

typedef enum
{
	INTERNAL_FILTER_BYPASS =0,
	INTERNAL_FILTER
}Ax_Sensor_FDS;

typedef enum
{
	AX_SENS_HP_OFF = 0,
	AX_SENS_HP_INT1_ON,
	AX_SENS_HP_INT2_ON,
	AX_SENS_HP_INT1_INT2_ON,
}Ax_Sensor_HPen;



typedef enum
{
	HP_FILTER_CUT_OFF_8HZ =0,
	HP_FILTER_CUT_OFF_16HZ,
	HP_FILTER_CUT_OFF_32HZ,
	HP_FILTER_CUT_OFF_64HZ
}Ax_Sensor_HPCF;

typedef enum
{
	INTERRUPT_SOURCE=0,
	INTERRUPT_1_OR_2_SRC,
	DATA_READY,
	BOOT_RUNNING
}Ax_Sensor_INT_CFG;

typedef enum
{
	AX_SENS_INTX_PULSED = 0,
	AX_SENS_INTX_LATCHED
}Ax_Sensor_Lir;

typedef enum
{
	PUSH_PULL	=	0,
	OPEN_DRAIN	=	1
}Ax_Sensor_PP_OD;



typedef enum
{
	INT_ACTIVE_HIGH	= 0,
	INT_ACTIVE_LOW
}Ax_Sensor_IHL;


/*	CTRL REG4	*/
typedef enum
{
	AX_SENS_UPDATED = 0,
	AX_SENS_NOT_UPDTAED
}Ax_Sensor_BDU;

typedef enum
{
	AX_SENS_LSB = 0,
	AX_SENS_MSB
}Ax_Sensor_BLE;

typedef enum
{
	FULL_SCALE_2G	= 0,
	FULL_SCALE_4G	= 1,
	FULL_SCALE_8g	= 3
}Ax_Sensor_FS;

typedef enum
{
	AX_SENS_ST_PLUS = 0,
	AX_SENS_ST_MINUS
}Ax_Sensor_STsign;

typedef enum
{
	AX_SENS_ST_DISABLE	= 0,
	AX_SENS_ST_ENABLE
}Ax_Sensor_STE;

typedef enum
{
	AX_SENS_SPI_4WIRE	= 0,
	AX_SENS_SPI_3WIRE
}Ax_Sensor_SIM;

/*	CTRL REG5	*/

typedef enum
{
	SLEEP_TO_WAKE_FUNC_DISABLE 	= 0,
	SLEEP_TO_WAKE_FUNC_ENABLE	= 3
}Ax_Sensor_TurnOn;

/*	INT1 CFG	*/

typedef enum
{
	OR_COMBINATION		= 0,
	MOVEMENT,
	AND_COMBINATNION,
	POSION 				= 3
}Ax_Sensor_INT_6D;

typedef struct {
	uint8 int_xlie	: 1;
	uint8 int_xhie	: 1;
	uint8 int_ylie	: 1;
	uint8 int_yhie	: 1;
	uint8 int_zlie	: 1;
	uint8 int_zhie	: 1;
} INT_TH_LEVEL;






//extern uint8 Ax_Sensor_Read(uint8 addr);
//
//extern void ax_read(void);
//
//extern int gsensor_axis_xen_set(uint8 value);
//
//extern uint8 spi_test;

/*	extern Functions	*/
extern int gsensor_device_id_get(uint8 *data);
extern int gsensor_axis_xen_set(uint8 value);
extern int gsensor_axis_yen_set(uint8 value);
extern int gsensor_axis_zen_set(uint8 value);
extern int gsensor_power_mode_set(Ax_Sensor_PM value);
extern int gsensor_data_rate_set(Ax_Senor_DR value);
extern int gsensor_boot_mode_set(Ax_Sensor_BM value);
extern int gsensor_HP_filter_mode_set(Ax_Sensor_HPM value);
extern int gsensor_internal_filter_set(Ax_Sensor_FDS value);
extern int gsensor_HPF_enable_set(Ax_Sensor_HPen value);
extern int gsensor_HPF_cutoff_set(Ax_Sensor_HPCF value);
extern int gsensor_int1_pad_set(Ax_Sensor_INT_CFG value);
extern int gsensor_int1_latch_set(Ax_Sensor_Lir value);
extern int gsensor_int2_pad_set(Ax_Sensor_INT_CFG value);
extern int gsensor_int2_latch_set(Ax_Sensor_Lir value);
extern int gsensor_pin_pad_set(Ax_Sensor_PP_OD value);
extern int gsensor_pin_polarity_set(Ax_Sensor_IHL value);
extern int gsensor_block_data_update_set(uint8 value);
extern int gsensor_data_format_set(Ax_Sensor_BLE value);
extern int gsensor_full_scale_set(Ax_Sensor_FS value);
extern int gsensor_self_test_sign_set(Ax_Sensor_STsign value);
extern int gsensor_self_test_set(Ax_Sensor_STE value);
extern int gsensor_spi_mode_set(Ax_Sensor_SIM value);
extern int gsensor_sleep_to_wakeup_set(Ax_Sensor_TurnOn value);
extern int gsensor_INT1_Int_mode_set(Ax_Sensor_INT_6D value);
extern int gsensor_INT1_threshold_level_set(INT_TH_LEVEL value);
extern int gsensor_INT1_event_get(Ax_Sensor_Int1_Src *value);
extern int gsensor_INT1_threshold_set(uint8 value);
extern int gsensor_INT1_duration_set(uint8 value);
extern int gsensor_INT2_Int_mode_set(Ax_Sensor_INT_6D value);
extern int gsensor_INT2_threshold_level_set(INT_TH_LEVEL value);
extern int gsensor_INT2_event_get(Ax_Sensor_Int2_Src *value);
extern int gsensor_INT2_threshold_set(uint8 value);
extern int gsensor_INT2_duration_set(uint8 value);

extern int gsensor_read_reg(uint8 addr, uint8 *data);
extern int gsensor_write_reg(uint8 addr, uint8 *data);




#endif /* AIS328DQ_REG_H_ */
