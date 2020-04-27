/*
 * Ccan.c
 *
 *  Created on: 2019. 10. 7.
 *      Author: junseok.lee
 */
#include "Ccan.h"
#include "Spisoc.h"
#include "util.h"

App_Ccan_struct g_Ccan;

IfxMultican_Message Ccan_msg_2B0;
IfxMultican_Message Ccan_msg_367;
IfxMultican_Message Ccan_msg_316;
IfxMultican_Message Ccan_msg_329;

void init_Ccan_Trans(void)
{
	/*	C-CAN	*/
	/*	STB Enable	*/
	IfxPort_setPinHigh(&MODULE_P02,6);
	/*	EN Enable	*/
	IfxPort_setPinHigh(&MODULE_P14,4);

}

void sleep_Ccan_Trans(void)
{
	/*	C-CAN	*/
	/*	STB Disable	*/
	IfxPort_setPinLow(&MODULE_P02,6);
	/*	EN Enable	*/
	IfxPort_setPinHigh(&MODULE_P14,4);

}

void init_Ccan(void)
{
	/* create module config */
	    IfxMultican_Can_Config canConfig;
	    IfxMultican_Can_initModuleConfig(&canConfig, &MODULE_CAN);

	    /* initialize module */
	    IfxMultican_Can_initModule(&g_Ccan.drivers.can, &canConfig);

	    /* create CAN node config */
	    IfxMultican_Can_NodeConfig canNodeConfig;
	    IfxMultican_Can_Node_initConfig(&canNodeConfig, &g_Ccan.drivers.can);

	    canNodeConfig.baudrate = 500000;     /* 500 KBaud	*/
	    //canNodeConfig.baudrate = 100000;     /* 100 KBaud	low can */

	    /* source Node */
	    {
	        canNodeConfig.nodeId    = IfxMultican_NodeId_1;
	        canNodeConfig.rxPin     = &IfxMultican_RXD1B_P14_1_IN;
	        canNodeConfig.rxPinMode = IfxPort_InputMode_pullUp;
	        canNodeConfig.txPin     = &IfxMultican_TXD1_P14_0_OUT;
	        canNodeConfig.txPinMode = IfxPort_OutputMode_pushPull;

	        IfxMultican_Can_Node_init(&g_Ccan.drivers.canDstNode, &canNodeConfig);
	    }

	    /* source Message object */
	    {
	        /* create message object config */
	        IfxMultican_Can_MsgObjConfig canMsgObjConfig;
	        IfxMultican_Can_MsgObj_initConfig(&canMsgObjConfig, &g_Ccan.drivers.canDstNode);

	        canMsgObjConfig.msgObjId              = 0;
	        canMsgObjConfig.messageId             = 0x367;
	        canMsgObjConfig.acceptanceMask        = 0x7FFFFFFFUL;
	        canMsgObjConfig.frame                 = IfxMultican_Frame_receive;
	        canMsgObjConfig.control.messageLen    = IfxMultican_DataLengthCode_8;
	        canMsgObjConfig.control.extendedFrame = FALSE;
	        canMsgObjConfig.control.matchingId    = TRUE;

	        /* initialize message object */
	        IfxMultican_Can_MsgObj_init(&g_Ccan.drivers.canMsgObj_367, &canMsgObjConfig);
	    }

	    {
	        /* create message object config */
	        IfxMultican_Can_MsgObjConfig canMsgObjConfig;
	        IfxMultican_Can_MsgObj_initConfig(&canMsgObjConfig, &g_Ccan.drivers.canDstNode);

	        canMsgObjConfig.msgObjId              = 1;
	        canMsgObjConfig.messageId             = 0x2B0;
	        canMsgObjConfig.acceptanceMask        = 0x7FFFFFFFUL;
	        canMsgObjConfig.frame                 = IfxMultican_Frame_receive;
	        canMsgObjConfig.control.messageLen    = IfxMultican_DataLengthCode_8;
	        canMsgObjConfig.control.extendedFrame = FALSE;
	        canMsgObjConfig.control.matchingId    = TRUE;

	        /* initialize message object */
	        IfxMultican_Can_MsgObj_init(&g_Ccan.drivers.canMsgObj_2B0, &canMsgObjConfig);
	    }
	    {
	        /* create message object config */
	        IfxMultican_Can_MsgObjConfig canMsgObjConfig;
	        IfxMultican_Can_MsgObj_initConfig(&canMsgObjConfig, &g_Ccan.drivers.canDstNode);

	        canMsgObjConfig.msgObjId              = 2;
	        canMsgObjConfig.messageId             = 0x316;
	        canMsgObjConfig.acceptanceMask        = 0x7FFFFFFFUL;
	        canMsgObjConfig.frame                 = IfxMultican_Frame_receive;
	        canMsgObjConfig.control.messageLen    = IfxMultican_DataLengthCode_8;
	        canMsgObjConfig.control.extendedFrame = FALSE;
	        canMsgObjConfig.control.matchingId    = TRUE;

	        /* initialize message object */
	        IfxMultican_Can_MsgObj_init(&g_Ccan.drivers.canMsgObj_316, &canMsgObjConfig);
	    }
	    {
	        /* create message object config */
	        IfxMultican_Can_MsgObjConfig canMsgObjConfig;
	        IfxMultican_Can_MsgObj_initConfig(&canMsgObjConfig, &g_Ccan.drivers.canDstNode);

	        canMsgObjConfig.msgObjId              = 3;
	        canMsgObjConfig.messageId             = 0x329;
	        canMsgObjConfig.acceptanceMask        = 0x7FFFFFFFUL;
	        canMsgObjConfig.frame                 = IfxMultican_Frame_receive;
	        canMsgObjConfig.control.messageLen    = IfxMultican_DataLengthCode_8;
	        canMsgObjConfig.control.extendedFrame = FALSE;
	        canMsgObjConfig.control.matchingId    = TRUE;

	        /* initialize message object */
	        IfxMultican_Can_MsgObj_init(&g_Ccan.drivers.canMsgObj_329, &canMsgObjConfig);
	    }


}

