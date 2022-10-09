#include "Node.h"
#ifndef LIST_H
#define LIST_H



struct List
{
    Node* head = nullptr;
    Node* tail = nullptr;
};

// Add element to front of list.
void add_front(List* list, int data);

// Add element of back of list.
void add_back(List* list, int data);

// Add in order
void add_in_order(List* list, int data);

#endif
