/*
 * Init.c
 *
 *  Created on: 2019. 7. 19.
 *      Author: junseok.lee
 */
#include "Init.h"
#include "util.h"

void init_led(void)
{

	IfxPort_setPinHigh(&MODULE_P00,0);

	delay_ms(300);

	IfxPort_setPinLow(&MODULE_P00,0);

	delay_ms(300);

	IfxPort_setPinHigh(&MODULE_P00,0);

	delay_ms(300);

	IfxPort_setPinLow(&MODULE_P00,0);

	delay_ms(300);

	IfxPort_setPinHigh(&MODULE_P00,0);

	delay_ms(300);

	IfxPort_setPinLow(&MODULE_P00,0);

	delay_ms(300);

}

void led_test(void)
{

	IfxPort_togglePin(&MODULE_P00,0);

	delay_ms(1000);

	//IfxPort_setPinLow(&MODULE_P00,0);

}

void Power_init_SoC(void)
{
	/*	SoC PMIC Power ON	*/
	IfxPort_setPinHigh(&MODULE_P33,7);

	/*	Wait RSMRST_B Signal	*/
	while(!(IfxPort_getPinState(&MODULE_P33, 10)==TRUE))
	{

	};

	/*	PWRBTN_B Enable	*/
	IfxPort_setPinHigh(&MODULE_P13, 3);

	/*	RESETBUTTON B Enable	*/
	IfxPort_setPinHigh(&MODULE_P33, 8);

	/*	Delay 20ms	*/
	delay_ms(20);

	/* DCDC 2~4 Enable	*/
	IfxPort_setPinHigh(&MODULE_P13, 0);
	IfxPort_setPinHigh(&MODULE_P13, 1);
	IfxPort_setPinHigh(&MODULE_P13, 2);

	/* Check the SoC Boot	*/
	while(!(IfxPort_getPinState(&MODULE_P20, 8)==TRUE))
	{
		/* SoC Boot Complete	*/
	};
}

void Power_Off_SoC(void)
{
	/* DCDC 2~4 Enable	*/
	IfxPort_setPinLow(&MODULE_P13, 0);
	IfxPort_setPinLow(&MODULE_P13, 1);
	IfxPort_setPinLow(&MODULE_P13, 2);

	/*	RESETBUTTON B Enable	*/
	IfxPort_setPinLow(&MODULE_P33, 8);

	/*	PWRBTN_B Enable	*/
	IfxPort_setPinLow(&MODULE_P13, 3);


	/*	SoC PMIC Power OFF	*/
	IfxPort_setPinLow(&MODULE_P33,7);
}

void Power_Reset_SoC(void)
{
	Power_Off_SoC();
	delay_ms(10);
	Power_init_SoC();

}

void Power_init(void)
{
	/*	5V CAP FET Enable	*/
	IfxPort_setPinHigh(&MODULE_P33,5);


	/*	DCDC Enable	*/
	IfxPort_setPinHigh(&MODULE_P33,6);

	/*	Delay 5ms	*/
	delay_ms(5);

	Power_init_SoC();


}





