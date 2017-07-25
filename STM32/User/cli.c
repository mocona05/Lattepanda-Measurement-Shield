#include "board.h"
#include "usb_device.h"
#include "usbd_cdc_if.h"
#include <mavlink/Lattepanda_shiled/mavlink.h>

extern RTC_HandleTypeDef hrtc;

static char cliBuffer[48];
static uint32_t bufferIndex = 0;
#define SEND_DATA_BYTE_SIZE ((bufferIndex - data_start_posion+1)/2)

static uint16_t mavlink_msg_control( const mavlink_message_t * msg,  uint8_t *  const buff);

	
void serial_direct_can_bus(void) {
		static uint32_t ID=0;
		static bool write_data_flag=false;
		static bool remote_flag=false;
		static bool start_flag=false;
		static uint16_t data_start_posion=0;
		char data_string[3]={NULL,};
		char msg_str[30]={NULL,};
		uint8_t i;
		uint8_t c;
		CanQueueType txd_msg;
//		if(!sys.can_to_serial_direct_send) {
//				sys.can_to_serial_direct_send =true;
//        printf("\r\nEntering CAN-BUS Dricet mode, type 'exit' to Exit\r\n");
//		}

    while (serial_to_can_port.receive_char_check()) {		
				 c =serial_to_can_port.get_char();
				if (bufferIndex && (c == '\n' || c == '\r')) {
						if(remote_flag) {
								remote_flag= false;;
								if( bufferIndex-data_start_posion ==0) {	//데이터 길이 체크
									if(ID < 2048) {
										txd_msg.StdId = ID;
										txd_msg.DLC =0;
										txd_msg.ExtId = 0x00;
										txd_msg.IDE = 	CAN_ID_STD;
									}
									else {
										txd_msg.StdId = 0;
										txd_msg.DLC =0;
										txd_msg.ExtId = ID;
										txd_msg.IDE = 	CAN_ID_EXT;
									}
									txd_msg.RTR = CAN_RTR_REMOTE;
									if(cfg.CAN_TX_msg_loopback) {
											CAN_enqueue(&CAN_rxd_queue, *(CanQueueType *)&txd_msg); 		//txd msg loopback
									}
									if(CAN_enqueue(&CAN_txd_queue, txd_msg) != QUEUE_SUCCESS){ 
	//													return  QUEUE_ERROR;
									}
							}
							else {
								sprintf(msg_str, "ERROR: RTR Data =0 byte \r\n");
									serial_to_can_port.strPrint((uint8_t *)msg_str, strlen(msg_str));								
//								if(hUsbDeviceFS.dev_state == USBD_STATE_CONFIGURED) {
//										CDC_Transmit_FS((uint8_t *)msg_str, strlen(msg_str));							
//								}										
							}
						}
						else if( write_data_flag) {
									memset(txd_msg.Data, NULL, 8);
									write_data_flag=false;
									if( bufferIndex-data_start_posion >0 && bufferIndex-data_start_posion <=16) {	//데이터 길이 체크
											*(cliBuffer +bufferIndex)= '\0';
										for(i=0; i <SEND_DATA_BYTE_SIZE; i++) {
											memcpy(data_string, cliBuffer+data_start_posion + i*2, 2);
											txd_msg.Data[i] = strtol(data_string ,NULL,16);
										}
										if(ID < 2048) {
											txd_msg.StdId = ID;
											txd_msg.DLC = SEND_DATA_BYTE_SIZE;	// 1문자일경우 처리를 위해서 +1
											txd_msg.ExtId = 1;
											txd_msg.IDE = 	CAN_ID_STD;
										}
										else {
											txd_msg.StdId = 0;
											txd_msg.DLC =SEND_DATA_BYTE_SIZE;
											txd_msg.ExtId = ID;
											txd_msg.IDE = 	CAN_ID_EXT;
										}
										txd_msg.RTR = CAN_RTR_DATA;
										if(cfg.CAN_TX_msg_loopback) {
												CAN_enqueue(&CAN_rxd_queue, *(CanQueueType *)&txd_msg); 		//txd msg loopback
										}
										if(CAN_enqueue(&CAN_txd_queue, txd_msg) != QUEUE_SUCCESS){ 
										}
									}
									else {
										sprintf(msg_str, "ERROR:Data byte 1~16 byte \r\n");
										serial_to_can_port.strPrint((uint8_t *)msg_str, strlen(msg_str));								
//										if(hUsbDeviceFS.dev_state == USBD_STATE_CONFIGURED) {
//												CDC_Transmit_FS((uint8_t *)msg_str, strlen(msg_str));							
//										}										
									}
						}
//						else {
//		            if (strncasecmp(cliBuffer, "exit", 4) == 0) {
//									sys.can_to_serial_direct_send = false;
//									*cliBuffer = '\0';
//									bufferIndex = 0;
//									write_data_flag=remote_flag=false;								
//									printf("\r\nExit CAN-BUS Direct mode\r\n");
//									return;
//								}
//						}
						start_flag =false;
//								printf("ERROR:Not Valid Command\r\n");
								bufferIndex=0;
				}
				else if (bufferIndex < sizeof(cliBuffer) && c >= 32 && c <= 126) {
							
//							if (c == '@') {
//									sys.can_to_serial_direct_send = false;
//									*cliBuffer = '\0';
//									bufferIndex = 0;
//									write_data_flag=remote_flag=false;								
//									printf("\r\nExit CAN-BUS Direct mode\r\n");
//									return;
//							}
								if(c =='x' || c == 'X') {	//시작 문자열을 체크
									start_flag = true;
									bufferIndex=0;
									*cliBuffer = '\0';
								}

							 else if(c == '?' && start_flag) {
									cliBuffer[bufferIndex++] = '\0';
									if( bufferIndex >2) {
											ID = strtol(cliBuffer,NULL, 16);
											remote_flag =true;
											data_start_posion = bufferIndex;
//										printf("ID=%x\r\n",ID);
									}
									else {
										sprintf(msg_str, "ERROR:None ID Value\r\n");
										serial_to_can_port.strPrint((uint8_t *)msg_str, strlen(msg_str));								
//										if(hUsbDeviceFS.dev_state == USBD_STATE_CONFIGURED) {
//												CDC_Transmit_FS((uint8_t *)msg_str, strlen(msg_str));							
//										}										
										*cliBuffer = '\0';
										bufferIndex = 0;
									}
//									bufferIndex=0;
//									write_data_flag=false;
							}
							else if(c == '=' && start_flag) {
										cliBuffer[bufferIndex++] = '\0';
										if( bufferIndex >2) {
												ID = strtol(cliBuffer,NULL, 16);
												write_data_flag=true;
												data_start_posion = bufferIndex;
											
	//											bufferIndex=0;
										}
	//									bufferIndex=0;
							}
					
							else if (!bufferIndex && c == 32) {	// space
								//  continue;
							}
							else {
								if(write_data_flag) {
									if((c>= '0' && c<='9') || (c >='A' &&  c <='F') || (c >='a' &&  c <='f')) {
											cliBuffer[bufferIndex++] = c;
									}
									else {
										bufferIndex=0;
										write_data_flag=false;
										sprintf(msg_str,"ERROR:CAN Data Not Valid\r\n");
										serial_to_can_port.strPrint((uint8_t *)msg_str, strlen(msg_str));								
//										if(hUsbDeviceFS.dev_state == USBD_STATE_CONFIGURED) {
//												CDC_Transmit_FS((uint8_t *)msg_str, strlen(msg_str));							
//										}										
									}
								}
								else {
									cliBuffer[bufferIndex++] = c;
//									if(CLI_MAX_BUFFER_SIZE <=bufferIndex) {		//buffer full
//										bufferIndex=0;
//										*cliBuffer = '\0';
//									}
								}
	//							cliWrite(c);
							}
				 }
	}		
}






