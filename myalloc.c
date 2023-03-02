#include <stdio.h>
#include <stdlib.h>

size_t heapMemoryAllocated = 0;
#define ADDITIONAL_MEMORY sizeof(int)

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
int main()
{
    printf("Heap memory allocated: %lu\n", heapMemoryAllocated);
    int *ptr = myalloc(sizeof(int));
    *ptr = 10;
    printf("Heap memory allocated: %lu\n", heapMemoryAllocated);
    myfree(ptr);
    printf("Heap memory allocated: %lu\n", heapMemoryAllocated);
    float *ptr2 = myalloc(sizeof(float));
    *ptr2 = 10.0;
    printf("Heap memory allocated: %lu\n", heapMemoryAllocated);
    char *ptr3 = myalloc(sizeof(char));
    *ptr3 = 'e';
    printf("Heap memory allocated: %lu\n", heapMemoryAllocated);
    myfree(ptr3);
    printf("Heap memory allocated: %lu\n", heapMemoryAllocated);
    double *arr;
    arr = myalloc(sizeof(double) * 40);

    printf("Heap memory allocated: %lu\n", heapMemoryAllocated);
    for (int i = 0; i < 40; i++)
    {
        arr[i] = i * 3.14;
    }
    myfree(arr);
    printf("Heap memory allocated: %lu\n", heapMemoryAllocated);
    myfree(ptr2);
    printf("Heap memory allocated: %lu\n", heapMemoryAllocated);
    return 0;
}