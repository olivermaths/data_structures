#include <stdio.h>
#include "stack/stack.h"

int main()
{
    Stack *stack = create();
    push_back(stack, 1);
    push_back(stack, 2);
    push_back(stack, 3);
    push_back(stack, 4);
    push_back(stack, 5);
    push_back(stack, 6);
    push_back(stack, 7);
    push_back(stack, 8);

    for (int i = 0; i < get_capacity(stack); i++)
    {
        printf("%d, ", get_element(stack, i));
    }

    pop(stack);
    pop(stack);
    push_back(stack, 20);

    printf("\n");
    for (int i = 0; i < get_capacity(stack); i++)
    {
        printf("%d, ", get_element(stack, i));
    }
    printf("\n");
}
