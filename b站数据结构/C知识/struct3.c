#include<stdio.h>
#include<string.h>

struct Student
{	
	//������Ա 
	int sid;
	char name[200];
	int age;
};//�ֺŲ���ʡ��

void f(struct Student * pst);//����һ��ǰ�ú��� 
void g(struct Student st);
void g2(struct Student *pst);

int main(void)
{
	struct Student st;//�Ѿ�Ϊst��������ڴ� 
	
	f(&st);
	
	g(st);//��g����������� 
	
	g2(&st);
	
	printf("%d %s %d\n",st.sid,st.name,st.age);
	
	return 0;
} 

void f(struct Student *pst)
{
	(*pst).sid=99;
	strcpy(pst->name,"����");
	pst->age=22;
}

//���ַ�ʽ���ڴ棬��ʱ�䣬���Ƽ� 
void g(struct Student st) //�ṹ��֮��ĸ�ֵ 
{
	printf("%d %s %d\n",st.sid,st.name,st.age);
}

void g2(struct Student *pst)
{
	printf("%d %s %d\n",pst->sid,pst->name,pst->age);
}
