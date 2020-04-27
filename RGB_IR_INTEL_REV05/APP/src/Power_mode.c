/*
 * Power_mode.c
 *
 *  Created on: 2019. 11. 15.
 *      Author: junseok.lee
 */
#include "Power_mode.h"
#include "Ccan.h"


//void check_EMG_MODE(void)
//{
//	uint8 emg_mode_cnt = 0;
//	sample_time = IfxStm_getLower(stmSfr2);
//	while(IGN==1 && ACC == 0 && check_Can_sleep(&g_Ccan.drivers.canDstNode) == 1 && check_Can_sleep(&g_MulticanBasic.drivers.mcanSrcNode) == 1 )
//	{
//    	current_time = IfxStm_getLower(stmSfr2);
//		if( current_time - sample_time >= Time_const )
//		{
//			sample_time += Time_const;
//			break;
//		}
//	}
//}


int check_park_rec_mode(void)
{
	/* check the battery using the LIN	*/

	return 1;
}


//void enter_Parking_Mode(void)
//{
//	if(gu8_SOC_MCU_PRK_Setting==1)
//	{
//		/* Cond.12 주차모드 진입 조건 */
//#if defined(USE_LIN)
//		sub_batt_status = Sub_Batt_Control(SUB_BATT_DISCHARGE);
//		//start_Battery_Discharge(1);
//#endif
//
//		gsensor_set_sleep_mode(Gsensor_get_PRK_THS(Prk_Ax_Sens_set_value),0);
//
//		OPERATING_MODE = PARKING_MODE;
//
//	}
//	else
//	{
//		/*	Cond.11 주차모드 미진입 조건 */
//		/* Sub Battery Stop	*/
//#if defined(USE_LIN)
//		//standby_Battery();
//		sub_batt_status = Sub_Batt_Control(SUB_BATT_STANDBY);
//#endif
//		OPERATING_MODE = GUI_READY;
//	}
//}
