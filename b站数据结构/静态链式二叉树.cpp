#include<stdio.h>
#include<malloc.h>

struct BTNode
{
	char data;//数据域
	struct BTNode *plchild;//左指针域
	struct BTNode *prchild;//右指针域 	
};

struct BTNode *CreateBTree();//静态创建一个二叉树 
void PreTraverse(struct BTNode *pT);//先序遍历 
void InTraverse(struct BTNode *pT);//中序遍历 
void PostTraverse(struct BTNode *pT);//后序遍历 

int main()
{
	struct BTNode *pT=CreateBTree();
	
	//PreTraverse(pT);
	
	//InTraverse(pT);
	
	PostTraverse(pT);
	
	return 0;
}

struct BTNode *CreateBTree()
{
	//假设这五个节点的先序遍历顺序为ABCDE
	struct BTNode *pA=(struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode *pB=(struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode *pC=(struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode *pD=(struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode *pE=(struct BTNode *)malloc(sizeof(struct BTNode));
	
	pA->data='A';
	pB->data='B';
	pC->data='C';
	pD->data='D';
	pE->data='E';
	
	pA->plchild=pB;
	pA->prchild=pC;
	pB->plchild=pB->prchild=NULL;
	pC->plchild=pD;
	pC->prchild=NULL;
	pD->plchild=NULL;
	pD->prchild=pE;
	pE->plchild=pE->prchild=NULL;
	
	return pA;
} 

void PreTraverse(struct BTNode *pT)
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

void InTraverse(struct BTNode *pT)
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

void PostTraverse(struct BTNode *pT)
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
