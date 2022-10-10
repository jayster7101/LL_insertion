#include "../include/sorters.h"

void insertion_sort(int a[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int next = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > next)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = next;
    }
}

/**
 * @brief Inserts existing node into a sorted list in order
 *
 * @param list Sorted list to insert node into
 * @param node Node to insert into list
 */
void insert_node_in_order(List* list, Node*& node)
{
    if (list->head == nullptr)
    {
        list->head = node;
        list->tail = node;
        node->next = nullptr;
        return;
    }
    if (node->data <= list->head->data)
    {
        node->next = list->head;
        list->head = node;
        return;
    }
    if (node->data >= list->tail->data)
    {
        list->tail->next = node;
        node->next = nullptr;
        list->tail = node;
        return;
    }
    Node* trav = list->head;
    while (trav->next != nullptr && trav->next->data < node->data)
    {
        trav = trav->next;
    }
    node->next = trav->next;
    trav->next = node;
}

void insertion_sort(List*& list)
{
    // Do nothing if list has less than 2 elements
    if (list->head == nullptr || list->head == list->tail)
    {
        return;
    }

    // Allocate a new list that will contain sorted nodes
    List* sorted = new List;

    Node* trav = list->head;

    // For each node, insert it in order into the sorted
    // list; this destroys its position in the original
    // list.
    while (trav != nullptr)
    {
        Node* next = trav->next; // Save next node for next iteration
        insert_node_in_order(sorted, trav);
        trav = next;
    }

    delete list;   // Original allocated list object needs to be deleted
    list = sorted; // Reassign list ref to newly allocated (and sorted) list
}
