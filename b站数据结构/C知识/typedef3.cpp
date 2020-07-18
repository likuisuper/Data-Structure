#include<stdio.h>
#include<string.h>

typedef int ZHANGSAN;//为int再重新多取一个名字，ZHANGSAN等价于Int 

typedef struct Student
{
	int sid;
	char name;
	char sex[10];
}* PST,ST;//PST等价于struct Student * ,ST等价于struct Student 

int main(void)
{
	ST st;//等价于struct Student st
	PST st1=&st;
	st1->sid=99;
	strcpy(st.sex,"男");
	printf("%d %s",st1->sid,st.sex); 
	return 0;
}
