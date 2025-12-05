/*
My goal here is to try to implement the observer pattern. 

My exposure to this pattern was with C# a bit of time ago. Back then I just had a little exposure to it and couldn't learn it completely, but now, with these advances that I've made with C, creating my own stuff (even though it could be very bad code), I'm feeling confident to create my own event system using pointers. I hope it works because this topic was pretty challenging for me the first time I faced it (when I was learning C#), so implementing it by, almost, first principles will mean a lot for me.
*/

#include <stdio.h>
#include <stdlib.h>

// Let's create an enum that tells the publisher who should be called and when to stop running through the list.
typedef enum {HEAD_TYPE, FUNC_TYPE, TAIL_TYPE} funcType;

void create();
int read(int n);
float delete(double q);


typedef struct node
{
    funcType exec;
    void (* func)();
    struct node * next;
} node;

typedef struct subscribers
{
    node * head;
    node * tail;
} subscribers;

int publisher(subscribers * eventSubList);

// the way how the event will trigger the publisher will be by actually not calling the observed function itself but a callback instead. We may make a function that takes the struct below and, when the function executes, the publisher will be called. 
typedef struct
{
    void (* event_function)();
    subscribers * eventSubs;
} event_t;

void callEvent(event_t * someEvent)
{
    someEvent->event_function();
    publisher(someEvent->eventSubs);
}

// Now let's make up a couple of functions that will serve us as events.
void create()
{
    printf("Created\n");
}
int read(int n)
{
    printf("Read\n");
    return n;
}
float delete(double q)
{
    int exponent = (*(int *)&q >> 52) - 1023;
    exponent &= 011111111111;
    printf("Deleted %f\n", (float)exponent);
    return (float)exponent;
}

// Now we can create some functions to perform the role of subscribers.
void bigEyeNumber1()
{
    printf("Eu, BIG EYE, notei o evento.\n");
}
void xereta()
{
    printf("Eu, Xereta, notei o evento.\n");
}
void intrometido()
{
    printf("Eu, Intrometido, notei isso aeh.\n");
}
void nosy()
{
    printf("I see you\n");
}
void bosybody()
{
    printf("O.O");
}

// We need a function to subscribe these observers to a chosen event.
int subscribeNOW(subscribers * eventSubList, void (* func)())
{
    node * newFunction = (node *)malloc(sizeof(node));

    if (newFunction == NULL)
    {
        printf("Error on trying to allocate memory for the new function.\n");
        return 0;
    }    

    newFunction->exec = FUNC_TYPE;
    newFunction->func = func;
    newFunction->next = eventSubList->head->next;
    eventSubList->head->next = newFunction;   
    
    return 1;
}

int publisher(subscribers * eventSubList)
{
    node * observer;

    if (observer == NULL)
    {
        printf("Error on trying to allocate memory for the iterator.\n");
        return 0;
    }    

    observer = eventSubList->head->next;

    while (observer->exec == FUNC_TYPE)
    {
        observer->func();
        observer = observer->next;
    }    

    return 1;
}

subscribers * eventListInitializer()
{
    subscribers * list = (subscribers *)malloc(sizeof(subscribers));
    node * headList = (node *)malloc(sizeof(node));
    node * tailList = (node *)malloc(sizeof(node));

    list->head = headList;
    list->tail = tailList;

    if (list == NULL)
    {
        printf("Error on trying to allocate memory for the list.");
        return NULL;
    }

    list->head->exec = HEAD_TYPE;
    list->head->next = list->tail;
    list->tail->next = list->tail;
    list->tail->exec = TAIL_TYPE;

    return list;
    
}

int main(int argc, char const *argv[])
{    
    event_t eventCreate;
    eventCreate.event_function = create;
    eventCreate.eventSubs = eventListInitializer();

    subscribeNOW(eventCreate.eventSubs, nosy);
    subscribeNOW(eventCreate.eventSubs, xereta);
    subscribeNOW(eventCreate.eventSubs, intrometido);

    callEvent(&eventCreate);

    return 0;
}
