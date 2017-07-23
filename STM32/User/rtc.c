#include "board.h"
#include "can_queue.h"
#include "stm32f3xx_hal_can.h"

RTC_TimeTypeDef RTC_time;
RTC_DateTypeDef RTC_date;
	
//extern RTC_HandleTypeDef hrtc;

//void read_RTC(void) {
//	//TM_RTC_GetDateTime(&hrtc, TM_RTC_Format_BIN);
//        
//	
//	
//}

//void write_RTC(RTC_DateTypeDef * date, RTC_TimeTypeDef  * time  ) {
////	HAL_RTCEx_SetTimeStamp(&hrtc, 

//	
////	date.Date = 9;
////	date.Year = 17;
////	date.Month = 7;
////	date.WeekDay = RTC_WEEKDAY_SUNDAY;
////	
////	time.Hours = 17;
////	time.Minutes= 27;
////	time.Seconds =00;
////	time.TimeFormat = RTC_HOURFORMAT_24;
//////	time.StoreOperation =
//	
//	
//	HAL_RTC_SetTime(&hrtc, time, RTC_FORMAT_BCD);
//	HAL_RTC_SetDate(&hrtc, date, RTC_FORMAT_BCD);
//}


//void set_RTC_alarm(void) {
//	RTC_AlarmTypeDef alarm;
//	
//	alarm.AlarmTime.Hours = 12;
//	
//	
//	alarm.AlarmDateWeekDay = RTC_WEEKDAY_SUNDAY;
////	alarm.AlarmDateWeekDaySel = 
////	alarm.AlarmSubSecondMask
//	
//	HAL_RTC_SetAlarm(&hrtc, &alarm, RTC_HOURFORMAT_24);
//	
//}


//void TM_RTC_WakeupHandler(void) {
//    /* Toggle leds */
////    TM_DISCO_LedToggle(LED_ALL);
//}
// 
///* Handle Alarm A event */
//void TM_RTC_AlarmAHandler(void) {
//    /* Print to LCD */
//    
//    /* Disable alarm */
////    TM_RTC_DisableAlarm(TM_RTC_Alarm_A);
//}

