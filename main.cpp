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
        std::cout << std::endl
                  << "Array and linked lists of size 50,000 created and have "
                     "been filled with random data (integers)"
                  << std::endl
                  << std::endl;

        std::cout << "The first 50 items in the unsorted list and array are:"
                  << std::endl
                  << std::endl;
        print50(list);

        std::cout << "Sorting unsorted Linked List..." << std::endl;
        lltime = insertion_LL(list);
        std::cout << "Now sorting unsorted Array..." << std::endl << std::endl;
        atime = insertion_A(size, arry);

        show_and_explain(size, list, arry, lltime, atime);

        std::cout << "Sorting sorted Linked List..." << std::endl;
        lltime = insertion_LL(list);
        std::cout << "Now sorting sorted Array..." << std::endl << std::endl;
        atime = insertion_A(size, arry);

        show_and_explain(size, list, arry, lltime, atime);

        std::cout << "The first 50 items in the SORTED lists and array are:"
                  << std::endl
                  << std::endl;
        print50(list);

        std::cout << "Do you want to continue? (Yes/No)" << std::endl;
        run = enter();
    }
}
