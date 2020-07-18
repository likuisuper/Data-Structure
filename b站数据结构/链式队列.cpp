#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
	int data;//数据域
	struct Node *pNext;//指针域
}NODE,*PNODE;

typedef struct Queue
{
	PNODE front;//队头指针
	PNODE rear;//队尾指针
}QUEUE,*PQUEUE;

void init_queue(PQUEUE);//初始化链队列
bool empty_queue(PQUEUE);
void en_queue(PQUEUE,int);//入队
bool out_queue(PQUEUE,int *);//出队
void traverse(PQUEUE);//遍历
int length_queue(PQUEUE);//求长度
void destory_queue(PQUEUE);//销毁队列
void clear(PQUEUE);//清空队列

int main(void)
{
	QUEUE Q;
	int val;
	init_queue(&Q);

	en_queue(&Q,1);
	en_queue(&Q,2);
	en_queue(&Q,3);
	en_queue(&Q,4);
	en_queue(&Q,5);
	en_queue(&Q,6);

	traverse(&Q);
	

	
	if(out_queue(&Q,&val))
		printf("出栈成功，出栈元素为%d\n",val);
	else
		printf("出栈失败！\n");
		
	traverse(&Q);
		
	int length=length_queue(&Q);
	printf("队列长度为:%d\n",length);	
	
	return 0;
}

void init_queue(PQUEUE pQ)
{
	pQ->front=(PNODE)malloc(sizeof(NODE));
	if(NULL==pQ->front)
	{
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	else
	{
		pQ->rear=pQ->front;
		pQ->front->pNext=NULL;		
	}

}

void traverse(PQUEUE pQ)
{
	PNODE p=pQ->front;
	while(p)
	{
		printf("%d\n",p->data);
		p=p->pNext;
	}
	return;
}

bool empty_queue(PQUEUE pQ)
{
	if(pQ->front==pQ->rear)
		return true;
	else
		return false;
}

void en_queue(PQUEUE pQ,int val)
{
	PNODE pNew=(PNODE)malloc(sizeof(NODE));//生成新结点
	if(NULL==pNew)
	{
		printf("动态内存分配失败!\n");
		exit(-1);
	}
	pNew->data=val;//将val插入到新结点的数据域中
	pNew->pNext=NULL;//新结点的指针域为空
	pQ->rear->pNext=pNew;//将新结点赋值给尾指针的后继
	pQ->rear=pNew;//把当前的新结点设置为队尾结点
}

bool out_queue(PQUEUE pQ,int *val)
{
	PNODE P;
	if(empty_queue(pQ))
		return false;
	else
	{
		P=pQ->front->pNext;//将欲删除的结点赋值给P(顺序不能写反，因为只声明了P,还没初始化P)
		*val=P->data;//将欲删除结点的值保存
		pQ->front->pNext=P->pNext;//将欲删除结点的后继赋值给头结点后继
		if(pQ->rear==P)
			pQ->rear=pQ->front;//若对头是队尾，则删除后将rear指向头结点
		free(P);
		P=NULL;
		return true;
	}
}

int length_queue(PQUEUE pQ)
{
	int count=0;
	while(pQ->front!=pQ->rear)
	{
		count++;
		pQ->front=pQ->front->pNext;
	}
	return count; 	
}

void destory_queue(PQUEUE pQ)
{
	while(pQ->front)
	{
		pQ->rear=pQ->front->pNext;
		free(pQ->front);
		pQ->front=pQ->rear;
	}
}

void clear(PQUEUE pQ)
{
	if(empty_queue(pQ))
		return;
	else
	{
		PNODE p=pQ->front;
		PNODE q=NULL;
		while(p!=pQ->rear)
		{
			q=p->pNext;
			free(p);
			p=q;
		}
		pQ->front=pQ->rear;
	}
}

