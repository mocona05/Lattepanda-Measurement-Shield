#pragma once
#include <stdbool.h>

extern volatile uint32_t sysTickUptime;

uint32_t micros(void);
uint32_t millis(void);
void systemInit(void);
void delay(uint32_t ms);
void systemReset(bool toBootloader);

