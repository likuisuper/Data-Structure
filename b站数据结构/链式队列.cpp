#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
	int data;//������
	struct Node *pNext;//ָ����
}NODE,*PNODE;

typedef struct Queue
{
	PNODE front;//��ͷָ��
	PNODE rear;//��βָ��
}QUEUE,*PQUEUE;

void init_queue(PQUEUE);//��ʼ��������
bool empty_queue(PQUEUE);
void en_queue(PQUEUE,int);//���
bool out_queue(PQUEUE,int *);//����
void traverse(PQUEUE);//����
int length_queue(PQUEUE);//�󳤶�
void destory_queue(PQUEUE);//���ٶ���
void clear(PQUEUE);//��ն���

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
		printf("��ջ�ɹ�����ջԪ��Ϊ%d\n",val);
	else
		printf("��ջʧ�ܣ�\n");
		
	traverse(&Q);
		
	int length=length_queue(&Q);
	printf("���г���Ϊ:%d\n",length);	
	
	return 0;
}

void init_queue(PQUEUE pQ)
{
	pQ->front=(PNODE)malloc(sizeof(NODE));
	if(NULL==pQ->front)
	{
		printf("��̬�ڴ����ʧ�ܣ�\n");
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
	PNODE pNew=(PNODE)malloc(sizeof(NODE));//�����½��
	if(NULL==pNew)
	{
		printf("��̬�ڴ����ʧ��!\n");
		exit(-1);
	}
	pNew->data=val;//��val���뵽�½�����������
	pNew->pNext=NULL;//�½���ָ����Ϊ��
	pQ->rear->pNext=pNew;//���½�㸳ֵ��βָ��ĺ��
	pQ->rear=pNew;//�ѵ�ǰ���½������Ϊ��β���
}

bool out_queue(PQUEUE pQ,int *val)
{
	PNODE P;
	if(empty_queue(pQ))
		return false;
	else
	{
		P=pQ->front->pNext;//����ɾ���Ľ�㸳ֵ��P(˳����д������Ϊֻ������P,��û��ʼ��P)
		*val=P->data;//����ɾ������ֵ����
		pQ->front->pNext=P->pNext;//����ɾ�����ĺ�̸�ֵ��ͷ�����
		if(pQ->rear==P)
			pQ->rear=pQ->front;//����ͷ�Ƕ�β����ɾ����rearָ��ͷ���
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

