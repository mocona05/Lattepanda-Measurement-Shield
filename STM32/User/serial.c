#include "board.h"
#include "usb_device.h"
#include "usbd_cdc_if.h"
#include <mavlink/Lattepanda_shiled/mavlink.h>

#ifdef USE_LAME_PRINTF
// gcc/GNU version
static void _putc(void *p, char c)
{
    (void)p;
    serialWrite(core.mainport, c);
}
#else
// keil/armcc version
int fputc(int c, FILE *f)
{
    // let DMA catch up a bit when using set or dump, we're too fast.
  //  while (!isSerialTransmitBufferEmpty(core.mainport));
//    serialWrite(core.mainport, c);
	CDC_Transmit_FS((uint8_t *)c, 1);
    return c;
}
#endif


port_t  	serial_to_can_port;
port_t 	mavlink_port;


static void serial_port_selcet(_port_typel_e portType, port_t * port);


void output_protocl_port_init(void) {
		serial_port_selcet(cfg.serial_to_can_port, &serial_to_can_port);
		serial_port_selcet(cfg.mavlink_port, &mavlink_port);
	
}



static void  serial_port_selcet(_port_typel_e portType, port_t * port) {
	switch((uint8_t) portType) {
		case USB_VCP:
				port->port_init =VCP_init;
				port->get_char = CDC_getchar;
				port->strPrint = CDC_Transmit_FS;
				port->receive_char_check = CDC_is_available;
				port->handller = VCP_handller;
			break;
		
		case UART2:
				port->port_init =uart2_dma_init;
				port->strPrint = uart2_str_print;
				port->get_char=uart2_get_char;
				port->receive_char_check = uart2_receive_check;
				port->handller = polling_read_rx_dma_buffer_to_queue;
				break;
		
		default:
				port->port_init =MX_USB_DEVICE_Init;
				port->get_char = CDC_getchar;
				port->strPrint = CDC_Transmit_FS;
				port->receive_char_check = CDC_is_available;
				port->handller = VCP_handller;
			break;
	}
	
}	



//void comm_send_buffer(mavlink_channel_t chan, uint8_t  * buffer, uint16_t lens)
//{
//    if (chan == MAVLINK_COMM_0)
//    {
//				if(hUsbDeviceFS.dev_state == USBD_STATE_CONFIGURED) {
//						CDC_Transmit_FS((uint8_t *)buffer, lens);
//		//        uart0_transmit(ch);
//				}
//    }
//    if (chan == MAVLINK_COMM_1)
//    {
//			HAL_UART_Transmit_DMA(&huart2, buffer, lens);
////    	uart1_transmit(ch);
//    }
//}
