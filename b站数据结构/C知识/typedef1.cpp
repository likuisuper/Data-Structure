#include<stdio.h>

typedef int ZHANGSAN;//Ϊint�����¶�ȡһ�����֣�ZHANGSAN�ȼ���Int 

typedef struct Student
{
	int sid;
	char name;
	char sex;
} ST;

int main(void)
{
	//int i=10;//�ȼ���ZHANGSAN i=10 
	//ZHANGSAN j=20;
	//printf("%d",j);
	
	struct Student st;//�ȼ���ST st 
	struct Student *ps=&st;//�ȼ���ST *ps
	ST st2;
	st2.sid=99;
	printf("%d",st2.sid); 
	return 0;
}
