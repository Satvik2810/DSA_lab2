#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "element.h"


LIST createNewList()
{
    LIST myList;
    myList = (LIST)malloc(sizeof(linked_list));
    if(myList == NULL)
    {
        return NULL;
    }
    myList->head = NULL;
    myList->count = 0;
    return myList;
}
NODE createNewNode(struct Element data)
{
    NODE myNode;
    myNode = (NODE)malloc(sizeof(node));
    myNode->data = data;
    myNode->next = NULL;
    return myNode;
}
void insertNodeIntoList(NODE node, LIST list)
// This function inserts a node at the beginning of the list.
{
    if(list->head == NULL)
    {
        list->head = node;
    }
    NODE temp = list->head;
    list->head = node;
    node->next = temp;
    list->count++;
}

void removeFirstNode(LIST list)
// This function removes the first node from the list.
{
    if(list->head == NULL)
    {
        printf("Empty stack, nothing to remove");
    }
    else if(list->count == 1)
    {
        list->head = NULL;
        list->count--;
    }
    else
    {
        NODE temp = list->head;
        list->head = temp->next;
        free(temp);
        list->count--;
    }
}

// void insertNodeAtEnd(NODE node, LIST list); // Not required for stack. Required for Queue
// This function inserts a node at the end of the list.

void destroyList(LIST list)
{
    free(list);
}

