#include "board.h"
#include "serial.h"

#define DMA_BUFFER_FULL_IRQ_READ_ENABLE
#define DMA_BUFFER_HALF__IRQ_READ_ENABLE


uart_dma_queue_type uart2_q;
uint8_t rx_dma_buf[DMA_BUF_SZ];

extern DMA_HandleTypeDef hdma_usart2_rx;
extern UART_HandleTypeDef huart2;

// 원형큐 초기화 함수
static void uart_init_queue(uart_dma_queue_type *q)
{
    q->q_front = q->q_rear = 0;    
}

// 공백상태 검출 함수
//비어 있으면 true 반환
static int uart_is_empty(uart_dma_queue_type *q)
{
    return (q->q_front == q->q_rear);
}

// 포화상태 검출 함수
//꽉차 있으면 true 반환
static int uart_queue_is_full(uart_dma_queue_type *q)
{
    return ((q->q_rear+1)%q->q_max == q->q_front);
}


// 삽입 함수
static QueueStatus uart_enqueue(uart_dma_queue_type *q, uint8_t data)
{ 
    if( uart_queue_is_full(q) ) 
        return QUEUE_ERROR;
	q->Q[q->q_rear] = data;
	q->q_rear = (q->q_rear+1) % q->q_max;
    
    return QUEUE_SUCCESS;    
}

// 삭제 함수
static QueueStatus uart_dequeue(uart_dma_queue_type *q, uint8_t * data) 
{ 
    if( uart_is_empty(q) )
        return QUEUE_ERROR;
    *data = q->Q[q->q_front];
    q->q_front = (q->q_front+1) % q->q_max;
    
    return QUEUE_SUCCESS;
}

void uart_dma_queue_init(uart_dma_queue_type *q)  {
	uart_init_queue(q);
	q->hurt = &huart2;
  q->H = &hdma_usart2_rx,
  q->dma_buf = rx_dma_buf,
  q->dma_head = 0,
  q->dma_max = DMA_BUF_SZ,
	q->q_front=0,
	q->q_rear=0,
	q->q_max=QLEN;
}

// DMA full 또는 half 인터럽트 발생시 DMA 링버퍼에 있는 값을 Uart Queue로 가져온다.
static void block_read_dma_buffer_to_queue(uart_dma_queue_type * q) {
	uint16_t  i;
	q->dma_head =	q->dma_max - q->H->Instance->CNDTR;
	if(q->dma_head > q->dma_tail) {
			q->dma_rxd_size = q->dma_head - q->dma_tail;
	}
	else {
			q->dma_rxd_size = q->dma_max -   q->dma_tail +q->dma_head;
	}
	for( i = 0 ; i < q->dma_rxd_size ; i ++) {
			uart_enqueue(q, q->dma_buf[q->dma_tail]);
			q->dma_tail = (q->dma_tail+1) % DMA_BUF_SZ;
	}	
}

static void byte_read_dma_buffer_to_queue(uart_dma_queue_type * q) {
	q->dma_head =	q->dma_max - q->H->Instance->CNDTR;
	if(q->dma_head > q->dma_tail) {
			q->dma_rxd_size = q->dma_head - q->dma_tail;
	}
	else {
			q->dma_rxd_size = q->dma_max -   q->dma_tail +q->dma_head;
	}
	if( q->dma_rxd_size) {
			uart_enqueue(q, q->dma_buf[q->dma_tail]);
			q->dma_tail = (q->dma_tail+1) % DMA_BUF_SZ;
	}	
}

//QueueStatus uart2_deque (uint8_t * data) {
//	return uart_dequeue(&uart2_q, data);
//	
//}

bool read_queue_to_buffer(uart_dma_queue_type * q, uint8_t * buffer ) {
//			switch((uint8_t)uart2_deque(buffer)){
		switch((uint8_t)uart_dequeue(q,buffer)){
				case QUEUE_SUCCESS:
					return true;
				default :
					return false;
			}
}


void uart2_dma_init(void) {
	uart_dma_queue_init(&uart2_q);
			if(HAL_UART_Receive_DMA(&huart2, rx_dma_buf, sizeof(rx_dma_buf)) != HAL_OK) {
		}

}


#ifdef DMA_BUFFER_FULL_IRQ_READ_ENABLE
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
		block_read_dma_buffer_to_queue(&uart2_q);
//		dma_buffer_half_over(&uart2_q);
}
#endif	

#ifdef DMA_BUFFER_HALF__IRQ_READ_ENABLE
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart) {
		block_read_dma_buffer_to_queue(&uart2_q);
//		dma_buffer_half_over(&uart2_q);
}
#endif	

void polling_read_rx_dma_buffer_to_queue(void) {		//dma 인터럽트로 처리되지 않은 남은 버퍼값을 가져오기 위해서 loop에서 호출 해줘야 한다. 
#define HEAD		head
	uint16_t rx_size, HEAD;
	head =	uart2_q.dma_max - uart2_q.H->Instance->CNDTR;
	//dma에 수신된 크기를 구한다.
	if(head == uart2_q.dma_tail) {
		return ;
	}
	else if(head > uart2_q.dma_tail) {
			rx_size = HEAD- uart2_q.dma_tail;
	}
	else {
			rx_size = uart2_q.dma_max -   uart2_q.dma_tail +HEAD;
	}
	if(rx_size==0) { //dma rxd empty
		return;
	}	
__disable_irq();	
			byte_read_dma_buffer_to_queue(&uart2_q);
	__enable_irq();	
}

