#include<stdio.h>

int main(void)
{
/*	//指针常量 
	char a=1;
	short b=2;
	int c=10;
	double d=123.45;
	
	printf("a=%d\n",*(char*)(0x62fe1f));
	printf("b=%d\n",*(short *)(0x62fe1c));
	printf("c=%d\n",*(int*)(0x62fe18));
	printf("d=%f\n",*(double*)(0x62fe10));
*/

/*	//常量指针不是一个单纯的地址，而是有类型的，指针 
	int data=0x12345678;
	printf("%#x\n",&data);
	printf("%x\n",*(char*)(0x62fe1c));//说明16进制的时候必须要说明类型，不然会报错 
	printf("%x\n",*(short*)(0x62fe1c));
	printf("%x\n",*(int*)(0x62fe1c));
	printf("%x\n",*(double*)(0x62fe1c));
	
	char a;
	&a=0x12345678;//指针常量的地址是不允许被赋值的
*/	

	//定义指针变量
/*	char a=1;
	short b=2;
	int c=3;
	double d=5.6;
	
	char *pa=&a;
	short *pb=&b;
	int *pc=&c;
	double *pd=&d;
	
	printf("%d\n",*pa);
	printf("%d\n",*pb); 
	printf("%d\n",*pc); 
	printf("%f\n",*pd); 
*/
	
	int data=0x12345678;
	int *pa=&data;
	printf("%x\n",&data);
	printf("%x\n",*(int*)pa);
	printf("%x\n",*(short*)pa);
	printf("%x\n",*(char*)pa);//此时pa存放了data的地址
	printf("%x\n",*(int*)0x62fe14); 
	printf("%x\n",*(short*)0x62fe14);
	printf("%x\n",*(char*)0x62fe14);
}
