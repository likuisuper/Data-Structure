#include<stdio.h>
#include<malloc.h>

#define MaxSize 1000
#define MinData -1000 //最小堆的哨兵值

int A[]={13,1,45,7,20,4,19,13,40,33,38};//预先定义好一组权值
int A_length=11;//定义其长度 

typedef struct Heap *MinHeap;//堆结构
typedef struct TreeNode *HuffmanTree; 
struct Heap
{
	HuffmanTree *data;//存值的数组
	int size;//堆的当前大小
	int capacity;//最大容量 
};

struct TreeNode
{
	int wight;//权值 
	HuffmanTree lchild;//左子树 
	HuffmanTree rchile;//右子树 
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

//初始化堆 
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
	//给堆设置哨兵
	T=init_tree();
	T->wight=MinData;
	H->data[0]=T;
	return H;
}

//初始化哈夫曼树 
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

//调整子最小堆
void PercDown(MinHeap H,int i)
{
	int child,parent;
	int tmp=H->data[i]->wight;//取出根节点的权值 
	for(parent=i;parent*2<=H->size;parent=child)
	{
		child=parent*2;
		if(child!=H->size&&H->data[child]->wight<H->data[child+1]->wight)
			child++;
		if(H->data[child]->wight>=tmp)
			break;
		else
			H->data[parent]=H->data[child];//移动的是节点，不是权值 
	}
	H->data[parent]->wight=tmp;
} 

//调整最小堆
void adjust(MinHeap H)
{
	int i;
	for(i=H->size/2;i>0;i--)
		PercDown(H,i);//每个子最小堆调整	
}

//建立最小堆
void CreatMinHeap(MinHeap H)
{
	//将权值读入堆中
	HuffmanTree T;
	int i;
	for(i=0;i<A_length;i++)
	{
		T=init_tree();
		T->wight=A[i];
		H->data[++H->size]=T;
	}
	adjust(H);//调整堆 
} 

//堆是否为空
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

//删除最小堆元素
HuffmanTree Delete(MinHeap H) 
{
	int parent,child;
	if(isEmpty(H))
		return NULL;
	HuffmanTree T=H->data[1];//取出根节点的哈夫曼树
	HuffmanTree tmp=H->data[H->size--];//取出最后一个节点的哈夫曼树
	for(parent=1;parent*2<=H->size;parent=child)
	{
		child=parent*2;
		if((child!=H->size)&&(H->data[child]->wight)>(H->data[child+1]->wight))
			child++;
		if(tmp->wight<=H->data[child]->wight)
			break;
		else
			H->data[parent]=H->data[child];//移动的是节点 
	}
	H->data[parent]=tmp; 
	//返回该节点 
	return T;
}

//插入一个哈夫曼树
void Insert(MinHeap H,HuffmanTree T)
{
	if(Full(H))
		return;
	int weight=T->wight;//取出权值 
	int i;
	i=++H->size;
	for(;H->data[i/2]->wight>weight;i/=2)
		H->data[i]=H->data[i/2];
	H->data[i]=T;
} 

//哈夫曼树的构造
HuffmanTree huffman(MinHeap H)
{
	int i;
	HuffmanTree T;
	CreatMinHeap(H);//建堆,即按权值调整成最小堆 
	for(i=1;i<H->size;i++)//做H->size次合并 
	{
		T=(HuffmanTree)malloc(sizeof(struct TreeNode));//建立新节点
		T->lchild=Delete(H);//从最小堆中删除一个节点，作为新T的左子节点
		T->rchile=Delete(H);//从最小堆中删除一个节点，作为新T的右子节点
		T->wight=T->lchild->wight+T->rchile->wight;//重新计算权值
		Insert(H,T);//将新T插入最小堆中 
	}
	T=Delete(H); 
	return T; 
} 

//遍历
void PreTraverse(HuffmanTree T)
{
	if(T)
	{
		printf("%d\n",T->wight);
		PreTraverse(T->lchild);
		PreTraverse(T->rchile);
	}
} 



