#include <stdlib.h>
#include "queue.h"

typedef struct queue
{
    u16_int head;
    u16_int tail;
    u16_int size;
    int *queue;
} queue;

queue *create(void)
{
    queue *queue = malloc(sizeof(queue));
    queue->size = 1;
    queue->head = queue->tail = 0;
    queue->queue = malloc(sizeof(int));
    queue->queue[0] = 0;
    return queue;
}

void enqueue(queue *queue, int element)
{
    if (queue->tail == queue->size)
    {
        queue->size *= 2;
        queue->queue = realloc(queue->queue, queue->size * sizeof(int));
    }
    queue->queue[queue->tail] = element;
    queue->tail += 1;
};

void dequeue(queue *queue)
{
    queue->queue[queue->head] = 0;
    queue->head += 1;
}

u16_int get_head(queue *queue)
{
    return queue->head;
};

u16_int get_tail(queue *queue)
{
    return queue->tail;
};

u16_int get_element(queue *queue, int index)
{
    if (index >= queue->head && index <= queue->tail)
    {
        return queue->queue[index];
    }
    return 0;
};
