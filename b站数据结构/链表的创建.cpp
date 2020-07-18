#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node
{
	int data;//数据域
	struct Node *pNext;//指针域 
}NODE,*PNODE;//Node等价于struct Node,PNODE等价于struct Node * 

//函数声明 
PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead); 
int length_list(PNODE pHead);
void reverse_list(PNODE pHead);//单链表逆序 
PNODE find_list(PNODE pHead,int val);//查找 
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
		printf("删除成功！您删除的元素是%d\n",val);
	}
	else
	{
		printf("删除失败！您删除的元素不存在");
	}
	traverse_list(pHead);
	
/*	int len=length_list(pHead);
	printf("链表的长度为%d\n",len);
	
	printf("排序之后为:\n");
	sort_list(pHead);
	traverse_list(pHead);
		
	insert_list(pHead,-2,20);
	traverse_list(pHead);
	
/*	if(is_empty(pHead))
		printf("链表为空！\n");
	else
		printf("链表不为空！\n");
*/	
	
	return 0;
}

PNODE create_list(void)
{
	int len;//用来存放有效节点的个数 
	int i;
	int val;//用来临时存放用户输入的结点的值 
	
	//分配了一个不存放有效数据的头节点
	PNODE pHead=(PNODE)malloc(sizeof(NODE));
	if(NULL==pHead)
	{
		printf("分配失败，程序终止！\n");
		exit(-1);
	} 
	PNODE pTail=pHead;
	pTail->pNext=NULL; 
	
	printf("请输入您需要生成的链表节点的个数：len= ");
	scanf("%d",&len);
	
	for(i=0;i<len;++i)
	{
		printf("请输入第%d个节点的值：",i+1);
		scanf("%d",&val);
		
		PNODE pNew=(PNODE)malloc(sizeof(NODE));
		if(NULL==pNew)
		{
			printf("分配失败，程序终止！\n");
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
			if(p->data>q->data) //类似于a[i]>a[j]
			{
				t=p->data;//类似于数组中的t=a[i] 
				p->data=q->data;//类似于数组中的a[i]=a[j] 
				q->data=t;//类似于数组中的a[j]=t 
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
	PNODE pTmp;//声明一个遍历链表指针
	if(NULL==pHead||NULL==pHead->pNext)
	{
		printf("链表为空\n");
		return NULL;
	}
	pTmp=pHead;
	while(pTmp->pNext)//遍历链表 
	{
		printf("%d\n",pTmp->pNext->data);
		if(pTmp->pNext->data==val)//判断值是否相等 
		{
			pTmp=pTmp->pNext;//找到目标结点 
			return pTmp;//返回目标结点
		}		
		pTmp=pTmp->pNext;//继续向下查找	
	}	
	return NULL;//查找失败 
}

bool insert_list(PNODE pHead,int pos,int val) //pHead所指向链表的第pos个节点的前面插入一个新的节点，该节点的值是pos,从1开始 
{
	int i=0;
	PNODE p=pHead;
	
	while(NULL!=p&&i<pos-1)
	{
		p=p->pNext;//相当于++p 
		++i;
	}
	
	if(NULL==p||i>pos-1)
		return false;
	
	PNODE pNew=(PNODE)malloc(sizeof(NODE));
	if(NULL==pNew)
	{
		printf("动态分配内存失败！\n");
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
	//删除之前先把它保存到*val所指向的主函数里的val变量中去 
	*val=q->data;
	
	//删除p结点后面的结点 
	p->pNext=p->pNext->pNext;
	free(q);//回收q结点
	q=NULL;
	return true; 
	
}
