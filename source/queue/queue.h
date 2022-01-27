#define u16_int unsigned int

typedef struct queue
{
    u16_int head;
    u16_int tail;
    u16_int size;
    int *queue;
} queue;

extern queue *create();
extern void insert(queue *queue, int element);
extern void pop(queue *queue);