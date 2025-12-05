/*
Implementation of a queue. The goal is to get used to writing data structures in general. I had implemented a stack in the past, and I think a queue is going to be very straightforward (I hope so).

Another important aspect of this code is that I wnat to practice as much as possible the use of dynamic structures. I'm very inexperienced with memory allocation in the heap and with pointers, so I want to use those things as much as I can to get better at it.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    void (* fun)();
    struct node * next;
} node;

int queueAdd(node * queueHead, void (* func)())
{
    node * functionElement = (node *)malloc(sizeof(node));

    if (functionElement == NULL)
    {
        printf("Fail in creating space for the new function.");
        return 0;
    }
    
    functionElement->next = queueHead->next;
    queueHead->next = functionElement;

    functionElement->fun = func;

    return 1;
}

int queuePop(node * queueHead)
{
    if (queueHead->next == queueHead->next->next)
    {
        printf("The queue is already empty.\n");
        return 0;
    }

    queueHead->next->fun();

    node * liberame = queueHead->next;

    queueHead->next = queueHead->next->next;

    free(liberame);

    return 1;    
}

node * queueInitializer()
{
    node * head = (node *)malloc(sizeof(node));
    node * tail = (node *)malloc(sizeof(node));

    if (head == NULL)
    {
        printf("Error on try to allocate memory for the head.");
        free(head);
        return NULL;
    }

     if (tail == NULL)
    {
        printf("Error on try to allocate memory for the tail.");
        free(tail);
        return NULL;
    }

    head->next = tail;
    tail->next = tail;
    
    return head;
}

void func1()
{
    printf("\t\tFunction 1\n");
}
void func2()
{
    printf("\t\tFunction 2\n");
}
void func3()
{
    printf("\t\tFunction 3\n");
}
void func4()
{
    printf("\t\tFunction 4\n");
}

int main(int argc, char const *argv[])
{
    node * head = queueInitializer();

    queueAdd(head, func1);
    queueAdd(head, func3);
    queueAdd(head, func4);
    queueAdd(head, func2);

    queuePop(head);
    queuePop(head);
    queuePop(head);
    queuePop(head);
    queuePop(head);
    queuePop(head);

    return 0;
}
