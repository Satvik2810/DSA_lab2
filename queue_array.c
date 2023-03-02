#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MAX 10000

struct Queue
{
    int front;
    int rear;   
    int size;
    Element arr[MAX];
};

Element itoe(int i);

Element itoe(int i)
{
    Element *e;
    e->int_value = i;
    e->float_value = 0;
    return *e;
}

Queue *createQueue()
// createQueue() returns a pointer to a new Queue instance.
{
    QUEUE myQueue = (QUEUE) malloc(sizeof(Queue));
    if(myQueue != NULL)
    {
        myQueue->front = 0;
        myQueue->rear = -1;
        myQueue->size = 0;
    }
    return myQueue;
}
bool enqueue(Queue *queue, Element element)
// enqueue() returns true if the element was successfully added to the
// queue, false otherwise.
{
    if(queue->size == MAX-1)
    {
        printf("array overflow");
        return false;
    }
    else if(queue->size == 0)
    {
        queue->arr[queue->front] = element;
        queue->rear++;
        queue->size++;
        return true;
    }
    else
    {
        queue->rear++;
        queue->arr[(queue->rear%MAX)-1] = element;
        queue->size++;
        return true;
    }
}
bool dequeue(Queue *queue)
// dequeue() returns true if the element was successfully removed from
// the queue, false otherwise.
{
    if(queue->size == 0)
    {
        printf("queue is empty, can't dequeue");
        return false;
    }
    queue->front++;
    queue->size++;
}
Element *front(Queue *queue)
// front() returns a pointer to the element at the front of the queue,
// or NULL if the queue is empty.
{
    if(queue->size == 0) return NULL;
    else return &(queue->arr[queue->front]);
}
int size(Queue *queue)
// size() returns the number of elements in the queue.
{
    return queue->size;
}
bool isEmpty(Queue *queue)
// isEmpty() returns true if the queue is empty, false otherwise.
{
    if(queue->size == 0) return true;
    else return false;
}

// void printQueue(QUEUE queue)
// {
//     while(queue->front != queue->rear)
//     {
//         printf("%d", (queue->arr[queue->front]).int_value);
//         queue->front++;
//         if(queue->front > MAX)
//         {
//             queue->front = ((queue->front)%MAX)-1;
//         }
//     }
//     printf("%d", (queue->arr[queue->front]).int_value);
// }
void destroyQueue(Queue *queue)
// destroyQueue() frees all memory associated with the queue.
{
    free(queue);
}

int main()
{
    int i1 = 5;
    int i2 = 4;
    int i3 = 3;
    int i4 = 2;
    int i5 = 1;
    QUEUE myQueue = createQueue();
    printf("%u\n",isEmpty(myQueue));
    enqueue(myQueue, itoe(i1));
    printf("%u\n",isEmpty(myQueue));
    enqueue(myQueue, itoe(i2));
    // enqueue(myQueue, itoe(i3));
    // enqueue(myQueue, itoe(i4));
    // enqueue(myQueue, itoe(i5));
    // printQueue(myQueue);
    printf("%d", myQueue->size);
}