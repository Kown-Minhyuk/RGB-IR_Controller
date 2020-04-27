/*
 * msg.h
 *
 *  Created on: 2018. 10. 16.
 *      Author: wanseok.kim
 */

#ifndef MSG_H_
#define MSG_H_

#include "Code_info.h"

typedef long unsigned int PACKET;
typedef unsigned int DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef int _priority_num;
typedef unsigned long CLOCK_TIME;

typedef struct msg
{
	_priority_num priority_code;
	CLOCK_TIME light_on_time;
	BYTE CAN_DB;				// /* CAN data info */ in Code_info.h file document.
	BYTE state;					// 0x00 : END or WAIT, 0x01 : DOING
	BYTE com_m[8];				// DATA(8BYTE)
}MSG;

#define LEN(x)	(sizeof(x)/sizeof(x[0]))

void initMassage(MSG *p);
void makeMassage(MSG *p, BYTE len, BYTE cmd, BYTE mode, BYTE canData);

//static BYTE imageCode[9] = { Default, Door, Brake, Gear_N, Turn_L, Turn_R, Speed, ACC_OFF, Emergency };

#endif /* MSG_H_ */
