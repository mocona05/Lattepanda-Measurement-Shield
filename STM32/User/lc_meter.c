#include "board.h"

// # Mesurement Range
// L : 0.1uH~100mH
// C : 0.1pF~0.5uF(about 1uF)



uint32_t befor_times, time_ms;


//typedef struct {
//      uint32_t F1_000;  // CxCx, CxLx, CxLx1,   LxLx
//      uint32_t F2_001;  // CxCx, CxLx1
//      uint32_t F2_100;  // CxLx
//      uint32_t F2_110;  // LxLx
//} frequency_t;



//uint32_t  f1=0,f2=0,f3=0;
//double a=0, b=0, c=0;
//double value=0;
//frequency_t freq;

//volatile uint32_t CountLow = 0;
//volatile uint32_t over_count = 0;

volatile bool LC_measu_complit_f=0;
volatile uint32_t ICPcount = 0;
volatile  uint32_t ICPValue = 0;	


uint32_t F3 = 0;

double Cx, Lx;

//static bool MeasureLC(uint32_t * LC_result);
//static void Measure_LC_timer_set(void);
static bool measuring_freq(uint32_t * Freq);

static bool Calibration(void);

static bool Measure_Cap(bool start);
static void LC_ICP_start(void);
static void LC_ICP_stop(void);
static bool Measure_CX_LX(bool start);
static bool Measure_CX_LX1(bool start);
static bool Measure_LX_LX(bool start);

typedef enum {
	CALIB_INIT,
	CALIB_START,
	CALIB_000,
	CALIB_001,
	CALIB_100,
	CALIB_110,
	CALIB_END,
	
} calib_status_e;


typedef enum {
	MEASU_LC_START,
	MEASU_LC_SET,
	MEASU_TIME_CLEAR,
	MEASU_ICP_ENABLE,
	CALCULATON_LC,
}measu_cap_e;


static bool Measure_LX_LX(bool start) {
	static uint32_t beforTime =0, wait_time=0;
	uint32_t timeNow;	
	double a,b,c,d;
	static measu_cap_e status = MEASU_LC_START;
//  uint8_t i;
	double f3_freq=0;
	double L2=0;
	timeNow = millis();

    if ( beforTime  + wait_time  >  timeNow &&  timeNow >= beforTime) {	//경과 않됨?
			return false;
		}	
		if(start) {
			status = MEASU_LC_START;
		}	
		switch((uint8_t)status) {
				case MEASU_LC_START:
					LC_ICP_stop();
					wait_time =100;
					status = MEASU_LC_SET;
					break;
				
				case MEASU_LC_SET:
						L1_OFF;
						L2_ON;
						L3_OFF;
						status = MEASU_ICP_ENABLE;
						wait_time =200;
						break;
				case MEASU_ICP_ENABLE:
						LC_ICP_start();
						wait_time =1;
						status = MEASU_TIME_CLEAR;
						break;
					
				case MEASU_TIME_CLEAR:
						wait_time =1;
						if(LC_measu_complit_f) {
								LC_measu_complit_f =false;
								status = CALCULATON_LC;
						}
						break;
				
				case CALCULATON_LC:
					f3_freq = LC_CHECK_COUNT  / ((double)ICPValue/1000000);
					F3 =f3_freq;
			// Lx모드에서 Lx=? , L1과 Lref 직렬하고 F2측정, Lref off하고 L1과 측정Lx를 직렬 F3측정..
		        L2 = L2_VALUE*((double)0.000001); //220uH , Lref=L2
		        //lx= ( (f2*f2)*(f1*f1-f3*f3)/(f3*f3)*(f1*f1-f2*f2) )*l2;//LX = (L2 * F2^2*(F1^2 -F3^2)) / (F3^2  *(F1^2 - F2^2));
					a=(double)cfg.F1_000*cfg.F1_000;
					b=(double)cfg.F2_110*cfg.F2_110;
					c=(double)f3_freq*f3_freq;
					d= (b*(a-c)) * L2 ;
					Lx = d /(c*(a-b)) * 1000000;			            

					wait_time =100;
					status = MEASU_ICP_ENABLE;
					return true;
					
		}
		return false;	
}


