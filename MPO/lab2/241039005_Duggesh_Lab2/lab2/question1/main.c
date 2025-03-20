#include "header.h"

/*********************************************
populate the integer array of length 1000 using random number
	create 2 thread  
	1st thread search total count of number more than 100
	2nd thread should display each element
********************************************************/

int main()
{

	  clock_t start_time = clock();


	pthread_t thread1,thread2;
	int *arr = (int *)malloc(sizeof(int)*ARRAY_SIZE);

	memset(arr,0,sizeof(int)*ARRAY_SIZE);

	//inserting random elements to array
	insert_array_element(arr);

	/*first thread creation*/
	pthread_create(&thread1,NULL,(void *)&print_array,(void *)arr);
	pthread_join(thread1,NULL);

	/*Second thread creation*/
	pthread_create(&thread2,NULL,(void *)&element_more_than100,(void *)arr);

	
	pthread_join(thread2,NULL);
	

// Calculate the elapsed time
    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nExecution time without pragma: %f seconds\n", execution_time);

	return 0;
}