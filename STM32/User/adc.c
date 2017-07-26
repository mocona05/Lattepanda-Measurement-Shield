#include "board.h"

#include <math.h>
#include "arm_math.h"
#include "arm_const_structs.h"

#define KELVIN_BUFF_SIZE	33		//moving avg
#define TC_ADC_BUFF_SIZE 16		//1ms = 16.67sample

uint32_t kelvin_SDADC[KELVIN_BUFF_SIZE];
uint32_t tc_SDADC[TC_ADC_BUFF_SIZE];

uint32_t raw_ADC[MAX_12BIT_ADC_CHANNEL];

#define KELVIN_ZERO_CALI_SAMPLE		200

extern SDADC_HandleTypeDef hsdadc1;
extern SDADC_HandleTypeDef hsdadc3;
extern ADC_HandleTypeDef hadc1;

double avg_item[SAMPLE_MAX_ITEM];


void ADC_init(void) {
//	if (HAL_SDADC_InjectedConfigChannel(&hsdadc1, SDADC_CHANNEL_6, SDADC_CONTINUOUS_CONV_ON) != HAL_OK) {
//		Error_Handler();
//	}

//	if (HAL_SDADC_InjectedConfigChannel(&hsdadc3, SDADC_CHANNEL_8, SDADC_CONTINUOUS_CONV_ON) != HAL_OK){
//		Error_Handler();
//	}
		if (HAL_SDADC_ConfigChannel(&hsdadc1, SDADC_CHANNEL_6, SDADC_CONTINUOUS_CONV_ON) != HAL_OK){
		Error_Handler();
	}
		if (HAL_SDADC_ConfigChannel(&hsdadc3, SDADC_CHANNEL_8, SDADC_CONTINUOUS_CONV_ON) != HAL_OK){
		Error_Handler();
	}
	
//---------------Calibration start -----------------------//	
	if(HAL_SDADC_CalibrationStart(&hsdadc1, SDADC_CALIBRATION_SEQ_1)!=HAL_OK){
			Error_Handler();
	}
	if(HAL_SDADC_PollForCalibEvent(&hsdadc1, HAL_MAX_DELAY) !=HAL_OK) {
				Error_Handler();
	}
	if(HAL_SDADC_CalibrationStart(&hsdadc3, SDADC_CALIBRATION_SEQ_1)!=HAL_OK){
			Error_Handler();
	}
	if(HAL_SDADC_PollForCalibEvent(&hsdadc3, HAL_MAX_DELAY) !=HAL_OK) {
				Error_Handler();
	}	
//--------------------------------------------------------
	
		
//	if(HAL_SDADC_InjectedStart_DMA(&hsdadc1, &raw_SDADC[0],1)!= HAL_OK) {
//			Error_Handler();
//	}
//	if(HAL_SDADC_InjectedMultiModeStart_DMA(&hsdadc3, &raw_SDADC[1],2)!= HAL_OK) {
//			Error_Handler();
//	}
//		if(HAL_SDADC_InjectedStart_DMA(&hsdadc3, &raw_SDADC[1],1)!= HAL_OK) {
			if(HAL_SDADC_Start_DMA(&hsdadc1, tc_SDADC,TC_ADC_BUFF_SIZE)!= HAL_OK) {
			Error_Handler();
	}

		if(HAL_SDADC_Start_DMA(&hsdadc3, kelvin_SDADC,KELVIN_BUFF_SIZE)!= HAL_OK) {
			Error_Handler();
	}
		
//----------------------------12bit ADC -------------------------

	if(HAL_ADCEx_InjectedStart(&hadc1)!= HAL_OK) {
			Error_Handler();
	}
	if(HAL_ADCEx_Calibration_Start(&hadc1) !=HAL_OK) {
	}
	if(HAL_ADC_Start_DMA(&hadc1, &raw_ADC[0],MAX_12BIT_ADC_CHANNEL)!= HAL_OK) {
			Error_Handler();
	}
}


#define DISP_NORMAL_SAMPLE	10L
#define DISP_NORMAL_RATE		(DISP_NORMAL_SAMPLE -1)
#define DISP_SLOW_SAMPLE	100L
#define DISP_SLOWL_RATE		(DISP_SLOW_SAMPLE -1)
#define DISP_VSLOW_SAMPLE	500L
#define DISP_VSLOW_RATE		(DISP_VSLOW_SAMPLE -1)

// SDADC Sampling Speed = 6MHz / 360sampe = 16666.67 Sample/sec 
//1ms = 16.67 sample

