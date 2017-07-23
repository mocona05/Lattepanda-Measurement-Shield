#include "board.h"

extern DAC_HandleTypeDef hdac1;
extern DAC_HandleTypeDef hdac2;

void DAC_init(void) {
	if(HAL_DAC_Start(&hdac1, DAC_CHANNEL_1) != HAL_OK) { 
			Error_Handler();
	}
	if(HAL_DAC_Start(&hdac2, DAC_CHANNEL_1) != HAL_OK) { 
			Error_Handler();
	}
	sys.DAC1_out_mV = 5000;
	sys.DAC2_out_mV = 5000;
	
}


void DAC_output_handller(void) {
		uint16_t cali_dac1_ouput_digit, cali_dac2_ouput_digit;

		cali_dac1_ouput_digit = 	((float)sys.DAC1_out_mV*mcfg.cali_gain_DAC[0]	 - mcfg.cali_offset_mV_DAC[0])/(DAC_OUTPUT_MAX_DEFAULT_mV) * DAC_RESOLUTION;
		cali_dac2_ouput_digit = 	((float)sys.DAC2_out_mV*mcfg.cali_gain_DAC[1]	 - mcfg.cali_offset_mV_DAC[1])/(DAC_OUTPUT_MAX_DEFAULT_mV) * DAC_RESOLUTION;
	
		if(cali_dac1_ouput_digit > DAC_RESOLUTION) {
			cali_dac1_ouput_digit =  DAC_RESOLUTION;
		}
		if(cali_dac2_ouput_digit > DAC_RESOLUTION) {
			cali_dac2_ouput_digit =  DAC_RESOLUTION;
		}
		
		if(HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, cali_dac1_ouput_digit) != HAL_OK) { 
		/* Setting value Error */ 
		}
		if(HAL_DAC_SetValue(&hdac2, DAC_CHANNEL_1, DAC_ALIGN_12B_R, cali_dac2_ouput_digit) != HAL_OK) { 
		/* Setting value Error */ 
		}	
}

