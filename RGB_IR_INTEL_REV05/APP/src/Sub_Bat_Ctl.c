/*
 * Sub_Bat_Ctl.c
 *
 *  Created on: 2019. 12. 5.
 *      Author: junseok.lee
 */

#include "AsclinLinDemo.h"
#include "Sub_Bat_Ctl.h"

uint8 bms_info_01 = 0x12;
uint8 bms_info_02 = 0x13;
uint8 bms_info_03 = 0x14;

uint8 bms_info_12_data[8]={0,};
uint8 bms_info_13_data[8]={0,};
uint8 bms_info_14_data[8]={0,};
uint8 bms_info_15_data[8]={0,};

uint8 certi_send_data[8] = {0x12,0x34,0x56,0x78,0x91,0xA2,0xB3,0xC4};
uint8 certi_receive_data[8]={0,};
uint8 debug_standby_operation_data[8]={0,};
uint8 debug_discharge_operation_data[8]={0,};
uint8 debug_charge_operation_data[8]={0,};

uint8 sub_batt_status = 0x3;

void AsclinLinDemo_certification(void){
	/* set the id byte */
	uint8 certi_Id = 0x10;
	uint8 certi_check_Id = 0x11;
	/* prepare data to transmit and receive */
	g_AsclinLin.size = 8;


    IfxAsclin_Lin_sendHeader(&g_AsclinLin.drivers.lin, &certi_Id);
    delay_ms(20);
	/* BMS.CERTI */
    IfxAsclin_Lin_sendHeader(&g_AsclinLin.drivers.lin, &certi_Id);                                             /* send header */
    if (g_AsclinLin.drivers.lin.acknowledgmentFlags.txHeaderEnd == 1)                                      /* if the header is been transmitted succesfully */
		{
			/* Send Key data */
			IfxAsclin_Lin_sendResponse(&g_AsclinLin.drivers.lin, certi_send_data, g_AsclinLin.size);        /* send response */
		}
    delay_ms(20);

    /* BMS.CERTI.CHECK */
    if (g_AsclinLin.drivers.lin.acknowledgmentFlags.txResponseEnd == 1) /* if the response is been transmitted succesfully */
    {
    	Lin_send_Header_receive_Response(&g_AsclinLin.drivers.lin, &certi_check_Id, certi_receive_data, g_AsclinLin.size);
    }
}

void Sub_Batt_Wake_up(void)
{
	uint8 certi_Id = 0x10;
	IfxAsclin_Lin_sendHeader(&g_AsclinLin.drivers.lin, &certi_Id); //LIN bus wake up
}

void get_BMS_INFO_01(void)
{
	Lin_send_Header_receive_Response(&g_AsclinLin.drivers.lin, &bms_info_01, bms_info_12_data, 8);
}

void get_BMS_INFO_02(void)
{
	Lin_send_Header_receive_Response(&g_AsclinLin.drivers.lin, &bms_info_02, bms_info_13_data, 8);
}

void get_BMS_INFO_03(void)
{
	Lin_send_Header_receive_Response(&g_AsclinLin.drivers.lin, &bms_info_03, bms_info_14_data, 8);
}





void get_Battery_inf(void){
	/* prepare data to transmit and receive */
	g_AsclinLin.size = 8;
	uint8 certi_Id = 0x10;

	IfxAsclin_Lin_sendHeader(&g_AsclinLin.drivers.lin, &certi_Id); //LIN bus wake up
	delay_ms(10);
	/* BMS.INFO_01 */
	Lin_send_Header_receive_Response(&g_AsclinLin.drivers.lin, &bms_info_01, bms_info_12_data, g_AsclinLin.size);
	delay_ms(20);
	/* BMS.INFO_02 */
	Lin_send_Header_receive_Response(&g_AsclinLin.drivers.lin, &bms_info_02, bms_info_13_data, g_AsclinLin.size);
	delay_ms(20);
	/* BMS.INFO_03 */
	Lin_send_Header_receive_Response(&g_AsclinLin.drivers.lin, &bms_info_03, bms_info_14_data, g_AsclinLin.size);

}

uint8 get_battery_discharging_time(uint8 _bat_SoC){
	uint8 ret=0;

	if(0xD<=_bat_SoC && _bat_SoC<=0x13) {
		ret=1;
	}
	else if(0x14<=_bat_SoC && _bat_SoC<=0x1B){
		ret=2;
	}
	else if(0x1C<=_bat_SoC && _bat_SoC<=0x22){
		ret=3;
	}
	else if(0x23<=_bat_SoC && _bat_SoC<=0x2A){
		ret=4;
	}
	else if(0x2B<=_bat_SoC && _bat_SoC<=0x31){
		ret=5;
	}
	else if(0x32<=_bat_SoC && _bat_SoC<=0x38){
		ret=6;
	}
	else if(0x39<=_bat_SoC && _bat_SoC<=0x40){
		ret=7;
	}
	else if(0x41<=_bat_SoC && _bat_SoC<=0x47){
		ret=8;
	}
	else if(0x48<=_bat_SoC && _bat_SoC<=0x4F){
		ret=9;
	}
	else if(0x50<=_bat_SoC && _bat_SoC<=0x64){
		ret=0xA;
	}
	delay_ms(1);
	return ret;
}


