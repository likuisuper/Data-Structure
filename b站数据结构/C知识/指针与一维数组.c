#include<stdio.h>
int main()
{
	int a[5]={1,2,3,4,5};//a表示指向第一个元素的地址 
	
	//a[3]=*(a+3)或者*[3+a]即等价于3[a]
	
	printf("%p\n",a+1);
	printf("%p\n",a+2);
	//printf("%p\n",a+3);//a+3是指向第四个地址
	printf("%d\n",*a+3);//*a+3等价于a[0]+3,即a+3本身,而不是地址 
}
