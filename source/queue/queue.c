#include <stdlib.h>
#include "queue.h"

queue *create(void)
{
    queue *queue = malloc(sizeof(queue));
    queue->size = 1;
    queue->head = queue->tail = 0;
    queue->queue = malloc(sizeof(int));
    queue->queue[0] = 0;
    return queue;
}

void insert(queue *queue, int element)
{
    if (queue->tail == queue->size)
    {
        queue->size *= 2;
        queue->queue = realloc(queue->queue, queue->size * sizeof(int));
    }
    queue->queue[queue->tail] = element;
    queue->tail += 1;
};

void pop(queue *queue)
{
    queue->queue[queue->head] = 0;
    queue->head += 1;
}