#include "stack.h"
#include <stdlib.h>

Stack *create()
{
    Stack *stack = malloc(sizeof(stack));
    stack->size = 2;
    stack->capacity = 0;
    stack->array = malloc(sizeof(int) * 2);
    stack->array[0] = 0;
    stack->array[1] = 0;
    return stack;
}
void push_back(Stack *stack, int element)
{
    if (stack->capacity == stack->size)
    {
        stack->size *= 2;
        stack->array = realloc(stack->array, stack->size * sizeof(int));
    }

    stack->array[stack->capacity] = element;
    stack->capacity += 1;
};
void pop(Stack *stack)
{
    stack->capacity -= 1;
    stack->array[stack->capacity] = 0;
};