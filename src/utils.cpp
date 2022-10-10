#include "../include/utils.h"
#include "../include/sorters.h"
// #include <ctime>
// #include <cstdlib>
#include <chrono>
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
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 50000);
        add_front(list, (rand() % 50000));
    }
}
/**
 * @brief handles yes or no questions
 *
 * @return bool true for yes, false for no
 */
bool enter()
{
    bool return_value;
    std::string yes_no;
    bool reprompt = false;
    while (!reprompt) // this is the first instance of input validation which
                      // only accepts yes or Yes or No or no and will keep
                      // prompting until valid
    {
        if (std::cin.fail())
            std::cin.ignore(100, '\n'); // ignores the flag on the error
        std::cin >> yes_no;
        if (yes_no == "yes" ||
            yes_no == "Yes") // the logic below compares the string to the 4
                             // possible values, and then returns true or false
                             // to either enter the if statement or skip to the
                             // else statement in the main function
        {
            reprompt = true;
            return_value = true;
        }
        else if (yes_no == "no" || yes_no == "No")
        {
            reprompt = true;
            return_value = false;
        }
        else
        {
            std::cout << "Please enter yes or no only\n> ";
        }
    }
    return return_value;
}

bool greet()
{
    std::cout << "Hello, Welcome to our program" << std::endl;
    std::cout << "********************************";
    std::cout << " Rundown ";
    std::cout << "********************************";
    std::cout << "* We have created a small program that compares the run time "
                 "efficiency of insertion sort on both linked list and arrays";
    std::cout
        << "* Would you like to try it out?\nPlease enter yes or no:\n-> ";
    return enter();
}

/**
 * @brief Sorts array using insertion sort and records time taken to complete
 *
 * @param size size or array
 * @param array
 * @return double time taken to sort data
 */
double insertion_A(int size, int array[])
{
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for (int i = 1; i < size; i++)
    {
        int temp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = temp;
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    return time_span.count();
}

double insertion_LL(List* list)
{
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    insertion_sort(list);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    return time_span.count();
}

void show_and_explain(int size, List* list, int array[], double ll_time,
                      double arr_time)
{

    std::cout << "~~~~~~~~~~~~~~~~~~~~Results~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "Data size: " << size << std::endl;
    std::cout << "Time taken for Array: " << arr_time << " seconds"
              << std::endl;
    std::cout << "Time taken for Linked-List: " << ll_time << " seconds"
              << std::endl;
    std::cout << "The percent difference between each algorithm is "
              << ((abs(ll_time - arr_time)) / ((ll_time + arr_time) / (2)))
              << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

void print50(const List* list)
{
    Node* trav = list->head;
    for (int i = 0; i < 50; i++)
    {
        if (trav == nullptr)
        {
            break;
        }
        std::cout << trav->data << " ";
        if ((i + 1) % 10 == 0)
        {
            std::cout << "\n";
        }
        trav = trav->next;
    }
}
