#include "header.h"

//inserting elements into array
void insert_array_element(int *arr,int arr_len)
{
	int i;

	for(i = 0;i < arr_len;i++)
		*(arr+i) = ((i+1)*737*27)%159;
}


//Thread 1 function
void thread1(void *ptr)
{
	int i;
	Arra *arr = (Arra *)ptr;
	

	for(i = 0;i < ARRAY1_SIZE;i++)
	 printf("\nThread Id:- %u sum %d",gettid(),arr->arr1[i]+arr->arr2[i]);
}

//thread 2 function
void thread2(void *ptr)
{
	int i;
	Arra *arr = (Arra *)ptr;

	for(i = 0;i < ARRAY1_SIZE;i++)
	 printf("\nThread Id:- %u sum %d",gettid(),arr->arr1[i]+arr->arr2[i]);
}

//thread 3 function
void thread3(void *ptr)
{
	int i;
	Arra *arr = (Arra *)ptr;

	for(i = 0;i < ARRAY1_SIZE;i++)
	 printf("\nThread Id:- %u sum %d",gettid(),arr->arr1[i]+arr->arr2[i]);
}
//thread 4 function
void thread4(void *ptr)
{
	int i;
	Arra *arr = (Arra *)ptr;
	for(i = 0;i < ARRAY1_SIZE;i++)
	 printf("\nThread Id:- %u sum %d",gettid(),arr->arr1[i]+arr->arr2[i]);
}
