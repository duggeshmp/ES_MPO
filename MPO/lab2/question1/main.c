#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

#define ARRAY_SIZE 1000

/*********************************************
populate the integer array of length 1000 using random number
	create 2 threads  
	1st thread search total count of number more than 100
	2nd thread should display each element
********************************************************/

int main()
{
    // Start measuring execution time
    clock_t start_time = clock();

    int *arr = (int *)malloc(sizeof(int) * ARRAY_SIZE);
    memset(arr, 0, sizeof(int) * ARRAY_SIZE);

    // Inserting random elements to array
    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task
            insert_array_element(arr);

            #pragma omp task
            print_array(arr);

            #pragma omp task
            element_more_than100(arr);
        }
    }

    free(arr);

    // Calculate the elapsed time
    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nExecution time using pragma: %f seconds\n", execution_time);

    return 0;
}
