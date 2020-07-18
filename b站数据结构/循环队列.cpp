#include<stdio.h>
#include<malloc.h>

//循环队列是基于数组实现的 
typedef struct Queue
{
	int *pBase;
	int front;
	int rear;
}QUEUE;

void init(QUEUE *);//初始化队列 
bool full_queue(QUEUE *);//判断队列是否满 
bool en_queue(QUEUE *,int);//入队 
void traverse_queue(QUEUE *);//遍历输出 
bool empty_queue(QUEUE *);//判断是否为空
bool out_queue(QUEUE *,int *);//出队 

int main(void)
{
	QUEUE Q;
	int Val;
	
	init(&Q);
	en_queue(&Q,1);
	en_queue(&Q,2);
	en_queue(&Q,3);
	en_queue(&Q,4);
	en_queue(&Q,5);
	en_queue(&Q,6);
	en_queue(&Q,7);
	
	traverse_queue(&Q);
	
	if(out_queue(&Q,&Val))
		printf("出队成功，出队的元素是:%d\n",Val);
	else
		printf("出队失败");
	
	traverse_queue(&Q);	
	
	return 0;
}

void init(QUEUE *pQ)
{
	pQ->pBase=(int*)malloc(sizeof(int) * 6);
	pQ->front=pQ->rear=0;
}

bool full_queue(QUEUE *pQ)
{
	if((pQ->rear+1)%6==pQ->front)
		return true;
	else
		return false;
}

bool en_queue(QUEUE *pQ,int val)
{
	if(full_queue(pQ))
		return false;
	else
	{
		pQ->pBase[pQ->rear]=val;
		pQ->rear=(pQ->rear+1)%6;
		return true;
	}
}

void traverse_queue(QUEUE *pQ)
{
	int i=pQ->front;
	while(i!=pQ->rear)
	{
		printf("%d\t",pQ->pBase[i]);
		i=(i+1)%6;
	}
	return;
}

bool empty_queue(QUEUE *pQ)
{
	if(pQ->front==pQ->rear)
		return true;
	else
		return false;
}

bool out_queue(QUEUE *pQ,int *pVal)
{
	if(empty_queue(pQ))
		return false;
	else
	{
		*pVal=pQ->pBase[pQ->front];
		pQ->front=(pQ->front+1)%6;
		return true;
	}
}
