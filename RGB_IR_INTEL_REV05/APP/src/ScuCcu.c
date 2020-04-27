/*
 * ScuCcu.c
 *
 *  Created on: 2019. 10. 23.
 *      Author: junseok.lee
 */


#include <Scu/Std/IfxScuCcu.h>
#include "ScuCcu.h"



void Init_Scu_Reg(void)
{
//	IfxCpu_disableInterrupts();
	Ifx_SCU *scu_temp = &MODULE_SCU;
//
	IfxScuWdt_clearCpuEndinit(IfxScuWdt_getSafetyWatchdogPassword());
	IfxScuWdt_clearSafetyEndinit(IfxScuWdt_getSafetyWatchdogPassword());
//
//	scu_temp->IOCR.B.PC0 = 2;
//
	scu_temp->RSTCON.B.ESR0 = 1;
	//scu_temp->RSTCON.B.ESR1 = 0;
	//scu_temp->PMSWCR0.B.ESR0TRIST = 1;

	scu_temp->RSTCON.B.SMU = 0;

//
	IfxScuWdt_setCpuEndinit(IfxScuWdt_getSafetyWatchdogPassword());
	IfxScuWdt_setSafetyEndinit(IfxScuWdt_getSafetyWatchdogPassword());


}
