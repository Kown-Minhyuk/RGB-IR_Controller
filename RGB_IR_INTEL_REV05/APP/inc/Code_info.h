/*
 * Code_info.h
 *
 *  Created on: 2018. 10. 18.
 *      Author: wanseok.kim
 */

#ifndef CODE_INFO_H_
#define CODE_INFO_H_

#include <stdbool.h>

//#define _DEBUG
typedef int _Sensor_Judge;
typedef char CAN;

typedef struct _SensorValueData
{
	//int iILL;
	float fRainVoltage;
	float fRainADC;
	int iPM25;
	int iPM10;

	//_Sensor_Judge ILL_Judge;
	_Sensor_Judge Rain_Judge;
	_Sensor_Judge Fog_Judge;

}SEN_VDATA;

typedef enum _SenSorCan
{
	SEN_ILL_LSB,
	SEN_ILL_MSB,
	SEN_RAIN_VOLT_LSB,
	SEN_RAIN_VOLT_MSB,
	SEN_PM25_LSB,
	SEN_PM25_MSB,
	SEN_PM10_LSB,
	SEN_PM10_MSB,
	SEN_MAX,
}SEN_CAN;

typedef enum _LampCCT
{
	LC_error = -1,
	LC_6000 = 0x00,
	LC_5000	= 0x01,
	LC_4000	= 0x02,
	LC_3000	= 0x03,
	LC_Invalid	= 0x04,
}LAMP_CCT;

//상황에 대한 우선순위
typedef enum _judgeCode
{
	clear  = 5,
	fogL = 3,
	fogH = 1,
	RainL= 4,
	RainH= 2,
	//clear_Ill = 5,
	//fogH_Ill= 1,
	//fogL_Ill = 2,
	//RainL_ILL= 2,
	//RainH_ILL= 1,
	error =6,
	initial = -1
}JUDGE_CODE;

//강도
#define EMPTY	0
#define LIGHT	1
#define HEAVY	2

/* CAN data info */
#define DEFAULT				0x00
#define CLEAR				0x01
#define FOG_L				0x03
#define FOG_H				0x04
#define RAIN_L				0x07
#define RAIN_H				0x08
//#define CLEAR_ILL			0x02
//#define FOG_L_ILL			0x05
//#define FOG_H_ILL			0x06
//#define RAIN_L_ILL			0x09
//#define RAIN_H_ILL			0x0A

// Lamp 가변하고 대기 시간
#define _onTime		10

/* control Code */
#define SOH		0x02
#define EOT		0x03

/* Mode info */
#define NTrans		0x81
#define Trans		0x82
#define OutImage	0x83
#define ImageSave	0x84

/* state code*/
#define END_WAIT	0x00
#define DOING		0x01

typedef struct _SensorJudgeData
{
	bool bUse;
	_Sensor_Judge ILL;
	_Sensor_Judge Fog;
	_Sensor_Judge Rain;

	CAN Sit;

}SEN_JDATA;


//static const int iILL_Limit = 350;
static const float fRain_Limit_L = 350.0;
static const float fRain_Limit_H = 800.0;


static const int iPM10_Limit_L = 20;
static const int iPM10_Limit_H = 300;

#define JudgeRefSit 9
static const SEN_JDATA JudgeRef[JudgeRefSit] = {
		//use	ILL		Fog		rain	situation
		{1,		EMPTY,	EMPTY, EMPTY, 	CLEAR			},
		{1,		EMPTY,	LIGHT, EMPTY, 	FOG_L			},
		{1,		EMPTY,	HEAVY, EMPTY, 	FOG_H			},
		{1,		EMPTY,	EMPTY, LIGHT, 	RAIN_L			},
		{1,		EMPTY,	EMPTY, HEAVY, 	RAIN_H			},
		//////////////아래 조건은 우위가 필요함.
		{1,		EMPTY,	LIGHT, LIGHT, 	FOG_L			},
		{1,		EMPTY,	LIGHT, HEAVY, 	RAIN_H			},
		{1,		EMPTY,	HEAVY, LIGHT, 	FOG_H			},
		{1,		EMPTY,	HEAVY, HEAVY, 	FOG_H			},

		// 외부조명 조건
		//{1,		LIGHT,	EMPTY, EMPTY, 	CLEAR_ILL		},
		//{1,		LIGHT,	LIGHT, EMPTY, 	FOG_L_ILL		},
		//{1,		LIGHT,	HEAVY, EMPTY, 	FOG_H_ILL		},
		//{1,		LIGHT,	EMPTY, LIGHT, 	RAIN_L_ILL		},
		//{1,		LIGHT,	EMPTY, HEAVY, 	RAIN_H_ILL		},
		//{1,		LIGHT,	LIGHT, LIGHT, 	FOG_L_ILL		},
		//{1,		LIGHT,	LIGHT, HEAVY, 	RAIN_H_ILL		},
		//{1,		LIGHT,	HEAVY, LIGHT, 	FOG_H_ILL		},
		//{1,		LIGHT,	HEAVY, HEAVY, 	FOG_H_ILL		},

};

#endif /* CODE_INFO_H_ */
