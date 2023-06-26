#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include <stdlib.h>
#include "record.c"


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
        minimum_idx= i;
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

void merge(Record *arr, int l, int m, int r)
{
	int i = 0, j = 0, k = l;
	int n1 = m - l + 1;
	int n2 = r - m;
	Record *L = malloc(sizeof(Record) * n1);
	Record *R = malloc(sizeof(Record) * n2);
	
	for(i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}
		
	for(j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1 + j];
	}
	
	i = 0, j = 0;

	while(i < n1 && j < n2)
	{
		if(L[i].idNumber <= R[j].idNumber)
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	while(i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	
	while(j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	
}

void mergeSort(Record *arr, int l, int r)
{
    if(l < r)
    {
    	int m = (l + r) / 2;	
    	mergeSort(arr, l, m);
    	mergeSort(arr, m+1, r);
    	merge(arr, l, m, r);
	}
}

/*
* Define AT LEAST ONE more sorting algorithm here, apart from the
* ones given above. Make sure that the method accepts an array of
* record structures.
*/

void bucketSort(Record *arr, int n) {

    int maxID = arr[0].idNumber;
    for (int i = 1; i < n; i++) {
        if (arr[i].idNumber > maxID) {
            maxID = arr[i].idNumber;
        }
    }
    int numBuckets = maxID / 10 + 1;
    int *bucketCounts = (int *)calloc(numBuckets, sizeof(int));
    Record **buckets = (Record **)malloc(numBuckets * sizeof(Record *));
    for (int i = 0; i < numBuckets; i++) {
        bucketCounts[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i].idNumber / 10;
        bucketCounts[bucketIndex]++;
    }
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = (Record *)malloc(bucketCounts[i] * sizeof(Record));
        bucketCounts[i] = 0; 
    }
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i].idNumber / 10;
        int count = bucketCounts[bucketIndex];
        buckets[bucketIndex][count] = arr[i];
        bucketCounts[bucketIndex]++;
    }
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        int count = bucketCounts[i];
        insertionSort(buckets[i], count); 
        for (int j = 0; j < count; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
        free(buckets[i]);
    }
    free(bucketCounts);
    free(buckets);
}


#endif