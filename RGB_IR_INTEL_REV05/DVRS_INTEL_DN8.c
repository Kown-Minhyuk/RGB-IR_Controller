/*****************************************************
 *
 * DVRS_INTEL_DN8.c
 *
 * Description : Hello World in C, ANSI-style
 *
 */

#include <stdio.h>
//#include "PinMapper/aurix_pin_mappings.h"
#include "swplatform.h"

#include "G_Sensor.h"
#include "QspiCpuDemo.h"
#include "Init.h"
#include "Gtm.h"
#include "ScuEru.h"
//#include "sched.h"
#include "Ccan.h"
#include "Vadc.h"
#include "FlashDemo.h"
#include "ScuCcu.h"

#include "AsclinLinDemo.h"
#include "Sub_Bat_Ctl.h"


App_Cpu0 g_AppCpu0; /**< \brief CPU 0 global data */

int main(void)
{
    IfxScuWdt_disableCpuWatchdog (IfxScuWdt_getCpuWatchdogPassword ());
    IfxScuWdt_disableSafetyWatchdog (IfxScuWdt_getSafetyWatchdogPassword ());

    /* Initialise the application state */
    g_AppCpu0.info.pllFreq = IfxScuCcu_getPllFrequency();
    g_AppCpu0.info.cpuFreq = IfxScuCcu_getCpuFrequency(IfxCpu_getCoreIndex());
    g_AppCpu0.info.sysFreq = IfxScuCcu_getSpbFrequency();
    g_AppCpu0.info.stmFreq = IfxStm_getFrequency(&MODULE_STM0);


    /* Enable the global interrupts of this CPU */
    IfxCpu_enableInterrupts();

	/* initialize GPIO	*/
	gpio_init_pins();

	Init_Scu_Reg();

    IfxScuCcu_ActInit();
    IfxStm_ActInit(0);
    GtmTomTimer_init();


//	init_spi_msg();
    IfxQspiCpuDemo_init();
    IfxQspiDma_init();

    /*	G Sensor Initialization	*/
    init_gsensor();
    gsensor_set_sleep_mode(GSENSOR_DRV_MID ,0 );



	init_Ccan_Trans();
	init_Ccan();
	init_Ccan_msg();


	ScuEru_init();

	VadcAutoScan_init();

	IfxPort_setPinHigh(&MODULE_P11, 11);


	Power_init();

    while(1)
    {
    	Scheduler_task();


    }
}
