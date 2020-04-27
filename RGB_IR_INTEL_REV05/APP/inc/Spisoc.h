/*
 * Spisoc.h
 *
 *  Created on: 2019. 10. 7.
 *      Author: junseok.lee
 */

#ifndef APP_INC_SPISOC_H_
#define APP_INC_SPISOC_H_

#include "util.h"

//uint8 veh_gear_disp = 0 ;

/* 주차모드 판단 관련 정의 추후 이동 	*/
#define PARKING 0
#define DRIVING 1
#define INVALID 2
#define ACC_OFF 0 //4.0V 미만
#define ACC_ON 1 //6.0V 이상
extern void Parking_Driving_Mode_Judgement(uint8 *acc, uint8 *Batt_SoC, uint8 *Bat_SoC, uint8 *Cur_Vehicle_State, uint8 *DVRS_Prk_Opr_Inform);



typedef struct
{
	uint8 IFX_ALIGN(64) spi_data_tx[16];
	uint8 IFX_ALIGN(64) spi_data_rx[16];

	uint8 spi_data_field_tx[16];

	uint8 spi_data_rx_2[32];


}App_spi_msg;

typedef struct
{
	uint8 Mcu_ver	:4;
	uint8 Wakup_src	:2;
	uint8 CurVehicleState	:2;
}DATA0_STRUCT;

typedef struct
{
	uint8 Veh_ACC		:1;
	uint8 Veh_bat_out	:1;
	uint8 Emg_mode		:1;
	uint8 Impact_rec	:1;
	uint8 Soc_off_req	:1;
	uint8 Rear_Cam_input:2;

}DATA4_STRUCT;

typedef struct
{
	uint8 SoC_OFF_Flag	:1;
	uint8 PRK_AX_SENS	:3;
	uint8 DRV_AX_SENS	:3;
	uint8 Reserved		:1;

}RX_DATA0;


//typedef struct
//{
//	uint8 Veh_ACC			:1;
//	uint8 Veh_Reverse		:1;
//	uint8 CurVehicleState	:2;
//	uint8 Reserved			:4;
//
//}DATA5_STRUCT;

typedef struct
{
	uint8 VEH_GEAR		:4;
	uint8 VEH_BRAKE 	:2;
	uint8 RESERVED		:2;

}DATA5_STRUCT;


typedef union
{
	DATA0_STRUCT data0;
	DATA4_STRUCT data4;
	DATA5_STRUCT data5;
	RX_DATA0	rx_data0;
	uint8	byte;

}soc_spi_msg_union;



extern App_spi_msg g_spi_msg;
extern uint8 veh_gear_disp;


extern soc_spi_msg_union soc_spi_union;

extern uint8 Cur_Veh_Stat;

extern uint8 Prk_Ax_Sens_set_value;
extern uint8 Drv_Ax_Sens_set_value;
extern uint8 DVRS_Sub_Bat_Status;

extern uint8 gu8_SOC_MCU_PRK_Setting;

extern uint8 veh_break;

extern void Spi_transfer_soc(void);
extern void get_veh_info(void);
extern void init_spi_msg(void);


extern void recieve_spi_msg(void);

#endif /* APP_INC_SPISOC_H_ */
