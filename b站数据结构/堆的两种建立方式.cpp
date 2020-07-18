#include<stdio.h>
#include<malloc.h>
#define MaxData 10000//哨兵的值 

typedef int ElementType;

typedef struct Heapstruct
{
	ElementType *Elements;//存储堆元素的数组 
	int Size;//堆的当前元素个数
	int Capacity;//堆的最大容量 
}HeapStruct,*MaxHeap;

MaxHeap Creat(int MaxSize);//初始化堆
void PercDown(MaxHeap H,int i);//排序
void BuildMaxHeap(MaxHeap H);//调整
void Traverse(MaxHeap H);//遍历 

/*-----第二种插入的方法-----*/
void Insert(MaxHeap H,int item);
void Traverse2(MaxHeap H);

int main()
{
	MaxHeap H;
	int MaxSize=100;
	H=Creat(MaxSize);
	int n,i;
	printf("请输入元素个数\n");
	scanf("%d",&n);
	printf("输入元素的值,以任意字符结束\n");
	for(i=0;i<n;++i)
		scanf("%d\t",&H->Elements[++H->Size]);
	BuildMaxHeap(H);
	Traverse(H);
	return 0;

/*	Insert(H,55);
	Insert(H,66);
	Insert(H,33);
	Insert(H,44);
	Insert(H,11);
	Insert(H,22);
	Insert(H,88);
	Insert(H,99);
	
	Traverse2(H);
*/		
}

MaxHeap Creat(int MaxSize)
{
	MaxHeap H=(MaxHeap)malloc(sizeof(HeapStruct));
	H->Elements=(ElementType *)malloc(sizeof(ElementType)*(MaxSize+1));//因为是从1开始存放数据
	H->Size=0;
	H->Capacity=MaxSize;
	H->Elements[0]=MaxData;//定义哨兵为大于堆中所有可能元素的值，便于以后更快操作
	return H; 
}

/*
虽说构造一个最大堆时只要把一个个元素按照插入方法插入到数组中即可完成。
但是其时间复杂度是(O(N log N))。我们有一种更简单的方式，使得时间复杂度下降到O(N)。
1.将输入的元素按顺序放入完全二叉树(数组)中。
2.调整各个节点的位置，满足最大堆的有序性。
调整的过程就是从最后一个父节点开始倒序到根节点，逐一向下进行过滤操作
(同删除的向下过滤一样，不过过滤元素就是父节点本身的元素)。
*/ 
void PercDown(MaxHeap H,int i)
{
	int temp,parent,child;
	temp=H->Elements[i];//拿到当前"根节点的值"
	for(parent=i;parent*2<=H->Size;parent=child)
	{
		child=parent*2;
		if(child!=H->Size&&H->Elements[child]<H->Elements[child+1])
			child++;
		if(temp>=H->Elements[child])
			break;
		else
			H->Elements[parent]=H->Elements[child];
	}
	H->Elements[parent]=temp; 
}

void BuildMaxHeap(MaxHeap H)
{
	int i;
	for(i=H->Size/2;i>0;--i)
	//以每个有孩子结点的结点作为根节点，对其子树进行排序 
		PercDown(H,i); 
}

void Traverse(MaxHeap H)
{
	int i;
	for(i=1;i<=H->Size;++i)
		printf("%d\n",H->Elements[i]);
} 

/*-------------第二种方法，用插入的方式插入到数组中构造最大堆 */
void Insert(MaxHeap H,int item)
{
	if(H->Size==H->Capacity)
		return;
	int i=++H->Size;//指向数组最后一个
	for( ;H->Elements[i/2]<item;i/=2)
		H->Elements[i]=H->Elements[i/2];
	H->Elements[i]=item;	
} 

void Traverse2(MaxHeap H)
{
	int i;
	for(i=1;i<=H->Size;++i)
		printf("%d\n",H->Elements[i]);
}
