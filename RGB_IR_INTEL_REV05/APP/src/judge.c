/*
 * judge.c
 *
 *  Created on: 2018. 10. 17.
 *      Author: wanseok.kim
 */

#include "judge.h"
#include <stdio.h>

CAN analysisCANdata(BYTE canData)
{
	/*BYTE x[MAX_CAN_LEN] = {};
	for(int i = 0; i<MAX_CAN_LEN; i++){
		x[i] = MASK(canData,i);
	}

	//상태의 우위에 따라 결과를 달리 return함.
	if 		(x[CAN_TRUN_L] == 0x01 && x[CAN_TRUN_R] == 0x01) 	{ return EMERGENCY; }
	else if (x[CAN_BRAKE_ON] == 0x01)							{ return BRAKE_SWITCH_ON; }
	else if (x[CAN_TRUN_L] == 0x01)								{ return TRUN_L; }
	else if (x[CAN_TRUN_R] == 0x01)								{ return TRUN_R; }
	else if (x[CAN_GERA_D] == 0x01)								{ return SPEED; }
	else if (x[CAN_UNLOCK] == 0x01)								{ return DOOR_UNLOCK; }
	else if (x[CAN_ROOM] == 0x01)								{ return GERA_N; }
	else if (x[CAN_ACC_OFF] == 0x01)							{ return ACC_OFF; }
	else {return DEFAULT;}*/

	return DEFAULT;
}

BYTE checkImageData(CAN canData)
{

	switch (canData)
	{
		case DEFAULT : return LC_Invalid; break;
		case CLEAR : return LC_6000; break;
		case FOG_L : return LC_3000; break;
		case FOG_H : return LC_3000; break;
		case RAIN_L : return LC_3000; break;
		case RAIN_H : return LC_3000; break;
		//case CLEAR_ILL : return LC_3000; break;
		//case FOG_L_ILL: return LC_4000; break;
		//case FOG_H_ILL : return LC_3000; break;
		//case RAIN_L_ILL: return LC_6000; break;
		//case RAIN_H_ILL : return LC_6000; break;
	}

	return LC_Invalid;

}

_priority_num checkCANdata(CAN canData) // 우선순위 check
{

	switch (canData)
	{
	case DEFAULT : return initial; break;
	case CLEAR : return clear; break;
	case FOG_L : return fogL; break;
	case FOG_H : return fogH; break;
	case RAIN_L : return RainL; break;
	case RAIN_H : return RainH; break;
	//case CLEAR_ILL : return clear_Ill; break;
	//case FOG_L_ILL: return fogL_Ill; break;
	//case FOG_H_ILL : return fogH_Ill; break;
	//case RAIN_L_ILL: return RainL_ILL; break;
	//case RAIN_H_ILL : return RainH_ILL; break;
	}

	return 0;
}

_light_change_code CheckPriority(MSG *p, CAN canData)
{
	_priority_num input_code = checkCANdata(canData); //지금 Candata를 -1,1~5로 구분
	_light_change_code output_code;
	if (input_code != initial){ // 들어온 값이 정상값이라면
		output_code = (p->priority_code >= input_code) ? _light_change : _light_keep;
		if (output_code == _light_change){
			p->CAN_DB = canData;
			p->priority_code = input_code;
		} else if (output_code == _light_keep){
		} else {
			initMassage(p);
			p->priority_code = error;
			return _system_error;
		}
	}
	else {
		output_code = _light_change;
		p->state = END_WAIT;
		p->CAN_DB = DEFAULT;
	}
	return output_code;
}

_light_condition initialCheck(MSG *p, CAN canData)
{

	if ((p->state != END_WAIT) && (p->state != DOING))// 상태가 이상한 값이 들어온경우
	{
		initMassage(p);
		p->priority_code = error;
		return _system_error;
	}
	else if(p->state == DOING) // 현상태가 동작중이면
	{
		if (p->CAN_DB != canData){
			return CheckPriority(p, canData);
		}
		else {
			return _light_keep;
		}
	}
	else if(p->state == END_WAIT)
	{
		_priority_num pri_Num = checkCANdata(canData);
		if ((pri_Num < initial) || (pri_Num >= error)) {
			initMassage(p);
			p->priority_code = error;
			return _system_error;
		}
		else {
			if (p->CAN_DB != canData){
				p->CAN_DB = canData;
				p->state = DOING;
				p->priority_code = pri_Num;
				return _light_change;
			}
			else {
				return _light_keep;
			}
		}
	}
	else
	{
		initMassage(p);
		p->priority_code = error;
		return _system_error;
	}

}

//  대경과제 용으로 생성 200304 hb

