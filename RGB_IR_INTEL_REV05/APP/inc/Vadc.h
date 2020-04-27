/*
 * Vadc.h
 *
 *  Created on: 2019. 10. 24.
 *      Author: junseok.lee
 */

#ifndef APP_INC_VADC_H_
#define APP_INC_VADC_H_

#include <Vadc/Std/IfxVadc.h>
#include <Vadc/Adc/IfxVadc_Adc.h>


typedef struct
{
    IfxVadc_Adc vadc; /* VADC handle */
    IfxVadc_Adc_Group adcGroup;
} App_VadcAutoScan;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
extern App_VadcAutoScan g_VadcAutoScan;

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/


extern void VadcAutoScan_init(void);
extern void Adc_Scan(void);
extern void EMG_Volt_Scan(void);

extern uint8 batt_voltage;
extern uint8 EMG_Voltage;


#endif /* APP_INC_VADC_H_ */
