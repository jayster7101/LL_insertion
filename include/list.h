#ifndef LIST_H
#define LIST_H

#include "node.h"

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

// Free list memory
void list_free(List* list);

#endif