CAN analysisCANdata_makeSenData(BYTE *canData, SEN_VDATA *senVData)
{


	//int iILL = (canData[SEN_ILL_MSB] << 8) + canData[SEN_ILL_LSB];



	BYTE RainV_H = canData[SEN_RAIN_VOLT_MSB];
	BYTE RainV_L = canData[SEN_RAIN_VOLT_LSB];

	float fRainV = RainV_H + (RainV_L/1000.0);

	DWORD dwPM25 = (canData[SEN_PM25_MSB] << 8) + canData[SEN_PM25_LSB];
	DWORD dwPM10 = (canData[SEN_PM10_MSB] << 8) + canData[SEN_PM10_LSB];

	// 계산 되어진 값을 구조체에 입력한다.
	//senVData->iILL = iILL;
	senVData->fRainVoltage = fRainV;
	senVData->fRainADC = senVData->fRainVoltage*1000 / 5.0;
	senVData->iPM25 = dwPM25;
	senVData->iPM10 = dwPM10;

	//printf("ILL Value : 0x%04X, %d\n",iILL,iILL);
	//printf("Rain Value : 0x%02X, 0x%02X, %f\n",RainV_H,RainV_L, fRainV);
	//printf("Dust Value : pm25 0x%04X, pm10 0x%04X\n",dwPM25,dwPM10);


	return JudgeSenData(senVData);
}



CAN JudgeSenData(SEN_VDATA *senVData)
{
	//senVData->ILL_Judge 	=JudgeSenData_ILL(senVData);
	senVData->Rain_Judge 	=JudgeSenData_Rain(senVData);
	senVData->Fog_Judge 	=JudgeSenData_Fog(senVData);

	return CheckSen_Priority(senVData);
}


_Sensor_Judge JudgeSenData_ILL(SEN_VDATA *senVData){

	_Sensor_Judge judge = EMPTY;
	//judge = (senVData->iILL >= iILL_Limit) ? LIGHT : EMPTY;

	printf("ILL %d\t", judge);
	return judge;
}
_Sensor_Judge JudgeSenData_Rain(SEN_VDATA *senVData){
	_Sensor_Judge judge = EMPTY;


	float fValue = senVData->fRainADC;
	//float fValue = senVData->fRainVoltage;

	if(fValue> fRain_Limit_H)
		judge = EMPTY;
	else if(fValue<= fRain_Limit_H && fValue > fRain_Limit_L)
		judge = LIGHT;
	else if(fValue <= fRain_Limit_L)
		judge = HEAVY;



	//printf("Rain %d\t", judge);
	return judge;

}
_Sensor_Judge JudgeSenData_Fog(SEN_VDATA *senVData){
	_Sensor_Judge judge = EMPTY;


	if(senVData->iPM10<= iPM10_Limit_L)
		judge = EMPTY;
	else if(senVData->iPM10<= iPM10_Limit_H && senVData->iPM10 > iPM10_Limit_L)
		judge = LIGHT;
	else if(senVData->iPM10> iPM10_Limit_H)
		judge = HEAVY;



	/*bool bPM25 = (senVData->iPM25>= iPM25_Limit) ? 1 : 0;
	bool bPM10 = (senVData->iPM10>= iPM10_Limit) ? 1 : 0;

	if((bPM25 && bPM10) || bPM25)
	{
		judge = HEAVY;
	}
	else if(bPM10)
	{
		judge = LIGHT;
	}
	else
	{
		judge = EMPTY;
	}*/
	printf("Fog %d\t", judge);
	return judge;
}

CAN CheckSen_Priority(SEN_VDATA *senVData){

	CAN canSit = DEFAULT;
	//	센서들의 우위를 판단한다.
	//	안개L	안개H	레인L	레인H
	//0 X		X		X		X
	//1 O		X		X		X
	//2	X		O		X		X
	//3	X		X		O		X
	//4	X		X		X		O
	//-------------------------------------위 상황(1~4)은 센서가 하나씩 해당하는 경우
	//5	O		X		O		X
	//6	O		X		X		O
	//7	X		O		O		X
	//8	X		O		X		O
	//-------------------------------------위 상황(5~8)은 센서 모두 해당되어 우위가 결정되어야하는 경우
	//	위 상태에 외부조명의 유무를 판단한다.

	//- 만약 LIGHT HEAVY 뿐만 아니라 수치에 정도로도 우위판단에 필요할 시 Value구조체(senVData)를 분석하여 다시 구성하여야함.
	//- 기본적인 상황을 제외하고 우위조건을 결정해야함.
	//- 현재 시야확보가 힘든 안개 센서를 우위를 높여서 판단하여 작성함.

	//_Sensor_Judge ILL = senVData->ILL_Judge;
	_Sensor_Judge Fog = senVData->Fog_Judge;
	_Sensor_Judge Rain= senVData->Rain_Judge;

	for(int t=0; t< JudgeRefSit; t++)
	{
		if(JudgeRef[t].bUse){ // 조건을 사용할 때

			if(/*JudgeRef[t].ILL == ILL &&*/ JudgeRef[t].Fog == Fog && JudgeRef[t].Rain == Rain)
			{
				canSit = JudgeRef[t].Sit;
				break;
			}
		}
	}

	//printf("Situation %d\t", canSit);
	return canSit;


}




