
#define u16_int unsigned int

typedef struct Stack
{
    u16_int size;
    u16_int capacity;
    int *array;
} Stack;

extern Stack *create(void);
extern void push_back(Stack *stack, int element);
extern void pop(Stack *stack);
