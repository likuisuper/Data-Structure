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
	
	st.sid=99;
	//st.name="李四";//错误
	strcpy(st.name,"李四");//给字符串赋值，要引入头文件 
	st.age=22;
	printf("%d %s %d\n",st.sid,st.name,st.age);
	
	return 0;
} 
