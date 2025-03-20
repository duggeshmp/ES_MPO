#include<stdio.h>
#include<pthread.h>
/*
WAmP that will take two number as input from user num1,num2
	pgm should list out the number between 0 and number2 which is divisible by number1
	

*/

void thred(void *ptr);

typedef struct{
	int num1;
	int num2;
}n;
int main()
{
	n num;
	pthread_t thread1;
	

	printf("enter two numbers\n");
	scanf("%d %d",&num.num1,&num.num2);

	//creating thread to print the numbers
	while(0 != pthread_create(&thread1,NULL,(void *)&thred,&num));

	//join of thread to main
	pthread_join(thread1,NULL);
	
	return 0;
}

/***********thread function**************/
void thred(void *ptr)
{
	n *p = (n *)ptr;
	printf("\nNumbers are:- ");

	for(int i = 0;i < p->num2;i++)
		if(i%p->num1 == 0) printf("%d ",i);
}