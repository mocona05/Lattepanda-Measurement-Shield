#include "board.h"
#include "usb_device.h"
#include "usbd_cdc_if.h"

//#include "stm32f3xx_hal.h"
//#include "cmsis_os.h"
//#include <stdbool.h>
//#include <string.h>
//#include "config.h"

//sys_t sys;
measu_t measu_data;


//core_t core;

config_t cfg;
master_t mcfg;

//	#define FLASH_PAGE_COUNT 256
//		#define FLASH_PAGE_SIZE                 ((uint16_t)0x400)
//		#define CONFIG_SIZE                     (FLASH_PAGE_SIZE * 2)


#ifdef STM32F10X_LD
	#define FLASH_PAGE_COUNT 32
	#define FLASH_PAGE_SIZE                 ((uint16_t)0x400)
	#define CONFIG_SIZE                     (FLASH_PAGE_SIZE * 2)
#endif

#ifdef STM32F10X_MD
	#define FLASH_PAGE_COUNT 128
	#define FLASH_PAGE_SIZE                 ((uint16_t)0x400)
	#define CONFIG_SIZE                     (FLASH_PAGE_SIZE * 2)
#endif

#ifdef STM32F303xC
	#define FLASH_PAGE_COUNT 256
		#define FLASH_PAGE_SIZE                 ((uint16_t)0x400)
		#define CONFIG_SIZE                     (FLASH_PAGE_SIZE * 2)
#endif

#ifdef STM32F373xC
	#define FLASH_PAGE_COUNT 128
//		#define FLASH_PAGE_SIZE                 ((uint16_t)0x800)
		#define CONFIG_SIZE                     (FLASH_PAGE_SIZE * 1)
#endif

#ifdef STM32F373xB
	#define FLASH_PAGE_COUNT 128
		#define FLASH_PAGE_SIZE                 ((uint16_t)0x400)
		#define CONFIG_SIZE                     (FLASH_PAGE_SIZE * 2)
#endif


static const uint8_t EEPROM_CONF_VERSION = EEPROM_VERSION;
static const uint32_t FLASH_WRITE_ADDR = 0x08000000 + (FLASH_PAGE_SIZE * (FLASH_PAGE_COUNT - (CONFIG_SIZE / FLASH_PAGE_SIZE)));



system_t 	sys;
config_t cfg;

//core_t core;
 master_t mcfg;



void config_value_update_check_and_save (void) {
//	static uint32_t befor_time=0, save_interval_time;
//	uint32_t timeNow=millis();
//	static bool save_eeprom_f=false;

//    if ((( (int64_t)timeNow - befor_time-500) < 0 && timeNow >= befor_time) ) {
//			return ;
//		}
//		befor_time = timeNow;
		vTaskDelay(500);
		
		if(sys.system_reboot_flag) {		//reboot flag가 설정 된경우
//				systemReset(false);
				NVIC_SystemReset();
		}
		
		if(sys.eeprom_write_f ) {		//lcd gui에서 config 변경시에는 바로 변경
				sys.eeprom_write_f = false;
				writeEEPROM(1, true); 
		}
		if(sys.bus_to_config_update_f ) {	//통신으로 config 변경시에는 일정 시간 후 변경
				sys.bus_to_config_update_f = false;
//				save_eeprom_f = true;
//				save_interval_time = timeNow;
//				TASK1 -> xTaskGetTickCount() =0;
		}
		/* 저장 플래그후 일정시간 이상 플래그 신호가 없을 경우 기록 실행 */
//    if ((( (int64_t)timeNow - save_interval_time-5000) < 0 && timeNow >= save_interval_time) || save_eeprom_f == false ) {
//			return ;
//		}
//		save_eeprom_f = false;
//		 writeEEPROM(1, true); 
		
//		writeFLASH(Factory_cfg_buff, sizeof(Factory_cfg_t), FLASH_FACTORY_CFG_ADDR);
//		writeFLASH(controler_cfg_buff, sizeof(controler_cfg_t), FLASH_CONTROLER_CFG_ADDR);
	
}



