/*
 * main.c
 *
 *  Created on: 2018. 10. 22.
 *      Author: wanseok.kim
 */


#include "msg.h"
#include "judge.h"
#include "Check_time.h"


int main(void)
{

	//makeMassage 함수에 InputData로 사용하나 내부에서 사용 안함.
	BYTE cmd = 0x3C;
	BYTE len = 0x05;
	BYTE mode = 0x82;
	//////////////////////////////
	MSG p;
	initMassage(&p);
	SEN_VDATA senVData;

	//Input data / 0x101
	BYTE CanData[SEN_MAX]={0,}; 	// 입력된 센서 canData를 배열에 넣어야함. 8 BYTE
	/*
	 * for(int i=0; i<SEN_MAX; i++)
	 * {
	 * 	CanData[i] = sensor data;
	 * }
	 */
	//입력된 센서 수치를 기후 환경에 대한 상황 분석
	CAN AnalysisCanData = analysisCANdata_makeSenData(CanData, &senVData);

	if(AnalysisCanData == DEFAULT) // 맞는 조건이 없는 경우 / 예외처리
	{
		return 0;
	}
	if (compareTime(p.light_on_time) >= _onTime){ //Lamp가 동작한 시간(소스적으로 변경된 시간)을 check
		if (AnalysisCanData != p.CAN_DB){
			initMassage(&p);
			makeMassage(&p, len, cmd, mode, AnalysisCanData);
			p.priority_code = checkCANdata(AnalysisCanData);
			p.state = DOING;
		}
		else {
			makeMassage(&p, len, cmd, mode, AnalysisCanData); // 같으면 동일 데이터 던져도 되는 것이 아닌지..Default대신에
			p.CAN_DB = AnalysisCanData;
		}
	}
	else {
		//Lamp의 동작여부와 기후환경(현재와 변경)에 따른 우위를 가려 Lamp의 변경 여부를 판단
		if (initialCheck(&p, AnalysisCanData) == _light_change){
			p.light_on_time = (CLOCK_TIME)clock();
			makeMassage(&p, len, cmd, mode, AnalysisCanData);
		}
//	__printURATtransmsg(&p);
	}

	//output data -> p.com_m[0] //cct 데이터 0~4
	// 이 데이터를 0x541에 던져야함.

	return 0;
}