static void kelvin_SDADC_range_set(kelvin_reg_range_e range) {
  SDADC_ConfParamTypeDef ConfParamStruct;

	if(HAL_SDADC_Stop_DMA(&hsdadc3)!= HAL_OK) {
		Error_Handler();
	}	
	
	switch((uint8_t)range) {
			case R_RANGE_1K:
				ConfParamStruct.Gain = SDADC_GAIN_1;
				KELVIN_CURRENT_1mA;
				cfg.kelvin_adc_gain  =1;
			
				break;
			case R_RANGE_100:
				ConfParamStruct.Gain = SDADC_GAIN_1;
				KELVIN_CURRENT_10mA;
				cfg.kelvin_adc_gain  =1;
				break;
			case  R_RANGE_10:
				ConfParamStruct.Gain = SDADC_GAIN_8;
				KELVIN_CURRENT_10mA;
				cfg.kelvin_adc_gain  =8;
				break;
			case  R_RANGE_1:
				ConfParamStruct.Gain = SDADC_GAIN_16;
				KELVIN_CURRENT_10mA;
				cfg.kelvin_adc_gain  =16;
				break;
			default:
				cfg.set_R_range = R_RANGE_100;
				KELVIN_CURRENT_10mA;
				ConfParamStruct.Gain = SDADC_GAIN_1;
				cfg.kelvin_adc_gain  =1;
				break;
		}

		
				ConfParamStruct.InputMode = SDADC_INPUT_MODE_DIFF;
//				ConfParamStruct.Gain = SDADC_GAIN_1;
				ConfParamStruct.CommonMode = SDADC_COMMON_MODE_VSSA;
				ConfParamStruct.Offset = 0;
				if (HAL_SDADC_PrepareChannelConfig(&hsdadc3, SDADC_CONF_INDEX_1, &ConfParamStruct) != HAL_OK)
				{
					_Error_Handler(__FILE__, __LINE__);
				}			
				
			//---------------Calibration start -----------------------//	
				if(HAL_SDADC_CalibrationStart(&hsdadc3, SDADC_CALIBRATION_SEQ_1)!=HAL_OK){
						Error_Handler();
				}
				if(HAL_SDADC_PollForCalibEvent(&hsdadc3, HAL_MAX_DELAY) !=HAL_OK) {
							Error_Handler();
				}	
				if(HAL_SDADC_Start_DMA(&hsdadc3, kelvin_SDADC,KELVIN_BUFF_SIZE)!= HAL_OK) {
					Error_Handler();
				}
	
}


static void kelvin_calculator(void) {
		int16_t kelvin_buff[KELVIN_BUFF_SIZE];
		uint8_t i;
		int16_t kelvin_adc=0;
		static int8_t befor_R_range =-1;
		static uint16_t zero_calibration_no=0;
		static int64_t kelvin_adc_zero_sum=0;
//		static float  kelvin_adc_gain	= KELVIN_ADC_GAIN;
		float kelvin_adc_zero_offset=0;
		float kelvin_offset_mV;
//		float kelvin_offset_Ohm;
	
	

		for(i=0;i< KELVIN_BUFF_SIZE;i++) {
			kelvin_buff[i] = (int16_t) ((uint32_t)(kelvin_SDADC[i] & 0x0000FFFF));
		}
		arm_mean_q15(kelvin_buff,KELVIN_BUFF_SIZE, &kelvin_adc);

		
		switch((uint8_t)cfg.set_R_range) {
			case R_RANGE_1K:
				KELVIN_CURRENT_1mA;
				break;
			case R_RANGE_100:
				KELVIN_CURRENT_10mA;
				break;
			case  R_RANGE_10:
				KELVIN_CURRENT_10mA;
				break;
			default:
				cfg.set_R_range = R_RANGE_100;
				KELVIN_CURRENT_10mA;
				break;
		}
		
		if(befor_R_range != cfg.set_R_range) {		//Range 변경시 Relay 접점 변경시간 동안 대기
				zero_calibration_no=0;
				kelvin_SDADC_range_set(cfg.set_R_range);
				vTaskDelay(200);
		}
		befor_R_range = cfg.set_R_range;
		
		if(sys.kelvin_mode &(1<<ZERO_CALI)) {
			//ring buffer		
				zero_calibration_no++;
				zero_calibration_no = zero_calibration_no % KELVIN_ZERO_CALI_SAMPLE;
				kelvin_adc_zero_sum +=kelvin_adc;
				if(!zero_calibration_no) {
						kelvin_adc_zero_offset = (double)kelvin_adc_zero_sum/KELVIN_ZERO_CALI_SAMPLE;
						kelvin_adc_zero_sum=0;
						cfg.kelvine_zero_offset[(uint8_t)cfg.set_R_range] =kelvin_adc_zero_offset;
						sys.kelvin_mode &= ~(1<<ZERO_CALI);
						kelvin_offset_mV =  ((double) kelvin_adc_zero_offset    * (mcfg.Vref_SDADC_mV) / (cfg.kelvin_adc_gain * SDADC_RESOL))* mcfg.cali_gain_Kelvin_mV[(uint8_t)cfg.set_R_range] + mcfg.cali_offset_Kelvin_mV[(uint8_t)cfg.set_R_range] ;	//디퍼렌셜
						cfg.kelvine_zero_offset[cfg.set_R_range ] = kelvin_offset_mV/mcfg.Kelvin_current_mA[(uint8_t)cfg.set_R_range];
				}
		}
		
		measu_data.Kelvin_mV = ((double)kelvin_adc * (mcfg.Vref_SDADC_mV) / (cfg.kelvin_adc_gain * SDADC_RESOL))* mcfg.cali_gain_Kelvin_mV[(uint8_t)cfg.set_R_range] + mcfg.cali_offset_Kelvin_mV[(uint8_t)cfg.set_R_range] ;	//디퍼렌셜
		measu_data.Kelvin_Ohm = measu_data.Kelvin_mV/mcfg.Kelvin_current_mA[(uint8_t)cfg.set_R_range] - cfg.kelvine_zero_offset[cfg.set_R_range ];
	
}


