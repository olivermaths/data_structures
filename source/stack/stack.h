
#define u16_int unsigned int

typedef struct Stack Stack;

extern Stack *create(void);
extern void push_back(Stack *stack, int element);
extern void pop(Stack *stack);
extern int get_capacity(Stack *stack);
extern int get_element(Stack *stack, int index);