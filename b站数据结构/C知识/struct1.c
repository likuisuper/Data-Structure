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
	
	st.sid=99;
	//st.name="����";//����
	strcpy(st.name,"����");//���ַ�����ֵ��Ҫ����ͷ�ļ� 
	st.age=22;
	printf("%d %s %d\n",st.sid,st.name,st.age);
	
	return 0;
} 
