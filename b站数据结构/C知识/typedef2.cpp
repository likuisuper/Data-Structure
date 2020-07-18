#include<stdio.h>

typedef int ZHANGSAN;//为int再重新多取一个名字，ZHANGSAN等价于Int 

typedef struct Student
{
	int sid;
	char name;
	char sex;
}* PST;//PST等价于struct Student * 

int main(void)
{
	struct Student st;
	PST st2=&st;
	st2->sid=99;
	printf("%d",st2->sid);
	return 0;
}
