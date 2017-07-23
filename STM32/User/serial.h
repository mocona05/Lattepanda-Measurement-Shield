#pragma once
#include <stdbool.h>

typedef void (* initPortFuncPtr)(void);  
typedef uint8_t (* str_printFuncPtr)(uint8_t *, uint16_t);                   //
typedef uint8_t (* get_charFuncPrt)(void);             //
typedef bool (* revice_char_checkFuncPtr)(void);             //
typedef void (* handllerFuncPtr)(void);  




typedef enum { 
		USB_VCP,
		UART2,
}_port_typel_e;



typedef struct port_t {
	
		initPortFuncPtr		port_init;
		get_charFuncPrt 	get_char;
		str_printFuncPtr 	strPrint;
		revice_char_checkFuncPtr	receive_char_check;
		handllerFuncPtr handller;
	
} port_t;


extern port_t  	serial_to_can_port;
extern port_t 	mavlink_port;

void output_protocl_port_init(void);

//void serial_port_selcet(_port_typel_e portType, port_t * port);


