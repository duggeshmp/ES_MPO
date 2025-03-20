#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
#include <sys/types.h>


#define ARRAY1_SIZE 100
#define ARRAY2_SIZE 100


typedef struct{
	int arr1[ARRAY1_SIZE];
	int arr2[ARRAY2_SIZE];
}Arra;

void insert_array_element(int *arr,int arr_len);

void thread1(void *ptr);
void thread2(void *ptr);
void thread3(void *ptr);
void thread4(void *ptr);