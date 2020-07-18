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
	printf("λ��Ϊ:%d\n",index);
	return 0;
}

void StrAssign(Str *S,const char *chars)
{
	assert(S!=NULL);//assert���ԭ�Ͷ�����<assert.h>�У�����������������������ش�������ֹ����ִ��
	int len=strlen(chars);
	S->length=len;
	for(int i=0;i<len;i++)
	{
		S->elem[i]=chars[i];
	}
}

/*void get_next(Str *P,int *next)
{
	int j=0,k=-1;//k��ֵΪ-1 
	next[0]=-1;//next��ʼ��Ϊ-1����ʾ��������ͬ�����ǰ׺������׺,��ʱj������ߣ����������ƶ��� 
	while(j<P->length-1)
	{
		if(k==-1||P->elem[j]==P->elem[k])//��ǰ׺�ַ����ں�׺�ַ� 
		{
			j++;
			k++;
			next[j]=k;			
		}
		else
		{
			k=next[k];//����k���� 
		}
	}
}
*/

/*
�Ľ�֮�����next����(���ַ���������ͬ�ַ�����һ���ַ�ʧ�䣬��
��һ��ָ���ƶ���λ���������ַ���ͬʱ�����ַ�һ��ʧ��) 
�����������ԭ�����p[j]=p[next[j]],������ָ��������Ҫ�ٴεݹ飬
����next[j]=next[next[j]] 
*/
void get_next(Str *P,int *next)
{
	int j=0,k=-1;//k��ֵΪ-1 
	next[0]=-1;//next��ʼ��Ϊ-1����ʾ��������ͬ�����ǰ׺������׺,��ʱj������ߣ����������ƶ��� 
	while(j<P->length-1)
	{
		if(k==-1||P->elem[j]==P->elem[k])//��ǰ׺�ַ����ں�׺�ַ� 
		{
			j++;
			k++;
			if(P->elem[j]!=P->elem[j])
				next[j]=k;
			else
				next[j]=next[k];//�ݹ飺k=next[k]=next[next[k]]		
		}
		else
		{
			k=next[k];//����k���� 
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
			j=next[j];//j���˵�next[j]��λ��(�ݹ�˼��) 
		}
	}
	if(j>=P->length)
		return i-P->length;//ƥ��ɹ��������Ӵ���λ�� 
	else
		return -1;//û�ҵ� 
 } 
