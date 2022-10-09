#include "include/utils.h"

#include <iostream>

void print_list(const List*);

int main()
{
    List* list = new List;

    add_in_order(list, 1);
    add_in_order(list, 2);
    add_in_order(list, 3);
    add_in_order(list, 0xA);
    add_in_order(list, 5);

    print_list(list);

    delete list;
}

void print_list(const List* list)
{
    Node* trav = list->head;
    while (trav != nullptr)
    {
        std::cout << trav->data << " ";
        trav = trav->next;
    }
    std::cout << "\n";
}