void ADC_handller(void) {
		uint8_t i;
		int32_t tc_adc=0;

	#if 0
		tc_adc = (int16_t) ((uint32_t)(raw_SDADC[0] & 0x0000FFFF));
		kelvin_adc = (int16_t) ((uint32_t)(raw_SDADC[1] & 0x0000FFFF));
	#else
		arm_mean_q31((int32_t *)tc_SDADC,TC_ADC_BUFF_SIZE, &tc_adc);
		tc_adc = (int16_t)((uint32_t)tc_adc&0xFFFF);
		
	#endif
		//SDADC_GAIN_4


/*
AD8495는 5mV/degC
AD8495의 REF_V = 1.25V
		VOUT 의 RATIO  =  저항 분압비가 1/4 이므로 측정전압 *4 를 하여 AD8495 출력전압 계산		
*/
		
		measu_data.TC_mV = ((((double)tc_adc + 32768) * mcfg.Vref_SDADC_mV) / (TC_ADC_GAIN * SDADC_RESOL)) *AD8495_VOUT_RATIO * mcfg.cali_gain_TC_V + mcfg.cali_offset_TC_mV;//싱글엔디드
		measu_data.TC_temp = ((((double)measu_data.TC_mV) -((float)mcfg.Vref_mV_TC))/AD8495_mV_FOR_degC)*mcfg.cali_gain_TC_Temp  + mcfg.cali_offset_TC_Temp;		


	kelvin_calculator();
//----------------------------12bit ADC -------------------------
		
		for(i=0; i <=MAX_12BIT_ADC_CHANNEL; i++) {
				measu_data.ADC_mV[i] = (float)raw_ADC[i]/ADC_TO_VOLTAGE_RATIO * mcfg.Gain_ADC[i] + mcfg.Offset_ADC_mV[i];
		}
		
}





void moving_avg_update(void) {
	static 	float  sample_item[SAMPLE_MAX_ITEM];
	uint8_t i;
	
		sample_item[0] = measu_data.Kelvin_Ohm;
		sample_item[1] = measu_data.Kelvin_mV;
		sample_item[2] = measu_data.TC_mV;
		sample_item[3] = measu_data.TC_temp;
		sample_item[4] = measu_data.ADC_mV[0];
		sample_item[5] = measu_data.ADC_mV[1];
	
	 for(i=0;i<SAMPLE_MAX_ITEM; i++) {	
			switch((uint8_t)cfg.display_speed[i]) {
			case DISPLAY_FAST:
				avg_item[i] = sample_item[i];
				break;
			case DISPLAY_NORMAL:
				avg_item[i] =  (avg_item[i] * DISP_NORMAL_RATE + sample_item[i]) / DISP_NORMAL_SAMPLE;  
				break;
			case DISPLAY_SLOW:
				avg_item[i] =  (avg_item[i] * DISP_SLOWL_RATE + sample_item[i]) / DISP_SLOW_SAMPLE;  
				break;
			case DISPLAY_VERY_SLOW:
				avg_item[i] =  (avg_item[i] * DISP_VSLOW_RATE + sample_item[i]) / DISP_VSLOW_SAMPLE;  
				break;
			}
		}
		
}

