#include<stdio.h>
#include<string.h>

struct Student
{	
	//������Ա 
	int sid;
	char name[200];
	int age;
};//�ֺŲ���ʡ��
 
int main(void)
{
	struct Student st={1000,"����",20};
	//printf("%d %s %d\n",st.sid,st.name,st.age);
	
	//st.sid=99; //��һ�ַ�ʽ
	
	struct Student * pst;
	pst=&st;
	pst->sid=99;//pst->sid�ȼ���(*pst).sid,��(*pst).sid�ȼ���st.sid
	//��ʾ��pst��ָ��Ľṹ������е�sid�����Ա 
	
	
	return 0;
} 