//void system_config_set_init(void) {
//		sys.hw_version = HW_VERSION;
//		sys.fw_version = 	FW_VERSION;
//}



void initEEPROM(void)
{
    // make sure (at compile time) that config struct doesn't overflow allocated flash pages
    ct_assert(sizeof(mcfg) < CONFIG_SIZE);
}


static uint8_t validEEPROM(void)
{
    const master_t *temp = (const master_t *)FLASH_WRITE_ADDR;
    const uint8_t *p;
    uint8_t chk = 0;

    // check version number
    if (EEPROM_CONF_VERSION != temp->version)
        return 0;

    // check size and magic numbers
    if (temp->size != sizeof(master_t) || temp->magic_be != 0xBE || temp->magic_ef != 0xEF)
        return 0;

    // verify integrity of temporary copy
    for (p = (const uint8_t *)temp; p < ((const uint8_t *)temp + sizeof(master_t)); p++)
        chk ^= *p;

    // checksum failed
    if (chk != 0)
        return 0;

    // looks good, let's roll!
    return 1;
}


void readEEPROM(void)
{
    // Sanity check
    if (!validEEPROM()){
//        failureMode(10);
		}

    // Read flash
    memcpy(&mcfg, (char *)FLASH_WRITE_ADDR, sizeof(master_t));
    // Copy current profile
//    if (mcfg.current_profile > 2) // sanity check
//        mcfg.current_profile = 0;
    memcpy(&cfg, &mcfg.profile, sizeof(config_t));
}



void loadAndActivateConfig(void)
{
    readEEPROM();
//    activateConfig();
}


void writeEEPROM(uint8_t b, uint8_t updateProfile)
{
//		HAL_StatusTypeDef status;
		FLASH_EraseInitTypeDef EraselnitStruct;
		uint32_t PAGEError;
		uint32_t ErrorCode;
    uint8_t chk = 0;
    const uint8_t *p;
		unsigned int i;
		unsigned int tries;
	
    // prepare checksum/version constants
    mcfg.version = EEPROM_CONF_VERSION;
    mcfg.size = sizeof(master_t);
    mcfg.magic_be = 0xBE;
    mcfg.magic_ef = 0xEF;
    mcfg.chk = 0;

    // when updateProfile = true, we copy contents of cfg to global configuration. when false, only profile number is updated, and then that profile is loaded on readEEPROM()
    if (updateProfile) {
        // copy current in-memory profile to stored configuration
        memcpy(&mcfg.profile, &cfg, sizeof(config_t));
    }

    // recalculate checksum before writing
    for (p = (const uint8_t *)&mcfg; p < ((const uint8_t *)&mcfg + sizeof(master_t)); p++)
        chk ^= *p;
    mcfg.chk = chk;

    // write it
    HAL_FLASH_Unlock();
		
		EraselnitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
		EraselnitStruct.PageAddress = FLASH_WRITE_ADDR;
		EraselnitStruct.NbPages =  (CONFIG_SIZE / FLASH_PAGE_SIZE);
		
    for ( tries = 3; tries; tries--) {

			if(HAL_FLASHEx_Erase(&EraselnitStruct, &PAGEError) ==HAL_OK) {
        for ( i = 0; i < sizeof(master_t) ; i += 4) {
//            status = FLASH_ProgramWord(FLASH_WRITE_ADDR + i, *(uint32_t *)((char *)&mcfg + i));
					if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, FLASH_WRITE_ADDR+i, *(uint32_t *)((char *)&mcfg + i))!=HAL_OK ) {
							ErrorCode = HAL_FLASH_GetError();
							break;
					}
				}
//        if (HAL_FLASH_ERROR_NONE == HAL_FLASH_GetError()){
//            break;
//				}
			}
			else {
					ErrorCode = HAL_FLASH_GetError();
			}
    }
    HAL_FLASH_Lock();

    // Flash write failed - just die now
    if (ErrorCode != HAL_FLASH_ERROR_NONE || !validEEPROM()) {
//        failureMode(10);
    }

    // re-read written data
    loadAndActivateConfig();
