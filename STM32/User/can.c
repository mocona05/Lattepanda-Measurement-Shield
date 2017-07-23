#include "board.h"
#include "can_queue.h"
#include "stm32f3xx_hal_can.h"

#include "usb_device.h"
#include "usbd_cdc_if.h"
#include <mavlink/Lattepanda_shiled/mavlink.h>




 static CanRxMsgTypeDef        RxMessage;	
	
extern CAN_HandleTypeDef hcan;
//CanRxMsgTypeDef RxMessage;   

//CanTxMsg TxMessage;
uint8_t KeyNumber = 0x0;

//#define CAN_TXD_DISABLE

//#define CAN_HANDLE		hcan

can_rxd_data_list_t rxd_data;
static bool tc_kevin_measuring(uint32_t id) ;
static bool LC_measuring(uint32_t id);
	
static bool status_rtr(uint32_t id);	

void can_bus_init(void) {

	//	NVIC_Config();    
		CAN_speed_config();
		/* IT Configuration for CAN1 */  
//		CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE);
}



#ifndef CAN_TXD_DISABLE
can_txd_list_t can_txd_list[] = {
	{10, tc_kevin_measuring, 		TC_KELVIN_ID},
	{10, LC_measuring, 		LC_ADC_ID},

};
#define CAN_TXD_COUNT (sizeof(can_txd_list) / sizeof(can_txd_list[0]))
	
can_rtr_list_t can_rtr_list[] = {
	{0x200, status_rtr},
};
#define CAN_RTR_COUNT (sizeof(can_rtr_list) / sizeof(can_rtr_list[0]))


#endif



can_rxd_type_t can_rxd_list[] = {
		{&sys.cycleTime, TC_KELVIN_ID, CAN_ID_STD, 8,  0, 16, VAR_UINT16, 1, 0,   NULL },
	
//		{&rxd_data.Lambda_1000, CAN_ID_LINEAR_SEN, CAN_ID_STD, 8,  0, 16, VAR_UINT16, 1, 0,   NULL },
//		{&rxd_data.AFR_100, CAN_ID_LINEAR_SEN, CAN_ID_STD, 8,  16, 16, VAR_UINT16, 1, 0,   NULL },
//		{&rxd_data.Oxy_100, CAN_ID_LINEAR_SEN, CAN_ID_STD, 8,  32, 16, VAR_UINT16, 1, 0,   NULL },
//		{&rxd_data.Ip_mA, CAN_ID_LINEAR_SEN, CAN_ID_STD, 8,  48, 16, VAR_INT16, 1, 0,   NULL },
//		
//		{&rxd_data.Rpvs_Ohm_10, CAN_ID_STATUS1, CAN_ID_STD, 8,  0, 16, VAR_UINT16, 1, 0,   NULL },
//		{&rxd_data.Vs_mV, CAN_ID_STATUS1, CAN_ID_STD, 8,  16, 16, VAR_INT16, 1, 0,   NULL },
//		{&rxd_data.HTR_Temp_degC, CAN_ID_STATUS1, CAN_ID_STD, 8,  32, 16, VAR_UINT16, 1, 0,   NULL },
//		{&rxd_data.Control_status, CAN_ID_STATUS1, CAN_ID_STD, 8,  48, 4, VAR_UINT8, 1, 0,   NULL },
//		{&rxd_data.Sensor_type, CAN_ID_STATUS1, CAN_ID_STD, 8,  52, 4, VAR_UINT8, 1, 0,   NULL },
//		{&rxd_data.Fuel_type, CAN_ID_STATUS1, CAN_ID_STD, 8,  56, 4, VAR_UINT8, 1, 0,   NULL },
//		
//		{&rxd_data.Input_mV, CAN_ID_ADC, CAN_ID_STD, 8,  0, 16, VAR_UINT16, 1, 0,   NULL },
//		{&rxd_data.HTR_mV, CAN_ID_ADC, CAN_ID_STD, 8,  16, 16, VAR_UINT16, 1, 0,   NULL },
	
};
#define CAN_RXD_COUNT (sizeof(can_rxd_list) / sizeof(can_rxd_list[0]))

