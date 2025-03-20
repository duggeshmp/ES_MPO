#include "header.h"

/*
program for addition of 2 matrix of order nxn
	
	size of matrix is 1000x1000
	multiplication
	dont use random func to populate matrix use your own function
	also find the time taken to exection
	
	


*/

int main()
{

	  clock_t start_time = clock();
	int **matrix1 = (int **)malloc(sizeof(int) * 1000*1000);
	int **matrix2 = (int **)malloc(sizeof(int )*1000*1000);
	int add[SIZE][SIZE],multiply[SIZE][SIZE];

	//insert into matrics1
	Insert_martix1(matrix1,SIZE);
	//insert into matrics2
	Insert_martix2(matrix2,SIZE);

	Print_martix(matrix1,SIZE);

	printf("\n \n");

	Print_martix(matrix2,SIZE);

	//add and multiply matrics
	Add_mul_2_matrix(add,multiply,matrix1,matrix2);

	//print added matrics
	Print_martix(add,SIZE);
	printf("\n \n");


	//print multiplied matrics
	Print_martix(multiply,SIZE);

	clock_t end_time = clock();

    // Calculate the execution time in seconds
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Output the execution time
    printf("Execution time: %f seconds\n", time_taken);

	return 0;
}