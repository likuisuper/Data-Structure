#include<stdio.h>
#include<malloc.h>

typedef int ElementType;

typedef struct BitNode
{
	ElementType data;//节点数据
	struct BitNode *lchild,*rchild;//左右孩子指针 
}BitNode,*BiTree;

//查找递归实现
BiTree Find(ElementType X,BiTree BST)//BST指向树的根 
{
	if(BST==NULL)//如果根节点为空 
		return NULL;
	if(X<BST->data)
		return Find(X,BST->lchild);//比根节点小，去左子树查找
	else if(X>BST->data)
		return Find(X,BST->rchild);//比根节点大，去右子树查找
	else if(X==BST->data)
		return BST; 
}

//查找非递归实现
BiTree IterFind(ElementType X,BiTree BST)
{
	while(BST)
	{
		if(X<BST->data)
			BST=BST->lchild;
		else if(X>BST->data)
			BST=BST->rchild;
		else if(X==BST->data)
			return BST;	
	}
	return NULL;
}

//查找最小值递归实现
BiTree FindMin(BiTree BST)
{
	if(BST==NULL)
		return NULL;
	else if(BST->lchild)
		return FindMin(BST->lchild);//还存在左子树，沿左分支继续查找
	else
		return BST;//找到了 
}

//查找最大值非递归实现
BiTree FindMax(BiTree BST)
{
	if(BST)//如果不空
		while(BST->rchild)//只要右子树还存在
			BST=BST->rchild;
	return BST; 
 } 

//插入
BiTree Insert(ElementType X,BiTree BST)
{
	if(!BST)
	{//如果为空，初始化该节点
		BST=(BiTree)malloc(sizeof(BitNode));
		BST->data=X;
		BST->lchild=NULL;
		BST->rchild=NULL; 		
	}
	else
	{
		if(X<BST->data)
			BST->lchild=Insert(X,BST->lchild);//如果小，挂在左边
		else if(X>BST->data)
			BST->rchild=Insert(X,BST->rchild);//如果大，挂在右边
		//如果相等，则什么都不做 
	}
	return BST;
}

//删除
BiTree Delete(ElementType X,BiTree BST)
{
	BiTree temp;
	if(!BST)
		printf("要删除的元素不存在!\n");
	else if(X<BST->data)//x比当前节点值小，在左子树继续查找删除
		BST->lchild=Delete(X,BST->lchild);
	else if(X>BST->data)//x比当前节点值大，在右子树继续查找删除
		BST->rchild=Delete(X,BST->rchild);
	else//找到被删除节点 
	{
		if(BST->lchild&&BST->rchild)//被删除节点有左右孩子
		{
			temp=FindMin(BST->rchild);//找到右子树中最小的 
			BST->data=temp->data;//用找到的值替换当前节点 
			BST->rchild=Delete(temp->data,BST->rchild);//把前面找到的右子树最小节点值删除 
		}
		else//被删除节点只有一个孩子节点或没有孩子节点 
		{
			temp=BST;
			if(!BST->lchild&&!BST->rchild)//没有孩子节点 
				BST=NULL;
			else if(BST->lchild&&!BST->rchild)//只有左孩子节点
				BST=BST->lchild;
			else if(!BST->lchild&&BST->rchild)//只有右孩子节点
				BST=BST->rchild; 
			free(temp);//这个返回语句不能写在外面的循环 
		} 		
	} 
	return BST;
}

//中序遍历
void InTraverse(BiTree BST)
{
	if(BST)
	{
		InTraverse(BST->lchild);//递归遍历左子树 
		printf("%d\n",BST->data);//打印根节点 
		InTraverse(BST->rchild);//递归遍历右子树 
	}	
} 

int main()
{
	BiTree BST=NULL;
	BST=Insert(5,BST);
	BST=Insert(7,BST);
	BST=Insert(3,BST);
	BST=Insert(1,BST);
	BST=Insert(2,BST);
	BST=Insert(4,BST);
	BST=Insert(6,BST);
	BST=Insert(8,BST);
	BST=Insert(9,BST);
	
	printf("中序遍历的结果:\n");
	InTraverse(BST);
	
	printf("查找值为7的节点左子树节点值:%d\n",IterFind(7,BST)->lchild->data);
	printf("查找值为7的节点右子树节点值:%d\n",Find(7,BST)->rchild->data);
	
	printf("查找最小值是:%d\n",FindMin(BST)->data);
	printf("查找最大值是:%d\n",FindMax(BST)->data);
	
	printf("删除值为7的节点\n");
	Delete(7,BST);
	
	printf("中序遍历的结果为:\n");
	InTraverse(BST);
	return 0;
} 
