#include "header.h"
/*********************
	create 2 function 1.add two array
			2. multiply two array
			
	wap to call these function in two seperate threads with their ids
 * ***************/

int main()
{
	Arra Arr;
	pthread_t thrd1,thrd2;

	//inserting elements into 2 arrays
	insert_array_element(Arr.arr1,ARRAY1_SIZE);
	insert_array_element(Arr.arr2,ARRAY2_SIZE);

	//creating thread to perform add operation
	while(0 != pthread_create(&thrd1,NULL,(void *)&thread1,&Arr));
	//creating thread to perform multiply operation
	while(0 != pthread_create(&thrd2,NULL,(void *)&thread2,&Arr));

	
	pthread_join(thrd1,NULL);
	pthread_join(thrd2,NULL);

	return 0;
}
