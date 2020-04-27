/*
 * Gtm.h
 *
 *  Created on: 2019. 9. 24.
 *      Author: junseok.lee
 */

#ifndef APP_INC_GTM_H_
#define APP_INC_GTM_H_

#include "swplatform.h"
#include "Gtm/Tom/Timer/IfxGtm_Tom_Timer.h"
#include "SysSe/Bsp/Bsp.h"
#include "ConfigurationIsr.h"


/** \brief Application information */
typedef struct
{
    struct
    {
        float32 gtmFreq;
        float32 gtmGclkFreq;
    }info;
    struct
    {
        IfxGtm_Tom_Timer timerOneMs;        /**< \brief Timer driver */
    }drivers;
    struct
    {
        uint32 slotOneMs;
        uint32 ledtimercnt;
    }isrCounter;
} App_GtmTomTimer;



/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

extern App_GtmTomTimer g_GtmTomTimer;
extern void GtmTomTimer_init(void);
extern uint16 LED_Timer;

#endif /* APP_INC_GTM_H_ */
