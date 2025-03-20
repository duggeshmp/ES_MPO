#include "header.h"


/*
WAMP to multiply every element in array by constant
	the even number thread should multiply element in the even indices of array
	odd number thread should multiply the element present in odd indices of array
*/
int main()
{
	int arr[ARRAY_SIZE];

	pthread_t thrd1,thrd2;

	insert_array_element(arr);

	//creating two threads 
	//thread 1 performs odd indexes computation
	while(0 != pthread_create(&thrd1,NULL,(void *)&thread1,arr));
	//thread 2 performs even indexes computation
	while(0 != pthread_create(&thrd2,NULL,(void *)&thread2,arr));
	
	pthread_join(thrd1,NULL);
	pthread_join(thrd2,NULL);
	
	return 0;
}