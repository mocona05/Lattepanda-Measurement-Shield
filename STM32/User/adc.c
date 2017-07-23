#include "board.h"

uint32_t raw_SDADC[3];
uint32_t raw_ADC[MAX_12BIT_ADC_CHANNEL];
extern SDADC_HandleTypeDef hsdadc1;
extern SDADC_HandleTypeDef hsdadc3;
extern ADC_HandleTypeDef hadc1;

double avg_item[SAMPLE_MAX_ITEM];


void ADC_init(void) {
	if (HAL_SDADC_InjectedConfigChannel(&hsdadc1, SDADC_CHANNEL_6, SDADC_CONTINUOUS_CONV_ON) != HAL_OK) {
		Error_Handler();
	}

		if (HAL_SDADC_InjectedConfigChannel(&hsdadc3, SDADC_CHANNEL_8, SDADC_CONTINUOUS_CONV_ON) != HAL_OK){
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
	
		
	if(HAL_SDADC_InjectedStart_DMA(&hsdadc1, &raw_SDADC[0],1)!= HAL_OK) {
			Error_Handler();
	}
//	if(HAL_SDADC_InjectedMultiModeStart_DMA(&hsdadc3, &raw_SDADC[1],2)!= HAL_OK) {
//			Error_Handler();
//	}
		if(HAL_SDADC_InjectedStart_DMA(&hsdadc3, &raw_SDADC[1],1)!= HAL_OK) {
			Error_Handler();
	}
		
//----------------------------12bit ADC -------------------------

	if(HAL_ADCEx_InjectedStart(&hadc1)!= HAL_OK) {
			Error_Handler();
	}
	if(HAL_ADCEx_Calibration_Start(&hadc1) !=HAL_OK) {
	}
	if(HAL_ADC_Start_DMA(&hadc1, &raw_ADC[0],2)!= HAL_OK) {
			Error_Handler();
	}
}

void ADC_handller(void) {
		static int8_t befor_R_range =-1;

		uint8_t i;
		int16_t tc_adc=0;
		int16_t kelvin_adc=0;
		
		uint16_t Kelvin_current_mA;
		/* Returns the injected channel conversion data */
		tc_adc = (int16_t) ((uint32_t)(raw_SDADC[0] & 0x0000FFFF));
		kelvin_adc = (int16_t) ((uint32_t)(raw_SDADC[1] & 0x0000FFFF));
		
		switch((uint8_t)cfg.set_R_range) {
			case R_RANGE_1K:
				R_1K_OHM_RANGE;
				break;
			case R_RANGE_100:
				R_100_OHM_RANGE;
				break;
			default:
				cfg.set_R_range = R_RANGE_100;
				R_100_OHM_RANGE;
				break;
		}
		if(befor_R_range != cfg.set_R_range) {		//Range 변경시 Relay 접점 변경시간 동안 대기
				vTaskDelay(200);
		}
		befor_R_range = cfg.set_R_range;
		
		measu_data.Kelvin_mV = ((float)kelvin_adc * (mcfg.Vref_SDADC_mV) / (KELVIN_ADC_GAIN * SDADC_RESOL)) ;	//디퍼렌셜
		
		switch((uint8_t)cfg.set_R_range) {
			case R_RANGE_1K:
				Kelvin_current_mA = 1;
//				measu_data.read_R_range = R_RANGE_1K;		//1~1k Ohm Range
				measu_data.Kelvin_Ohm = measu_data.Kelvin_mV/Kelvin_current_mA * mcfg.cali_gain_Kelvin[R_RANGE_1K] + mcfg.cali_offset_Kelvin_Ohm[R_RANGE_1K];
				break;
			case R_RANGE_100:
				Kelvin_current_mA = 10;
//				measu_data.read_R_range = R_RANGE_100;		//0.1 ~ 100 Ohm Range
				measu_data.Kelvin_Ohm = measu_data.Kelvin_mV/Kelvin_current_mA * mcfg.cali_gain_Kelvin[R_RANGE_100] + mcfg.cali_offset_Kelvin_Ohm[R_RANGE_100];
				break;
		}
	
		
/*
AD8495는 5mV/degC
AD8495의 REF_V = 1.25V
		VOUT 의 RATIO  =  저항 분압비가 1/4 이므로 측정전압 *4 를 하여 AD8495 출력전압 계산		
*/
		measu_data.TC_mV = ((((double)tc_adc + 32768) * mcfg.Vref_SDADC_mV) / (KELVIN_ADC_GAIN * SDADC_RESOL)) *AD8495_VOUT_RATIO * mcfg.cali_gain_TC_V + mcfg.cali_offset_TC_mV;//싱글엔디드
		measu_data.TC_temp = ((((double)measu_data.TC_mV) -((float)mcfg.Vref_mV_TC))/AD8495_mV_FOR_degC)*mcfg.cali_gain_TC_Temp  + mcfg.cali_offset_TC_Temp;		

//----------------------------12bit ADC -------------------------
		
		for(i=0; i <=MAX_12BIT_ADC_CHANNEL; i++) {
				measu_data.ADC_mV[i] = (float)raw_ADC[i]/ADC_TO_VOLTAGE_RATIO * mcfg.Gain_ADC[i] + mcfg.Offset_ADC_mV[i];
		}
}


#define DISP_NORMAL_SAMPLE	10L
#define DISP_NORMAL_RATE		(DISP_NORMAL_SAMPLE -1)
#define DISP_SLOW_SAMPLE	100L
#define DISP_SLOWL_RATE		(DISP_SLOW_SAMPLE -1)
#define DISP_VSLOW_SAMPLE	1000L
#define DISP_VSLOW_RATE		(DISP_VSLOW_SAMPLE -1)


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
