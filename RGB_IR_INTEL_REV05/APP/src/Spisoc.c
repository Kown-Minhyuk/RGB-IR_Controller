/*
 * Spisoc.c
 *
 *  Created on: 2019. 10. 1.
 *      Author: junseok.lee
 */

#include "Spisoc.h"
#include "QspiCpuDemo.h"
#include "ScuEru.h"
#include "util.h"
#include "Vadc.h"


#define MCU_VER	0x02;
#define SPI_MSG_ID	0x10;
#define SPI_MSG_DLC	13;


App_spi_msg g_spi_msg;

soc_spi_msg_union soc_spi_union;

uint8 veh_gear_disp=0;
uint8 veh_break =0;


uint8 Cur_Veh_Stat = PARKING;

uint8 Impact_rec_cnt =0;

uint8 Batt_Soc_temp = 0;
uint8 DVRS_Prk_Opr_Inform_temp =0;
uint8 gu8_SOC_MCU_PRK_Setting = 0x02;


uint8 calc_spi_msg_checksum(uint8 *data)
{
	uint32 sum = 0;
	int i = 0;

	for(i=0;i<=14;i++)
	{
		sum += data[i];
	}


	return (uint8)sum;
}


void Spi_transfer_soc(void)
{
	uint32 current_time = 0;
	uint32 sample_time = 0;
//	uint32 Time_const = 10000000;	/* 500ms	*/
	uint32 Time_const = 20000;	/* 10ms	*/


	g_spi_msg.spi_data_tx[1] = 29;
	g_spi_msg.spi_data_tx[31] = 0xff - calc_spi_msg_checksum(&g_spi_msg.spi_data_tx[0]);


	sample_time = IfxStm_getLower(stmSfr1);

    while (IfxQspi_SpiSlave_getStatus(&g_QspiCpu.drivers.spiSlave) == SpiIf_Status_busy)
    {
    	current_time = IfxStm_getLower(stmSfr1);
		if( current_time - sample_time >= Time_const )
		{
			sample_time += Time_const;
			goto end;
		}


    }

    IfxQspi_SpiSlave_exchange(&g_QspiCpu.drivers.spiSlave, &g_spi_msg.spi_data_tx[0],
        &g_spi_msg.spi_data_rx[0], SPI_BUFFER_SIZE);


   // g_spi_msg.spi_data_tx[23] = 0xF;




    end:
	{}

}

void get_veh_info(void)
{

	Adc_Scan();
	soc_spi_union.byte = g_spi_msg.spi_data_tx[2];
	soc_spi_union.data0.Mcu_ver = MCU_VER;
	soc_spi_union.data0.CurVehicleState = Cur_Veh_Stat;

	g_spi_msg.spi_data_field_tx[0] = soc_spi_union.byte;
	g_spi_msg.spi_data_field_tx[1] = batt_voltage;


	soc_spi_union.byte = g_spi_msg.spi_data_tx[2];
	soc_spi_union.data4.Veh_ACC = ACC_SIGNAL ;

	if(soc_spi_union.data4.Impact_rec==1)
	{
		Impact_rec_cnt++;
		if(Impact_rec_cnt>=20)
		{
			Impact_rec_cnt = 0;
			soc_spi_union.data4.Impact_rec=0;
		}
	}

	g_spi_msg.spi_data_field_tx[2] =  soc_spi_union.byte;


	soc_spi_union.byte = 0;
	soc_spi_union.data5.VEH_GEAR = veh_gear_disp;
	soc_spi_union.data5.VEH_BRAKE = veh_break;
	g_spi_msg.spi_data_field_tx[3] = soc_spi_union.byte;



}


void spi_put_msg(void)
{

	g_spi_msg.spi_data_tx[0] = SPI_MSG_ID;
	g_spi_msg.spi_data_tx[1] = SPI_MSG_DLC;
	g_spi_msg.spi_data_tx[2] = g_spi_msg.spi_data_field_tx[0];
	g_spi_msg.spi_data_tx[3] = g_spi_msg.spi_data_field_tx[1];
	g_spi_msg.spi_data_tx[4] = g_spi_msg.spi_data_field_tx[2];
	g_spi_msg.spi_data_tx[5] = g_spi_msg.spi_data_field_tx[3];
	g_spi_msg.spi_data_tx[6] = g_spi_msg.spi_data_field_tx[4];
	g_spi_msg.spi_data_tx[7] = g_spi_msg.spi_data_field_tx[5];
	g_spi_msg.spi_data_tx[8] = g_spi_msg.spi_data_field_tx[6];
	g_spi_msg.spi_data_tx[9] = g_spi_msg.spi_data_field_tx[7];
	g_spi_msg.spi_data_tx[10] = g_spi_msg.spi_data_field_tx[8];
	g_spi_msg.spi_data_tx[11] = g_spi_msg.spi_data_field_tx[9];
	g_spi_msg.spi_data_tx[12] = g_spi_msg.spi_data_field_tx[10];
	g_spi_msg.spi_data_tx[13] = g_spi_msg.spi_data_field_tx[11];
	g_spi_msg.spi_data_tx[14] = g_spi_msg.spi_data_field_tx[12];
	g_spi_msg.spi_data_tx[15] = 0xff - calc_spi_msg_checksum(&g_spi_msg.spi_data_tx[0]);

}







