#pragma once
#include <stdbool.h>
#define ASSERT_CONCAT_(a, b) a##b
#define ASSERT_CONCAT(a, b) ASSERT_CONCAT_(a, b)
#define ct_assert(e) enum { ASSERT_CONCAT(assert_line_, __LINE__) = 1/(!!(e)) }


typedef enum  {
		DISPLAY_FAST,
		DISPLAY_NORMAL,
		DISPLAY_SLOW,
		DISPLAY_VERY_SLOW,
}display_speed_e;

typedef enum  {
		SAMPLE_KELVIN_OHM,
		SAMPLE_KELVIN_mV,
		SAMPLE_TC_mV,
		SAMPLE_TC_TEMP,
		SAMPLE_TC_ADC1,
		SAMPLE_TC_ADC2,
	
		SAMPLE_MAX_ITEM,
}_measuer_item_e;


typedef enum { 
		NO_TEST,
		CHECKING,
		PASS,
		NG,
}_result_e;

typedef enum { 
			ZERO_CALI,

}_kelvin_control_mode_e;


typedef enum { 
			L_SP_R,
			R_SP_R,
			MIC_R, 
			SP_BAL, 
			FOR_BTN, 
			PLAY_BTN, 
			BAC_BTN, 

}_result_item_e;


typedef enum { 
			LEFT_SP,
			RIGHT_SP,
			MIC, 

}_kelvin_adc_item_e;

typedef enum  {
//		RANGE_100_100K,
		KELVIN_CURRENT_SOURCE_1mA,
		KELVIN_CURRENT_SOURCE_10mA,
	
		KELVIN_CURRENT_SOURCE_MAX_NUM	
}kelvin_current_source_e;

typedef enum  {
//		RANGE_100_100K,
		R_RANGE_100,
		R_RANGE_1K,		//100~1k Ohm
		R_RANGE_10,		//0.1~10 Ohm
		R_RANGE_1,		//0.01~1 Ohm
	
	
		R_RANGE_MAX_NUM
	
}kelvin_reg_range_e;

typedef enum { FREQ_ADJ, 
												OFFSET_ADJ, 
												REMODTE_CAN, 
												REMOTE_UART,
}_control_mode; 


typedef enum  {
		BAUD_9600_BPS,
		BAUD_19200_BPS,
		BAUD_38400_BPS,
		BAUD_57600_BPS,
		BAUD_11500_BPS,
		BAUD_230400_BPS,
}baud_speed_e;


typedef enum  {
		BAUD_10K_BPS,
		BAUD_20K_BPS,
		BAUD_50K_BPS,
		BAUD_83K_BPS,
		BAUD_100K_BPS,
		BAUD_125K_BPS,
		BAUD_250K_BPS,
		BAUD_500K_BPS,
		BAUD_800K_BPS,
		BAUD_1000K_BPS,
}can_speed_e;


typedef enum  {
		CHAG_BAT,
		BLUE_CONNTED,
		LV1_LED,
		LV2_LED,
		LOW_VOLTAGE,
	
}_conffee_sound_status_e;

typedef struct config_t {
	
//		uint16_t Ch1_Value;
//		uint16_t Ch2_Value;
	
		uint8_t sys_id;
		uint32_t serial_baudrate;               // primary serial  port baudrate
		can_speed_e can_baud_speed;	
		int8_t time_zone_hour;
		bool can_termi_reg;
	
	//calibration value
		uint32_t  F1_000;			// CxCx, CxLx, CxLx1,   LxLx
		uint32_t  F2_001; 		// CxCx, CxLx1
		uint32_t  F2_100;			// CxLx
		uint32_t  F2_110; 		// LxLx
//		get_charFuncPrt 	get_char;
//		str_printFuncPtr 	strPrint;
//		revice_char_checkFuncPtr	receive_char_check;
		kelvin_reg_range_e 	set_R_range; 
		kelvin_current_source_e set_C_range;
	  uint8_t LC_mode_set;
		uint8_t LC_range_set;
			_measuer_item_e display_speed[SAMPLE_MAX_ITEM];
			
			int16_t calib_TC_table[12];
			float kelvine_zero_offset[2];

			bool CAN_TX_msg_loopback;
		_port_typel_e mavlink_port;
		_port_typel_e serial_to_can_port;
	
} config_t;






