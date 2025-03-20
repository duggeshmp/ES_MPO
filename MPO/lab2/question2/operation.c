#include "header.h"

extern int num;

/*function to dynamic memory allocation of matrics*/
int ** get_matrix_memory(int row,int col)
{
	int **matrix = NULL;

	matrix = (int **)malloc(sizeof(int *)*row);
	
	if(NULL == matrix)	printf("\nmemory allocation failed");

	for(int i = 0;i < row;i++)
	{
		*(matrix+i) = (int *)malloc(sizeof(int )*col);
		if(NULL == *(matrix+i)) printf("\n memory allocation failed");
	}

	return matrix;
}


/*Initialization of matrcs*/
void initialize_matrix(void *ptr)
{
	//matrix *mat = (matrix *)ptr;
	int **mat = (int **)ptr;
	for(int i = 0;i < MATRIX_SIZE; i++)
	{
		for(int j =0;j < MATRIX_SIZE;j++)
		{
			//*(*(mat->mat+i)+j) = ((i+1+j)*737*27)%159;
			*(*(mat+i)+j) = ((i+1+j)*737*27)%159;
			printf("%d ",*(*(mat+i)+j));
			
		}
	}
}


/* thread to search element */
void search_num(void *ptr)
{
	int **mat = (int **)ptr;
	int count = 0;

	for(int i = 0;i < MATRIX_SIZE; i++)
	{
		for(int j =0;j < MATRIX_SIZE;j++)
		{
			if(num == *(*(mat+i)+j)) count++;
		}
	}
	printf("count %d",count);
}