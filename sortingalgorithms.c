#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include "record.c"

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/

void getNumOfRecs(char path[500], int *n){
	FILE *fp;
    fp = fopen(path, "r");
    fscanf(fp, "%d", n);
}

// Helper Function that print records to a file for testing
void printRecords(Record *records, int n, char outputPath[500]) {
    FILE *fp = fopen(outputPath, "w");
    if (fp == NULL) {
        printf("Error opening output file.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d %s\n", records[i].idNumber, records[i].name);
    }

    fclose(fp);
}





void insertionSort(Record *arr, int n)
{
    // TODO: Implement this sorting algorithm here.
    Record key;
    int i,j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j].idNumber > key.idNumber) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
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