void init_Ccan_msg(void)
{
	IfxMultican_Message_init(&Ccan_msg_2B0, 0x2B0, 0xFFFFFFFF, 0xFFFFFFFF, IfxMultican_DataLengthCode_8); /* start with invalid values */
	IfxMultican_Message_init(&Ccan_msg_367, 0x367, 0xFFFFFFFF, 0xFFFFFFFF, IfxMultican_DataLengthCode_8); /* start with invalid values */
	IfxMultican_Message_init(&Ccan_msg_316, 0x316, 0xFFFFFFFF, 0xFFFFFFFF, IfxMultican_DataLengthCode_8); /* start with invalid values */
	IfxMultican_Message_init(&Ccan_msg_329, 0x329, 0xFFFFFFFF, 0xFFFFFFFF, IfxMultican_DataLengthCode_8); /* start with invalid values */


}

void Recieve_Ccan_10ms(void)
{
	Ccan_msg msg;


	IfxMultican_Status  readStatus = IfxMultican_Can_MsgObj_readMessage(&g_Ccan.drivers.canMsgObj_367, &Ccan_msg_367);
	readStatus = IfxMultican_Can_MsgObj_readMessage(&g_Ccan.drivers.canMsgObj_2B0, &Ccan_msg_2B0);
	readStatus = IfxMultican_Can_MsgObj_readMessage(&g_Ccan.drivers.canMsgObj_316, &Ccan_msg_316);
	readStatus = IfxMultican_Can_MsgObj_readMessage(&g_Ccan.drivers.canMsgObj_329, &Ccan_msg_329);


	veh_gear_disp = (uint8)(Ccan_msg_367.data[1]&GEAR_DISP_MASK);

	g_spi_msg.spi_data_field_tx[4] = Ccan_msg_2B0.data[0]&STR_ANGLE_LOW_MASK;
	g_spi_msg.spi_data_field_tx[5] = (Ccan_msg_2B0.data[0]&STR_ANGLE_HIGH_MASK)>>8;

	msg.byte4 = Ccan_msg_316.data[0];
	g_spi_msg.spi_data_field_tx[6] = msg.ems_316_low.RPM_LOW;
	g_spi_msg.spi_data_field_tx[7] = msg.ems_316_low.RPM_HIGH;

	msg.byte4 = Ccan_msg_316.data[1];
	g_spi_msg.spi_data_field_tx[8] = msg.ems_316_high.VS;

	msg.byte4 = Ccan_msg_329.data[1];
	g_spi_msg.spi_data_field_tx[9] = msg.ems_329_high.ACC_PEDAL;
	g_spi_msg.spi_data_field_tx[10] = msg.ems_329_high.THROTTLE;

	veh_break = msg.ems_329_high.BRAKE_ACT;


}


