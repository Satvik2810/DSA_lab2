#include "element.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1000

size_t heapMemoryAllocated = 0;
#define ADDITIONAL_MEMORY sizeof(int)

struct Element itoe(int i);

void *myalloc(size_t size)
{
    void *ptr = malloc(size + ADDITIONAL_MEMORY);
    if (ptr == NULL)
        return NULL;
    heapMemoryAllocated += size;
    *((int *)ptr) = size;
    return ptr + ADDITIONAL_MEMORY;
}
void myfree(void *ptr)
{
    int size = *((int *)(ptr - ADDITIONAL_MEMORY));
    heapMemoryAllocated -= size;
    free(ptr - ADDITIONAL_MEMORY);
}

struct Stack
{
    int top;
    struct Element data[STACK_SIZE];
};
Stack *newStack()
{
    Stack *s = (Stack *)myalloc(sizeof(Stack));
    if (s != NULL)
        s->top = -1;
    return s;
}
bool push(Stack *s, struct Element e)
{
    if (s->top >= STACK_SIZE - 1)
        return false;
    s->data[++(s->top)] = e;
    return true;
}

bool pop(Stack *s)
{
    if (s->top <= -1)
        return false;
    --(s->top);
    return true;
}

bool isEmpty(Stack *s)
{
    if (s->top == -1)
        return true;
    else
        return false;
}

Element *top(Stack *s)
{
    if (s->top == -1)
        return NULL;
    return &(s->data[s->top]);
}
void freeStack(Stack *s)
{
    myfree(s);
}

int main()
{
    Stack *s = newStack();
    if (isEmpty(s))
        printf("Stack is empty\n");

    push(s, itoe(1));
    int value = top(s)->int_value;
    printf("Top of stack is %d\n", value);

    push(s, itoe(2));
    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);

    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);

    pop(s);

    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);
    printf("Pop returned %s\n", pop(s) ? "true" : "false");

    printf("Trying to pop an empty stack\n");
    printf("Pop returned %s\n", pop(s) ? "true" : "false");

    freeStack(s);
    return 0;
}
Element itoe(int i)
{
    Element *e;
    e->int_value = i;
    e->float_value = 0;
    return *e;
}