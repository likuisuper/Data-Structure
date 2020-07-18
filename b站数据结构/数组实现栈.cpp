#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100//存储空间初始化分配量
#define STACKINCREMENT 10//存储空间分配增量 

typedef struct Stack
{
	int *pBase;
	int *top;
	int stacksize;//当前已分配的存储空间，以元素为单位 
}STACK;

void init_stack(STACK *);//初始化一个空栈 
void push_stack(STACK *,int);//压栈 
bool traverse_stack(STACK *);//遍历 
bool pop_stack(STACK *,int *);//出栈 
bool GetTop(STACK *,int *);//获取栈顶元素 

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
	printf("栈顶元素为:%d\n",val);
*/
	if(pop_stack(&S,&val))
		printf("出栈成功，出栈元素是:%d\n",val);
	else
		printf("出栈失败");
		
	traverse_stack(&S);
	
	return 0;
}

void init_stack(STACK *pS)
{
	pS->pBase=(int *)malloc(sizeof(int) * STACK_INIT_SIZE);
	if(!pS->pBase)
	{
		printf("动态分配内存失败\n");
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
		//栈满，追加存储空间
		pS->pBase=(int *)realloc(pS->pBase,sizeof(int) * (pS->stacksize+STACKINCREMENT));
		if(!pS->pBase)
		{
			printf("存储分配失败\n");
			exit(-1);
		}
		else
		{
			pS->top=pS->pBase+pS->stacksize;
			pS->stacksize+=STACKINCREMENT;
		}
	}
	*(pS->top)=val;//将val插入top指向的位置 
	pS->top++;//top指针后移
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
