#pragma once

#include "stm32f3xx_hal.h"
#include "cmsis_os.h"
#include <stdbool.h>
#include <string.h>


#define EEPROM_VERSION 1
#define UART1_BAURD 115200


#define DAC_RESOLUTION 	0x0FFF		//12bit
//#define DAC_OUTPUT_MIN_DEFAULT_mV		0
#define DAC_OUTPUT_MAX_DEFAULT_mV		5000


#define SDADC_VREF        2500  /* SDADC external reference is set to 3.3V */
#define TC_VREF		1250
#define DEFAULT_ADC_REF_3_3V_mV     3300    // ADC Ref Voltage
#define MAX_12BIT_ADC_CHANNEL 	2


#define DC_MEAS_Reg_PullUp  115000      //ohm
#define DC_MEAS_Reg_PullDown  10000    //ohm
#define  ADC_TO_VOLTAGE_RATIO		((4095/((((float)DC_MEAS_Reg_PullUp+DC_MEAS_Reg_PullDown)/DC_MEAS_Reg_PullDown)*((float)mcfg.Vref_ADC_mV/1000)))/1000)


#define KELVIN_ADC_GAIN           (uint32_t) 1
#define TC_ADC_GAIN           (uint32_t) 2
#define SDADC_RESOL          (uint32_t) 65535 /* 2e16 - 1 */
#define AD8495_mV_FOR_degC		5
#define AD8495_PULLUP_REG		30000
#define AD8495_PULLDOWN_REG		10000
#define AD8495_VOUT_RATIO			((AD8495_PULLUP_REG+AD8495_PULLDOWN_REG)/AD8495_PULLDOWN_REG)

	
#ifdef RANGE_Pin
	#define R_100_OHM_RANGE					RANGE_GPIO_Port->BSRR = RANGE_Pin
	#define R_1K_OHM_RANGE         RANGE_GPIO_Port->BRR = RANGE_Pin
#else
	#define R_100_RANGE				;
	#define R_1K_RANGE         ;
#endif


//#define USB_DISCONNEC_PORT 	USB_EN_GPIO_Port
//#define USB_DISCONNECT_PIN 		 USB_EN_Pin

//#define USB_DECTETION_ENABLE                  digitalLo(USB_DISCONNEC_PORT, USB_DISCONNECT_PIN)	//fet on
//#define USB_DECTETION_DISABLE                digitalHi(USB_DISCONNEC_PORT, USB_DISCONNECT_PIN)		//fet off
#define USB_DECTETION_DISABLE                  USB_EN_GPIO_Port->BRR = USB_EN_Pin	//npn tr off
#define USB_DECTETION_ENABLE               USB_EN_GPIO_Port->BSRR = USB_EN_Pin		//npn tr on

#ifdef RELAY_Pin
	#define RELAY1_ON					RELAY_GPIO_Port->BSRR = RELAY_Pin
	#define RELAY1_OFF         RELAY_GPIO_Port->BRR = RELAY_Pin
	#define RELAY1_TOGGLE         digitalToggle(RELAY_GPIO_Port,RELAY_Pin)
#endif


#ifdef L1_Pin
	#define L1_ON					L1_GPIO_Port->BSRR = L1_Pin
	#define L1_OFF         L1_GPIO_Port->BRR = L1_Pin
	#define L1_TOGGLE         digitalToggle(L1_GPIO_Port,L1_Pin)
#else
	#define L1_ON				;
	#define L1_OFF         ;
	#define L1_TOGGLE         ;
#endif

#ifdef L2_Pin
	#define L2_ON					L2_GPIO_Port->BSRR = L2_Pin
	#define L2_OFF         L2_GPIO_Port->BRR = L2_Pin
	#define L2_TOGGLE         digitalToggle(L2_GPIO_Port,L2_Pin)
#else
	#define L2_ON				;
	#define L2_OFF         ;
	#define L2_TOGGLE         ;
#endif

#ifdef L3_Pin
	#define L3_ON					L3_GPIO_Port->BSRR = L3_Pin
	#define L3_OFF         L3_GPIO_Port->BRR = L3_Pin
	#define L3_TOGGLE         digitalToggle(L3_GPIO_Port,L3_Pin)
#else
	#define L3_ON				;
	#define L3_OFF         ;
	#define L3_TOGGLE         ;
#endif

#ifdef C_CTL_Pin
	#define C_CTL_HIGH					C_CTL_GPIO_Port->BSRR = C_CTL_Pin
	#define C_CTL_LOW        C_CTL_GPIO_Port->BRR = C_CTL_Pin
	#define C_CTL_TOGGLE         digitalToggle(C_CTL_GPIO_Port,C_CTL_Pin)
#else
	#define C_CTL_HIGH				;
	#define C_CTL_LOW        ;
	#define C_CTL_TOGGLE         ;
#endif

#define RED_DI_CH1		((DI_CH1_GPIO_Port->IDR & DI_CH1_Pin) != (uint32_t)GPIO_PIN_RESET)
#define RED_DI_CH2		((DI_CH2_GPIO_Port->IDR & DI_CH2_Pin) != (uint32_t)GPIO_PIN_RESET)
#define RED_DI_CH3		((DI_CH3_GPIO_Port->IDR & DI_CH3_Pin) != (uint32_t)GPIO_PIN_RESET)

#define READ_DI_PORT		((RED_DI_CH1 | (RED_DI_CH2<<1) | (RED_DI_CH1<<2))&0x07)

#include "drv_system.h"
#include "adc.h"
#include "lc_meter.h"
//#include "drv_uart.h"
//#include "drv_serial.h"
//#include "serial.h"
#include "uart_dma.h"
#include "serial.h"

#include "vcp.h"
#include "can.h"
#include "can_queue.h"
#include "cli.h"
#include "function.h"
#include "dac.h"
#include "config.h"
#include "Digital_control.h"
#include "rtc.h"

