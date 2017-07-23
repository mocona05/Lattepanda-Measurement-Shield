#pragma once
#include <stdbool.h>
#define DMA_BUF_SZ 64
#define QLEN 128

typedef enum {QUEUE_SUCCESS = 0, QUEUE_ERROR = !QUEUE_SUCCESS, QUEUE_FULL, QUEUE_EMPT} QueueStatus;


typedef struct uart_rx_dma_tag {
	UART_HandleTypeDef * hurt;
		DMA_HandleTypeDef *H; // 해당 uart의 수신 DMA 레지스터를 접근하기 위한 Dma handler 주소
		uint8_t *dma_buf;        // 해당 uart의 수신 DMA 저장 공간
		int dma_head;                    // DMA buffer의 위치이며 cur 위치까지 dma buffer에서 uart 수신 큐로 데이타 이동함.
		int dma_rxd_size;
		int dma_tail;
		int dma_max;                  // DMA buffer 크기
//		void (*insert_func)(struct uart_rx_dma_tag *Q,uint8_t ch);  // uart 수신 queue insert 함수
//		int  (*delete_func)(struct uart_rx_dma_tag *Q, uint8_t *p); // uart 수신 queue delete 함수

		uint8_t Q[QLEN];      // uart 수신 queue 
		uint16_t q_front;
		uint16_t q_rear;
		uint16_t q_max;
} uart_dma_queue_type;

extern UART_HandleTypeDef huart2;
extern uart_dma_queue_type uart2_q;

void uart2_dma_init(void);
void polling_read_rx_dma_buffer_to_queue(void);
QueueStatus uart2_deque (uint8_t * data);
void uart_dma_queue_init(uart_dma_queue_type *q);
bool read_queue_to_buffer(uart_dma_queue_type * q, uint8_t * buffer );


uint8_t uart2_str_print(uint8_t * buffer, uint16_t lens);
uint8_t uart2_get_char(void );
bool uart2_receive_check(void);


//typedef struct serialPort {

//    const struct serialPortVTable *vTable;

//    uint8_t identifier;
////    portMode_t mode;
////    portOptions_t options;

//    uint32_t baudRate;

//    uint32_t rxBufferSize;
//    uint32_t txBufferSize;
//    volatile uint8_t *rxBuffer;
////    volatile uint8_t *txBuffer;
//    uint32_t rxBufferHead;
//    uint32_t rxBufferTail;
//    uint32_t txBufferHead;
//    uint32_t txBufferTail;

//    // FIXME rename member to rxCallback
////    serialReceiveCallbackPtr callback;
//} serialPort_t;

//typedef struct {
//    serialPort_t port;

//    // FIXME these are uart specific and do not belong in here
//    DMA_Channel_TypeDef *rxDMAChannel;
//    DMA_Channel_TypeDef *txDMAChannel;

//    uint32_t rxDMAIrq;
//    uint32_t txDMAIrq;

//    uint32_t rxDMAPos;
//    bool txDMAEmpty;

//    USART_TypeDef *USARTx;
//} uartPort_t;


//struct serialPortVTable {
//    void (*serialWrite)(serialPort_t *instance, uint8_t ch);

//    uint8_t (*serialTotalBytesWaiting)(serialPort_t *instance);

//    uint8_t (*serialRead)(serialPort_t *instance);

//    // Specified baud rate may not be allowed by an implementation, use serialGetBaudRate to determine actual baud rate in use.
//    void (*serialSetBaudRate)(serialPort_t *instance, uint32_t baudRate);

//    bool (*isSerialTransmitBufferEmpty)(serialPort_t *instance);

////    void (*setMode)(serialPort_t *instance, portMode_t mode);
//};

//extern uartPort_t uartPort2;


