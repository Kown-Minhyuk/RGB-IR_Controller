/*
 * sched.c
 *
 *  Created on: 2019. 10. 7.
 *      Author: junseok.lee
 */


#include "sched.h"
#include "util.h"
#include "PinMapper/aurix_pin_mappings.h"
#include "ScuCcu.h"
#include "Spisoc.h"

#include "ScuEru.h"
#include "Ccan.h"

#include "Standby_mode.h"
#include "Init.h"
#include "Power_mode.h"
#include "Sub_Bat_Ctl.h"
#include "G_Sensor.h"
#include "AsclinLinDemo.h"

#define C_CAN_INH	IfxPort_getPinState(&MODULE_P11,4)

Ifx_STM *stmSfr5 = &MODULE_STM0;


OPERATING_MODE_TYPE OPERATING_MODE;

//uint8 OPERATING_MODE = 0;
Ifx_SCU *scu_reset = &MODULE_SCU;
uint8 ent_park_mode_flag = 1;
uint8 dvrs_mode_flag = 0;

uint8 recording_close_flag = 0;
uint8 dvrs_menu_close_flag = 0;

uint8 prk_condition = 1;

uint32 can_sleep_cnt = 0;
uint32 pre_can_sleep_cnt = 0;
uint32 can_sleep_time_cont = 20000000;	/* 1s maybe? */

uint32 can_sleep_timer = 180;

uint32 can_sleep_cnt_sec = 0;

uint8 gu8_prk_can_flag = 0;

uint8 mcan_error_flag = 0;
uint8 end_flag = 0;

uint8 Timeflag_1ms;
uint8 Timeflag_10ms;
uint8 Timeflag_100ms;
uint8 Timeflag_200ms;
uint8 Timeflag_500ms;
uint8 Timeflag_1000ms;
uint8 Timeflag_1010ms;
uint8 Timeflag_1030ms;
uint8 Timeflag_1050ms;






void Task_1ms(void)
{

}
void Task_10ms(void)
{
	Recieve_Ccan_10ms();
	get_veh_info();
	spi_put_msg();
	Qspi_Dma_transfer();

}
void Task_100ms(void)
{

}
void Task_200ms(void)
{

}
void Task_500ms(void)
{

}
void Task_1000ms(void)
{
	IfxPort_togglePin(&MODULE_P00,0);
}

void Task_1010ms(void)
{
}

void Task_1030ms(void)
{
}

void Task_1050ms(void)
{
}

void Scheduler_task(void)
{
	if(Timeflag_1ms == TRUE)
	{
		Task_1ms();
		Timeflag_1ms = FALSE;
	}
	if(Timeflag_10ms == TRUE)
	{
		Task_10ms();
		Timeflag_10ms = FALSE;
	}
	if(Timeflag_100ms == TRUE)
	{
		Task_100ms();
		Timeflag_100ms = FALSE;
	}
	if(Timeflag_200ms == TRUE)
	{
		Task_200ms();
		Timeflag_200ms = FALSE;
	}
	if(Timeflag_500ms == TRUE)
	{
		Task_500ms();
		Timeflag_500ms = FALSE;
	}
	if(Timeflag_1000ms == TRUE)
	{
		Task_1000ms();
		Timeflag_1000ms = FALSE;
	}
	if(Timeflag_1010ms == TRUE)
	{
		Task_1010ms();
		Timeflag_1010ms = FALSE;
	}
	if(Timeflag_1030ms == TRUE)
	{
		Task_1030ms();
		Timeflag_1030ms = FALSE;
	}
	if(Timeflag_1050ms == TRUE)
	{
		Task_1050ms();
		Timeflag_1050ms = FALSE;
	}
}


