#pragma once
#include <stdbool.h>


void usb_VCP_test(void);
void enqueue_cdc_data(uint8_t *buf, uint32_t len);
bool dequeue_cdc_data(uint8_t *p);
bool CDC_is_available(void);
void CDC_putchar(char ch);
void CDC_printf(char *fmt,...);
uint8_t CDC_getchar(void);
void VCP_init(void);
void VCP_handller(void);