static bool Measure_CX_LX1(bool start) {
	static uint32_t beforTime =0, wait_time=0;
	uint32_t timeNow;	
//	double a, b;
	static measu_cap_e status = MEASU_LC_START;
//  uint8_t i;
	double f3_freq=0;
//	double L2=0;
	double a,b,c,d;
	timeNow = millis();
	
    if ( beforTime  + wait_time  >  timeNow &&  timeNow >= beforTime) {	//경과 않됨?
			return false;
		}	
		if(start) {
			status = MEASU_LC_START;
		}	
		switch((uint8_t)status) {
				case MEASU_LC_START:
					LC_ICP_stop();
					wait_time =100;
					status = MEASU_LC_SET;
					break;
				
				case MEASU_LC_SET:
						L1_OFF;
						L2_ON;
						L3_OFF;
						status = MEASU_ICP_ENABLE;
						wait_time =200;
						break;
				case MEASU_ICP_ENABLE:
						LC_ICP_start();
						wait_time =1;
						status = MEASU_TIME_CLEAR;
						break;
					
				case MEASU_TIME_CLEAR:
						wait_time =1;
						if(LC_measu_complit_f) {
								LC_measu_complit_f =false;
								status = CALCULATON_LC;
						}
						break;
				
				case CALCULATON_LC:
					f3_freq = LC_CHECK_COUNT  / ((double)ICPValue/1000000);
					F3 =f3_freq;
	        a = (((double)cfg.F1_000/f3_freq) * ((double)cfg.F1_000/f3_freq)) - 1;				
	        b = (((double)cfg.F1_000/cfg.F2_001) * ((double)cfg.F1_000/cfg.F2_001)) - 1;
//	        c = 1000000000; // = 1/1000pf = (/1000)* 10^12 = (10^-3)*(10^12) = 10^9
	        c = 1086 *1000000; // = 1/1000pf = (/1000)* 10^12 = (10^-3)*(10^12) = 10^9
	        d = (1/((double)6.283*cfg.F1_000)) * (1/((double)6.283*cfg.F1_000));					
					Lx = (a*b*c*d *1000000);
				
					wait_time =100;
					status = MEASU_ICP_ENABLE;
	
					return true;
					
		}
		return false;	
}


static bool Measure_CX_LX(bool start) {
	static uint32_t beforTime =0, wait_time=0;
	uint32_t timeNow;	
//	double a, b;
	static measu_cap_e status = MEASU_LC_START;
//  uint8_t i;
	double f3_freq=0;
	double L2=0;
	timeNow = millis();

    if ( beforTime  + wait_time  >  timeNow &&  timeNow >= beforTime) {	//경과 않됨?
			return false;
		}	
		if(start) {
			status = MEASU_LC_START;
		}	
		switch((uint8_t)status) {
				case MEASU_LC_START:
					LC_ICP_stop();
					wait_time =100;
					status = MEASU_LC_SET;
					break;
				
				case MEASU_LC_SET:
						L1_OFF;
						L2_OFF;
						L3_OFF;
						status = MEASU_ICP_ENABLE;
						wait_time =200;
						break;
				case MEASU_ICP_ENABLE:
						LC_ICP_start();
						wait_time =1;
						status = MEASU_TIME_CLEAR;
						break;
					
				case MEASU_TIME_CLEAR:
						wait_time =1;
						if(LC_measu_complit_f) {
								LC_measu_complit_f =false;
								status = CALCULATON_LC;
						}
						break;
				
				case CALCULATON_LC:
					f3_freq = LC_CHECK_COUNT  / ((double)ICPValue/1000000);
					F3 =f3_freq;
	        L2=(double)REF_L1_VALUE*(double)0.000001; // 220uH, L1과 병렬,Lref병렬하고, F2측정,,, Lref off하고 Lx병렬 F3측정..
//	        L2=(double)200*(double)0.000001; // 220uH, L1과 병렬,Lref병렬하고, F2측정,,, Lref off하고 Lx병렬 F3측정..
	        // CX모드에서 lx=?  // Lref=L2
	        Lx= ((double)cfg.F2_100*cfg.F2_100 - (double)cfg.F1_000*cfg.F1_000)*L2 / ((double)f3_freq*f3_freq - (double)cfg.F1_000*cfg.F1_000); // LX= (F2^2-F1^2)*L2 / (F3^2-F1^2);
					Lx *= 1000000;
//	        Value=lx;
//	        Value *= 1000000;
					wait_time =100;
					status = MEASU_ICP_ENABLE;
					return true;
					
		}
		return false;	
}


