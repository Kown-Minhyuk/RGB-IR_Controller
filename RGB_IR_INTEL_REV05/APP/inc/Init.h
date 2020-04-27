/*
 * Init.h
 *
 *  Created on: 2019. 7. 19.
 *      Author: junseok.lee
 */

#ifndef APP_INIT_H_
#define APP_INIT_H_

#include "PinMapper/aurix_pin_mappings.h"


typedef struct
{
    float32 sysFreq;                /**< \brief Actual SPB frequency */
    float32 cpuFreq;                /**< \brief Actual CPU frequency */
    float32 pllFreq;                /**< \brief Actual PLL frequency */
    float32 stmFreq;                /**< \brief Actual STM frequency */
} AppInfo;

/** \brief Application information */
typedef struct
{
    AppInfo info;                               /**< \brief Info object */
} App_Cpu0;


extern void Power_init(void);
extern void led_test(void);
extern void init_led(void);
extern void Power_init_SoC(void);
extern void Power_Off_SoC(void);
extern void Power_Reset_SoC(void);

#endif /* APP_INIT_H_ */
