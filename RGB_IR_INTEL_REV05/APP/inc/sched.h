/*
 * sched.h
 *
 *  Created on: 2019. 10. 23.
 *      Author: junseok.lee
 */

#ifndef APP_INC_SCHED_H_
#define APP_INC_SCHED_H_

#include "Cpu/Std/Ifx_Types.h"

//  typedef enum { COLD_START             = 0x0001,
//                 ECU_POWER_UP_TESTS     = 0x0002,
//                 WARM_START             = 0x0004,
//                 SYSTEM_POWER_UP_TESTS  = 0x0008,
//                 NORMAL_OPERATION       = 0x0010,
//                 SOFT_SHUTDOWN          = 0x0020,
//                 POWER_DOWN_TESTS       = 0x0040,
//                 POWER_DOWN             = 0x0080,
//                 SYSTEM_FAILURE         = 0x0083,
//                 MAINTENANCE            = 0x0086,
//                 SAFE_MAINTENANCE       = 0x008C,
//                 UNINITIALISED          = 0x0098,
//                 LIMITED_SYSTEM_FAILURE = 0x00B0} SYSTEM_MODE_TYPE;

typedef enum
{
	COLD_START		=	0,
	SYSTEM_OFF		=	1,
	GUI_READY		=	2,
	DRIVE_MODE		=	3,
	PARKING_MODE	= 	4,
	GUI_MODE		=	5

}OPERATING_MODE_TYPE;

//uint8 Timeflag_1ms;
//uint8 Timeflag_10ms;
//uint8 Timeflag_100ms;
//uint8 Timeflag_200ms;
//uint8 Timeflag_500ms;
//uint8 Timeflag_1000ms;
//uint8 Timeflag_1010ms;
//uint8 Timeflag_1030ms;
//uint8 Timeflag_1050ms;





extern OPERATING_MODE_TYPE OPERATING_MODE;


extern void Scheduler_task(void);

extern uint8 Timeflag_1ms;
extern uint8 Timeflag_10ms;
extern uint8 Timeflag_100ms;
extern uint8 Timeflag_200ms;
extern uint8 Timeflag_500ms;
extern uint8 Timeflag_1000ms;
extern uint8 Timeflag_1010ms;
extern uint8 Timeflag_1030ms;
extern uint8 Timeflag_1050ms;




#endif /* APP_INC_SCHED_H_ */
