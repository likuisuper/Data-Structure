#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct BTNode
{
	char data;//������
	struct BTNode *plchild;//��ָ����
	struct BTNode *prchild;//��ָ���� 	
}BiTNode,*BiTree;


typedef struct Node
{
	BiTree data;
	struct Node *pNext;
}NODE,*PNODE;

/*---------------------ջ�ṹ-----------------------------*/ 

typedef struct Stack
{
	PNODE pTop;//ָ��ջ��
	PNODE pBottom;//ָ��ջ��
}STACK,*PSTACK;
/*-------------------------------------------------------*/

/*---------------------���нṹ--------------------------*/

typedef struct Queue *PQUEUE;
struct Queue
{
	PNODE front;
	PNODE rear;
};
/*--------------------------------------------------------*/

void CreateBTree(BiTree *);//��̬����������
void PreTraverse(BiTree); 
void InTraverse(BiTree);
void PostTraverse(BiTree); 
int Depth(BiTree); //��������� 
void init(PSTACK); 
void push(Stack,BiTree);
BiTree pop(Stack);
void PreTraverse1(BiTree);//����ǵݹ� 
void InTraverse1(BiTree);//����ǵݹ� 
void PostTraverse1(BiTree);//����ǵݹ�
void init_queue(PQUEUE);
bool isEmpty(PQUEUE); 
void en_queue(PQUEUE,BiTree);
BiTree out_queue(PQUEUE);
void LevelTraverse(BiTree);//��α��� 

int main()
{
	BiTree pT;
	printf("������Ҫ���ɵĽڵ�\n"); 
	CreateBTree(&pT);//�����������AB##CD##EF##G## 
	
	//PreTraverse1(pT);//�������ΪABCDEFG 
	
	//InTraverse1(pT);
	
	PostTraverse1(pT);
	
	//LevelTraverse(pT);
	
	int h=Depth(pT);
	printf("�������Ϊ%d",h);
	
	return 0;
}

/*
1.�β��Ǹ�ָ��ṹ�������ָ���ָ��
2.�������������˳��������������(�������򴴽��Ļ�Ҫ�ı�������ַ�˳���Լ�������˳��)
3.����������������������Ǻ����޷�Ψһ��ȷ��һ�������������Խ�ÿһ���ڵ�
�Ŀ�ָ���趨Ϊһ������ֵ#����Щ����ֵҲҪ�������룬���ִ����Ķ�����Ϊԭ��������
��չ������ 
*/ 
void CreateBTree(BiTree *pT)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
		*pT=NULL;
	else
	{
		*pT=(BiTree)malloc(sizeof(BiTNode));
		if(!(*pT))//������ʧ�� 
			exit(-1);
		(*pT)->data=ch;//���ɸ��ڵ�
		CreateBTree(&((*pT)->plchild));//�ݹ鴴��������
		CreateBTree(&((*pT)->prchild));//�ݹ鴴��������		
	}
}

/*
��ʹ��ָ���ʾ����ʹ�õ�ַ��ʾҲ��һ���� 
void CreateBTree(BiTree &pT)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
		pT=NULL;
	else
	{
		pT=(BiTNode)malloc(sizeof(BiTNode));
		if(!(pT))//������ʧ�� 
			exit(-1);
		(pT)->data=ch;//���ɸ��ڵ�
		CreateBTree(pT->plchild);//�ݹ鴴��������
		CreateBTree(pT->prchild);//�ݹ鴴��������		
	}
}
*/

/*----------------------------ջ�Ĳ���---------------------------*/ 
void init(PSTACK pS)
{
	pS->pTop=(PNODE)malloc(sizeof(NODE));
	if(NULL==pS->pTop)
	{
		printf("��̬�ڴ����ʧ��!\n");
		exit(-1);
	}
	else
	{
		pS->pBottom=pS->pTop;//˳���ܷ�����,��Ϊ����ֻ֪��pS->pTop��ֵ��Ȼ���������pS->pBottom
		pS->pTop->pNext=NULL;
	}
}

void push(PSTACK pS,BiTree val)
{
	PNODE pNew=(PNODE)malloc(sizeof(Node));
	if(NULL==pNew)
	{
		printf("��̬�ڴ����ʧ��!\n");
		exit(-1);
	}
	pNew->data=val;
	pNew->pNext=pS->pTop;
	pS->pTop=pNew;
}

bool empty(PSTACK pS)
{
	if(pS->pTop==pS->pBottom)
		return true;
	else
		return false;
}

BiTree pop(PSTACK pS)
{
	BiTree TopVal;
	if(empty(pS))
		return NULL;
	else
	{
		PNODE q=pS->pTop;
		pS->pTop=q->pNext;
		TopVal=q->data;
		free(q);
		q=NULL;
		return TopVal;
	}	
}
/*----------------------------ջ��������-----------------------------*/

/*----------------------------���в���---------------------------------*/
void init_queue(PQUEUE Q)
{
	Q=(PQUEUE)malloc(sizeof(struct Queue));
	if(NULL==Q)
	{
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);
	}
	Q->front=NULL;
	Q->rear=NULL;
}

bool isEmpty(PQUEUE Q)
{
	if(Q->front==NULL)
		return true;
	else
		return false;
}

