#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100//�洢�ռ��ʼ��������
#define STACKINCREMENT 10//�洢�ռ�������� 

typedef struct Stack
{
	int *pBase;
	int *top;
	int stacksize;//��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ 
}STACK;

void init_stack(STACK *);//��ʼ��һ����ջ 
void push_stack(STACK *,int);//ѹջ 
bool traverse_stack(STACK *);//���� 
bool pop_stack(STACK *,int *);//��ջ 
bool GetTop(STACK *,int *);//��ȡջ��Ԫ�� 

int main(void)
{
	STACK S;
	int val;
	
	init_stack(&S);

	push_stack(&S,8);
	push_stack(&S,1);
	push_stack(&S,2);
	push_stack(&S,3);
	push_stack(&S,4);
	push_stack(&S,5);
	push_stack(&S,6);
	
	traverse_stack(&S);
	
/*	GetTop(&S,&val);
	printf("ջ��Ԫ��Ϊ:%d\n",val);
*/
	if(pop_stack(&S,&val))
		printf("��ջ�ɹ�����ջԪ����:%d\n",val);
	else
		printf("��ջʧ��");
		
	traverse_stack(&S);
	
	return 0;
}

void init_stack(STACK *pS)
{
	pS->pBase=(int *)malloc(sizeof(int) * STACK_INIT_SIZE);
	if(!pS->pBase)
	{
		printf("��̬�����ڴ�ʧ��\n");
		exit(-1);
	} 
	else
	{
		pS->top=pS->pBase;
		pS->stacksize=STACK_INIT_SIZE;
		return;
	}
	
}

void push_stack(STACK *pS,int val)
{
	if(pS->top-pS->pBase>=pS->stacksize)
	{
		//ջ����׷�Ӵ洢�ռ�
		pS->pBase=(int *)realloc(pS->pBase,sizeof(int) * (pS->stacksize+STACKINCREMENT));
		if(!pS->pBase)
		{
			printf("�洢����ʧ��\n");
			exit(-1);
		}
		else
		{
			pS->top=pS->pBase+pS->stacksize;
			pS->stacksize+=STACKINCREMENT;
		}
	}
	*(pS->top)=val;//��val����topָ���λ�� 
	pS->top++;//topָ�����
	return;
} 

bool traverse_stack(STACK *pS)
{
	if(pS->top==pS->pBase)
		return false;
	else
	{
		while(pS->pBase!=pS->top)
		{
			printf("%d\n",*(pS->pBase));
			pS->pBase++;
		}
		printf("\n");
		return true;		
	}
}

bool GetTop(STACK *pS,int *val)
{
	if(pS->top==pS->pBase)
	{
		return false;
	}		
	else
	{
		*val=*(pS->top-1);
		return true;		
	}
	
}

bool pop_stack(STACK *pS,int *val)
{
	if(pS->top==pS->pBase)
		return false;
	else
	{
		*val=*--(pS->top);
		return true;
	}
}
