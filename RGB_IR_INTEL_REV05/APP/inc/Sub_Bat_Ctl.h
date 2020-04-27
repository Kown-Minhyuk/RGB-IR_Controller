/*
 * Sub_Bat_Ctl.h
 *
 *  Created on: 2019. 12. 5.
 *      Author: junseok.lee
 */

#ifndef APP_INC_SUB_BAT_CTL_H_
#define APP_INC_SUB_BAT_CTL_H_



#define SUB_BATT_STANDBY	0
#define SUB_BATT_CHARGE		1
#define SUB_BATT_DISCHARGE	2


extern uint8 bms_info_13_data[8];
extern uint8 sub_batt_status;


extern void AsclinLinDemo_certification(void);
extern void get_Battery_status(uint8 *_bat_SoC, uint8 *_bat_Volt, uint16 *_bat_Current, uint16 *_bat_Temp);
extern void start_Battery_Charge(void);
extern void start_Battery_Discharge(uint8 _bat_SoC);
extern void get_Battery_inf(void);
extern void debug_start_Battery_Discharge(void);
extern uint8 get_battery_discharging_time(uint8 _bat_SoC);
extern void standby_Battery(void);

extern void Sub_Batt_Wake_up(void);
extern void get_BMS_INFO_01(void);
extern void get_BMS_INFO_02(void);
extern void get_BMS_INFO_03(void);
extern uint8 Sub_Batt_Control(uint8 sb_control);

#endif /* APP_INC_SUB_BAT_CTL_H_ */
