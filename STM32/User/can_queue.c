#include "board.h"

#ifndef CAN_TXD_DISABLE
CAN_Queue_t CAN_txd_queue;
#endif
CAN_Queue_t CAN_rxd_queue;


// ����ť �ʱ�ȭ �Լ�
void can_init_queue(CAN_Queue_t *q)
{
    q->front = q->rear = 0;    
}

// ������� ���� �Լ�
//��� ������ true ��ȯ
int can_is_empty(CAN_Queue_t *q)
{
    return (q->front == q->rear);
}

// ��ȭ���� ���� �Լ�
//���� ������ true ��ȯ
int can_queue_is_full(CAN_Queue_t *q)
{
    return ((q->rear+1)%MAX_CAN_QUEUE_SIZE == q->front);
}

// ���� �Լ�
QueueStatus CAN_enqueue(CAN_Queue_t *q, volatile CanQueueType  item)
{ 
    if( can_queue_is_full(q) ) 
        return QUEUE_ERROR;
	q->rear = (q->rear+1) % MAX_CAN_QUEUE_SIZE;
	q->queue[q->rear] = item;
    
    return QUEUE_SUCCESS;    
}

// ���� �Լ�
QueueStatus CAN_dequeue(CAN_Queue_t *q, CanQueueType *item) 
{ 
    if( can_is_empty(q) )
        return QUEUE_ERROR;
    q->front = (q->front+1) % MAX_CAN_QUEUE_SIZE;
    *item = q->queue[q->front];
    
    return QUEUE_SUCCESS;
}
