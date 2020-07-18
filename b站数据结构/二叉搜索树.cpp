#include<stdio.h>
#include<malloc.h>

typedef int ElementType;

typedef struct BitNode
{
	ElementType data;//�ڵ�����
	struct BitNode *lchild,*rchild;//���Һ���ָ�� 
}BitNode,*BiTree;

//���ҵݹ�ʵ��
BiTree Find(ElementType X,BiTree BST)//BSTָ�����ĸ� 
{
	if(BST==NULL)//������ڵ�Ϊ�� 
		return NULL;
	if(X<BST->data)
		return Find(X,BST->lchild);//�ȸ��ڵ�С��ȥ����������
	else if(X>BST->data)
		return Find(X,BST->rchild);//�ȸ��ڵ��ȥ����������
	else if(X==BST->data)
		return BST; 
}

//���ҷǵݹ�ʵ��
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

//������Сֵ�ݹ�ʵ��
BiTree FindMin(BiTree BST)
{
	if(BST==NULL)
		return NULL;
	else if(BST->lchild)
		return FindMin(BST->lchild);//�������������������֧��������
	else
		return BST;//�ҵ��� 
}

//�������ֵ�ǵݹ�ʵ��
BiTree FindMax(BiTree BST)
{
	if(BST)//�������
		while(BST->rchild)//ֻҪ������������
			BST=BST->rchild;
	return BST; 
 } 

//����
BiTree Insert(ElementType X,BiTree BST)
{
	if(!BST)
	{//���Ϊ�գ���ʼ���ýڵ�
		BST=(BiTree)malloc(sizeof(BitNode));
		BST->data=X;
		BST->lchild=NULL;
		BST->rchild=NULL; 		
	}
	else
	{
		if(X<BST->data)
			BST->lchild=Insert(X,BST->lchild);//���С���������
		else if(X>BST->data)
			BST->rchild=Insert(X,BST->rchild);//����󣬹����ұ�
		//�����ȣ���ʲô������ 
	}
	return BST;
}

//ɾ��
BiTree Delete(ElementType X,BiTree BST)
{
	BiTree temp;
	if(!BST)
		printf("Ҫɾ����Ԫ�ز�����!\n");
	else if(X<BST->data)//x�ȵ�ǰ�ڵ�ֵС������������������ɾ��
		BST->lchild=Delete(X,BST->lchild);
	else if(X>BST->data)//x�ȵ�ǰ�ڵ�ֵ������������������ɾ��
		BST->rchild=Delete(X,BST->rchild);
	else//�ҵ���ɾ���ڵ� 
	{
		if(BST->lchild&&BST->rchild)//��ɾ���ڵ������Һ���
		{
			temp=FindMin(BST->rchild);//�ҵ�����������С�� 
			BST->data=temp->data;//���ҵ���ֵ�滻��ǰ�ڵ� 
			BST->rchild=Delete(temp->data,BST->rchild);//��ǰ���ҵ�����������С�ڵ�ֵɾ�� 
		}
		else//��ɾ���ڵ�ֻ��һ�����ӽڵ��û�к��ӽڵ� 
		{
			temp=BST;
			if(!BST->lchild&&!BST->rchild)//û�к��ӽڵ� 
				BST=NULL;
			else if(BST->lchild&&!BST->rchild)//ֻ�����ӽڵ�
				BST=BST->lchild;
			else if(!BST->lchild&&BST->rchild)//ֻ���Һ��ӽڵ�
				BST=BST->rchild; 
			free(temp);//���������䲻��д�������ѭ�� 
		} 		
	} 
	return BST;
}

//�������
void InTraverse(BiTree BST)
{
	if(BST)
	{
		InTraverse(BST->lchild);//�ݹ���������� 
		printf("%d\n",BST->data);//��ӡ���ڵ� 
		InTraverse(BST->rchild);//�ݹ���������� 
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
	
	printf("��������Ľ��:\n");
	InTraverse(BST);
	
	printf("����ֵΪ7�Ľڵ��������ڵ�ֵ:%d\n",IterFind(7,BST)->lchild->data);
	printf("����ֵΪ7�Ľڵ��������ڵ�ֵ:%d\n",Find(7,BST)->rchild->data);
	
	printf("������Сֵ��:%d\n",FindMin(BST)->data);
	printf("�������ֵ��:%d\n",FindMax(BST)->data);
	
	printf("ɾ��ֵΪ7�Ľڵ�\n");
	Delete(7,BST);
	
	printf("��������Ľ��Ϊ:\n");
	InTraverse(BST);
	return 0;
} 