static float TC_cali_map [][2] ={			//열전상 온도 보정맵
{	-100	,	-83.2	},	
{	-80	,	-67.9	},	
{	-50	,	-42.5	},	
{	-30	,	-23.9},
{	-20	,	-15.2},
{	0.001	,	4.9	},
{	50	,	55.2	},
{	100	,	106.1	},
{	200	,	206.8	},
{	300	,	308.1
},
{	400	,	412.3	},
{	500	,	517.7},	
{	600	,	622.9	},	
{	700	,	730.2	},
{	800	,	834},
{	900	,	935.1	},
{	1000	,	1033.6},
{	1100	,	1129.3},
{	1200	,	1222.2},
{	1300	,	1312.2},
{	1370	,	1372.2},

};
#define TC_R_MAP_DATA_SIZE 	(sizeof(TC_cali_map)/ sizeof(TC_cali_map[0]))
	

static float interpolation (float (* pMap_data)[2], float  input_value, uint16_t size_dim ) {		//직선보간 함수
	float  Interpolation_result=0;
	float A0=0, A=0, gap=0, T0=0;	
	uint16_t i=0;
	
	for( i=0; i < size_dim ; i++) {
		if(( pMap_data[i][1] <=  input_value && pMap_data[i+1][1] >=  input_value) || pMap_data[0][1] > input_value) {
			#if 1	//1열 2열 이 모두 오름차순일 경우
			gap = pMap_data[i+1][0] - pMap_data[i][0];//속한 구간의 큰값 - 작은값
			T0 =  pMap_data[i+1][0];
			A0 =pMap_data[i+1][1];
			A =  pMap_data[i][1];
			#else		//1열 오름 차순 2열이 내림차순일 경우
			gap = pMap_data[i][0] - pMap_data[i+1][0];//속한 구간의 큰값 - 작은값
			T0 =  pMap_data[i][0];
			A0 =pMap_data[i][1];
			A =  pMap_data[i+1][1];
			#endif
			break;
		}
	}
 	Interpolation_result = (T0 - (A0-  input_value)/(A0-A) *gap);		// 실수 보정계산
//	Interpolation_result = ((T0<<7) - ((A0-input_value)<<7)/(A0-A) *gap)>>7;		//보정계산 
	return Interpolation_result ;
}


float Calibration_TC_value(float input_TC) {
//			return	interpolation(TC_ch_set[TCNo].cali_map,(((float)tc_value->Raw_Temp*0.25)+tc_value->CJC_Temp), TC_ch_set[TCNo].table_size  );
			return	interpolation(TC_cali_map, input_TC, TC_R_MAP_DATA_SIZE  );
	
}

			

// int16_t Calibration_TC_Table[][3] = {
//{	-40	,	650	,	0	},//시작데이터는 추세를 연장한  추측데이터임 
//{	596	,	600	,	1631	},
//{	603	,	547	,	1577	},
//{	610	,	500	,	1557	},
//{	620	,	444	,	1609	},
//{	629	,	401	,	1620	},
//{	642	,	348	,	1616	},
//{	655	,	299	,	1453	},
//{	673	,	248	,	1584	},
//{	695	,	199	,	1614	},
//{	708	,	172	,	1442	},
//{	720	,	155	,	1883	},
//{	740	,	128	,	1742	},
//{	769	,	100	,	2053	},
//{	800	,	77	,	2243	},
//{	825	,	62	,	2405	},
//{	859	,	48	,	3102	},
//{	900	,	36	,	3854	},
//{	950	,	25	,	4526	},

//{-1,0,0},
//};


//#define DISP_MIN_DEGC -100
//#define DISP_MAX_DEGC 1400
// float  Calibraton_TC_to_Temperature (int16_t (* table)[3], float  TC_degC) {
//	int32_t	temp_degC;
//	uint8_t	 i=0;
//	uint32_t 	K0;
//	uint32_t 	R0;
//	uint32_t 	B_10x;
////	float Rpvs_Ohm = (Rpvs_mOhm/1000);
////	float Rpvs_Ohm = L9780_stat.Rpvs;
//		if( TC_degC < DISP_MIN_DEGC ){
//				temp_degC =  DISP_MIN_DEGC;
//				return 0;
//		}
//		else if( DISP_MAX_DEGC > table[0][1]){	//테이블의 최대 저항값보다 클경우
//			temp_degC = DISP_MAX_DEGC;
//				return 0;
//		}
//		else {
//				for(i=0 ;table[i][0] >= 0; i++) {
//						if( TC_degC<= table[i][1] && TC_degC > table[i+1][1] ){
//							K0 = table[i][0];
//							R0 = table[i][1];
//							B_10x  = table[i+1][2];
//							temp_degC = K0*exp((float)B_10x/10*((float)1/(273+ TC_degC)-(float)1/(273+R0)));
////						temp_degC =  (uint16_t)temp_degC;
//							return temp_degC;
//						}
//				}
//		}
//		return DISP_MIN_DEGC;	//open TC
//}