static bool Measure_Cap(bool start){
	static uint32_t beforTime =0, wait_time=0;
	uint32_t timeNow;	
	double a, b;
	static measu_cap_e status = MEASU_LC_START;
//  uint8_t i;
	double f3_freq=0;

	timeNow = millis();

    if ( beforTime  + wait_time  >  timeNow &&  timeNow >= beforTime) {	//경과 않됨?
			return false;
		}	
		if(start) {
			status = MEASU_LC_START;
		}
		switch((uint8_t)status) {
				case MEASU_LC_START:
					LC_ICP_stop();
					wait_time =100;
					status = MEASU_LC_SET;
					break;
				
				case MEASU_LC_SET:
						L1_OFF;
						L2_OFF;
						L3_OFF;
						status = MEASU_ICP_ENABLE;
						wait_time =200;
						break;
				case MEASU_ICP_ENABLE:
						LC_ICP_start();
						wait_time =1;
						status = MEASU_TIME_CLEAR;
						break;
					
				case MEASU_TIME_CLEAR:
						wait_time =1;
						if(LC_measu_complit_f) {
								LC_measu_complit_f =false;
								status = CALCULATON_LC;
						}
						break;
				
				case CALCULATON_LC:
//				    F3 = (uint32_t) (SystemCoreClock / ICPValue);
						f3_freq = LC_CHECK_COUNT  / ((double)ICPValue/1000000);
						F3 =f3_freq;
						a = (((double)cfg.F1_000/f3_freq) * ((double)cfg.F1_000/f3_freq)) - 1;
						b = (((double)cfg.F1_000/cfg.F2_001) * ((double)cfg.F1_000/cfg.F2_001)) - 1;
//						Cx = ((double)a / b) *969.7;// REF_C1;//1000; // pF
						Cx = ((double)a / b) *979.0;// REF_C1;//1000; // pF				
//						status = MEASU_CAP_CALCUL;
						wait_time =100;
								
					status = MEASU_ICP_ENABLE;
					return true;
					
		}
		return false;
	
}



typedef enum {
		FREQ_MEASU_SET,
		FREQ_MEASU,
		MEASU_CYCLE,
}measu_set_e;


static bool measuring_freq(uint32_t * Freq) {
	static uint32_t beforTime =0, wait_time=0;
	uint32_t timeNow;	
	static measu_set_e status = FREQ_MEASU_SET;
	timeNow = millis();
    if ( beforTime  +wait_time  >  timeNow &&  timeNow >= beforTime) {	//경과 않됨?
			return false;
		}	

		switch((uint8_t)status) {
				case FREQ_MEASU_SET:
					wait_time =1;
					LC_ICP_start();
					status = FREQ_MEASU;
					break;
				
				case FREQ_MEASU:
						wait_time =1;
						if(LC_measu_complit_f) {
							LC_measu_complit_f =false;
							* Freq = (uint32_t)(LC_CHECK_COUNT  / ((double)ICPValue/1000000));
								status = FREQ_MEASU_SET;
								return true;

						}
						break;
		}
		return false;
}



