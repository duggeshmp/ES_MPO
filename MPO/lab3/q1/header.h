#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
#include <sys/types.h>


#define ARRAY_SIZE 100

void insert_array_element(int *arr);

void thread1(void *ptr);
void thread2(void *ptr);
void thread3(void *ptr);
void thread4(void *ptr);