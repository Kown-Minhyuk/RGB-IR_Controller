/*
 * Ccan.h
 *
 *  Created on: 2019. 10. 7.
 *      Author: junseok.lee
 */

#ifndef APP_INC_CCAN_H_
#define APP_INC_CCAN_H_

#include "Cpu/Std/Ifx_Types.h"
#include <Multican/Can/IfxMultican_Can.h>
#include "QspiCpuDemo.h"

#define FIFO_SIZE 4

#define GEAR_DISP_MASK	(0x000FU)
#define STR_ANGLE_LOW_MASK	(0x00FFU)
#define STR_ANGLE_HIGH_MASK	(0x000FF00U)

typedef struct
{
    struct
    {
        IfxMultican_Can        can;          /**< \brief CAN driver handle */
        IfxMultican_Can_Node   canSrcNode;   /**< \brief CAN Source Node */
        IfxMultican_Can_Node   canDstNode;   /**< \brief CAN Source Node */

        IfxMultican_Can_MsgObj canMsgObj_367; /**< \brief CAN Destination Message object */
        IfxMultican_Can_MsgObj canMsgObj_2B0; /**< \brief CAN Destination Message object */
        IfxMultican_Can_MsgObj canMsgObj_316; /**< \brief CAN Destination Message object */
        IfxMultican_Can_MsgObj canMsgObj_329; /**< \brief CAN Destination Message object */

    }drivers;
} App_Ccan_struct;



typedef struct
{
	uint32	G_SEL_DISP				:4;
	uint32	RESEVED					:28;
}CCAN_CGW_PC5_High;

typedef struct
{
	uint32	RESERVED				:6;
	uint32	BRAKE_ACT				:2;
	uint32	THROTTLE				:8;
	uint32	ACC_PEDAL				:8;
	uint32	RESERVED2					:8;
}CCAN_EMS_329_HIGH;

typedef struct
{
	uint32	RESERVED				:8;
	uint32	RPM_LOW					:8;
	uint32	RPM_HIGH				:8;
	uint32	RESERVED2				:8;
}CCAN_EMS_316_LOW;

typedef struct
{
	uint32	RESERVED				:16;
	uint32	VS						:8;
	uint32	RESERVED2				:8;
}CCAN_EMS_316_HIGH;

typedef union
{
	CCAN_CGW_PC5_High cgw_pc5_high;
	CCAN_EMS_329_HIGH ems_329_high;
	CCAN_EMS_316_LOW	ems_316_low;
	CCAN_EMS_316_HIGH	ems_316_high;
	uint32	byte4;
}Ccan_msg;

extern void init_Ccan_Trans(void);
extern void init_Ccan(void);
extern void Recieve_Ccan(void);
extern void sleep_Ccan_Trans(void);

extern void init_Ccan_msg(void);
extern void Recieve_Ccan_10ms(void);



extern App_Ccan_struct g_Ccan;

#endif /* APP_INC_CCAN_H_ */
