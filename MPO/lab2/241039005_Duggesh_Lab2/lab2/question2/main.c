#include "header.h"
/**********************************
	
	multi threaded program that will find repetation of number in nxn matrics
	initialization of the matrics should be done in the parallel region,but done by one thread.
	the number to be searched should be entered by user before entering the parallel region


*********************************/
int num;
int main()
{
	//matrix mat;
	pthread_t thread1,thread2;
	int **mat = NULL;
	
	
	//get matrics memort
	mat = get_matrix_memory(MATRIX_SIZE,MATRIX_SIZE);

	if(mat == NULL) printf("memory allocation failed");
	printf("\nenter element to be searched:- ");
	scanf("%d ",&num);
	
	//thread to initialize matrics
	pthread_create(&thread1,NULL,(void *)initialize_matrix,(void **)mat);
	
	//thread to search entered number
	pthread_create(&thread2,NULL,(void *)search_num,(void **)mat);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	return 0;
}