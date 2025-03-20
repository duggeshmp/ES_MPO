#include "header.h"


//inserting elements into array
void insert_array_element(int *arr,int arr_len)
{
	int i;

	for(i = 0;i < arr_len;i++)
		*(arr+i) = ((i+1)*737*27)%159;
}

//thread 1 calling add function

void thread1(void *ptr)
{
	add(ptr);
}

//thread 1 calling multiplication function
void thread2(void *ptr)
{

	multiply(ptr);
	
}

//performs addition of two arrays
void add(void *ptr)
{
	int i;
	Arra *arr = (Arra *)ptr;

	for(i = 0;i < ARRAY1_SIZE;i++)
	 printf("\nThread Id:- %u sum %d",gettid(),arr->arr1[i]+arr->arr2[i]);
}

//performs multiplication of two arrays
void multiply(void *ptr)
{
	int i;
	Arra *arr = (Arra *)ptr;
	for(i = 0;i < ARRAY1_SIZE;i++)
	 printf("\nThread Id:- %u product %d",gettid(),arr->arr1[i]*arr->arr2[i]);
}
