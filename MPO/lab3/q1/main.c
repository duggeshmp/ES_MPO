#include "header.h"

/**********************************

write a multithreaded pgm to multiply every 
element in an array by a constant number
create 4 thread and print
the thread number with the each multiplication that thread has done

***************************************/
int main()
{
	int arr[ARRAY_SIZE];
	pthread_t thrd1,thrd2,thrd3,thrd4;

	//inserting elements for array
	insert_array_element(arr);

	/*creation of four threads */
	while(0 != pthread_create(&thrd1,NULL,(void *)&thread1,arr));
	while(0 != pthread_create(&thrd2,NULL,(void *)&thread2,arr));
	while(0 != pthread_create(&thrd3,NULL,(void *)&thread3,arr));
	while(0 != pthread_create(&thrd4,NULL,(void *)&thread4,arr));
	
	/*Joining of each four thread*/
	pthread_join(thrd1,NULL);
	pthread_join(thrd2,NULL);
	pthread_join(thrd3,NULL);
	pthread_join(thrd4,NULL);
	
	return 0;
}