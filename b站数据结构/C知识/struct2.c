#include<stdio.h>
#include<string.h>

struct Student
{	
	//三个成员 
	int sid;
	char name[200];
	int age;
};//分号不能省掉
 
int main(void)
{
	struct Student st={1000,"张三",20};
	//printf("%d %s %d\n",st.sid,st.name,st.age);
	
	//st.sid=99; //第一种方式
	
	struct Student * pst;
	pst=&st;
	pst->sid=99;//pst->sid等价于(*pst).sid,而(*pst).sid等价于st.sid
	//表示：pst所指向的结构体变量中的sid这个成员 
	
	
	return 0;
} 
