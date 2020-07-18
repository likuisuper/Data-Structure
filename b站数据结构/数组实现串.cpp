#include<stdio.h>
#include<string.h>
#include<assert.h>

#define SIZE 20

typedef struct
{
	char elem[SIZE];//elem����������Ŵ���Ԫ��
	int length;//���ĳ��� 
}Str,*PStr;

void StrAssign(PStr S,const char *chars);//����һ����ֵ�����ַ�������chars�Ĵ�S
void Show(PStr S);//��ӡ 
void StrCopy(PStr S,PStr T);//��T�����ڣ��ɴ�T���Ƶ���S 
int GetLength(PStr S);//��ȡ���ĳ��� 
int StrCompare(PStr S,PStr T);//���Ƚϣ���S>T�򷵻�1����S=T�򷵻�0����S<T�򷵻�-1 
bool SubString(PStr S,PStr Sub,int pos,int len);//��sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���ַ���(pos��1��ʼ)
int Index(PStr S,PStr T,int pos);//����S�д��ںʹ�Tֵ��ͬ���Ӵ����򷵻����ڴ�S�еĵ�pos��λ���ַ�����ֵĵ�һ��λ�ã����򷵻�0
bool StringEmpty(PStr S);//�жϴ��Ƿ�Ϊ�� 
bool StrInsert(PStr S,int pos,PStr T);//�ڴ�S�ĵ�pos��λ�ò��봮T
bool StrDelete(PStr S,PStr Sub,int pos,int len);//�ڴ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�������ɾ���Ӵ����浽Sub��
bool Replace(PStr S,PStr T,PStr V,int pos);//��V�滻��S�д�posλ�ÿ�ʼ�ĵ�һ��T
bool ReplaceAll(PStr S,PStr T,PStr V);//�ڴ�S���ҵ���T���ô�V�滻 
/*
1.��S1->length+S2->length<=MAXSIZEʱ����S2ƴ����S1����
2.��S1->length+S2->length>MAXSIZE,����S1->lengthʱ,����S1���Ӻ�S2����MAXSIZE�Ĳ��ֱ��ض� 
3.��S1->length=MAXSIZE,S2��ȫ���ضϣ�����Ҫƴ�� 
*/
bool Concat(PStr S,PStr S1,PStr S2);//�ַ���ƴ�� 

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
	
	
/*	printf("���滻�Ĵ�Ϊ:%s\n",t);
	ReplaceAll(&s,&t,&sub);
	
	Show(&s);
	
/*	//StrInsert(&s,2,&t);
	
	StrDelete(&s,&sub,3,4);
	printf("ɾ�����Ӵ�Ϊ:%s\n",sub);
	
	//SubString(&s,&sub,3,4);
	//printf("�ضϵ��ַ���Ϊ:%s\n",sub);
	
		
	Show(&sub);
	
	Show(&s);
	int length=GetLength(&s);
	printf("���ĳ���Ϊ:%d\n",length);
	
	int index=Index(&s,&t,1);
	printf("λ��Ϊ:%d\n",index);
	
		
	Show(&t);
	
	int comp=StrCompare(&s,&t);
	printf("�ȽϽ��Ϊ:%d\n",comp);
	
	
	StrAssign(&t,s2);
	StrCopy(&s,&t);
*/

	return 0;
}
 
void StrAssign(PStr S,const char *chars)
{
	assert(S!=NULL);//assert���ԭ�Ͷ�����<assert.h>�У�����������������������ش�������ֹ����ִ��
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
	while(i<S->length&&j<T->length)//������<=��Ȼ���Ϊ0 
	{
		if(S->elem[i]==T->elem[j])
		{
			++i;
			++j;//�����ȽϺ������ַ� 			
		} 
		else
		{
			i=i-j+1;//�ȼ���i=i+1 
			j=0;//ָ����ˣ����¿�ʼƥ��
		}
	}
	if(j>=T->length)
		return i-T->length;//�ȼ���i-j 
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
	
	//��һ����Sub�����汻ɾ�����Ӵ���Ȼ�����SubString����(ע����һ��Ҫ��д��ǰ�棬��Ϊ���ȱ���ֵ��ɾ��)
	for(j=0;j<Sub->length;j++) 
	{
		Sub->elem[j]=S->elem[pos-1+j];
	}
	SubString(S,Sub,pos,len);//���÷�����ȡ�ַ��� 
	
	//�������Ԫ����ǰ�� 
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


