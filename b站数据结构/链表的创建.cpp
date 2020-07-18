#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node
{
	int data;//������
	struct Node *pNext;//ָ���� 
}NODE,*PNODE;//Node�ȼ���struct Node,PNODE�ȼ���struct Node * 

//�������� 
PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead); 
int length_list(PNODE pHead);
void reverse_list(PNODE pHead);//���������� 
PNODE find_list(PNODE pHead,int val);//���� 
bool insert_list(PNODE pHead,int pos,int val);
bool delete_list(PNODE pHead,int pos,int *val);
void sort_list(PNODE pHead);

int main(void)
{
	PNODE pHead=NULL;
	int val;
	pHead=create_list(); 
	traverse_list(pHead);
	
	find_list(pHead,3);
	
/*	reverse_list(pHead);
	traverse_list(pHead);

		
	if(delete_list(pHead,3,&val))
	{
		printf("ɾ���ɹ�����ɾ����Ԫ����%d\n",val);
	}
	else
	{
		printf("ɾ��ʧ�ܣ���ɾ����Ԫ�ز�����");
	}
	traverse_list(pHead);
	
/*	int len=length_list(pHead);
	printf("����ĳ���Ϊ%d\n",len);
	
	printf("����֮��Ϊ:\n");
	sort_list(pHead);
	traverse_list(pHead);
		
	insert_list(pHead,-2,20);
	traverse_list(pHead);
	
/*	if(is_empty(pHead))
		printf("����Ϊ�գ�\n");
	else
		printf("����Ϊ�գ�\n");
*/	
	
	return 0;
}

PNODE create_list(void)
{
	int len;//���������Ч�ڵ�ĸ��� 
	int i;
	int val;//������ʱ����û�����Ľ���ֵ 
	
	//������һ���������Ч���ݵ�ͷ�ڵ�
	PNODE pHead=(PNODE)malloc(sizeof(NODE));
	if(NULL==pHead)
	{
		printf("����ʧ�ܣ�������ֹ��\n");
		exit(-1);
	} 
	PNODE pTail=pHead;
	pTail->pNext=NULL; 
	
	printf("����������Ҫ���ɵ�����ڵ�ĸ�����len= ");
	scanf("%d",&len);
	
	for(i=0;i<len;++i)
	{
		printf("�������%d���ڵ��ֵ��",i+1);
		scanf("%d",&val);
		
		PNODE pNew=(PNODE)malloc(sizeof(NODE));
		if(NULL==pNew)
		{
			printf("����ʧ�ܣ�������ֹ��\n");
			exit(-1);
		}
		pNew->data=val;
		pTail->pNext=pNew;
		pNew->pNext=NULL;
		pTail=pNew;		
	}
	return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p=pHead->pNext;
	
	while(NULL!=p)
	{
		printf("%d ",p->data);
		p=p->pNext;
	}
	printf("\n");
	
	return;
}

bool is_empty(PNODE pHead)
{
	if(NULL==pHead->pNext)
		return true;
	else
		return false;
}

int length_list(PNODE pHead)
{
	PNODE p=pHead->pNext;
	int len=0;
	while(NULL!=p)
	{
		++len;
		p=p->pNext;
	}
	return len;
}

void sort_list(PNODE pHead)
{
	int i,j,t;
	int len=length_list(pHead);
	PNODE p,q;
	for(i=0,p=pHead->pNext;i<len-1;++i,p=p->pNext)
	{
		for(j=i+1,q=p->pNext;j<len;++j,q=q->pNext)
		{
			if(p->data>q->data) //������a[i]>a[j]
			{
				t=p->data;//�����������е�t=a[i] 
				p->data=q->data;//�����������е�a[i]=a[j] 
				q->data=t;//�����������е�a[j]=t 
			}
		}
	}
	
	return;
}

void reverse_list(PNODE pHead)
{
	PNODE pPre=NULL;
	PNODE pCur=NULL;
	PNODE pTmp=NULL;
	
	if(NULL==pHead||NULL==pHead->pNext||NULL==pHead->pNext)
		return;
	pPre=pHead->pNext;
	pCur=pHead->pNext->pNext;
	while(pCur)
	{
		pTmp=pCur->pNext;
		pCur->pNext=pPre;
		pPre=pCur;
		pCur=pTmp;
	}
	pHead->pNext->pNext=NULL;
	pHead->pNext=pPre;
	
}

PNODE find_list(PNODE pHead,int val)
{
	PNODE pTmp;//����һ����������ָ��
	if(NULL==pHead||NULL==pHead->pNext)
	{
		printf("����Ϊ��\n");
		return NULL;
	}
	pTmp=pHead;
	while(pTmp->pNext)//�������� 
	{
		printf("%d\n",pTmp->pNext->data);
		if(pTmp->pNext->data==val)//�ж�ֵ�Ƿ���� 
		{
			pTmp=pTmp->pNext;//�ҵ�Ŀ���� 
			return pTmp;//����Ŀ����
		}		
		pTmp=pTmp->pNext;//�������²���	
	}	
	return NULL;//����ʧ�� 
}

bool insert_list(PNODE pHead,int pos,int val) //pHead��ָ������ĵ�pos���ڵ��ǰ�����һ���µĽڵ㣬�ýڵ��ֵ��pos,��1��ʼ 
{
	int i=0;
	PNODE p=pHead;
	
	while(NULL!=p&&i<pos-1)
	{
		p=p->pNext;//�൱��++p 
		++i;
	}
	
	if(NULL==p||i>pos-1)
		return false;
	
	PNODE pNew=(PNODE)malloc(sizeof(NODE));
	if(NULL==pNew)
	{
		printf("��̬�����ڴ�ʧ�ܣ�\n");
		exit(-1);
	}
	pNew->data=val;
	PNODE q=p->pNext;
	pNew->pNext=q;
	p->pNext=pNew;
	
	return true;
}

bool delete_list(PNODE pHead,int pos,int *val)
{
	int i=0;
	PNODE p=pHead;
	
	while(NULL!=p&&i<pos-1)
	{
		p=p->pNext;
		++i;
	}
	
	if(NULL==p||i>pos-1)
		return false;
	PNODE q=p->pNext;
	//ɾ��֮ǰ�Ȱ������浽*val��ָ������������val������ȥ 
	*val=q->data;
	
	//ɾ��p������Ľ�� 
	p->pNext=p->pNext->pNext;
	free(q);//����q���
	q=NULL;
	return true; 
	
}
