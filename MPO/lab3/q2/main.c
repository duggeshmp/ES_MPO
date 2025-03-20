#include "header.h"
/*************************************
WAMP to add two arrays create 4  
threads and print the thread number with
 each computation that is performed
*****************************************/

int main()
{
	Arra Arr;
	pthread_t thrd1,thrd2,thrd3,thrd4;

	//inserting elements for each array
	insert_array_element(Arr.arr1,ARRAY1_SIZE);
	insert_array_element(Arr.arr2,ARRAY2_SIZE);

	//creating 4 different thread
	while(0 != pthread_create(&thrd1,NULL,(void *)&thread1,&Arr));
	while(0 != pthread_create(&thrd2,NULL,(void *)&thread2,&Arr));
	while(0 != pthread_create(&thrd3,NULL,(void *)&thread3,&Arr));
	while(0 != pthread_create(&thrd4,NULL,(void *)&thread4,&Arr));
	
	//joining 4 threads to main
	pthread_join(thrd1,NULL);
	pthread_join(thrd2,NULL);
	pthread_join(thrd3,NULL);
	pthread_join(thrd4,NULL);
	return 0;
}