#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "list.h"

// Generate an array of random numbers
//populates linked list and array with random numbers 
void random_gen(int size, int array[], List* list);

// greets user and gets logic to enter program 
bool greet();

// yes or no question handler; 
bool enter(); 

// sorts array using insertion sort algo and returns time taken to run
double insertion_A(int size, int array[]); 

// sorts array using insertion sort algo and returns time taken to run
double insertion_LL(int size, List* array );

// Explains results of run
void show_and_explain(int size, List* list, int array, double ll_time, double arr_time);

#endif