typedef struct master_t {
	    uint8_t version;
			uint16_t size;
			uint8_t magic_be;                       // magic number, should be 0xBE
			uint16_t looptime;                      // imu loop time in us
			


			float Vref_mV_TC ;
			float Gain_ADC[MAX_12BIT_ADC_CHANNEL];
			float Offset_ADC_mV[MAX_12BIT_ADC_CHANNEL];
	
			float Vref_SDADC_mV;
			float Vref_ADC_mV;
	
	
			float cali_gain_TC_V;
			float cali_offset_TC_mV;
			float cali_gain_TC_Temp;
			float  cali_offset_TC_Temp;
	
			float Kelvin_current_mA[KELVIN_CURRENT_SOURCE_MAX_NUM];
			float cali_gain_Kelvin_mV[R_RANGE_MAX_NUM];
			float cali_offset_Kelvin_mV[R_RANGE_MAX_NUM];
	
//			float cali_gain_1K_Reg;
//			float cali_gain_100_Reg;
//			float cali_offset_1K_Reg;
//			float cali_offset_100_Reg;
	
			float cali_gain_DAC[2];
			float cali_offset_mV_DAC[2];
			

    config_t profile;//[3];                  // profiles
 //   uint8_t current_profile;                // currently loaded profile
	
			uint8_t reboot_character;               // which byte is used to reboot. Default 'R', could be changed carefully to something else.
		
	    uint8_t magic_ef;                       // magic number, should be 0xEF
	    uint8_t chk;                            // XOR checksum
	} master_t;




typedef struct system_t {
		uint32_t cycleTime;
		uint16_t usb_ADC;
		uint16_t usb_V_mean;
//			int32_t  actualADC[MAX_ADC2_CHANNEL_NUM + MAX_ADC1_CHANNEL_NUM];
	
//			uint16_t RTD_Reg_100;
//			uint16_t RTD_Temp_100;
			bool system_reboot_flag;
			bool eeprom_write_f;
			bool bus_to_config_update_f;
			bool Mavlink_mode;
			bool power_hold_button_long_push_flag;
			bool reboot_message_flag;

		uint8_t can_rx_err_cnt;
		uint8_t can_tx_err_cnt;
		uint8_t can_last_err;	
		uint32_t can_rxd_base_id;
	
			bool result;
			bool adc_buffer_full_f;
			bool config_default_set_f;
			
			bool can_to_serial_direct_send;
			bool rtcok;

		
			uint16_t DAC1_out_mV;
			uint16_t DAC2_out_mV;
			float PWM_freq_Hz;
			float PWM_duty_per;
			bool Relay1_out;
			uint8_t kelvin_mode;
//			bool calvin_zero_calibration_flag;
			
} system_t;


typedef struct measuring_t {
//	kelvin_reg_range_e 	set_R_range; 
//	kelvin_reg_range_e 	read_R_range; 
	float Kelvin_Ohm; 
	float Kelvin_mV; 
	float TC_mV;
	float TC_temp;
	uint8_t DI;
	
//	int32_t Kelvin_mOhm_mean[3]; 
//	int32_t kelvin_mV;
//	float sp_balance_per;
//	_result_e result[7];
	
	uint16_t ADC_mV[2];
	
} measu_t;





extern system_t sys;
extern measu_t measu_data;

extern config_t cfg;
extern master_t mcfg;

void configInit (void);
void resetConf(void);

bool read_uart_string(void);
void pwm_mode_set(void) ;		//ultra pwm mode or std ppm mode 설정 
void  push_putton_long_push_check(uint32_t * push_time);
void led_street_action (void);	//LED를 20ms 주기로 순차적으로 3회 점멸함.
void led_wink_action (void) ;	//LED를 20ms 주기로  3회  동시 점멸함.
void led_boom_action (void);	//LED를 중심에서 외과으로 점멸함.

void blinkLED(uint8_t num, uint8_t wait, uint8_t repeat);
bool checkFirstTime(bool reset);
void writeEEPROM(uint8_t b, uint8_t updateProfile);
void loadAndActivateConfig(void);
void readEEPROM(void);
static uint8_t validEEPROM(void);
void initEEPROM(void);
void initSystemset (void);

