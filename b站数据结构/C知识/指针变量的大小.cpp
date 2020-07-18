#include<stdio.h>

int main(void)
{
	/*
	char a;
	short b;
	int c;
	double d;
	
	printf("sizeof(&a)=%d\n",sizeof(&a));//64位操作系统下，指针变量的大小为8个字节 
	printf("sizeof(&b)=%d\n",sizeof(&b));
	printf("sizeof(&c)=%d\n",sizeof(&c));
	printf("sizeof(&d)=%d\n",sizeof(&d)); 

	//不同类型变量的地址,%#x是以16进制格式化输出(输出中带0x)
	printf("%#x\t%d\n",&a,&a); 
	printf("%#x\t%d\n",&b,&b);
	printf("%#x\t%d\n",&c,&c);
	printf("%#x\t%d\n",&d,&d);
*/	
	char a=1;
	short b=2;
	int c=3;
	long d=4;
	float e=1.2;
	double f=2.3;
	printf("打印出变量地址为：\n");
	printf("&a=%p\n",&a);
	printf("&a=%p\n",&b);
	printf("&a=%p\n",&c);
	printf("&a=%p\n",&d);
	printf("&a=%p\n",&e);
	printf("&a=%p\n",&f);
	
	printf("打印出变量地址的大小为：\n");
	printf("sizeof(&a)=%d\n",sizeof(&a));
	printf("sizeof(&a)=%d\n",sizeof(&b));
	printf("sizeof(&a)=%d\n",sizeof(&c));
	printf("sizeof(&a)=%d\n",sizeof(&d));
	printf("sizeof(&a)=%d\n",sizeof(&e));
	printf("sizeof(&a)=%d\n",sizeof(&f));
	
	printf("通过取地址和解引用访问到变量的值为：\n");
	printf("a=%d\n",*(&a));
	printf("b=%d\n",*(&b));
	printf("b=%d\n",*(&c));
	printf("b=%d\n",*(&d));
	printf("b=%f\n",*(&e));
	printf("b=%f\n",*(&f));
} 
