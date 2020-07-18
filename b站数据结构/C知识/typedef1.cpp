#include<stdio.h>

typedef int ZHANGSAN;//为int再重新多取一个名字，ZHANGSAN等价于Int 

typedef struct Student
{
	int sid;
	char name;
	char sex;
} ST;

int main(void)
{
	//int i=10;//等价于ZHANGSAN i=10 
	//ZHANGSAN j=20;
	//printf("%d",j);
	
	struct Student st;//等价于ST st 
	struct Student *ps=&st;//等价于ST *ps
	ST st2;
	st2.sid=99;
	printf("%d",st2.sid); 
	return 0;
}
