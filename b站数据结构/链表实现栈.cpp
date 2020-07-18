#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *pNext;
}NODE,*PNODE;

typedef struct Stack
{
	PNODE pTop;//指向顶部 
	PNODE pBottom;//指向底部 
}STACK,*PSTACK;

void init(PSTACK);//初始化一个空栈
void push(PSTACK,int);//压栈(入栈)
bool empty(PSTACK);
void traverse(PSTACK);//遍历 
bool pop(PSTACK,int*);//出栈
void clear(PSTACK);//清空 

int main(void)
{
	STACK S;
	int val;
	
	init(&S);
	push(&S,1);
	push(&S,2);
	push(&S,3);
	push(&S,4);
	push(&S,5);
	push(&S,6);
	traverse(&S);
	
	clear(&S);
	//traverse(&S);
	
	if(pop(&S,&val))
		printf("出栈成功，出栈的元素是:%d\n",val);
	else
		printf("出栈失败");
	traverse(&S);
	return 0;
}

void init(PSTACK pS)
{
	pS->pTop=(PNODE)malloc(sizeof(NODE));
	if(NULL==pS->pTop)
	{
		printf("动态分配内存失败!\n");
		exit(-1);
	}
	else
	{
		pS->pBottom=pS->pTop;
		pS->pTop->pNext=NULL;
	}
}

void push(PSTACK pS,int val)
{
	PNODE pNew=(PNODE)malloc(sizeof(NODE));
	pNew->data=val;
	pNew->pNext=pS->pTop;//ps->pTop不能写成ps->pButtom
	pS->pTop=pNew;
	 
}

bool empty(PSTACK pS)
{
	if(pS->pTop==pS->pBottom)
		return true;
	else
		return false;
}

void traverse(PSTACK pS)
{
	PNODE p=pS->pTop;
	while(p!=pS->pBottom)
	{
		printf("%d\t",p->data);
		p=p->pNext;		
	}
	printf("\n");
	return;
}

bool pop(PSTACK pS,int *val)
{
	if(empty(pS))
		return false;
	else
	{
		PNODE r=pS->pTop;
		*val=r->data;
		pS->pTop=r->pNext;
		free(r);
		r=NULL;
		return true;
	}
} 

void clear(PSTACK pS)
{
	if(empty(pS))
		return;
	else
	{
		PNODE p=pS->pTop;
		PNODE q=NULL;
		while(p!=pS->pBottom)
		{
			q=p->pNext;
			free(p);
			p=q;
		}
		pS->pTop=pS->pBottom;
	}
}
 