//void Mavlink(uint8_t * rxd_buffer, uint16_t lens) {
void Mavlink_handller(void) {
//		static bool start_f= false;
		uint16_t tx_len = 0;
//		uint16_t i;
		mavlink_message_t Rmsg;//, Tmsg;
		mavlink_status_t Rstatus;
		static uint8_t tx_buffer[263];	//mavlink buffer
     uint8_t c;

//    while (CDC_is_available()) {
    while (mavlink_port.receive_char_check()) {
					c =mavlink_port.get_char();
//				dequeue_cdc_data(&c);			
        if (mavlink_parse_char(MAVLINK_COMM_0, c, &Rmsg, &Rstatus) == MAVLINK_FRAMING_OK){
					tx_len = mavlink_msg_control(&Rmsg, tx_buffer);
					if(tx_len) {
							mavlink_port.strPrint(tx_buffer,tx_len);
					}
				}
			}
}


static uint16_t mavlink_msg_control( const mavlink_message_t * msg,  uint8_t *  const buff)  {
		bool reboot_flag=false;
		float calibrated_TC;
//		uint8_t i;
//		static RTC_TimeTypeDef time;
//		static RTC_DateTypeDef date;	
//		bool write_flag=false;
		uint16_t  Tx_len=0;		//return value
		mavlink_message_t Tmsg;
		switch(msg->msgid) {
			case MAVLINK_MSG_ID_MEASURING_DATA :
				if(msg->len ==0) {		//수순값의 길이가 구조체 자료형의 크기와 일치 할경우 수신값을 디코딩
//					mavlink_msg_measuring_data_pack(cfg.sys_id, 1, &Tmsg, measu_data.Kelvin_Ohm, (float)Cx, (float)Lx, measu_data.TC_temp,measu_data.Kelvin_mV,measu_data.TC_mV, \
//					measu_data.ADC_mV[0],measu_data.ADC_mV[1],READ_DI_PORT,0);
					calibrated_TC = Calibration_TC_value(avg_item[SAMPLE_TC_TEMP]);
//					
//					mavlink_msg_measuring_data_pack(cfg.sys_id, 1, &Tmsg, avg_item[SAMPLE_KELVIN_OHM], (float)Cx, (float)Lx, avg_item[SAMPLE_TC_TEMP],avg_item[SAMPLE_KELVIN_mV],avg_item[SAMPLE_TC_mV], \
//					avg_item[SAMPLE_TC_ADC1], avg_item[SAMPLE_TC_ADC2],READ_DI_PORT,0);
					
					mavlink_msg_measuring_data_pack(cfg.sys_id, 1, &Tmsg, avg_item[SAMPLE_KELVIN_OHM], (float)Cx, (float)Lx, calibrated_TC,avg_item[SAMPLE_KELVIN_mV],avg_item[SAMPLE_TC_mV], \
					avg_item[SAMPLE_TC_ADC1], avg_item[SAMPLE_TC_ADC2],READ_DI_PORT,0);
					
					Tx_len =mavlink_msg_to_send_buffer(buff, &Tmsg);
						return Tx_len;
				}				
			case MAVLINK_MSG_ID_DAC_SETTING_DATA :
				if(msg->len ==0) {		//수순값의 길이가 구조체 자료형의 크기와 일치 할경우 수신값을 디코딩
					mavlink_msg_dac_setting_data_pack(cfg.sys_id, 1, &Tmsg, sys.DAC1_out_mV, sys.DAC2_out_mV);
					Tx_len =mavlink_msg_to_send_buffer(buff, &Tmsg);
//					return Tx_len;
				}
				else {
					sys.DAC1_out_mV = mavlink_msg_dac_setting_data_get_DAC_ch1(msg);
					sys.DAC2_out_mV = mavlink_msg_dac_setting_data_get_DAC_ch2(msg);
				}

				break;
			case MAVLINK_MSG_ID_DIGITAL_OUT_SETTING_DATA:
				if(msg->len ==0) {		//수순값의 길이가 구조체 자료형의 크기와 일치 할경우 수신값을 디코딩
					mavlink_msg_digital_out_setting_data_pack(cfg.sys_id, 1, &Tmsg, sys.PWM_freq_Hz, sys.PWM_duty_per, sys.Relay1_out);
					Tx_len =mavlink_msg_to_send_buffer(buff, &Tmsg);
				}
				else {
					sys.PWM_freq_Hz = mavlink_msg_digital_out_setting_data_get_L_Side_Freq(msg);
					sys.PWM_duty_per = mavlink_msg_digital_out_setting_data_get_L_Side_Duty(msg);
					sys.Relay1_out = mavlink_msg_digital_out_setting_data_get_DO(msg);
					digital_out_put_controler();
				}
				break;
				
			case MAVLINK_MSG_ID_ADC_CALIBRATION_Data:
				if(msg->len ==0) {		//수순값의 길이가 구조체 자료형의 크기와 일치 할경우 수신값을 디코딩
					mavlink_msg_adc_calibration_data_pack(cfg.sys_id,1, &Tmsg, mcfg.Gain_ADC, mcfg.Offset_ADC_mV, mcfg.Vref_ADC_mV, mcfg.Vref_SDADC_mV);
					Tx_len =mavlink_msg_to_send_buffer(buff, &Tmsg);
				}
				else {
					mavlink_msg_adc_calibration_data_get_Gain_ADC(msg, mcfg.Gain_ADC);
					mavlink_msg_adc_calibration_data_get_Offset_ADC_mV(msg, mcfg.Offset_ADC_mV);
					mcfg.Vref_ADC_mV = mavlink_msg_adc_calibration_data_get_Vref_ADC_mV(msg);
					mcfg.Vref_SDADC_mV = mavlink_msg_adc_calibration_data_get_Vref_SDADC_mV(msg);
				}
				break;
			case MAVLINK_MSG_ID_DAC_CALIBRATION_Data:
				if(msg->len ==0) {		//수순값의 길이가 구조체 자료형의 크기와 일치 할경우 수신값을 디코딩
					mavlink_msg_dac_calibration_data_pack(cfg.sys_id,1, &Tmsg, mcfg.cali_gain_DAC, mcfg.cali_offset_mV_DAC);
					Tx_len =mavlink_msg_to_send_buffer(buff, &Tmsg);
				}
				else {
					mavlink_msg_dac_calibration_data_get_Gain_DAC(msg, mcfg.cali_gain_DAC);
					mavlink_msg_dac_calibration_data_get_Offset_DAC(msg, mcfg.cali_offset_mV_DAC);
				}
				break;
				
			case MAVLINK_MSG_ID_TC_CALIBRATION_Data:
				if(msg->len ==0) {		//수순값의 길이가 구조체 자료형의 크기와 일치 할경우 수신값을 디코딩
					mavlink_msg_tc_calibration_data_pack(cfg.sys_id,1, &Tmsg, mcfg.cali_gain_TC_V, mcfg.cali_offset_TC_mV, mcfg.cali_gain_TC_Temp, mcfg.cali_offset_TC_Temp, mcfg.Vref_mV_TC,cfg.calib_TC_table);
					Tx_len =mavlink_msg_to_send_buffer(buff, &Tmsg);
				}
				else {
					mcfg.cali_gain_TC_V=mavlink_msg_tc_calibration_data_get_Gain_TCV(msg);
					mcfg.cali_offset_TC_mV=mavlink_msg_tc_calibration_data_get_Offset_mV_TCV(msg);
					mcfg.cali_gain_TC_Temp=mavlink_msg_tc_calibration_data_get_Gain_TC_degC(msg);
					mcfg.cali_offset_TC_Temp=mavlink_msg_tc_calibration_data_get_Offset_TC_degC(msg);
					mcfg.Vref_mV_TC=mavlink_msg_tc_calibration_data_get_Vref_mV_TC(msg);
				}
				break;
				
			case MAVLINK_MSG_ID_Kelvin_CALIBRATION_Data:
				if(msg->len ==0) {		//수순값의 길이가 구조체 자료형의 크기와 일치 할경우 수신값을 디코딩
					mavlink_msg_kelvin_calibration_data_pack(cfg.sys_id,1, &Tmsg, mcfg.cali_gain_Kelvin_mV, mcfg.cali_offset_Kelvin_mV);
					Tx_len =mavlink_msg_to_send_buffer(buff, &Tmsg);
				}
				else {
					mavlink_msg_kelvin_calibration_data_get_Gain_Kelvin(msg, mcfg.cali_gain_Kelvin_mV);
					mavlink_msg_kelvin_calibration_data_get_Offset_Kelvin(msg, mcfg.cali_offset_Kelvin_mV);
				}
				break;
			case MAVLINK_MSG_ID_REAL_TIME_CLOCK_SET:
				if(msg->len ==0) {		//수순값의 길이가 구조체 자료형의 크기와 일치 할경우 수신값을 디코딩
					HAL_RTC_GetTime(&hrtc,&RTC_time, RTC_FORMAT_BIN);
					HAL_RTC_GetDate(&hrtc,&RTC_date, RTC_FORMAT_BIN);
					mavlink_msg_real_time_clock_set_pack(cfg.sys_id,1, &Tmsg, RTC_time.SubSeconds, (uint16_t)RTC_date.Year+2000, RTC_date.Month, RTC_date.Date, RTC_date.WeekDay, RTC_time.Hours, \
					RTC_time.Minutes, RTC_time.Seconds,  RTC_time.TimeFormat ,RTC_time.DayLightSaving);
					Tx_len =mavlink_msg_to_send_buffer(buff, &Tmsg);
				}
				else {
					RTC_date.Year = (uint8_t)mavlink_msg_real_time_clock_set_get_year(msg)-2000;
					RTC_date.Month = mavlink_msg_real_time_clock_set_get_month(msg);
					RTC_date.Date = mavlink_msg_real_time_clock_set_get_mday(msg);
					RTC_date.WeekDay = mavlink_msg_real_time_clock_set_get_wday(msg);
					HAL_RTC_SetDate(&hrtc, &RTC_date, RTC_FORMAT_BIN);
					
					RTC_time.Hours = mavlink_msg_real_time_clock_set_get_hour(msg);
					RTC_time.Minutes = mavlink_msg_real_time_clock_set_get_min(msg);
					RTC_time.Seconds = mavlink_msg_real_time_clock_set_get_sec(msg);
//					RTC_time.SubSeconds =mavlink_msg_real_time_clock_set_get_subsec(msg);
					RTC_time.TimeFormat = mavlink_msg_real_time_clock_set_get_timeFormat(msg);
//					RTC_time.DayLightSaving= (uint32_t)mavlink_msg_real_time_clock_set_get_DayLightSaving(msg);
//					
					HAL_RTC_SetTime(&hrtc, &RTC_time, RTC_FORMAT_BIN);
				}
				break;
				
			case MAVLINK_MSG_ID_MEASURING_SETTING:
				if(msg->len ==0) {		//수순값의 길이가 구조체 자료형의 크기와 일치 할경우 수신값을 디코딩
					mavlink_msg_measuring_setting_pack(cfg.sys_id,1, &Tmsg, (uint8_t *)cfg.display_speed, sys.kelvin_mode, cfg.set_R_range, cfg.LC_mode_set, cfg.LC_range_set);
					Tx_len =mavlink_msg_to_send_buffer(buff, &Tmsg);
				}
				else {
					mavlink_msg_measuring_setting_get_Display_speed(msg, (uint8_t *)cfg.display_speed);
					sys.kelvin_mode =mavlink_msg_measuring_setting_get_Kelvin_mode_set(msg);
					cfg.set_R_range =(kelvin_reg_range_e) mavlink_msg_measuring_setting_get_Kelvin_Range(msg);
					cfg.LC_mode_set =mavlink_msg_measuring_setting_get_LC_mode_set(msg);
					cfg.LC_range_set =mavlink_msg_measuring_setting_get_L_C_Range(msg);
					
					
					switch(sys.kelvin_mode) {
						case ZERO_CALI:
//							sys.calvin_zero_calibration_flag =true;
//							cfg.kelvine_zero_offset[(uint8_t)cfg.set_R_range]= avg_item[SAMPLE_KELVIN_OHM];
//							sys.kelvin_mode=0;
							break;
					}
				}
				break;
				
				
			case MAVLINK_MSG_ID_SYSTEM_CONTROL_SET:
				if(msg->len >0) {		//쓰기만 해당
					writeEEPROM(reboot_flag,mavlink_msg_system_control_set_get_save_config(msg));
					if(mavlink_msg_system_control_set_get_Reboot(msg)) {	//System reboot
						systemReset(false);
					}
					if(mavlink_msg_system_control_set_get_default_set(msg)) {		//default set
						resetConf();
					}
				}
				break;
				
				
			case MAVLINK_MSG_ID_CAN_BUS_CONFIG_SETTING_DATA :
				break;
			default:
				break;
		}
		return Tx_len;
}


void mavlink_interval_send_test(void) {
	static uint32_t beforTime =0;
	uint32_t timeNow;
	static char buffer[100]={NULL,};
	mavlink_message_t Tmsg;
	static uint8_t buff[263];
		uint16_t  Tx_len=0;
	
	timeNow = millis();
	if ( (int64_t)timeNow - beforTime  -10  <  0 &&  timeNow >= beforTime) {	//100ms 경과 않됨?
		return ;
	}
		memset((char *)buffer,NULL,sizeof(buffer));
		mavlink_msg_measuring_data_pack(cfg.sys_id, 1, &Tmsg, measu_data.Kelvin_Ohm, (float)Cx, (float)Lx, measu_data.TC_temp,measu_data.Kelvin_mV,measu_data.TC_mV, \
		measu_data.ADC_mV[0],measu_data.ADC_mV[1],READ_DI_PORT,0);
		Tx_len =mavlink_msg_to_send_buffer(buff, &Tmsg);
		mavlink_port.strPrint(buff,Tx_len);
	
		beforTime = timeNow;
	
	
}


void mavlink_send_data(void) {
//	uint8_t buffer[100];
////	_mavlink_send_uart(
//	MAVLINK_SEND_UART_BYTES(buffer,10);
	
	
	
	
}

