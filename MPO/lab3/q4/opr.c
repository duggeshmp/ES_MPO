#include "header.h"

//inserting element into array
void insert_array_element(int *arr)
{
	int i;

	for(i = 0;i < ARRAY_SIZE;i++)
		*(arr+i) = ((i+1)*737*27)%159;
}

//thread function 1 performs odd indexes computation
void thread1(void *ptr)
{
	int i;
	int *arr = (int *)ptr;

	for(i = 1;i < ARRAY_SIZE;i = i+2)
	 printf("\nThread Id:- %u Product %d",gettid(),arr[i]*CONSTANT);
}

//thread function 2 performs even indexes computation
void thread2(void *ptr)
{
	int i;
	int *arr = (int *)ptr;

	for(i = 0;i < ARRAY_SIZE;i = i+2)
	 printf("\nThread Id:- %u Product %d",gettid(),arr[i]*CONSTANT);
}