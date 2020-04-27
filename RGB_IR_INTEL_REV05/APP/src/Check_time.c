/*
 * Check_time.c
 *
 *  Created on: 2018. 10. 21.
 *      Author: wanseok.kim
 */

#include "Check_time.h"

void delay(CLOCK_TIME n)
{
	CLOCK_TIME start = (CLOCK_TIME)clock();
	while((((CLOCK_TIME)clock()-start)/1000.0) < n);
}

double compareTime(CLOCK_TIME start)
{
	CLOCK_TIME end;
	end = (CLOCK_TIME)clock(); //RTC 현재시간 넣기
	return ((end-start)/1000.0);
}