static bool Calibration(void){
		static uint32_t beforTime =0, wait_time=0;
		uint32_t timeNow;	
		uint32_t freq=0;
	
		static calib_status_e status = CALIB_INIT;
		timeNow = millis();
    if ( beforTime  + wait_time  >  timeNow &&  timeNow >= beforTime) {	//경과 않됨?
			return false;
		}	
		switch((uint8_t)status) {
			case CALIB_INIT:
						LC_ICP_stop();
						L1_OFF;
						L2_OFF;
						L3_OFF;
						wait_time =800;	
						status=CALIB_START;
						break;
			
			case CALIB_START:
						LC_ICP_start();
						status=CALIB_000;
						wait_time =1;	
						break;
			
				case CALIB_000:
						L1_OFF;
						L2_OFF;
						L3_OFF;
						if(measuring_freq(&freq)) {
								cfg.F1_000 =freq;
								status=CALIB_001;
								wait_time =800;	
								L1_OFF;
								L2_OFF;
								L3_ON;
						}						
						break;
				
				case CALIB_001:
						L1_OFF;
						L2_OFF;
						L3_ON;

						if(measuring_freq(&freq)) {
								cfg.F2_001 =freq;
								status=CALIB_100;
								wait_time =800;	
								L1_ON;
								L2_OFF;
								L3_OFF;
						}
						break;
				case CALIB_100:
						L1_ON;
						L2_OFF;
						L3_OFF;
						if(measuring_freq(&freq)) {
							cfg.F2_100 =freq;
								status=CALIB_110;
								wait_time =800;	
								L1_ON;
								L2_ON;
								L3_OFF;
						}
						break;
				case CALIB_110:
						L1_ON;
						L2_ON;
						L3_OFF;

						if(measuring_freq(&freq)) {
								cfg.F2_110 =freq;
								status=CALIB_START;
								wait_time =0;	
								beforTime= timeNow;	 
								L1_OFF;
								L2_OFF;
								L3_OFF;
								return true;
						}
						break;
		}
		beforTime= timeNow;	 
		return false;
}


void LC_meter_handller(void) {
	static bool calib_result=false;
	if(!calib_result && Calibration()) {
		calib_result = true;
//			Measure_CX_LX(true);		//측정이 잘않됨.
//			Measure_CX_LX1(true);		//교정전 정확도 낮음 교정하면 그나마 쓸만함.
		
//			Measure_LX_LX(true);		//L측정시 정확도가 가장높음 (교정전에도 정확도가 잘나옴)
		Measure_Cap(true);			// C측정용
	}
	if(calib_result) {
		
//			Measure_LX_LX(false);
			Measure_Cap(false);
	}

//	
//	if(!measu_cap && Measure_Cap(1)){
//		measu_cap = true;
//	}
}


static void LC_ICP_start(void) {
		ICPcount =0;
		LC_measu_complit_f =false;
	ICP_TIMER_ENABLE;
	ICP_TIMEE_IC_IT_ENABLE;
	
//		if(HAL_TIM_Base_Start(&htim4) !=HAL_OK) {
//					Error_Handler();
//	}
//	if(HAL_TIM_IC_Start(&htim4,TIM_CHANNEL_4)!=HAL_OK) {
//			Error_Handler();
//	}
//	if(HAL_TIM_IC_Start_IT(&htim4,TIM_CHANNEL_4) !=HAL_OK) {
//					Error_Handler();
//	}
}
static void LC_ICP_stop(void) {
		ICPcount =0;
		LC_measu_complit_f =false;
	ICP_TIMER_DISABLE;
	ICP_TIMEE_IC_IT_DISABLE;
	
//	if(HAL_TIM_Base_Stop(&htim4) !=HAL_OK) {
//					Error_Handler();
//	}
//		if(HAL_TIM_IC_Stop(&htim4,TIM_CHANNEL_4)!=HAL_OK) {
//				Error_Handler();
//		}
//		if(HAL_TIM_IC_Stop_IT(&htim4,TIM_CHANNEL_4) !=HAL_OK) {
//				Error_Handler();
//	}	
}
 void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim){
	 static volatile uint32_t timeNow=0, timeBefor=0;
		if(__HAL_TIM_GET_IT_SOURCE(htim, TIM_IT_CC4) !=RESET) {
//			 __HAL_TIM_CLEAR_IT(htim, TIM_IT_CC4);
		if(ICPcount ==0 || LC_measu_complit_f) {
				timeNow =micros();
				ICPcount=0;
				timeBefor = timeNow;
		//		LC_measu_complit_f=false;
		}
		if(ICPcount >=LC_CHECK_COUNT ) {
				timeNow =micros();
				ICPValue = timeNow - timeBefor;
				timeBefor = timeNow;
				LC_measu_complit_f=true;
				ICPcount=0;
			
//				HAL_TIM_Base_Stop(htim);
				ICP_TIMER_DISABLE;
				ICP_TIMEE_IC_IT_DISABLE;			
	
			return;
		}
		ICPcount++;
	}
}

