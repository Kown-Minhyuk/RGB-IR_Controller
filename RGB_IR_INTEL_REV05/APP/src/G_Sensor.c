/*
 * G_Sensor.c
 *
 *  Created on: 2018. 12. 7.
 *      Author: junseok.lee
 */
#include "G_Sensor.h"
#include "AIS328DQ_REG.h"
#include "Spisoc.h"
//
//static int init_Gsensor(void)
//{
//	uint8 id = 0;
////	if(Ax_Sensor_Read(WHO_AM_I , &id) !=0)
////		return -1;
//}

static uint8 test_a =0;

static uint8 xyz[6] = {0};
static uint16 xval,yval,zval = 0;
//static float fx,fy,fz =0;

//static Ax_Sensor_Reg reg_static;

static int init_ais328dq(void)
{
	static uint8 id = 0;

	/*	Check the device ID	*/
	if(	gsensor_device_id_get(&id) !=0 )
	{
		return -1;
	}
	test_a = id;

	if( id != 0x32 )
	{
		return -1;
	}

		if(gsensor_power_mode_set(NORMAL_MODE) !=0 )
		{
			return -1;
		}

	/*	Block Data Update 1	*/
	/*	Output register not updated between MSb and LSb reading	*/
	if( gsensor_block_data_update_set(AX_SENS_UPDATED) != 0 )
	{
		return -1;
	}
	if( gsensor_full_scale_set(FULL_SCALE_8g) != 0)
	{
		return -1;
	}
	if(gsensor_HPF_enable_set(AX_SENS_HP_OFF) !=0 )
	{
		return -1;
	}
	if(gsensor_internal_filter_set(INTERNAL_FILTER_BYPASS) !=0 )
	{
		return -1;
	}
	if(gsensor_power_mode_set(NORMAL_MODE) !=0 )
	{
		return -1;
	}

	//if(gsensor_data_rate_set(NORMAL_MODE_1000HZ) !=0 )
	if(gsensor_data_rate_set(NORMAL_MODE_100HZ) !=0 )
	{
		return -1;
	}

	if(gsensor_pin_polarity_set(INT_ACTIVE_HIGH) !=0 )
	{
		return -1;
	}
	if(gsensor_pin_pad_set(PUSH_PULL) != 0)
	{
		return -1;
	}

	return 0;
}

void init_gsensor(void)
{
	while(init_ais328dq() != 0);
}



//int gsensor_set_sleep_mode(uint8 threshold, uint8 duration)
void gsensor_set_sleep_mode(uint8 threshold, uint8 duration)
{
	int ret = 0;

	INT_TH_LEVEL int1_cfg;

//	int1_cfg.int_xhie = 1;
//	int1_cfg.int_xlie = 1;
//	int1_cfg.int_yhie = 1;
//	int1_cfg.int_ylie = 1;
//	int1_cfg.int_zhie = 1;
//	int1_cfg.int_zlie = 1;

	int1_cfg.int_xhie = 1;
	int1_cfg.int_xlie = 0;
	int1_cfg.int_yhie = 1;
	int1_cfg.int_ylie = 0;
	int1_cfg.int_zhie = 1;
	int1_cfg.int_zlie = 0;

	ret = gsensor_pin_polarity_set(INT_ACTIVE_LOW);
	ret |= gsensor_pin_pad_set(PUSH_PULL);
	ret |= gsensor_int1_latch_set(AX_SENS_INTX_PULSED);
	ret |= gsensor_INT1_threshold_set(threshold);
	ret |= gsensor_INT1_duration_set(duration);
	ret |= gsensor_INT1_threshold_level_set(int1_cfg);

	ret |= gsensor_int2_latch_set(AX_SENS_INTX_PULSED);
	ret |= gsensor_INT2_threshold_set(threshold);
	ret |= gsensor_INT2_duration_set(duration);
	ret |= gsensor_INT2_threshold_level_set(int1_cfg);

	//return ret;
}



