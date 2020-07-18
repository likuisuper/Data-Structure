#include<stdio.h>

void f(int *q);
void f1(int **q);
int main(void)
{
	int i=9;
	int *p=&i;
	
	printf("%p\n",p);
	f(p);
	printf("%p\n",p);
	f1(&p);
	printf("%p\n",p);
	
	return 0;
}

void f(int *q)
{
	q=(int *)0xFFFFFFFF;
}

void f1(int **q)//÷∏’Îµƒ÷∏’Î 
{
	*q=(int *)0xFFFFFFFF;
}
