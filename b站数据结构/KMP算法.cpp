#include<stdio.h>
#include<assert.h>
#include<string.h>
#define SIZE 50

typedef struct
{
	char elem[SIZE];
	int length;
}Str;

void StrAssign(Str *S,const char *chars);
void get_next(Str *P,int *next); 
int KMP(Str *S,Str *P);

int main(void)
{
	Str s;
	Str p;
	
	
	char *s1="aaaabcde";
	char *s2="de";
	
	StrAssign(&s,s1);
	StrAssign(&p,s2);
	
	
	int index=KMP(&s,&p);
	printf("位置为:%d\n",index);
	return 0;
}

void StrAssign(Str *S,const char *chars)
{
	assert(S!=NULL);//assert宏的原型定义在<assert.h>中，其作用是如果它的条件返回错误，则终止程序执行
	int len=strlen(chars);
	S->length=len;
	for(int i=0;i<len;i++)
	{
		S->elem[i]=chars[i];
	}
}

/*void get_next(Str *P,int *next)
{
	int j=0,k=-1;//k初值为-1 
	next[0]=-1;//next初始化为-1，表示不存在相同的最大前缀和最大后缀,此时j在最左边，不可能再移动了 
	while(j<P->length-1)
	{
		if(k==-1||P->elem[j]==P->elem[k])//若前缀字符等于后缀字符 
		{
			j++;
			k++;
			next[j]=k;			
		}
		else
		{
			k=next[k];//否则k回溯 
		}
	}
}
*/

/*
改进之后的求next数组(当字符串存在相同字符，后一个字符失配，则
下一次指针移动的位置与适配字符相同时，该字符一定失配) 
造成这个问题的原因就是p[j]=p[next[j]],如果出现该情况，则要再次递归，
即令next[j]=next[next[j]] 
*/
void get_next(Str *P,int *next)
{
	int j=0,k=-1;//k初值为-1 
	next[0]=-1;//next初始化为-1，表示不存在相同的最大前缀和最大后缀,此时j在最左边，不可能再移动了 
	while(j<P->length-1)
	{
		if(k==-1||P->elem[j]==P->elem[k])//若前缀字符等于后缀字符 
		{
			j++;
			k++;
			if(P->elem[j]!=P->elem[j])
				next[j]=k;
			else
				next[j]=next[k];//递归：k=next[k]=next[next[k]]		
		}
		else
		{
			k=next[k];//否则k回溯 
		}
	}
}

int KMP(Str *S,Str *P)
{
	int next[SIZE];
	int i=0,j=0;
	get_next(P,next);
	while(i<S->length&&j<P->length)
	{
		if(j==-1||S->elem[i]==P->elem[j])
		{
			i++;
			j++;
		}
		else
		{
			j=next[j];//j回退到next[j]的位置(递归思想) 
		}
	}
	if(j>=P->length)
		return i-P->length;//匹配成功，返回子串的位置 
	else
		return -1;//没找到 
 } 