void gsensor_get_xyz(uint8 *x_l, uint8 *x_h, uint8 *y_l, uint8 *y_h, uint8 *z_l, uint8 *z_h)
{
	gsensor_read_reg(OUT_X_L,x_l);
	gsensor_read_reg(OUT_X_H,x_h);
	gsensor_read_reg(OUT_Y_L,y_l);
	gsensor_read_reg(OUT_Y_H,y_h);
	gsensor_read_reg(OUT_Z_L,z_l);
	gsensor_read_reg(OUT_Z_H,z_h);
}

//static Ax_Sensor_Int1_Src src_value;
//static Ax_Sensor_Int2_Src src_value2;

static uint8 ctl1 =0;
static uint8 ctl1_1 =0;
static uint8 ctl2 =0;
static uint8 ctl3 =0;
static uint8 ctl4 =0;
static uint8 ctl5 =0;

static uint8 var_int1_ths =0;
static uint8 var_int1_dur =0;
static uint8 var_int1_cfg =0;
static uint8 var_int1_src =0;





void gsensor_value_read(void)
{


	gsensor_read_reg(CTRL_REG1, &ctl1);
	gsensor_read_reg(CTRL_REG1, &ctl1_1);
	gsensor_read_reg(CTRL_REG2, &ctl2);
	gsensor_read_reg(CTRL_REG3, &ctl3);
	gsensor_read_reg(CTRL_REG4, &ctl4);
	gsensor_read_reg(CTRL_REG5, &ctl5);

	gsensor_read_reg(INT1_THS, &var_int1_ths);
	gsensor_read_reg(INT1_DURATION, &var_int1_dur);
	gsensor_read_reg(INT1_CFG, &var_int1_cfg);

	gsensor_read_reg(INT1_SRC, &var_int1_src);
//
//
//
//
	gsensor_get_xyz(&xyz[0],&xyz[1],&xyz[2],&xyz[3],&xyz[4],&xyz[5]);
	xval = ((uint16)xyz[1]<<8 | (uint16)xyz[0]);
	yval = ((uint16)xyz[3]<<8 | (uint16)xyz[2]);
	zval = ((uint16)xyz[5]<<8 | (uint16)xyz[4]);

	if(xval>0x7fff)
	{
		xval = xval-65536;
	}
	if(yval>0x7fff)
	{
		yval = xval-65536;
	}
	if(zval>0x7fff)
	{
		zval = xval-65536;
	}


}
static uint8 id_temp =0;

void gsensor_read_id(void)
{


	gsensor_device_id_get(&id_temp);
}

void gsensor_write_temp(void)
{
	uint8 reg_write = 0xAA;

	gsensor_write_reg(INT1_CFG, &reg_write);

}

void gsensor_read_temp(void)
{

	uint8 reg_read = 0;
	gsensor_read_reg(INT1_CFG, &reg_read);
}

uint8 Gsensor_get_DRV_THS(uint8 set_value)
{
	uint8 ret_value =0;

	switch(set_value)
	{
	case 0:
		ret_value = GSENSOR_DRV_LOW;
		break;
	case 1:
		ret_value = GSENSOR_DRV_MID_LOW;
		break;
	case 2:
		ret_value = GSENSOR_DRV_MID;
		break;
	case 3:
		ret_value = GSENSOR_DRV_MID_HIGH;
		break;
	case 4:
		ret_value = GSENSOR_DRV_HIGH;
		break;
	case 5:
		ret_value = 0;
		break;

	default:
		ret_value = 0;
		break;
	}

	return ret_value;

}

uint8 Gsensor_get_PRK_THS(uint8 set_value)
{
	uint8 ret_value =0;

	switch(set_value)
	{
	case 0:
		ret_value = GSENSOR_PRK_LOW;
		break;
	case 1:
		ret_value = GSENSOR_PRK_MID_LOW;
		break;
	case 2:
		ret_value = GSENSOR_PRK_MID;
		break;
	case 3:
		ret_value = GSENSOR_PRK_MID_HIGH;
		break;
	case 4:
		ret_value = GSENSOR_PRK_HIGH;
		break;
	case 5:
		ret_value = 0;
		break;

	default:
		ret_value = 0;
		break;
	}

	return ret_value;
}





