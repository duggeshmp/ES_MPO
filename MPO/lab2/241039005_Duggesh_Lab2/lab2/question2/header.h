#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>

#define MATRIX_SIZE 5

typedef struct matrics
{
	int **mat;
	int num;
}matrix;

int ** get_matrix_memory(int row,int col);

void initialize_matrix(void *ptr);
void search_num(void *ptr);