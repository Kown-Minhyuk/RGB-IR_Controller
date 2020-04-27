/*
 * Gtm.c
 *
 *  Created on: 2019. 9. 24.
 *      Author: junseok.lee
 */
#include "Gtm.h"
#include "Spisoc.h"

#include "Ccan.h"
#include "sched.h"
#include "Sub_Bat_Ctl.h"
#include "AsclinLinDemo.h"
#include "Qspi_Dma.h"

App_GtmTomTimer g_GtmTomTimer; /**< \brief Demo information */

IFX_INTERRUPT(ISR_Timer_1ms, 0, ISR_PRIORITY_TIMER_1MS);

uint16 LED_Timer = 100;

void CallBack1ms(void)
{
    if(g_GtmTomTimer.isrCounter.ledtimercnt%LED_Timer==0)
    {
        //IfxPort_togglePin(&MODULE_P00,0);
        g_GtmTomTimer.isrCounter.ledtimercnt =0;
    }

	if(g_GtmTomTimer.isrCounter.slotOneMs%1 == 0)
	{
		Timeflag_1ms = TRUE;
	}
	if(g_GtmTomTimer.isrCounter.slotOneMs%10 == 0)
	{
		Timeflag_10ms = TRUE;
	}
	if(g_GtmTomTimer.isrCounter.slotOneMs%100 == 0)
	{
		Timeflag_100ms = TRUE;
	}
	if(g_GtmTomTimer.isrCounter.slotOneMs%200 == 0)
	{
		Timeflag_200ms = TRUE;
	}
	if(g_GtmTomTimer.isrCounter.slotOneMs%500 == 0)
	{
		Timeflag_500ms = TRUE;
	}
	if(g_GtmTomTimer.isrCounter.slotOneMs%1000 == 0)
	{
		Timeflag_1000ms = TRUE;
	}
	if(g_GtmTomTimer.isrCounter.slotOneMs%1010 == 0)
	{
		Timeflag_1010ms = TRUE;
	}
	if(g_GtmTomTimer.isrCounter.slotOneMs%1030 == 0)
	{
		Timeflag_1030ms = TRUE;
	}
	if(g_GtmTomTimer.isrCounter.slotOneMs%1050 == 0)
	{
		Timeflag_1050ms = TRUE;
		g_GtmTomTimer.isrCounter.slotOneMs = 0;
	}
}


void ISR_Timer_1ms(void)
{
    IfxCpu_enableInterrupts();
    IfxGtm_Tom_Timer_acknowledgeTimerIrq(&g_GtmTomTimer.drivers.timerOneMs);
    g_GtmTomTimer.isrCounter.slotOneMs++;
    g_GtmTomTimer.isrCounter.ledtimercnt++;
    CallBack1ms();

}



void GtmTomTimer_initTimer(void)
{
    {   /* GTM TOM configuration */
        IfxGtm_Tom_Timer_Config timerConfig;
        IfxGtm_Tom_Timer_initConfig(&timerConfig, &MODULE_GTM);
        timerConfig.base.frequency       = 1000;
        timerConfig.base.isrPriority     = ISR_PRIORITY(INTERRUPT_TIMER_1MS);
        timerConfig.base.isrProvider     = ISR_PROVIDER(INTERRUPT_TIMER_1MS);
        timerConfig.base.minResolution   = (1.0 / timerConfig.base.frequency) / 1000;
        timerConfig.base.trigger.enabled = FALSE;
        timerConfig.tom                  = IfxGtm_Tom_1;
        timerConfig.timerChannel         = IfxGtm_Tom_Ch_0;
        timerConfig.clock                = IfxGtm_Tom_Ch_ClkSrc_cmuFxclk1;
        IfxGtm_Tom_Timer_init(&g_GtmTomTimer.drivers.timerOneMs, &timerConfig);

        IfxGtm_Tom_Timer_run(&g_GtmTomTimer.drivers.timerOneMs);
    }
}


void GtmTomTimer_init(void)
{
    /* disable interrupts */
    boolean  interruptState = IfxCpu_disableInterrupts();

    /** - GTM clocks */
    Ifx_GTM *gtm = &MODULE_GTM;
    g_GtmTomTimer.info.gtmFreq = IfxGtm_Cmu_getModuleFrequency(gtm);
    IfxGtm_enable(gtm);

    /* Set the global clock frequencies */
    IfxGtm_Cmu_setGclkFrequency(gtm, g_GtmTomTimer.info.gtmFreq);
    g_GtmTomTimer.info.gtmGclkFreq = IfxGtm_Cmu_getGclkFrequency(gtm);

    /** - Initialise the GTM part */
    GtmTomTimer_initTimer();

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);

    IfxGtm_Cmu_enableClocks(gtm, IFXGTM_CMU_CLKEN_FXCLK | IFXGTM_CMU_CLKEN_CLK0);
}