static void can_txd_msg_loop_back_rxd_queue(CanQueueType * txd_msg) {
		if(CAN_enqueue(&CAN_rxd_queue, *(CanQueueType *)txd_msg) != QUEUE_SUCCESS){
		}	
}

static bool status_rtr(uint32_t id) {
		CanQueueType txd_msg;
		txd_msg.StdId = id;
		txd_msg.DLC =2;
		txd_msg.ExtId = 0x00;
		txd_msg.IDE = 	CAN_ID_STD;
		txd_msg.RTR = CAN_RTR_DATA;
		
		txd_msg.Data[0] = ((uint8_t)sys.cycleTime);
		txd_msg.Data[1] = (uint8_t)(sys.cycleTime>>8);

		if(CAN_enqueue(&CAN_txd_queue, txd_msg) == QUEUE_SUCCESS){
			if(cfg.CAN_TX_msg_loopback) {
				can_txd_msg_loop_back_rxd_queue(&txd_msg);
			}
			return QUEUE_SUCCESS;			
		}
		return  QUEUE_ERROR;
}



static bool tc_kevin_measuring(uint32_t id) {
		CanQueueType txd_msg;
		txd_msg.StdId = id;
		txd_msg.DLC =6;
		txd_msg.ExtId = 0x00;
		txd_msg.IDE = 	CAN_ID_STD;
		txd_msg.RTR = CAN_RTR_DATA;
	
		int32_t kelvin_mOhm;
		int16_t TC_temp10;
	
		kelvin_mOhm =measu_data.Kelvin_mV*1000;
		TC_temp10 = measu_data.TC_temp*10;
//	CAN_HANDLE.pTxMsg->
		
		txd_msg.Data[0] = ((uint8_t)kelvin_mOhm);
		txd_msg.Data[1] = (uint8_t)(kelvin_mOhm>>8);
		txd_msg.Data[2] = ((uint8_t)kelvin_mOhm>>16);
		txd_msg.Data[3] = (uint8_t)(kelvin_mOhm>>24);
		txd_msg.Data[4] = ((uint8_t)TC_temp10);
		txd_msg.Data[5] = (uint8_t)(TC_temp10>>8);

		if(CAN_enqueue(&CAN_txd_queue, txd_msg) == QUEUE_SUCCESS){ 
			if(cfg.CAN_TX_msg_loopback) {
				CAN_enqueue(&CAN_rxd_queue, *(CanQueueType *)&txd_msg);
			}
			return QUEUE_SUCCESS;			
		}
		return  QUEUE_ERROR;
}

static bool LC_measuring(uint32_t id) {
		CanQueueType txd_msg;
		txd_msg.StdId = id;
		txd_msg.DLC =8;
		txd_msg.ExtId = 0x00;
		txd_msg.IDE = 	CAN_ID_STD;
		txd_msg.RTR = CAN_RTR_DATA;

		int32_t cap;
		cap = Cx;
	

		txd_msg.Data[0] = ((uint8_t)cap);
		txd_msg.Data[1] = (uint8_t)(cap>>8);
		txd_msg.Data[2] = ((uint8_t)cap>>16);
		txd_msg.Data[3] = (uint8_t)(cap>>24);
		txd_msg.Data[4] = ((uint8_t)measu_data.ADC_mV[0]);
		txd_msg.Data[5] = (uint8_t)(measu_data.ADC_mV[0]>>8);
		txd_msg.Data[6] = ((uint8_t)measu_data.ADC_mV[1]);
		txd_msg.Data[7] = (uint8_t)(measu_data.ADC_mV[1]>>8);


		if(CAN_enqueue(&CAN_txd_queue, txd_msg) == QUEUE_SUCCESS){
			if(cfg.CAN_TX_msg_loopback) {
				can_txd_msg_loop_back_rxd_queue(&txd_msg);
			}				
			return QUEUE_SUCCESS;			
		}
		return  QUEUE_ERROR;
}

