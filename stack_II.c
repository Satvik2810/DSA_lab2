#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "stack.h"

struct Stack
{
    int top;
    LIST myList;
};

typedef struct Stack* STACK;
STACK newStack()
// Returns a pointer to a new stack. Returns NULL if memory allocation fails
{
    STACK myStack = (STACK)malloc(sizeof(Stack));
    LIST myList = createNewList();
    myStack->myList = myList;
    return myStack;
}
bool push(STACK stack, Element element)
// Pushes element onto stack. Returns false if memory allocation fails
{
    NODE myNode = createNewNode(element);
    if(myNode == NULL)
    {
        return false;
    }
    insertNodeIntoList(myNode, stack->myList);
    // NODE temp = stack->myList->head;
    // stack->myList->head = myNode;
    // myNode->next = temp;
    return true;
}
Element *top(STACK stack)
// Returns a pointer to the top element. Returns NULL if stack is empty
{
    if(stack->myList->head == NULL)
    {
        printf("BT");
    }
    Element *e = (Element *)malloc(sizeof(Element));
    *e = stack->myList->head->data;
    return e;
}
bool pop(STACK stack)
// Pops the top element and returns true. Returns false if stack is empty
{
    if(stack->myList->head==NULL)
    {
        return false;
    }
    removeFirstNode(stack->myList);
    return true;
}
bool isEmpty(Stack *stack)
// Returns true if stack is empty. Returns false otherwise
{
    if(stack->myList->head == NULL)
    {
        return true;
    }
    else return false;
}
void freeStack(Stack *stack)
// Frees all memory associated with stack
{
    free(stack);
}
Element itoe(int i)
{
    Element *e;
    e->int_value = i;
    e->float_value = 0;
    return *e;
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