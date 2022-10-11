#include "include/utils.h"

#include <iostream>

constexpr int SIZE = 50000;

int main()
{
    bool run = greet();
    // user interface
    while (run)
    {
        // create data
        List* list = new List;
        int array[SIZE];
        random_gen(SIZE, array, list);

        double lltime, atime;
        std::cout << std::endl
                  << "Array and linked lists of size 50,000 created and have "
                     "been filled with random data (integers)."
                  << std::endl
                  << std::endl;

        std::cout << "The first 50 items in the unsorted list and array are:"
                  << std::endl
                  << std::endl;
        preview(list);

        std::cout << "Sorting unsorted Linked List..." << std::endl;
        lltime = time_insertion_sort(list);
        std::cout << "Now sorting unsorted Array..." << std::endl << std::endl;
        atime = time_array_sort(array, SIZE);

        show_and_explain(SIZE, lltime, atime);

        std::cout << "Sorting sorted Linked List..." << std::endl;
        lltime = time_insertion_sort(list);
        std::cout << "Now sorting sorted Array..." << std::endl << std::endl;
        atime = time_array_sort(array, SIZE);

        show_and_explain(SIZE, lltime, atime);

        std::cout << "The first 50 items in the sorted lists and array are:"
                  << std::endl
                  << std::endl;
        preview(list);

        std::cout << "Do you want to continue? (Yes/No)" << std::endl;
        run = enter();

        list_free(list);
    }
}
