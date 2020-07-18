#include<stdio.h>
#include<malloc.h>

#define MaxSize 1000
#define MinData -1000 //��С�ѵ��ڱ�ֵ

int A[]={13,1,45,7,20,4,19,13,40,33,38};//Ԥ�ȶ����һ��Ȩֵ
int A_length=11;//�����䳤�� 

typedef struct Heap *MinHeap;//�ѽṹ
typedef struct TreeNode *HuffmanTree; 
struct Heap
{
	HuffmanTree *data;//��ֵ������
	int size;//�ѵĵ�ǰ��С
	int capacity;//������� 
};

struct TreeNode
{
	int wight;//Ȩֵ 
	HuffmanTree lchild;//������ 
	HuffmanTree rchile;//������ 
}; 

MinHeap init_heap();
HuffmanTree init_tree();
void PercDown(MinHeap H,int i);
void adjust(MinHeap H);
void CreatMinHeap(MinHeap H);
bool isEmpty(MinHeap H);
bool Full(MinHeap H);
HuffmanTree Delete(MinHeap H);
void Insert(MinHeap H,HuffmanTree T);
void PreTraverse(HuffmanTree T);
HuffmanTree huffman(MinHeap H);

int main()
{
	MinHeap H;
	HuffmanTree T;
	H=init_heap();
	T=huffman(H);
	PreTraverse(T);	
	return 0;
}

//��ʼ���� 
MinHeap init_heap()
{
	MinHeap H;
	HuffmanTree T;
	H=(MinHeap)malloc(sizeof(struct Heap));
	if(H==NULL)
		printf("out of space");	
	H->data=(HuffmanTree *)malloc(sizeof(struct TreeNode)*(MaxSize+1));
	if(H->data==NULL)
		printf("out of space");
	H->capacity=MaxSize;
	H->size=0;
	//���������ڱ�
	T=init_tree();
	T->wight=MinData;
	H->data[0]=T;
	return H;
}

//��ʼ���������� 
HuffmanTree init_tree()
{
	HuffmanTree T;
	T=(HuffmanTree)malloc(sizeof(struct TreeNode));
	if(T==NULL)
		printf("out of space");
	T->wight=0;
	T->lchild=NULL;
	T->rchile=NULL;
	return T;
}

//��������С��
void PercDown(MinHeap H,int i)
{
	int child,parent;
	int tmp=H->data[i]->wight;//ȡ�����ڵ��Ȩֵ 
	for(parent=i;parent*2<=H->size;parent=child)
	{
		child=parent*2;
		if(child!=H->size&&H->data[child]->wight<H->data[child+1]->wight)
			child++;
		if(H->data[child]->wight>=tmp)
			break;
		else
			H->data[parent]=H->data[child];//�ƶ����ǽڵ㣬����Ȩֵ 
	}
	H->data[parent]->wight=tmp;
} 

//������С��
void adjust(MinHeap H)
{
	int i;
	for(i=H->size/2;i>0;i--)
		PercDown(H,i);//ÿ������С�ѵ���	
}

//������С��
void CreatMinHeap(MinHeap H)
{
	//��Ȩֵ�������
	HuffmanTree T;
	int i;
	for(i=0;i<A_length;i++)
	{
		T=init_tree();
		T->wight=A[i];
		H->data[++H->size]=T;
	}
	adjust(H);//������ 
} 

//���Ƿ�Ϊ��
bool isEmpty(MinHeap H)
{
	if(H->size==0)
		return true;
	else
		return false;
}

bool Full(MinHeap H)
{
	if(H->size==H->capacity)
		return true;
	else
		return false;
} 

//ɾ����С��Ԫ��
HuffmanTree Delete(MinHeap H) 
{
	int parent,child;
	if(isEmpty(H))
		return NULL;
	HuffmanTree T=H->data[1];//ȡ�����ڵ�Ĺ�������
	HuffmanTree tmp=H->data[H->size--];//ȡ�����һ���ڵ�Ĺ�������
	for(parent=1;parent*2<=H->size;parent=child)
	{
		child=parent*2;
		if((child!=H->size)&&(H->data[child]->wight)>(H->data[child+1]->wight))
			child++;
		if(tmp->wight<=H->data[child]->wight)
			break;
		else
			H->data[parent]=H->data[child];//�ƶ����ǽڵ� 
	}
	H->data[parent]=tmp; 
	//���ظýڵ� 
	return T;
}

//����һ����������
void Insert(MinHeap H,HuffmanTree T)
{
	if(Full(H))
		return;
	int weight=T->wight;//ȡ��Ȩֵ 
	int i;
	i=++H->size;
	for(;H->data[i/2]->wight>weight;i/=2)
		H->data[i]=H->data[i/2];
	H->data[i]=T;
} 

//���������Ĺ���
HuffmanTree huffman(MinHeap H)
{
	int i;
	HuffmanTree T;
	CreatMinHeap(H);//����,����Ȩֵ��������С�� 
	for(i=1;i<H->size;i++)//��H->size�κϲ� 
	{
		T=(HuffmanTree)malloc(sizeof(struct TreeNode));//�����½ڵ�
		T->lchild=Delete(H);//����С����ɾ��һ���ڵ㣬��Ϊ��T�����ӽڵ�
		T->rchile=Delete(H);//����С����ɾ��һ���ڵ㣬��Ϊ��T�����ӽڵ�
		T->wight=T->lchild->wight+T->rchile->wight;//���¼���Ȩֵ
		Insert(H,T);//����T������С���� 
	}
	T=Delete(H); 
	return T; 
} 

//����
void PreTraverse(HuffmanTree T)
{
	if(T)
	{
		printf("%d\n",T->wight);
		PreTraverse(T->lchild);
		PreTraverse(T->rchile);
	}
} 



