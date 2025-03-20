#include "header.h"

/*to insert elements into array*/
void insert_array_element(int *arr)
{
	int i;

	for(i = 0;i < ARRAY_SIZE;i++)
		*(arr+i) = ((i+1)*737*27)%159;
}

/*thread to print element of array*/
void print_array(void *a)
{
	int *arr = (int *)a;
	printf("\nElements of array :- ");
	for(int i = 0;i < ARRAY_SIZE;i++)
		printf("%d ",*(arr+i));
}

/*thread function to display elements more than 100*/
void element_more_than100(void *a)
{
	int *arr = (int *)a;
	int count = 0;

	for(int i = 0; i < ARRAY_SIZE; i++)
		if(100 < *(arr+i)) count++;

	printf("\n elements count more_than 100 in array is :- %d",count);

}
