#include<stdio.h>
int main()
{
	int *p;//p是个变量名字，int *表示该p变量只能保存Int类型变量的地址
	int i=10;
	int j;
	
	p=&i;//表示取地址,此时p指向i，*p表示的就是i 
	j=*p;//等价于j=i=10
	printf("i=%d,j=%d,*p=%d\n",i,j,*p);
	printf("%p\n",p);//%p表示按16进制输出 
}
