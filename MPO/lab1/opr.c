#include "header.h"

/**populating elements of matrics*/
void Insert_martix1(int **mat,int size)
{
	int num1 = 17;
	int num2 = 97;

	for(int i = 0;i < size;i++)
	{
		for(int j = 0;j < size;j++){
			*(*(mat+ i)+j) = ((i-71)*(j-67)*967/7)%500;
		}
	}
}

/**populating elements of matrics*/
void Insert_martix2(int **mat,int size)
{
	int num1 = 7;
	int num2 = 63;

	for(int i = 0;i < size;i++)
	{
		for(int j = 0;j < size;j++){
			*(*(mat+ j)+i) = ((i-39)*(j-43)*977/76)%500;
		}
	}
}


/*Printing the elemants of matrics*/
void Print_martix(int mat[][SIZE],int size)
{
	for(int i = 0;i < size;i++)
	{
		for(int j = 0;j < size;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}


/*To perform addition and multiplication operation*/
void Add_mul_2_matrix(int add[][SIZE],int multiply[][SIZE],int mat1[][SIZE],int mat2[][SIZE])
{

	for(int i = 0;i < SIZE;i++)
	{
		for(int j = 0;j < SIZE;j++){
			add[i][j] = mat1[i][j] + mat2[i][j];
			multiply[i][j] = mat1[i][j] * mat2[i][j];
		}
		printf("\n");
	}
}

