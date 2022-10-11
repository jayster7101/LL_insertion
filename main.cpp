#include "include/utils.h"

#include <iostream>

void print_list(const List*);

int main()
{
    bool run = greet();
    // user interface
    while (run)
    {
        // create data
        List* list = new List;
        int const size = 50000;
        int arry[size];
        random_gen(size, arry, list);
        double lltime, atime = 0;
        std::cout << "\nArray and linked lists of size 50,000 created and have been filled with random data (integers)\n\n";

        std::cout << "The first 50 items in the unsorted list and array are:\n\n";
        print50(list);

        std::cout << "Sorting Linked List...\n";
        lltime = insertion_LL(list);
        lltime = insertion_LL(list);

        std::cout << "Now sorting Array...\n\n";
        atime = insertion_A(size, arry);
        atime = insertion_A(size, arry);

        show_and_explain(size, list, arry, lltime, atime);

        std::cout << "The first 50 items in the SORTED lists and array are:\n\n";
         print50(list);

        std::cout << "Do you want to continue? (Yes/No)\n";
        run = enter();
    }
}

// prints list
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
