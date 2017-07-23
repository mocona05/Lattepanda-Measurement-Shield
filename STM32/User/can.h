#pragma once
#include <stdbool.h>



//인디게이터는 컨트로러와 송수신 주소가 바뀜
#define CAN_ID_TRANSCEIVER_CONFIG  0x010
#define CAN_ID_RECEIVE_CONFIG  0x011

#define ID_DIFF_VALUE 	((ENCO_VALUE%2)*16)



//txd id
#define TC_KELVIN_ID		0x500
#define LC_ADC_ID		0x510

#define CAN_SPEED  BAUD_500K_BPS
#define CAN_ALT_FUNCTION_USE

#define CAN_MSG_CH_NO  MAX_CTAS_T_CH_NUM


//extern CanTxMsg SYSTEM_ETC;

typedef struct can_txd_list_t{
	uint32_t resendTime;
	bool (*function)(uint32_t  );
	uint32_t  StdId;
	bool RTR;
	
}can_txd_list_t;

typedef struct can_rxd_t{
	uint16_t  StdId;
	uint8_t	ExtId;
	uint32_t IDE;
	uint8_t DLC;
	uint8_t FMI;
}can_rxd_t;


typedef struct can_rtr_list_t{
	
	uint32_t  StdId;
	bool (*function)(uint32_t  );
	bool RTR;
	
}can_rtr_list_t;


typedef struct
{
  uint32_t StdId;  /*!< Specifies the standard identifier.
                        This parameter can be a value between 0 to 0x7FF. */

  uint32_t ExtId;  /*!< Specifies the extended identifier.
                        This parameter can be a value between 0 to 0x1FFFFFFF. */

  uint32_t IDE;     /*!< Specifies the type of identifier for the message that 
                        will be received. This parameter can be a value of 
                        @ref CAN_identifier_type */

  uint32_t RTR;     /*!< Specifies the type of frame for the received message.
                        This parameter can be a value of 
                        @ref CAN_remote_transmission_request */

  uint32_t DLC;     /*!< Specifies the length of the frame that will be received.
                        This parameter can be a value between 0 to 8 */

  uint8_t Data[8]; /*!< Contains the data to be received. It ranges from 0 to 
                        0xFF. */

  uint8_t FMI;     /*!< Specifies the index of the filter the message stored in 
                        the mailbox passes through. This parameter can be a 
                        value between 0 to 0xFF */
} CanQueueType;
//FMI는 수신시에만 해당되므로 메모리 카피시 주의!!

typedef struct can_rxd_type_t{
void *ptr;
uint32_t id;
uint32_t IDE;	//CAN_ID_STD
uint8_t DLC;
uint8_t start_bit;
uint8_t bit_length;
const uint8_t type; // vartype_e
double scale;
double offset;
void (*function)(void);
bool  * rxd_id_flag;
}can_rxd_type_t;


typedef struct can_rxd_data_list_t{
	
	uint16_t Lambda_1000;
	uint16_t AFR_100;
	uint16_t Oxy_100;
	int16_t Ip_mA;
	
	uint16_t Rpvs_Ohm_10;
	int16_t Vs_mV;
	uint16_t HTR_Temp_degC;
	uint8_t Control_status;
	uint8_t Sensor_type;
	uint8_t Fuel_type;
	uint8_t OBD_Enable;

	uint16_t Input_mV;
	uint16_t HTR_mV;
	int16_t HTR_mA;
	int16_t Vp_mV;
	
	uint16_t OBD_Value;
	uint8_t Temp_INT;
	
	
	

}can_rxd_data_list_t;
	
	

extern can_rxd_data_list_t rxd_data;


void can_bus_init(void);

void CAN_TXD(void);

static void CAN_speed_config(void);
static void NVIC_Config(void);

void Init_RxMes(CanRxMsgTypeDef *RxMessage);     



//static bool write_room_condition(uint32_t id);
static bool adc_condition(uint32_t id);
static uint8_t  CAN_TXD_enQueue_Config(void);
static uint8_t  CAN_RXD_queue_to_deQueue_Config(void);

static void data_set_value(const can_rxd_type_t * var, const int32_t value);
//static void CAN_RXD_data_update(CanQueueType * rxd_data) ;
//static uint8_t CAN_TXD_enQueue_Config(void);
static void CAN_TXD_sterimming (void );

static void CAN_RXD_data_update(const CanQueueType * rxd_data);

uint8_t CAN_RXD_Queue_Handller (void );
void CAN_TXD_Time_Handller_en_queue(void) ;
void CAN_Config(void);

//void CAN_Tranmission_Test(void);




