#include <stdio.h>
#include "queue/queue.h"

int main()
{
    queue *queue = create();
    insert(queue, 1);
    insert(queue, 2);
    insert(queue, 3);
    insert(queue, 4);
    insert(queue, 5);
    insert(queue, 6);
    insert(queue, 7);
    insert(queue, 8);

    for (int i = get_head(queue); i < get_tail(queue); i++)
    {
        printf("%d, ", get_element(queue, i));
    }

    pop(queue);
    pop(queue);
    printf("\n");

    for (int i = get_head(queue); i < get_tail(queue); i++)
    {
        printf("%d, ", get_element(queue, i));
    }
    printf("\n");
}
