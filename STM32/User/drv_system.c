#include "board.h"

static volatile uint32_t usTicks = 0;
// current uptime for 1kHz systick timer. will rollover after 49 days. hopefully we won't care.
volatile uint32_t sysTickUptime = 0;

static void cycleCounterInit(void)
{
//	#ifndef RTX_USED
//    RCC_ClocksTypeDef clocks;
//    RCC_GetClocksFreq(&clocks);
//    usTicks = clocks.SYSCLK_Frequency / 1000000;
//	#else
		usTicks =1;//OS_TICK/1000;
//	#endif
}



uint32_t micros(void){
    register uint32_t ms, cycle_cnt;
    do {
        ms = sysTickUptime;
        cycle_cnt = SysTick->VAL;
    } while (ms != sysTickUptime);
    return (ms * 1000) + (SystemCoreClock/1000 - cycle_cnt) / (SystemCoreClock/1000000);
	
}

uint32_t millis(void)
{
//	  return sysTickUptime;
//	#else
	
		return osKernelSysTick();
	
//	#endif
}

void systemInit(void){
	
	    // Init cycle counter
    cycleCounterInit();

    // SysTick
    SysTick_Config(SystemCoreClock / 1000);
	
}

void delay(uint32_t ms){
        osDelay(ms);
}


#define AIRCR_VECTKEY_MASK    ((uint32_t)0x05FA0000)


void systemReset(bool toBootloader){
	USB_DECTETION_DISABLE;
		if (toBootloader) {
        // 1FFFF000 -> 20000200 -> SP
        // 1FFFF004 -> 1FFFF021 -> PC
        *((uint32_t *)0x20004FF0) = 0xDEADBEEF; // 20KB STM32F103
    }        

    // Generate system reset
    SCB->AIRCR = AIRCR_VECTKEY_MASK | (uint32_t)0x04;
}
