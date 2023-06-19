#include "record.c"
#include "sortingalgorithms.c"
#include "filereader.c"
#include "timer.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n;
	
	// Provide the file path to read
	char filePath[500]="C:/Users/Kristian/Desktop/CCDSALG/starter_code_c/data/almostsorted.txt";
	// Provide the file path to output
	char outputPath[500] = "C:/Users/Kristian/Desktop/CCDSALG/starter_code_c/output.txt";
	
	// Gets the number of records the file contains
	getNumOfRecs(filePath, &n);
    // Declare records with dynamic memory allocation
	Record *records = malloc(sizeof(Record) * n);
	
    // Read the file and populate the records array
    readFile(records, filePath);

    // Sort the records based on ID numbers
    // Get execution time
    long startTime, endTime, executionTime;
	startTime = currentTimeMillis(); // store the current time
	selectionSort(records, n); // CALL THE ALGORITHM HERE
	endTime = currentTimeMillis(); // store the current time
	executionTime = endTime - startTime;
	
    // Print the sorted contents of the records array for testing
    printRecords(records, n, outputPath);
    
    // Print execution time for documentation
    printf("Execution Time: %ld", executionTime);

    return 0;
}