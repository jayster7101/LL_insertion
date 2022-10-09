#include "../include/list.h"
#include "../include/node.h"
#include <iostream>

void add_front(List* list, int data)
{
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == nullptr)
    {
        list->tail = new_node;
    }
}

void add_back(List* list, int data)
{
    Node* new_node = new Node;
    new_node->data = data;
    if (list->head == nullptr)
    {
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        list->tail->next = new_node;
    }
}

void add_in_order(List* list, int data)
{
    if (list->head == nullptr)
    {
        add_front(list, data);
        return;
    }
    else if (data <= list->head->data)
    {
        add_front(list, data);
        return;
    }
    else if (data >= list->tail->data)
    {
        add_back(list, data);
        return;
    }

    Node* new_node = new Node;
    new_node->data = data;

    Node* trav = list->head;
    while (trav->next != nullptr && trav->next->data < data)
    {
        trav = trav->next;
    }

    new_node->next = trav->next;
    trav->next = new_node;
}


