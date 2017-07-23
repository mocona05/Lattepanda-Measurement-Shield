#pragma once
#include <stdbool.h>

extern 	uint32_t raw_SDADC[3];
extern 	uint32_t raw_ADC[MAX_12BIT_ADC_CHANNEL];
extern double avg_item[];

void ADC_handller(void);

void ADC_init(void);
void moving_avg_update(void);
float Calibration_TC_value(float input_TC);

