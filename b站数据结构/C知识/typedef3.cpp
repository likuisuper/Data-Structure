#include<stdio.h>
#include<string.h>

typedef int ZHANGSAN;//Ϊint�����¶�ȡһ�����֣�ZHANGSAN�ȼ���Int 

typedef struct Student
{
	int sid;
	char name;
	char sex[10];
}* PST,ST;//PST�ȼ���struct Student * ,ST�ȼ���struct Student 

int main(void)
{
	ST st;//�ȼ���struct Student st
	PST st1=&st;
	st1->sid=99;
	strcpy(st.sex,"��");
	printf("%d %s",st1->sid,st.sex); 
	return 0;
}
