/*
 * util.c
 *
 *  Created on: 2019. 7. 29.
 *      Author: junseok.lee
 */

#include "util.h"
#include "IfxStm_ActInit.h"

Ifx_STM *stmSfr1 = &MODULE_STM0;

uint32 Fsys_temp = 0;
uint32 sam_temp = 0;

uint32 c_timer = 0;



void delay_ms(uint16 ms)
{


	static volatile uint32 Fsys;
	static volatile uint32 currentTimer;
	static volatile uint32 TimeConst;
	static volatile uint32 sampleTime;

	Fsys_temp = IfxStm_getFrequency(stmSfr1);
	Fsys = IfxStm_getFrequency(stmSfr1);
	TimeConst = Fsys / (1000 / ms);
	//TimeConst = Fsys / (8000 / ms);
	//TimeConst = Fsys / ms;
	sampleTime = IfxStm_getLower(stmSfr1);
	sam_temp = IfxStm_getLower(stmSfr1);


	while(1)
	{
		c_timer = IfxStm_getLower(stmSfr1);
		currentTimer = IfxStm_getLower(stmSfr1);
		if( currentTimer - sampleTime >= TimeConst )
		{
			sampleTime += TimeConst;
			sam_temp += TimeConst;
			break;
		}

	}


}