#ifndef	CAN_TXD_DISABLE
static void CAN_TXD_sterimming (void ) {				//queue에서 전송 데이터를 꺼내 CAN-BUS로 전송
	CanQueueType	dequeue_msg;
  static CanTxMsgTypeDef        TxMessage;	
	bool static txd_error_flag=0;
	
  hcan.pTxMsg = &TxMessage;
	
			//Queue에 data가 있고 CAN-BUS의 mail box가 비어 있을경우
			if( txd_error_flag) {	//메세지 박스가 꽉차 미전송시 이전 값  재전송
					if(HAL_CAN_Transmit(&hcan,10) !=HAL_OK) {
					}
					if(hcan.State == HAL_CAN_STATE_BUSY_TX) {
						txd_error_flag=0;
					}
					return;
			}
			while(QUEUE_SUCCESS==CAN_dequeue(&CAN_txd_queue,&dequeue_msg))  {
					memcpy(&TxMessage, &dequeue_msg, 48);			//크기다 다르므로 txg msg 부분만 복사
					if(HAL_CAN_Transmit(&hcan,10) !=HAL_OK) {
					}
					if(hcan.State == HAL_CAN_STATE_BUSY_TX) {
							txd_error_flag=1;
							return;
					}
					else {
							txd_error_flag=0;
							return;
					}
			}
}
#endif



static void CAN_RXD_data_update(const CanQueueType * can_rxd_data) {
		uint16_t i=0;
		uint64_t   buffer;
		uint8_t data[8];
		uint64_t value;
		bool (*Func) (uint32_t );	
//		uint8_t RTR;
		char ID[9];
//		uint32_t id=0;
		char data_str[17]={NULL,};
		char msg_str[28] ={NULL,};
		char print_str[32] ={NULL,};
		char check_sum_str[3]={NULL, NULL, NULL};		
	if(sys.can_to_serial_direct_send) {
//		memcpy(&buffer, &can_rxd_data->Data[0], sizeof(buffer));
//		RTR = (!can_rxd_data->RTR)? '=':'?';
	if(can_rxd_data->IDE ==CAN_ID_EXT) {
			sprintf(ID,"%08X",can_rxd_data->ExtId);
	}
	else {		//CAN_ID_STD
			sprintf(ID,"%03X",can_rxd_data->StdId);
	}
		
//		if(can_rxd_data->ExtId) {		//8자로
//			sprintf(ID,"%08X",can_rxd_data->ExtId);
////				id = can_rxd_data->ExtId;
//		}
//		else {
//			sprintf(ID,"%03X",can_rxd_data->StdId);
////				id = can_rxd_data->StdId;
//		}
		if(!can_rxd_data->RTR) {
//				memcpy(&data[0], &can_rxd_data->Data[0], can_rxd_data->DLC);
			//MSB -> LSB 
				for(i=0; i < can_rxd_data->DLC; i++) {
						data[i] = can_rxd_data->Data[can_rxd_data->DLC-1-i];
				}			
				sprintf(data_str, "%016llX", *(uint64_t *)data);

				//XOR check sum Enable
				sprintf(msg_str, "x%s=%s",ID, data_str+(16-can_rxd_data->DLC*2));
				check_Sum_to_str(msg_str, check_sum_str, strlen(msg_str));
				sprintf(print_str, "%s,%s\r",msg_str,check_sum_str);
//				sprintf(print_str,"%s=%s\r\n",ID, data_str+(16-can_rxd_data->DLC*2));
				serial_to_can_port.strPrint((uint8_t *)print_str,strlen(print_str));
//				if(hUsbDeviceFS.dev_state == USBD_STATE_CONFIGURED) {
//						CDC_Transmit_FS((uint8_t *)print_str, strlen(print_str));							
//				}
			
			
		}
		else if(can_rxd_data->RTR == CAN_RTR_REMOTE ) {		//can request 일경우
//				printf("%s?\r", ID);
				for(i=0; i<CAN_RTR_COUNT;i++) {
						if(can_rtr_list[i].StdId == can_rxd_data->StdId || can_rtr_list[i].StdId == can_rxd_data->ExtId ) {
								Func = can_rtr_list[i].function;	
								Func(can_rxd_data->StdId);
						}
				}
		}

	}
	if(!can_rxd_data->RTR) {
	
		for (i=0 ; i < CAN_RXD_COUNT ; i++) {
			if (can_rxd_list[i].id  == can_rxd_data->StdId &&  can_rxd_list[i].IDE  == can_rxd_data->IDE && can_rxd_list[i].DLC == can_rxd_data->DLC){
				
//				buffer = *(uint64_t *) can_rxd_data->Data;
					memcpy(&buffer, can_rxd_data->Data, sizeof(buffer));
					value =  (( buffer)>>can_rxd_list[i].start_bit)& (~(0xFFFFFFFFFFFFFFFF << can_rxd_list[i].bit_length)) ;		//최대 32bit 자료형만 변환가능
//					value =  ((*(uint64_t *)can_rxd_data->Data)>>can_rxd_list[i].start_bit) & (~(0xFFFFFFFFFFFFFFFF << can_rxd_list[i].bit_length)) ;		//최대 32bit 자료형만 변환가능

					data_set_value(&can_rxd_list[i], value);
				
					if(can_rxd_list[i].function != NULL) {
							void (*Func) (void);
							Func = can_rxd_list[i].function;		//관련된 함수 호출
							Func();							
					}
					if(can_rxd_list[i].rxd_id_flag != NULL) {
						* can_rxd_list[i].rxd_id_flag =true;		//수신 플레그를 기록 
					}					
			}
		}//for
	}
}



