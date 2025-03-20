#include "header.h"

//To insert element to array
void insert_array_element(int *arr)
{
	int i;

	for(i = 0;i < ARRAY_SIZE;i++)
		*(arr+i) = ((i+1)*737*27)%159;
}


//Thread 1 function
void thread1(void *ptr)
{
	int i;
	int *arr = (int *)ptr;

	for(i = 0;i < ARRAY_SIZE;i++)
	 printf("\nThread Id:- %u Product %d",gettid(),arr[i]*7);
}

//thread 2 function
void thread2(void *ptr)
{
	int i;
	int *arr = (int *)ptr;

	for(i = 0;i < ARRAY_SIZE;i++)
	 printf("\nThread Id:- %u Product %d",gettid(),arr[i]*17);
}

//Thread 3 function
void thread3(void *ptr)
{
	int i;
	int *arr = (int *)ptr;

	for(i = 0;i < ARRAY_SIZE;i++)
	 printf("\nThread Id:- %u Product %d",gettid(),arr[i]*27);
}

//thread 4 function
void thread4(void *ptr)
{
	int i;
	int *arr = (int *)ptr;
	for(i = 0;i < ARRAY_SIZE;i++)
	 printf("\nThread Id:- %u Product %d",gettid(),arr[i]*37);
}