//��� 
void en_queue(PQUEUE Q,BiTree val)
{
	PNODE P=(PNODE)malloc(sizeof(NODE));
	if(P==NULL)
	{
		printf("��̬�����ڴ�ʧ��");
		exit(-1);
	}
	P->data=val;
	P->pNext=NULL;
	if(Q->rear==NULL)//��ʱ����Ϊ��
	{
		Q->rear=P;
		Q->front=P;
	}
	else
	{
		Q->rear->pNext=P;
		Q->rear=P;	
	} 
}

//����
BiTree out_queue(PQUEUE Q)
{
	PNODE P;
	BiTree val;
	if(isEmpty(Q))
		return NULL;
	P=Q->front;
	if(Q->front==Q->rear)//��ʱ������ֻ��һ��Ԫ��
		Q->front=Q->rear=NULL;
	else
		Q->front=Q->front->pNext;
	val=P->data;
	free(P);
	return val; 
} 

/*----------------------------���в�������-----------------------------*/ 

//������ʵݹ�ʵ�� 
void PreTraverse(BiTree pT)
{
	/*
	�ȷ��ʸ��ڵ㣬�������������������������������� 
	*/ 
	if(pT==NULL)
		return;
	printf("%c\n",pT->data);
	PreTraverse(pT->plchild);//�ݹ� 
	PreTraverse(pT->prchild);
}

//������ʷǵݹ�ʵ��
void PreTraverse1(BiTree pT)
{
	BiTree T=pT;
	PSTACK S;
	init(S);
	if(T==NULL)
		return;
	push(S,T);//�����ڵ�ѹ��ջ��
	while(!empty(S))
	{
		T=pop(S);
		printf("%c\n",T->data);
		//�����ĺ��Ӳ�Ϊ��ʱ��һ������ѹ���Һ��ӣ���ѹ������ 
		if(T->prchild!=NULL)
			push(S,T->prchild);
		if(T->plchild!=NULL)
			push(S,T->plchild);
	 } 
} 

//������ʵݹ�ʵ�� 
void InTraverse(BiTree pT)
{
	/*
	������������������ٷ��ʸ��ڵ㣬��������������� 
	*/
	if(pT==NULL)
		return;
	InTraverse(pT->plchild);
	printf("%c\n",pT->data);
	InTraverse(pT->prchild);
}

//������ʷǵݹ�ʵ��
void InTraverse1(BiTree pT)
{
	BiTree T=pT;
	PSTACK S;
	init(S);
	while(T||!empty(S))
	{
		while(T)
		{
			push(S,T);//�����ڵ��ѹջ
			T=T->plchild;//���������� 
		}
		if(!empty(S))//����ջ���� 
		{
			T=pop(S);//��ջ 
			printf("%c\n",T->data);//���ʽڵ� 
			T=T->prchild;//���������� 
		}
	}	
} 

//������ʵݹ�ʵ�� 
void PostTraverse(BiTree pT)
{
	/*
	�����������������������������������ٷ��ʸ��ڵ� 
	*/
	if(pT==NULL)
		return;
	PostTraverse(pT->plchild);
	PostTraverse(pT->prchild);
	printf("%c\n",pT->data); 
}

//������ʷǵݹ�ʵ�� 
void PostTraverse1(BiTree pT)
{
	BiTree T=pT;
	PSTACK S;
	init(S);
	BiTree R=NULL;//ָ��������ʹ��Ľڵ� 
	while(T||!empty(S))
	{
		while(T)//�ߵ������ 
		{
			push(S,T);
			T=T->plchild;
		}
		T=S->pTop->data;//��ȡջ��Ԫ��
		if(T->prchild&&T->prchild!=R)//���������ڣ���δ�����ʹ�
		{
			T=T->prchild;//���������� 
			push(S,T);//ѹջ 
			T=T->plchild;//�ٱ���������
		}
		else
		{
			T=pop(S);//�����ڵ�
			printf("%c\n",T->data);//����
			R=T;//��¼������ʹ��Ľڵ�
			T=NULL;//�ڵ�����������ָ�� 
		}	
	}
}

//��α���
void LevelTraverse(BiTree pT)
{
	BiTree T=pT;
	if(!T)
		return;//���ǿ���ֱ�ӷ��� 
	PQUEUE Q;
	init_queue(Q);
	en_queue(Q,T);//�����ڵ���� 
	while(!isEmpty(Q))//���в���ѭ�� 
	{
		T=out_queue(Q);//��ͷ�ڵ���� 
		printf("%c\n",T->data);//���ʳ��ӽڵ� 
		if(T->plchild)
			en_queue(Q,T->plchild);//���������ڣ������������ڵ���� 
		if(T->prchild)
			en_queue(Q,T->prchild);//���������ڣ������������ڵ���� 
	}
} 


int Depth(BiTree pT)
{
	int d,dl,dr;
	if(!pT)
		return 0;
	else
	{
		dl=Depth(pT->plchild);
		dr=Depth(pT->prchild);
		d=1+(dl>dr?dl:dr);//��ʱ�����ڣ���һ���и������Լ�1��������ȼ�Ϊ�������������������ĸ߶�
		return d; 
	}
}
        

