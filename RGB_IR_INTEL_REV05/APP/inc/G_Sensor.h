/*
 * G_Sensor.h
 *
 *  Created on: 2018. 12. 7.
 *      Author: junseok.lee
 */

#ifndef G_SENSOR_H_
#define G_SENSOR_H_

#include "Cpu/Std/Ifx_Types.h"


//#define GSENSOR_DRV_LOW			0x4000
//#define GSENSOR_DRV_MID_LOW		0x3400
//#define GSENSOR_DRV_MID			0x2800
//#define GSENSOR_DRV_MID_HIGH	0x1800
//#define GSENSOR_DRV_HIGH		0xCCD
//
//#define GSENSOR_PRK_LOW			0x800
//#define GSENSOR_PRK_MID_LOW		0x4CD
//#define GSENSOR_PRK_MID			0x2E1
//#define GSENSOR_PRK_MID_HIGH	0x23D
//#define GSENSOR_PRK_HIGH		0x19A

#define GSENSOR_DRV_LOW			0x40
#define GSENSOR_DRV_MID_LOW		0x34
#define GSENSOR_DRV_MID			0x28
#define GSENSOR_DRV_MID_HIGH	0x18
#define GSENSOR_DRV_HIGH		0x0C

#define GSENSOR_PRK_LOW			0x08
#define GSENSOR_PRK_MID_LOW		0x04
#define GSENSOR_PRK_MID			0x02
#define GSENSOR_PRK_MID_HIGH	0x02
#define GSENSOR_PRK_HIGH		0x01




//extern int gsensor_set_sleep_mode(uint8 threshold, uint8 duration);
extern void gsensor_set_sleep_mode( uint8 threshold,  uint8 duration);
extern void init_gsensor(void);
extern void gsensor_get_xyz(uint8 *x_l, uint8 *x_h, uint8 *y_l, uint8 *y_h, uint8 *z_l, uint8 *z_h);

extern void gsensor_value_read(void);
extern void gsensor_read_id(void);

extern void gsensor_write_temp(void);
extern void gsensor_read_temp(void);

extern uint8 Gsensor_get_DRV_THS(uint8 set_value);
extern uint8 Gsensor_get_PRK_THS(uint8 set_value);

#endif /* G_SENSOR_H_ */
