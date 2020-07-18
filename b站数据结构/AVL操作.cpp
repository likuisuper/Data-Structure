#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct AVLNode
{
	ElementType data;
	struct AVLNode *lchild,*rchild;
	int height;//���� 
}AVLNode,*AVLTree;

//�������ֵ
int Max(int a,int b)
{
	return a>b?a:b;
}

//�������ߣ���������-1
int GetHeight(AVLTree A)
{
	return A==NULL?-1:A->height;
}

//LL����(��������������ת) 
//��ԭ��B�ڵ����������ΪA�����������ٽ�A�ҵ�B����������
AVLTree LLRotation(AVLTree A)
{
	AVLTree B=A->lchild;//BΪA�������� 
	A->lchild=B->rchild;//��B������������A���������� 
	B->rchild=A;//��A�ҵ�B����������
	A->height=Max(GetHeight(A->lchild),GetHeight(A->rchild)+1); 
	B->height=Max(GetHeight(B->lchild),GetHeight(B->rchild)+1);
	return B;//��ʱBΪ���ڵ��� 
}

//RR����(��������������ת)
//��ԭ��B�ڵ����������ΪA�����������ٽ�A�ҵ�B����������
AVLTree RRRotation(AVLTree A)
{
	AVLTree B=A->rchild;//BΪA��������
	A->rchild=B->lchild;//��B������������A����������
	B->lchild=A;//��A����B����������
	A->height=Max(GetHeight(A->lchild),GetHeight(A->rchild)+1);
	B->height=Max(GetHeight(B->lchild),GetHeight(B->rchild)+1);
	return B;//��ʱBΪ���ڵ��� 
}

//LR����(˫������RR(����)����LL(����) 
AVLTree LRRotation(AVLTree A)
{
	//��RR����(A����ڵ�����) 
	A->lchild=RRRotation(A->lchild);
	//��LL����(A����ڵ�����) 
	return LLRotation(A);
}

//RL����(˫������LL(����)����RR(����))
AVLTree RLRotation(AVLTree A)
{
	//��LL����(A���ҽڵ�����)
	A->rchild=LLRotation(A->rchild);
	//��RR����(A���ҽڵ�����) 
	return RRRotation(A);
}

//����
AVLTree Insert(AVLTree T,ElementType X)
{
	if(!T)//����ڵ�Ϊ�գ���ʼ���ýڵ� 
	{
		T=(AVLTree)malloc(sizeof(AVLNode));
		if(T==NULL)
		{
			printf("��̬�����ڴ�ʧ��");
			exit(-1);
		}
		else
		{
			T->data=X;
			T->lchild=T->rchild=NULL;
			T->height=0;	
		}
	}
	else//����Ϊ�� 
	{
		if(X<T->data)//������
		{
			T->lchild=Insert(T->lchild,X);//����߲�
			if(GetHeight(T->lchild)-GetHeight(T->rchild)==2)
			{
				if(X<T->lchild->data)
					T=LLRotation(T);//LL����
				else if(X>T->lchild->data)
					T=LRRotation(T);//LR����
			} 
		}
		else if(X>T->data)//������
		{
			T->rchild=Insert(T->rchild,X);//���ұ߲�
			if(GetHeight(T->rchild)-GetHeight(T->lchild)==2)
			{
				if(X>T->rchild->data)
					T=RRRotation(T);//RR����
				else if(X<T->rchild->data)
					T=RLRotation(T);//RL���� 
			 } 
		 } 
	}
	//��������
	T->height=Max(GetHeight(T->lchild),GetHeight(T->rchild))+1;
	return T;		
} 
 
int main()
{
	AVLTree T=NULL;
	int n;
	printf("������ڵ����:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int temp;
		printf("������Ҫ����Ľڵ�ֵ:");
		scanf("%d",&temp);
		T=Insert(T,temp);
	}
	printf("%d\n",T->data);
	return 0;
}
