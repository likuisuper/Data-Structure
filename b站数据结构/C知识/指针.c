#include<stdio.h>
int main()
{
	int *p;//p�Ǹ��������֣�int *��ʾ��p����ֻ�ܱ���Int���ͱ����ĵ�ַ
	int i=10;
	int j;
	
	p=&i;//��ʾȡ��ַ,��ʱpָ��i��*p��ʾ�ľ���i 
	j=*p;//�ȼ���j=i=10
	printf("i=%d,j=%d,*p=%d\n",i,j,*p);
	printf("%p\n",p);//%p��ʾ��16������� 
}
