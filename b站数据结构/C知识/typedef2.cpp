#include<stdio.h>

typedef int ZHANGSAN;//Ϊint�����¶�ȡһ�����֣�ZHANGSAN�ȼ���Int 

typedef struct Student
{
	int sid;
	char name;
	char sex;
}* PST;//PST�ȼ���struct Student * 

int main(void)
{
	struct Student st;
	PST st2=&st;
	st2->sid=99;
	printf("%d",st2->sid);
	return 0;
}
