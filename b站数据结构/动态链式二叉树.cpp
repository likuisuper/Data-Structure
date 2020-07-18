#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct BTNode
{
	char data;//数据域
	struct BTNode *plchild;//左指针域
	struct BTNode *prchild;//右指针域 	
}BiTNode,*BiTree;


typedef struct Node
{
	BiTree data;
	struct Node *pNext;
}NODE,*PNODE;

/*---------------------栈结构-----------------------------*/ 

typedef struct Stack
{
	PNODE pTop;//指向栈顶
	PNODE pBottom;//指向栈底
}STACK,*PSTACK;
/*-------------------------------------------------------*/

/*---------------------队列结构--------------------------*/

typedef struct Queue *PQUEUE;
struct Queue
{
	PNODE front;
	PNODE rear;
};
/*--------------------------------------------------------*/

void CreateBTree(BiTree *);//动态创建二叉树
void PreTraverse(BiTree); 
void InTraverse(BiTree);
void PostTraverse(BiTree); 
int Depth(BiTree); //求树的深度 
void init(PSTACK); 
void push(Stack,BiTree);
BiTree pop(Stack);
void PreTraverse1(BiTree);//先序非递归 
void InTraverse1(BiTree);//中序非递归 
void PostTraverse1(BiTree);//后序非递归
void init_queue(PQUEUE);
bool isEmpty(PQUEUE); 
void en_queue(PQUEUE,BiTree);
BiTree out_queue(PQUEUE);
void LevelTraverse(BiTree);//层次遍历 

int main()
{
	BiTree pT;
	printf("请输入要生成的节点\n"); 
	CreateBTree(&pT);//假设输入的是AB##CD##EF##G## 
	
	//PreTraverse1(pT);//遍历结果为ABCDEFG 
	
	//InTraverse1(pT);
	
	PostTraverse1(pT);
	
	//LevelTraverse(pT);
	
	int h=Depth(pT);
	printf("树的深度为%d",h);
	
	return 0;
}

/*
1.形参是个指向结构体变量的指针的指针
2.这里是以先序的顺序来创建二叉树(中序或后序创建的话要改变输入的字符顺序以及创建的顺序)
3.无论是以先序还是中序或者是后序都无法唯一的确定一个二叉树，所以将每一个节点
的空指针设定为一个虚拟值#，这些虚拟值也要进行输入，这种处理后的二叉树为原二叉树的
扩展二叉树 
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
		if(!(*pT))//若分配失败 
			exit(-1);
		(*pT)->data=ch;//生成根节点
		CreateBTree(&((*pT)->plchild));//递归创建左子树
		CreateBTree(&((*pT)->prchild));//递归创建右子树		
	}
}

/*
不使用指针表示，而使用地址表示也是一样的 
void CreateBTree(BiTree &pT)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
		pT=NULL;
	else
	{
		pT=(BiTNode)malloc(sizeof(BiTNode));
		if(!(pT))//若分配失败 
			exit(-1);
		(pT)->data=ch;//生成根节点
		CreateBTree(pT->plchild);//递归创建左子树
		CreateBTree(pT->prchild);//递归创建右子树		
	}
}
*/

/*----------------------------栈的操作---------------------------*/ 
void init(PSTACK pS)
{
	pS->pTop=(PNODE)malloc(sizeof(NODE));
	if(NULL==pS->pTop)
	{
		printf("动态内存分配失败!\n");
		exit(-1);
	}
	else
	{
		pS->pBottom=pS->pTop;//顺序不能反过来,因为这里只知道pS->pTop的值，然后把他赋给pS->pBottom
		pS->pTop->pNext=NULL;
	}
}