uint8_t  CAN_RXD_Queue_Handller (void ) {				//queue에 수신된 CAN DATA를 처리
		CanQueueType	rxd_msg;
	

			while(QUEUE_SUCCESS==CAN_dequeue(&CAN_rxd_queue,&rxd_msg))  {
				
					CAN_RXD_data_update(&rxd_msg);
				
					return QUEUE_SUCCESS;
			}
			return QUEUE_FULL;
			
}



#ifndef	CAN_TXD_DISABLE

void CAN_TXD_Time_Handller_en_queue(void) {		// 정해준 주기마다 DATA를 CAN TXD QUEUE에 넣음.
		static uint8_t i=0;
		static uint32_t sendTime[CAN_TXD_COUNT]={0,};
		bool (*Func) (uint32_t );
		uint32_t timeNow=0;

		timeNow = millis();

	if (!can_queue_is_full(&CAN_txd_queue)) { //TXD	 queue에 공간이 있을경우
			for(i=0; i<CAN_TXD_COUNT; i++) {	//스트리밍 값을 que에 입력
				if ( (int64_t)sendTime[i] + can_txd_list[i].resendTime <  timeNow && timeNow >= sendTime[i]) {
						if(  can_txd_list[i].function != NULL ) {
								Func = can_txd_list[i].function;	
								if( QUEUE_SUCCESS==Func(can_txd_list[i].StdId)) {//관련된 함수 호출
										sendTime[i]= timeNow;	//Queue error가 없을경우 전송 시간을 업데이트
								}
						}
				}			
			}
		}
			CAN_TXD_sterimming();
//	}
}
#endif




static void data_set_value(const can_rxd_type_t * var, const int32_t value) {
    switch (var->type) {
        case VAR_UINT8:
            *(uint8_t *)var->ptr = (uint8_t)((double) value * var->scale + var->offset);
            break;
        case VAR_INT8:
            *(char *)var->ptr = (char)((double)value * var->scale + var->offset);
            break;

        case VAR_UINT16:
            *(uint16_t *)var->ptr = (uint16_t)((double)value * var->scale + var->offset);
            break;
        case VAR_INT16:
            *(short *)var->ptr = (int16_t)((double)value * var->scale + var->offset);
            break;

        case VAR_UINT32:
            *(uint32_t *)var->ptr = (uint32_t)((double)value * var->scale + var->offset);
            break;

        case VAR_INT32:
            *(int32_t *)var->ptr = (int32_t)((double)value * var->scale + var->offset);
            break;

        case VAR_FLOAT:
            *(float *)var->ptr = (float )((double)value * var->scale + var->offset);
            break;
    }
}


