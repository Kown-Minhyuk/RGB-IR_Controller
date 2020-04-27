/*
 * Vadc.c
 *
 *  Created on: 2019. 10. 24.
 *      Author: junseok.lee
 */

#include "Vadc.h"

App_VadcAutoScan g_VadcAutoScan; /**< \brief Demo information */

uint8 batt_voltage = 0;
uint8 EMG_Voltage = 0;

void VadcAutoScan_init(void)
{
    /* VADC Configuration */

    /* create configuration */
    IfxVadc_Adc_Config adcConfig;
    IfxVadc_Adc_initModuleConfig(&adcConfig, &MODULE_VADC);

    adcConfig.supplyVoltage = IfxVadc_LowSupplyVoltageSelect_3V;

    /* initialize module */
    IfxVadc_Adc_initModule(&g_VadcAutoScan.vadc, &adcConfig);

    /* create group config */
    IfxVadc_Adc_GroupConfig adcGroupConfig;
    IfxVadc_Adc_initGroupConfig(&adcGroupConfig, &g_VadcAutoScan.vadc);

    /* with group 1 */
    adcGroupConfig.groupId = IfxVadc_GroupId_1;
    adcGroupConfig.master  = adcGroupConfig.groupId;

    /* enable scan source */
    adcGroupConfig.arbiter.requestSlotScanEnabled = TRUE;

    /* enable auto scan */
    adcGroupConfig.scanRequest.autoscanEnabled = TRUE;

    /* enable all gates in "always" mode (no edge detection) */
    adcGroupConfig.scanRequest.triggerConfig.gatingMode = IfxVadc_GatingMode_always;

    /* initialize the group */
    /*IfxVadc_Adc_Group adcGroup;*/    //declared globally
    IfxVadc_Adc_initGroup(&g_VadcAutoScan.adcGroup, &adcGroupConfig);
}



uint8 calc_batt_voltage(uint32 volt)
{
	uint8 dc_voltage = 0;
	volt = (volt * 290); 		/* Q15	((3.3V*242)/(4096*22))*2^15  */
	dc_voltage = (uint8)(((uint32)volt*10)>>15); 	/* batt_voltage*10	*/

	return  dc_voltage;
}

void Adc_Scan(void)
{
	uint32 adc_voltage = 0;

	uint32 chnIx;
	IfxVadc_Adc_ChannelConfig adcChannelConfig[3];
	IfxVadc_Adc_Channel       adcChannel[3];

	chnIx = 0;
	IfxVadc_Adc_initChannelConfig(&adcChannelConfig[chnIx], &g_VadcAutoScan.adcGroup);
	adcChannelConfig[chnIx].channelId      = (IfxVadc_ChannelId)(chnIx);
	adcChannelConfig[chnIx].resultRegister = (IfxVadc_ChannelResult)(chnIx);  /* use dedicated result register */

	/* initialize the channel */
	IfxVadc_Adc_initChannel(&adcChannel[chnIx], &adcChannelConfig[chnIx]);

	/* add to scan */
	unsigned channels = (1 << adcChannelConfig[chnIx].channelId);
	unsigned mask     = channels;
	IfxVadc_Adc_setScan(&g_VadcAutoScan.adcGroup, channels, mask);


    /* start autoscan */
    IfxVadc_Adc_startScan(&g_VadcAutoScan.adcGroup);

    unsigned     group   = adcChannel[chnIx].group->groupId;
    unsigned     channel = adcChannel[chnIx].channel;

    /* wait for valid result */
    Ifx_VADC_RES conversionResult;

    do
    {
        conversionResult = IfxVadc_Adc_getResult(&adcChannel[chnIx]);
    } while (!conversionResult.B.VF);

    adc_voltage = conversionResult.B.RESULT;
    batt_voltage = calc_batt_voltage(adc_voltage);



}

void EMG_Volt_Scan(void)
{
	uint32 adc_voltage = 0;

	uint32 chnIx;
	IfxVadc_Adc_ChannelConfig adcChannelConfig[3];
	IfxVadc_Adc_Channel       adcChannel[3];

	chnIx = 1;
	IfxVadc_Adc_initChannelConfig(&adcChannelConfig[chnIx], &g_VadcAutoScan.adcGroup);
	adcChannelConfig[chnIx].channelId      = (IfxVadc_ChannelId)(chnIx);
	adcChannelConfig[chnIx].resultRegister = (IfxVadc_ChannelResult)(chnIx);  /* use dedicated result register */

	/* initialize the channel */
	IfxVadc_Adc_initChannel(&adcChannel[chnIx], &adcChannelConfig[chnIx]);

	/* add to scan */
	unsigned channels = (1 << adcChannelConfig[chnIx].channelId);
	unsigned mask     = channels;
	IfxVadc_Adc_setScan(&g_VadcAutoScan.adcGroup, channels, mask);


    /* start autoscan */
    IfxVadc_Adc_startScan(&g_VadcAutoScan.adcGroup);

    unsigned     group   = adcChannel[chnIx].group->groupId;
    unsigned     channel = adcChannel[chnIx].channel;

    /* wait for valid result */
    Ifx_VADC_RES conversionResult;

    do
    {
        conversionResult = IfxVadc_Adc_getResult(&adcChannel[chnIx]);
    } while (!conversionResult.B.VF);

    adc_voltage = conversionResult.B.RESULT;
    EMG_Voltage = calc_batt_voltage(adc_voltage);

}
