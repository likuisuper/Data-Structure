#include<stdio.h>
#include<string.h>

struct Student
{	
	//三个成员 
	int sid;
	char name[200];
	int age;
};//分号不能省掉

void f(struct Student * pst);//声明一个前置函数 
void g(struct Student st);
void g2(struct Student *pst);

int main(void)
{
	struct Student st;//已经为st分配好了内存 
	
	f(&st);
	
	g(st);//向g发送整体变量 
	
	g2(&st);
	
	printf("%d %s %d\n",st.sid,st.name,st.age);
	
	return 0;
} 

void f(struct Student *pst)
{
	(*pst).sid=99;
	strcpy(pst->name,"张三");
	pst->age=22;
}

//这种方式耗内存，耗时间，不推荐 
void g(struct Student st) //结构体之间的赋值 
{
	printf("%d %s %d\n",st.sid,st.name,st.age);
}

void g2(struct Student *pst)
{
	printf("%d %s %d\n",pst->sid,pst->name,pst->age);
}