void CAN_speed_config(void) {
//Main Clock 36MHz 
 switch((uint8_t)cfg.can_baud_speed) {
	 case BAUD_10K_BPS:
		 //Sample Point 87.5%
				hcan.Init.Prescaler = 255;
				hcan.Init.BS1 = CAN_BS1_13TQ;
				hcan.Init.BS2 = CAN_BS2_2TQ;
				break;
	 case BAUD_20K_BPS:
		 //Sample Point 87.5%
				hcan.Init.Prescaler = 255;
				hcan.Init.BS1 = CAN_BS1_6TQ;
				hcan.Init.BS2 = CAN_BS2_1TQ;
				break;
	 case BAUD_50K_BPS:
		 //Sample Point 87.5%
				hcan.Init.Prescaler = 45;
				hcan.Init.BS1 = CAN_BS1_13TQ;
				hcan.Init.BS2 = CAN_BS2_2TQ;
				break;
	 case BAUD_83K_BPS:
		 //Sample Point 87.5%
				hcan.Init.Prescaler = 27;
				hcan.Init.BS1 = CAN_BS1_13TQ;
				hcan.Init.BS2 = CAN_BS2_2TQ;	 
				break;
	 case BAUD_100K_BPS:
		 //Sample Point 87.5%
				hcan.Init.Prescaler = 45;
				hcan.Init.BS1 = CAN_BS1_6TQ;
				hcan.Init.BS2 = CAN_BS2_1TQ;	 
				break;
	 case BAUD_125K_BPS:
		 //Sample Point 87.5%
				hcan.Init.Prescaler = 18;
				hcan.Init.BS1 = CAN_BS1_13TQ;
				hcan.Init.BS2 = CAN_BS2_2TQ;	 
				break;
	 case BAUD_250K_BPS:
		 //Sample Point 87.5%
				hcan.Init.Prescaler = 9;
				hcan.Init.BS1 = CAN_BS1_13TQ;
				hcan.Init.BS2 = CAN_BS2_2TQ;	 
				break;
	 case BAUD_500K_BPS:
		 //Sample Point 87.5%
				hcan.Init.Prescaler = 9;
				hcan.Init.BS1 = CAN_BS1_6TQ;
				hcan.Init.BS2 = CAN_BS2_1TQ;	 
				break;
	 case BAUD_800K_BPS:
		 //Sample Point 86.7%
				hcan.Init.Prescaler = 3;
				hcan.Init.BS1 = CAN_BS1_12TQ;
				hcan.Init.BS2 = CAN_BS2_2TQ;	 
				break;
	 case BAUD_1000K_BPS:
		 //Sample Point 88.9%
				hcan.Init.Prescaler = 4;
				hcan.Init.BS1 = CAN_BS1_7TQ;
				hcan.Init.BS2 = CAN_BS2_1TQ;	 
				break;
 }
 
  /* CAN filter init */
   hcan.Instance = CAN;
 // hcan.Init.Prescaler = 9;
  hcan.Init.Mode = CAN_MODE_NORMAL;
  hcan.Init.SJW = CAN_SJW_1TQ;
//  hcan.Init.BS1 = CAN_BS1_6TQ;
 // hcan.Init.BS2 = CAN_BS2_1TQ;
  hcan.Init.TTCM = DISABLE;
  hcan.Init.ABOM = ENABLE;
  hcan.Init.AWUM = DISABLE;
  hcan.Init.NART = DISABLE;
  hcan.Init.RFLM = DISABLE;
  hcan.Init.TXFP = DISABLE;
  if (HAL_CAN_Init(&hcan) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
	
//  CAN_FilterInitStructure.CAN_FilterNumber = 0;
//  CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;
//  CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;
//  CAN_FilterInitStructure.CAN_FilterIdHigh = 0x0000;
//  CAN_FilterInitStructure.CAN_FilterIdLow = 0x0000;
//  CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0x0000;
//  CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000;
//  CAN_FilterInitStructure.CAN_FilterFIFOAssignment = 0;
//  CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
//  CAN_FilterInit(&CAN_FilterInitStructure);

  /* Enable FIFO 0 message pending Interrupt */
//  CAN_ITConfig(CANx, CAN_IT_FMP0, ENABLE);
//  
//  /* Enable FIFO 1 message pending Interrupt */
//  CAN_ITConfig(CANx, CAN_IT_FMP1, ENABLE);
  
}


void Init_RxMes(CanRxMsgTypeDef *RxMessage)
{
  uint8_t i = 0;

  RxMessage->StdId = 0;
  RxMessage->ExtId = 0;
  RxMessage->IDE = CAN_ID_STD;
  RxMessage->DLC = 0;
  RxMessage->FMI = 0;
  for (i = 0; i < 8; i++)
  {
    RxMessage->Data[i] = 0;
  }
}





//       static CanTxMsgTypeDef        TxMessage;
//       static CanRxMsgTypeDef        RxMessage;

//void CAN_Tranmission_Test(void) {
//  hcan.Instance = CAN;
//  hcan.pTxMsg = &TxMessage;
//	
//	  /*##-3- Start the Transmission process #####################################*/
//  hcan.pTxMsg->StdId = 0xFF;
//  hcan.pTxMsg->RTR = CAN_RTR_DATA;
//  hcan.pTxMsg->IDE = CAN_ID_STD;
//  hcan.pTxMsg->DLC = 4;
//  hcan.pTxMsg->Data[0] = 0x00;
//  hcan.pTxMsg->Data[1] = 0x00;
//  hcan.pTxMsg->Data[2] = 0x00;
//  hcan.pTxMsg->Data[3] = 0x00;
//	  if(HAL_CAN_Transmit(&hcan, 10) != HAL_OK)
//  {
////    printf("CAN transmit error!!\r\n");
//  }
//	
//}


void CAN_Config(void) {
	CAN_FilterConfTypeDef  sFilterConfig;	
	
 		hcan.pRxMsg = &RxMessage;	
	
  sFilterConfig.FilterNumber = 0;
  sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
  sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
  sFilterConfig.FilterIdHigh = 0x0000;
  sFilterConfig.FilterIdLow = 0x0000;
  sFilterConfig.FilterMaskIdHigh = 0x0000;
  sFilterConfig.FilterMaskIdLow = 0x0000;
  sFilterConfig.FilterFIFOAssignment = 0;
  sFilterConfig.FilterActivation = ENABLE;
  sFilterConfig.BankNumber = 14;

  if (HAL_CAN_Receive_IT(&hcan, CAN_FIFO0) != HAL_OK)
  {
    __HAL_CAN_ENABLE_IT(&hcan, CAN_IT_FMP0);  // set interrupt flag for RX FIFO0 if CAN locked
  }
  if(HAL_CAN_ConfigFilter(&hcan, &sFilterConfig) != HAL_OK)
  {
    /* Filter configuration Error */
    Error_Handler();
  }	

}

void HAL_CAN_RxCpltCallback(CAN_HandleTypeDef* hcan){

    /* Call receive function */
		if(CAN_enqueue(&CAN_rxd_queue, *(CanQueueType *)&RxMessage) != QUEUE_SUCCESS){ 
		}	
//		HAL_CAN_Receive_IT(hcan,  CAN_FIFO0);
  if (HAL_CAN_Receive_IT(hcan, CAN_FIFO0) != HAL_OK)
  {
    __HAL_CAN_ENABLE_IT(hcan, CAN_IT_FMP0);  // set interrupt flag for RX FIFO0 if CAN locked
  }

}

