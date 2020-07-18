#include<stdio.h>
#include<malloc.h>

struct BTNode
{
	char data;//������
	struct BTNode *plchild;//��ָ����
	struct BTNode *prchild;//��ָ���� 	
};

struct BTNode *CreateBTree();//��̬����һ�������� 
void PreTraverse(struct BTNode *pT);//������� 
void InTraverse(struct BTNode *pT);//������� 
void PostTraverse(struct BTNode *pT);//������� 

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
	//����������ڵ���������˳��ΪABCDE
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
	�ȷ��ʸ��ڵ㣬�������������������������������� 
	*/ 
	if(pT==NULL)
		return;
	printf("%c\n",pT->data);
	PreTraverse(pT->plchild);//�ݹ� 
	PreTraverse(pT->prchild);
}

void InTraverse(struct BTNode *pT)
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

void PostTraverse(struct BTNode *pT)
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
