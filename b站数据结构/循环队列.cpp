#include<stdio.h>
#include<malloc.h>

//ѭ�������ǻ�������ʵ�ֵ� 
typedef struct Queue
{
	int *pBase;
	int front;
	int rear;
}QUEUE;

void init(QUEUE *);//��ʼ������ 
bool full_queue(QUEUE *);//�ж϶����Ƿ��� 
bool en_queue(QUEUE *,int);//��� 
void traverse_queue(QUEUE *);//������� 
bool empty_queue(QUEUE *);//�ж��Ƿ�Ϊ��
bool out_queue(QUEUE *,int *);//���� 

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
		printf("���ӳɹ������ӵ�Ԫ����:%d\n",Val);
	else
		printf("����ʧ��");
	
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
