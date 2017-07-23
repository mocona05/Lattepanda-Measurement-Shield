#pragma once
#include <stdbool.h>
#define LC_CHECK_COUNT		50000L

#define		L2_VALUE  99.70f			//Tank
#define		REF_L1_VALUE  99.53f

#define  	C3 1041.6f					//Tank
#define   REF_C1		986.0f					//calibration cab

#define ICP_TIMER_CNT_CLEAR				TIM4->CNT	=0
#define ICP_TIMER_CCR_CLEAR				TIM4->CCR4	=0

#define ICP_TIMER_ENABLE								TIM4->CR1 |= TIM_CR1_CEN//TIM_Cmd(TIM4, ENABLE)
#define ICP_TIMEE_IC_IT_ENABLE				TIM4->DIER |= TIM_IT_CC4
#define ICP_CONT_READ				TIM4->CNT

#define ICP_TIMER_DISABLE								TIM4->CR1 &= (uint16_t)(~((uint16_t)TIM_CR1_CEN))//TIM_Cmd(TIM4, DISABLE)
#define ICP_TIMEE_IC_IT_DISABLE				TIM4->DIER &= (uint16_t)~TIM_IT_CC4
#define ICP_PULS_COUNT		TIM4->CCR4

extern double Cx, Lx;

extern uint32_t F3;
extern volatile  uint32_t ICPValue;
	
	
extern 	volatile bool LC_measu_complit_f;
extern volatile uint32_t ICPcount;
extern volatile  uint32_t ICPValue;	

void LC_meter_Init(void) ;
//void Measure_LX_LX(void);
void LC_meter_handller(void);
