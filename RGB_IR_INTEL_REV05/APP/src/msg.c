/*
 * msg.c
 *
 *  Created on: 2018. 10. 17.
 *      Author: wanseok.kim
 */

#include "msg.h"
#include "judge.h"
#include <time.h>

void initMassage(MSG *p)
{
	p->CAN_DB = DEFAULT;
	p->state = END_WAIT;
	p->com_m[0] = LC_Invalid;
	p->com_m[1] = 0;
	p->com_m[2] = 0;
	p->com_m[3] = 0;
	p->com_m[4] = 0;
	p->com_m[5] = 0;
	p->com_m[6] = 0;
	p->com_m[7] = 0;
	p->priority_code = initial;
	p->light_on_time = clock();//RTC 현재시간 넣기
}

void makeMassage(MSG *p, BYTE len, BYTE cmd, BYTE mode, BYTE canData)
{
	p->CAN_DB = canData;
	//p->com_m[1] = len;
	//p->com_m[2] = cmd;
	//p->com_m[3] = mode;
	p->com_m[0] = checkImageData(canData); //CCT값 입력 0~4
}