void start_Battery_Charge(void){
	uint8 certi_Id = 0x10;
	uint8 operation_Id = 0x15;
	uint8 i;

	//clear send data
	for(i=0; i<8; i++){
		debug_charge_operation_data[i]=0;
	}

	debug_charge_operation_data[0]=0x01;
	IfxAsclin_Lin_sendHeader(&g_AsclinLin.drivers.lin, &certi_Id); //LIN bus wake up
	delay_ms(1);

	//배터리 충전 시작
	IfxAsclin_Lin_sendHeader(&g_AsclinLin.drivers.lin, &operation_Id);                                             /* send header */
	if (g_AsclinLin.drivers.lin.acknowledgmentFlags.txHeaderEnd == 1)                                      /* if the header is been transmitted succesfully */
	{
		/* Send operation command */
		IfxAsclin_Lin_sendResponse(&g_AsclinLin.drivers.lin, debug_charge_operation_data, g_AsclinLin.size);        /* send response */
	}
	delay_ms(1);
}


void start_Battery_Discharge(uint8 _bat_SoC){
	uint8 certi_Id = 0x10;
	uint8 operation_Id = 0x15;
	uint8 i;
	uint8 discharge_hour=0x00;

	discharge_hour=get_battery_discharging_time(_bat_SoC);
	//clear send data
	for(i=0; i<8; i++){
		debug_discharge_operation_data[i]=0;
	}

	debug_discharge_operation_data[0]=0x02;
	debug_discharge_operation_data[1]=discharge_hour;
	IfxAsclin_Lin_sendHeader(&g_AsclinLin.drivers.lin, &certi_Id); //LIN bus wake up
	delay_ms(1);

	//배터리 충전 시작
	IfxAsclin_Lin_sendHeader(&g_AsclinLin.drivers.lin, &operation_Id);                                             /* send header */
	if (g_AsclinLin.drivers.lin.acknowledgmentFlags.txHeaderEnd == 1)                                      /* if the header is been transmitted succesfully */
	{
		/* Send operation command */
		IfxAsclin_Lin_sendResponse(&g_AsclinLin.drivers.lin, debug_discharge_operation_data, g_AsclinLin.size);        /* send response */
	}
	delay_ms(1);
}


void standby_Battery(void){
	uint8 certi_Id = 0x10;
	uint8 operation_Id = 0x15;
	uint8 i;

	//clear send data
	for(i=0; i<8; i++){
		debug_standby_operation_data[i]=0;
	}

	debug_standby_operation_data[0]=0x0;
	IfxAsclin_Lin_sendHeader(&g_AsclinLin.drivers.lin, &certi_Id); //LIN bus wake up
	delay_ms(1);

	//배터리 충전 시작
	IfxAsclin_Lin_sendHeader(&g_AsclinLin.drivers.lin, &operation_Id);                                             /* send header */
	if (g_AsclinLin.drivers.lin.acknowledgmentFlags.txHeaderEnd == 1)                                      /* if the header is been transmitted succesfully */
	{
		/* Send operation command */
		IfxAsclin_Lin_sendResponse(&g_AsclinLin.drivers.lin, debug_standby_operation_data, g_AsclinLin.size);        /* send response */
	}
	delay_ms(1);
}



uint8 Sub_Batt_Control(uint8 sb_control)
{
	static uint8 sb_stat = 0;
	switch(sb_control)
	{
	case SUB_BATT_STANDBY :
		if(sub_batt_status==SUB_BATT_STANDBY)
		{
			break;
		}
		standby_Battery();
		sb_stat = SUB_BATT_STANDBY;
		break;
	case SUB_BATT_CHARGE :
		if(sub_batt_status==SUB_BATT_CHARGE)
		{
			break;
		}
		start_Battery_Charge();
		sb_stat = SUB_BATT_CHARGE;
		break;
	case SUB_BATT_DISCHARGE :
		if(sub_batt_status==SUB_BATT_DISCHARGE)
		{
			break;
		}
		start_Battery_Discharge(bms_info_13_data[0]);
		sb_stat = SUB_BATT_DISCHARGE;
		break;
	}

	return sb_stat;

}

uint8 check_Sub_Batt_Status(void)
{
	uint8 time = 0;
	time = get_battery_discharging_time(bms_info_13_data[0]);
	if(time==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
