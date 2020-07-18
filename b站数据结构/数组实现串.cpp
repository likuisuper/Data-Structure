#include<stdio.h>
#include<string.h>
#include<assert.h>

#define SIZE 20

typedef struct
{
	char elem[SIZE];//elem数组用来存放串的元素
	int length;//串的长度 
}Str,*PStr;

void StrAssign(PStr S,const char *chars);//生成一个其值等于字符串常量chars的串S
void Show(PStr S);//打印 
void StrCopy(PStr S,PStr T);//串T若存在，由串T复制到串S 
int GetLength(PStr S);//获取串的长度 
int StrCompare(PStr S,PStr T);//串比较：若S>T则返回1，若S=T则返回0，若S<T则返回-1 
bool SubString(PStr S,PStr Sub,int pos,int len);//用sub返回串S的第pos个字符起长度为len的字符串(pos从1开始)
int Index(PStr S,PStr T,int pos);//若串S中存在和串T值相同的子串，则返回他在串S中的第pos个位置字符后出现的第一次位置，否则返回0
bool StringEmpty(PStr S);//判断串是否为空 
bool StrInsert(PStr S,int pos,PStr T);//在串S的第pos个位置插入串T
bool StrDelete(PStr S,PStr Sub,int pos,int len);//在串S中删除第pos个字符起长度为len的子串，并将删除子串保存到Sub中
bool Replace(PStr S,PStr T,PStr V,int pos);//用V替换串S中从pos位置开始的第一个T
bool ReplaceAll(PStr S,PStr T,PStr V);//在串S中找到串T并用串V替换 
/*
1.当S1->length+S2->length<=MAXSIZE时，将S2拼接在S1后面
2.当S1->length+S2->length>MAXSIZE,但是S1->length时,则与S1连接后S2超出MAXSIZE的部分被截断 
3.当S1->length=MAXSIZE,S2被全部截断，不需要拼接 
*/
bool Concat(PStr S,PStr S1,PStr S2);//字符串拼接 

int main(void)
{
	Str s;
	Str t;
	Str sub;
	//char *s1="abcdefgh";
	char *s1="";
	char *s2="abcfghfdgtchnbdsefs"; 
	char *s3="pppodru";
	
	
	StrAssign(&s,s1);
	StrAssign(&t,s2);
	StrAssign(&sub,s3);
	
	
	Concat(&s,&t,&sub);
	Show(&s);
	
	
/*	printf("被替换的串为:%s\n",t);
	ReplaceAll(&s,&t,&sub);
	
	Show(&s);
	
/*	//StrInsert(&s,2,&t);
	
	StrDelete(&s,&sub,3,4);
	printf("删除的子串为:%s\n",sub);
	
	//SubString(&s,&sub,3,4);
	//printf("截断的字符串为:%s\n",sub);
	
		
	Show(&sub);
	
	Show(&s);
	int length=GetLength(&s);
	printf("串的长度为:%d\n",length);
	
	int index=Index(&s,&t,1);
	printf("位置为:%d\n",index);
	
		
	Show(&t);
	
	int comp=StrCompare(&s,&t);
	printf("比较结果为:%d\n",comp);
	
	
	StrAssign(&t,s2);
	StrCopy(&s,&t);
*/

	return 0;
}
 
void StrAssign(PStr S,const char *chars)
{
	assert(S!=NULL);//assert宏的原型定义在<assert.h>中，其作用是如果它的条件返回错误，则终止程序执行
	int len=strlen(chars);
	S->length=len;
	for(int i=0;i<len;i++)
	{
		S->elem[i]=chars[i];
	}
}

void Show(PStr S)
{
	for(int i=0;i<S->length;i++)
	{
		printf("%c",S->elem[i]);
	}
	printf("\n");
} 

void StrCopy(PStr S,PStr T)
{
	for(int i=0;i<T->length;i++)
	{
		S->elem[i]=T->elem[i];
	}
	S->length=T->length;
}

int GetLength(PStr S)
{
	return S->length;
} 

