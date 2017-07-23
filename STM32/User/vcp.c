#include "board.h"
#include "usb_device.h"
#include "usbd_cdc_if.h"
#include <mavlink/Lattepanda_shiled/mavlink.h>
#include <stdarg.h>
//#define MAVLINK_USE_CONVENIENCE_FUNCTIONS
//#define MAVLINK_SEND_UART_BYTES	CDC_Transmit_FS
//[출처] [STM32L476/CubeMx] USB CDC 입출력 (아두이노 AVR DIY 놀이터(임베디드홀릭)) |작성자 임베디드홀릭


#define MAX_CDC_RX_Q 263
__IO uint32_t Q_rear,Q_front;
__IO uint8_t CDC_rx_q[MAX_CDC_RX_Q];

void enqueue_cdc_data(uint8_t *buf, uint32_t len)
{
 int i;
 for( i = 0 ; i < len ; i ++)
 {
  if(((Q_front + 1) % MAX_CDC_RX_Q) == Q_rear) // Queue full
   return;
  CDC_rx_q[Q_front] = buf[i];
  Q_front = (Q_front + 1) % MAX_CDC_RX_Q;
 }
}

bool dequeue_cdc_data(uint8_t *p)
{
 if((Q_front % MAX_CDC_RX_Q) == Q_rear) return false;
 *p = CDC_rx_q[Q_rear];
 Q_rear = (Q_rear + 1) % MAX_CDC_RX_Q;
	return true;
}

bool CDC_is_available(void){
    if(Q_rear == Q_front) {
			return false;
		}
    return true;
}



void CDC_putchar(char ch){
 char buf[2]={NULL,};
 buf[0] = ch;
 CDC_Transmit_FS((uint8_t *)buf,1);
}

void CDC_printf(char *fmt,...){
	char buf[128]={NULL,};
	va_list argp;
	va_start(argp, fmt);
	vsprintf(buf,fmt,argp);
	CDC_Transmit_FS((uint8_t *)buf,strlen(buf));
	va_end(argp);
}

uint8_t CDC_getchar(void){
	#if 0
 uint8_t ch;
 while(!CDC_is_available());
 dequeue_cdc_data(&ch);
 return ch;
	#else
 uint8_t ch;
 dequeue_cdc_data(&ch);
 return ch;
	#endif
}

void VCP_init(void) {
	USB_DECTETION_DISABLE;
//	osDelay(500);
//	MX_USB_DEVICE_Init();
	USB_DECTETION_ENABLE;
}

void VCP_handller(void) {
	if(hUsbDeviceFS.dev_state == USBD_STATE_CONFIGURED) {
//		USB_DECTETION_ENABLE;
		
	}
	else {
//		USB_DECTETION_DISABLE;
	}
}


void usb_VCP_test(void) {
	static uint32_t beforTime =0;
	uint32_t timeNow;
	static char buffer[100]={NULL,};
	timeNow = millis();
	if ( (int64_t)timeNow - beforTime  -333  <  0 &&  timeNow >= beforTime) {	//100ms 경과 않됨?
		return ;
	}
		memset((char *)buffer,NULL,sizeof(buffer));
		sprintf((char*)buffer,"ADC1 =%5dmV, ADC2=%5dmV, Kelvin=%7.3fOhm, tc_temp=%5.1fdegC, Cx=%6.1f\r\n", measu_data.ADC_mV[0], measu_data.ADC_mV[1], measu_data.Kelvin_Ohm, measu_data.TC_temp, Cx);
//		if(HAL_UART_Transmit_DMA(&huart2, (uint8_t *)buffer, strlen((char *)buffer)) != HAL_OK) {
//		}

		if(hUsbDeviceFS.dev_state == USBD_STATE_CONFIGURED) {
			CDC_Transmit_FS((uint8_t *)buffer, strlen((char *)buffer));				
		}
		beforTime = timeNow;
	
	
}


//static void Mavlink(serialPort_t *port) {
////		static bool start_f= false;
//		uint16_t tx_len = 0;
//		uint16_t i;
//		mavlink_message_t Rmsg;//, Tmsg;
//		mavlink_status_t Rstatus;
//		uint8_t tx_buffer[263];	//mavlink buffer

//    while (serialTotalBytesWaiting(port)) {
//        uint8_t c = serialRead(port);
//			
//        if (mavlink_parse_char(MAVLINK_COMM_0, c, &Rmsg, &Rstatus) == MAVLINK_FRAMING_OK){
//					tx_len = mavlink_msg_control(&Rmsg, tx_buffer);
//					if(tx_len) {
//						for(i=0; i <tx_len; i++) {
//							serialWrite(port, tx_buffer[i]);
//						}
//					}
//				}
//			}
//}

//int _write(int FD, char * outstr, int len){

//     while(CDC_Transmit_FS((uint8_t*)outstr,len) == USBD_BUSY); //start new transmit
// // for some reason printf() needs this recovery time
//     dummy();
//     return len;
//}


