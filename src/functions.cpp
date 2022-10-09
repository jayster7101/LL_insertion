#include "../include/functions.h"
// #include <ctime>
// #include <cstdlib>
#include <iostream>
/**
 * @brief Fills array and linked list with random numbers
 * 
 * @param size size of array & linked list
 * @param arr array to be filled
 * @param list linked list to be filled
 */
void random_gen(int size, int arr[], List* list)
{
    srand(time(NULL));
    for(int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 50000);
        add_front(list, (rand() % 50000));
    }
}