void push(PSTACK pS,BiTree val)
{
	PNODE pNew=(PNODE)malloc(sizeof(Node));
	if(NULL==pNew)
	{
		printf("动态内存分配失败!\n");
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
/*----------------------------栈操作结束-----------------------------*/

/*----------------------------队列操作---------------------------------*/
void init_queue(PQUEUE Q)
{
	Q=(PQUEUE)malloc(sizeof(struct Queue));
	if(NULL==Q)
	{
		printf("动态内存分配失败！\n");
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

//入队 
void en_queue(PQUEUE Q,BiTree val)
{
	PNODE P=(PNODE)malloc(sizeof(NODE));
	if(P==NULL)
	{
		printf("动态分配内存失败");
		exit(-1);
	}
	P->data=val;
	P->pNext=NULL;
	if(Q->rear==NULL)//此时队列为空
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

//出队
BiTree out_queue(PQUEUE Q)
{
	PNODE P;
	BiTree val;
	if(isEmpty(Q))
		return NULL;
	P=Q->front;
	if(Q->front==Q->rear)//此时队列中只有一个元素
		Q->front=Q->rear=NULL;
	else
		Q->front=Q->front->pNext;
	val=P->data;
	free(P);
	return val; 
} 

/*----------------------------队列操作结束-----------------------------*/ 

//先序访问递归实现 
void PreTraverse(BiTree pT)
{
	/*
	先访问根节点，再先序访问左子树，再先序访问右子树 
	*/ 
	if(pT==NULL)
		return;
	printf("%c\n",pT->data);
	PreTraverse(pT->plchild);//递归 
	PreTraverse(pT->prchild);
}

//先序访问非递归实现
void PreTraverse1(BiTree pT)
{
	BiTree T=pT;
	PSTACK S;
	init(S);
	if(T==NULL)
		return;
	push(S,T);//将根节点压入栈中
	while(!empty(S))
	{
		T=pop(S);
		printf("%c\n",T->data);
		//当它的孩子不为空时，一定是先压入右孩子，再压入左孩子 
		if(T->prchild!=NULL)
			push(S,T->prchild);
		if(T->plchild!=NULL)
			push(S,T->plchild);
	 } 
} 

//中序访问递归实现 
void InTraverse(BiTree pT)
{
	/*
	先先序访问左子树，再访问根节点，再先序访问右子树 
	*/
	if(pT==NULL)
		return;
	InTraverse(pT->plchild);
	printf("%c\n",pT->data);
	InTraverse(pT->prchild);
}

//中序访问非递归实现
void InTraverse1(BiTree pT)
{
	BiTree T=pT;
	PSTACK S;
	init(S);
	while(T||!empty(S))
	{
		while(T)
		{
			push(S,T);//遇到节点就压栈
			T=T->plchild;//遍历左子树 
		}
		if(!empty(S))//当堆栈不空 
		{
			T=pop(S);//出栈 
			printf("%c\n",T->data);//访问节点 
			T=T->prchild;//访问右子树 
		}
	}	
} 

//后序访问递归实现 
void PostTraverse(BiTree pT)
{
	/*
	先先序访问左子树，再先序访问右子树，再访问根节点 
	*/
	if(pT==NULL)
		return;
	PostTraverse(pT->plchild);
	PostTraverse(pT->prchild);
	printf("%c\n",pT->data); 
}

//后序访问非递归实现 
void PostTraverse1(BiTree pT)
{
	BiTree T=pT;
	PSTACK S;
	init(S);
	BiTree R=NULL;//指向最近访问过的节点 
	while(T||!empty(S))
	{
		while(T)//走到最左边 
		{
			push(S,T);
			T=T->plchild;
		}
		T=S->pTop->data;//获取栈顶元素
		if(T->prchild&&T->prchild!=R)//右子树存在，且未被访问过
		{
			T=T->prchild;//遍历右子树 
			push(S,T);//压栈 
			T=T->plchild;//再遍历左子树
		}
		else
		{
			T=pop(S);//弹出节点
			printf("%c\n",T->data);//访问
			R=T;//记录最近访问过的节点
			T=NULL;//节点访问完后，重置指针 
		}	
	}
}

//层次遍历
void LevelTraverse(BiTree pT)
{
	BiTree T=pT;
	if(!T)
		return;//若是空树直接返回 
	PQUEUE Q;
	init_queue(Q);
	en_queue(Q,T);//将根节点入队 
	while(!isEmpty(Q))//队列不空循环 
	{
		T=out_queue(Q);//对头节点出队 
		printf("%c\n",T->data);//访问出队节点 
		if(T->plchild)
			en_queue(Q,T->plchild);//左子树存在，则左子树根节点入队 
		if(T->prchild)
			en_queue(Q,T->prchild);//右子树存在，则右子树根节点入队 
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
		d=1+(dl>dr?dl:dr);//此时树存在，则一定有根，所以加1，树的深度即为左子树或右子树中最大的高度
		return d; 
	}
}
        

