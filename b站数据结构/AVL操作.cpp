#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct AVLNode
{
	ElementType data;
	struct AVLNode *lchild,*rchild;
	int height;//树高 
}AVLNode,*AVLTree;

//返回最大值
int Max(int a,int b)
{
	return a>b?a:b;
}

//返回树高，空树返回-1
int GetHeight(AVLTree A)
{
	return A==NULL?-1:A->height;
}

//LL调整(单旋，即向右旋转) 
//将原来B节点的右子树作为A的左子树，再将A挂到B的右子树上
AVLTree LLRotation(AVLTree A)
{
	AVLTree B=A->lchild;//B为A的左子树 
	A->lchild=B->rchild;//将B的右子树挂在A的左子树上 
	B->rchild=A;//将A挂到B的右子树上
	A->height=Max(GetHeight(A->lchild),GetHeight(A->rchild)+1); 
	B->height=Max(GetHeight(B->lchild),GetHeight(B->rchild)+1);
	return B;//此时B为根节点了 
}

//RR调整(单旋，即向左旋转)
//将原来B节点的左子树作为A的右子树，再将A挂到B的左子树上
AVLTree RRRotation(AVLTree A)
{
	AVLTree B=A->rchild;//B为A的右子树
	A->rchild=B->lchild;//将B的左子树挂在A的右子树上
	B->lchild=A;//将A挂在B的左子树上
	A->height=Max(GetHeight(A->lchild),GetHeight(A->rchild)+1);
	B->height=Max(GetHeight(B->lchild),GetHeight(B->rchild)+1);
	return B;//此时B为根节点了 
}

//LR调整(双旋，先RR(左旋)，再LL(右旋) 
AVLTree LRRotation(AVLTree A)
{
	//先RR调整(A的左节点左旋) 
	A->lchild=RRRotation(A->lchild);
	//再LL调整(A的左节点右旋) 
	return LLRotation(A);
}

//RL调整(双旋，先LL(右旋)，再RR(左旋))
AVLTree RLRotation(AVLTree A)
{
	//先LL调整(A的右节点右旋)
	A->rchild=LLRotation(A->rchild);
	//再RR调整(A的右节点左旋) 
	return RRRotation(A);
}

//插入
AVLTree Insert(AVLTree T,ElementType X)
{
	if(!T)//如果节点为空，初始化该节点 
	{
		T=(AVLTree)malloc(sizeof(AVLNode));
		if(T==NULL)
		{
			printf("动态分配内存失败");
			exit(-1);
		}
		else
		{
			T->data=X;
			T->lchild=T->rchild=NULL;
			T->height=0;	
		}
	}
	else//否则不为空 
	{
		if(X<T->data)//左子树
		{
			T->lchild=Insert(T->lchild,X);//往左边插
			if(GetHeight(T->lchild)-GetHeight(T->rchild)==2)
			{
				if(X<T->lchild->data)
					T=LLRotation(T);//LL调整
				else if(X>T->lchild->data)
					T=LRRotation(T);//LR调整
			} 
		}
		else if(X>T->data)//右子树
		{
			T->rchild=Insert(T->rchild,X);//往右边插
			if(GetHeight(T->rchild)-GetHeight(T->lchild)==2)
			{
				if(X>T->rchild->data)
					T=RRRotation(T);//RR调整
				else if(X<T->rchild->data)
					T=RLRotation(T);//RL调整 
			 } 
		 } 
	}
	//更新树高
	T->height=Max(GetHeight(T->lchild),GetHeight(T->rchild))+1;
	return T;		
} 
 
int main()
{
	AVLTree T=NULL;
	int n;
	printf("请输入节点个数:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int temp;
		printf("请输入要插入的节点值:");
		scanf("%d",&temp);
		T=Insert(T,temp);
	}
	printf("%d\n",T->data);
	return 0;
}
