#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include "record.c"

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/






void insertionSort(Record *arr, int n)
{
    // TODO: Implement this sorting algorithm here.






}

void selectionSort(Record *arr, int n)
{
    int i, j, minimum_idx;
    for (i = 0; i < n - 1; i++) {
        minimum_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].idNumber < arr[minimum_idx].idNumber) {
                minimum_idx = j;
            }
        }
        // Swap the minimum element with the first element
        Record temp = arr[minimum_idx];
        arr[minimum_idx] = arr[i];
        arr[i] = temp;
    }

}

void mergeSort(Record *arr, int p, int r)
{
    // TODO: Implement this sorting algorithm here.






}

/*
* Define AT LEAST ONE more sorting algorithm here, apart from the
* ones given above. Make sure that the method accepts an array of
* record structures.
*/











#endif