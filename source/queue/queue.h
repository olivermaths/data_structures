#define u16_int unsigned int

typedef struct queue queue;

extern queue *create();
extern void enqueue(queue *queue, int element);
extern void dequeue(queue *queue);
extern u16_int get_element(queue *queue, int index);
extern u16_int get_head(queue *queue);
extern u16_int get_tail(queue *queue);