//----------------------------------------------------------------------------------


uint8_t  uart2_str_print(uint8_t * buffer, uint16_t lens) {
		if(HAL_UART_Transmit_DMA(&huart2, (uint8_t *)buffer, lens) != HAL_OK) {
			return false;
		}
		return true;
	}

uint8_t uart2_get_char(void ) {
		uint8_t ch;
		switch((uint8_t)uart_dequeue(&uart2_q,&ch)) {
				case QUEUE_SUCCESS:
						return true;
				default :
						return false;
		}
}

bool uart2_receive_check(void) {
	return !uart_is_empty(&uart2_q);
}
	
	

#if 0
static void dma_buffer_half_over (uart_dma_queue_type *q) {
	uint16_t rx_size;
	if(q->dma_head > q->dma_tail) {
			rx_size = q->dma_head - q->dma_tail;
	}
	else {
			rx_size = q->dma_max -   q->dma_tail -q->dma_head;
	}
	  if(rx_size >= (q->dma_max>>2)) {		//반이상 찼을경우 
				read_dma_buffer_to_queue(q);		//버퍼 읽어옴
		}
}
#endif

//void uartWrite(serialPort_t *instance) {
//		if(HAL_UART_Transmit_DMA(instance->uart_rxd_port->hurt   , &instance->txd_buff, 1) != HAL_OK){
//		}
//		
//}
//void uartTotalBytesWaiting(serialPort_t *instance) {
//		if(HAL_UART_Transmit_DMA(instance->uart_rxd_port->hurt   , &instance->txd_buff, instance->txd_size) != HAL_OK){
//		}
//		
//}

//uint8_t uartRead(serialPort_t *instance){
//	uint8_t ch;
//			switch((uint8_t)uart_dequeue(instance->uart_rxd_port, &ch)){
//				case QUEUE_SUCCESS:
//					return ch;
//				default :
//					return NULL;
//			}
//	
//}

//const struct serialPortVTable uartVTable[] = {
//    {
//        uartWrite,
//        uartTotalBytesWaiting,
//        uartRead,
////        uartSetBaudRate,
////        isUartTransmitBufferEmpty,
////        uartSetMode,
//    }
//};

//serialPort_t *uart2Open(void){
//	serialPort_t * s;
//	uart2_dma_init();
//	
////	uart_dma_queue_type 
//	
//	return  (serialPort_t *)s;
//}


//uint8_t uartRead(serialPort_t *instance)
//{
//    uint8_t ch;
//    uartPort_t *s = (uartPort_t *)instance;

//    if (s->rxDMAChannel) {
//        ch = s->port.rxBuffer[s->port.rxBufferSize - s->rxDMAPos];
//        if (--s->rxDMAPos == 0)
//            s->rxDMAPos = s->port.rxBufferSize;
//    } else {
//        ch = s->port.rxBuffer[s->port.rxBufferTail];
//        s->port.rxBufferTail = (s->port.rxBufferTail + 1) % s->port.rxBufferSize;
//    }

//    return ch;
//}







//#define UART_RX_QUEUE_SIZE    256

//#define UART2_RX_BUFFER_SIZE    256
//#define UART2_TX_BUFFER_SIZE    256


//uint8_t rx2_dma_Buffer[UART2_RX_BUFFER_SIZE];
//volatile static uint8_t tx2Buffer[UART2_TX_BUFFER_SIZE];

//uartPort_t uartPort2;





//// USART2 - GPS or Spektrum or ?? (RX + TX by IRQ)
//uartPort_t *serialUSART2(UART_HandleTypeDef * huart)
//{
//    uartPort_t *s;
//    static volatile uint8_t rx2Buffer[UART2_RX_BUFFER_SIZE];
////    static volatile uint8_t tx2Buffer[UART2_TX_BUFFER_SIZE];

//    s = &uartPort2;
////    s->port.vTable = uartVTable;

//    s->port.baudRate = huart->Init.BaudRate;

//    s->port.rxBufferSize = UART2_RX_BUFFER_SIZE;
//    s->port.txBufferSize = UART2_TX_BUFFER_SIZE;
//    s->port.rxBuffer = rx2Buffer;
////    s->port.txBuffer = tx2Buffer;

//    s->USARTx = USART2;


//    return s;
//}


//bool isUartTransmitBufferEmpty(serialPort_t *instance)
//{
//    uartPort_t *s = (uartPort_t *)instance;
//    if (s->txDMAChannel)
//        return s->txDMAEmpty;
//    else
//        return s->port.txBufferTail == s->port.txBufferHead;
//}

//void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart) {
////		static char buffer[50];
////		sprintf(buffer, "test\r\n");	
////		if(HAL_UART_Transmit_DMA(&huart2, (uint8_t *)buffer, strlen((char *)buffer)) != HAL_OK) {
////		}
//}




//void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {

//}





//rx_dma & queue 선언 및 초기화
//uart_dma_queue_type uart2_q ;
//{
//  .H = &hdma_usart2_rx,
//  .dma_buf = rx_dma_buf,
//  .dma_head = 0,
//  .dma_max = DMA_BUF_SZ,
////  .insert_func = insert_queue,
////  .delete_func = delete_queue,
//	.q_front=0,
//	.q_rear=0,
//	.q_max=QLEN,
//};