//    if (b)
//        blinkLED(15, 20, 1);
}


bool checkFirstTime(bool reset)
{
    // check the EEPROM integrity before resetting values
    if (!validEEPROM() || reset) {
        resetConf();
        // no need to memcpy profile again, we just did it in resetConf() above
        writeEEPROM(0, false);
				return true;
    }
		return false;
}


void blinkLED(uint8_t num, uint8_t wait, uint8_t repeat)
{
    uint8_t i, r;

    for (r = 0; r < repeat; r++) {
        for (i = 0; i < num; i++) {
//            LED1_TOGGLE;            // switch LEDPIN state
 //           BEEP_ON;
            vTaskDelay(wait);
 //           BEEP_OFF;
        }
        vTaskDelay(60);
    }
}



void resetConf(void){
//	uint8_t i;
	
	  memset(&mcfg, 0, sizeof(master_t));
    memset(&cfg, 0, sizeof(config_t));
    mcfg.version = EEPROM_CONF_VERSION;
	
		cfg.sys_id = 1;
		mcfg.reboot_character = 'R';
    cfg.serial_baudrate = UART1_BAURD;
		cfg.can_baud_speed = BAUD_500K_BPS;	
	
//		mcfg.Vref_mV_SD =	SDADC_VREF;
		mcfg.Vref_SDADC_mV =	2498;
		mcfg.Vref_mV_TC = TC_VREF;
		mcfg.cali_gain_TC_V =1.046828;
		mcfg.cali_offset_TC_mV = 0;
		mcfg.cali_gain_TC_Temp =1;
		mcfg.cali_offset_TC_Temp =0;

		mcfg.cali_gain_Kelvin[R_RANGE_100] =1;
		mcfg.cali_gain_Kelvin[R_RANGE_1K] =1;
		mcfg.cali_offset_Kelvin_Ohm[R_RANGE_100] =0;
		mcfg.cali_offset_Kelvin_Ohm[R_RANGE_1K] =0;
	
		mcfg.cali_gain_DAC[0] =1;
		mcfg.cali_offset_mV_DAC[0] =0;
		mcfg.cali_gain_DAC[1] =1;
		mcfg.cali_offset_mV_DAC[1] =0;
//		mcfg.ref_3_3V_mV = DEFAULT_ADC_REF_3_3V_mV;
		mcfg.Vref_ADC_mV = 3286;

		mcfg.Gain_ADC[0] =1;
		mcfg.Gain_ADC[1] =1;
		mcfg.Offset_ADC_mV[0] =0;
		mcfg.Offset_ADC_mV[1] =0;
		
		memset(cfg.display_speed ,DISPLAY_SLOW, sizeof(cfg.display_speed));
		
//		cfg.get_char = CDC_getchar;
//		cfg.strPrint = CDC_Transmit_FS;
//		cfg.receive_char_check = CDC_is_available;
	#if 0	
		cfg.serial_to_can_port = USB_VCP;
		cfg.mavlink_port = UART2;
	#else
		cfg.serial_to_can_port = UART2;
		cfg.mavlink_port = USB_VCP;
	#endif
		cfg.CAN_TX_msg_loopback =true;
		output_protocl_port_init();
//		cfg.main_disp_max_item=3;
    memcpy(&mcfg.profile, &cfg, sizeof(config_t));	
}	

void initSystemset (void) {
	sys.DAC1_out_mV =0;
	sys.DAC2_out_mV =0;
	sys.Relay1_out =0;
	sys.PWM_duty_per = 50;
	sys.PWM_freq_Hz =1000;
	
	
}
