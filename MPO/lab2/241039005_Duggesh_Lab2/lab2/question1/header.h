#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>

#define ARRAY_SIZE 1000

void insert_array_element(int *arr);

void print_array(void *a);

void element_more_than100(void *arr);