int StrCompare(PStr S,PStr T)
{
	int i;
	for(i=0;i<S->length&&i<T->length;i++)
	{
		if(S->elem[i]!=T->elem[i])
		{
			if(S->elem[i]>T->elem[i])
				return 1;
			else
				return -1;
		}
	}
	return 0;
} 

bool SubString(PStr S,PStr Sub,int pos,int len)
{
	int i;
	if(pos<1||pos>S->length||len>S->length-pos+1)
		return false;
	else
	{
		for(i=pos-1;i<pos-1+len;i++)
		{
			Sub->elem[i+1-pos]=S->elem[i];
			
		}
		Sub->length=len;
	}
	return true;	
}

bool StringEmpty(PStr S)
{
	if(S->length==0)
		return true;
	else
		return false;
 } 

int Index(PStr S,PStr T,int pos)
{
	if(StringEmpty(S)||pos<1||pos>S->length)
		return 0;
	int i=pos-1;
	int j=0;
	while(i<S->length&&j<T->length)//不能是<=不然结果为0 
	{
		if(S->elem[i]==T->elem[j])
		{
			++i;
			++j;//继续比较后续的字符 			
		} 
		else
		{
			i=i-j+1;//等价于i=i+1 
			j=0;//指针回退，重新开始匹配
		}
	}
	if(j>=T->length)
		return i-T->length;//等价于i-j 
	else
		return 0;
} 

bool StrInsert(PStr S,int pos,PStr T)
{
	assert(S!=NULL);
	assert(T!=NULL);
	int i;
	int j;
	if(pos<1||pos>S->length+1||pos+T->length>SIZE)
		return false;
	else
	{
		for(i=S->length-1;i>=pos-1;i--)
		{
			S->elem[i+T->length]=S->elem[i];
		}
		for(j=0;j<T->length;j++)
		{
			S->elem[j+pos-1]=T->elem[j];
		}
		S->length+=T->length;
		return true;
	} 
}

bool StrDelete(PStr S,PStr Sub,int pos,int len)
{
	if(pos<1||pos+len>S->length+1||len<0)
		return false;
	int i,j;
	
	//用一个串Sub来保存被删除的子串，然后调用SubString方法(注意这一步要先写在前面，因为是先保存值在删除)
	for(j=0;j<Sub->length;j++) 
	{
		Sub->elem[j]=S->elem[pos-1+j];
	}
	SubString(S,Sub,pos,len);//调用方法截取字符串 
	
	//将后面的元素向前移 
	for(i=pos-1+len;i<S->length;i++)
	{
		S->elem[i-len]=S->elem[i];
	}
	S->length=S->length-len;
		
	return true;
}

bool Replace(PStr S,PStr T,PStr V,int pos)
{
	assert(S!=NULL);
	assert(T!=NULL);
	assert(V!=NULL);
	int index=Index(S,T,pos);
	if(index<1)
		return false;
	StrDelete(S,T,index,T->length);
	return StrInsert(S,index,V);
}

bool ReplaceAll(PStr S,PStr T,PStr V)
{
	assert(S!=NULL);
	assert(T!=NULL);
	assert(V!=NULL);
	while(Replace(S,T,V,1))
	{
		return true;
	}	
}

bool Concat(PStr S,PStr S1,PStr S2)
{
	int i;
	if(S1->length+S2->length<=SIZE) 
	{
		for(i=0;i<S1->length;i++)
			S->elem[i]=S1->elem[i];
		for(i=0;i<S2->length;i++)
			S->elem[i+S1->length]=S2->elem[i];
		S->length=S1->length+S2->length;
		return true;
	}
	else if(S1->length<SIZE)
	{
		for(i=0;i<S1->length;i++)
			S->elem[i]=S1->elem[i];
		for(i=S1->length;i<SIZE;i++)
			S->elem[i]=S2->elem[i-S1->length];
		S->length=SIZE;
		return false; 
	}
	else
	{
		for(i=0;i<SIZE;i++)
			S->elem[i]=S1->elem[i];
		return false;
	}
}


