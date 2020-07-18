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

MaxHeap Creat(int MaxSize);//最大堆的建立
bool Full(MaxHeap H);//判断堆是否为满
void Insert(MaxHeap H,ElementType item);//在堆中插入元素(从最后一个位置插入)
bool Empty(MaxHeap H);//判断堆是否为空
ElementType Delete(MaxHeap H);//在堆中删除元素(从根节点删除)
void Traverse(MaxHeap H);//层序遍历 

int main()
{
	MaxHeap H;
	int MaxSize=100;
	H=Creat(MaxSize);
	Insert(H,55);
	Insert(H,66);
	Insert(H,33);
	Insert(H,44);
	Insert(H,11);
	Insert(H,22);
	Insert(H,88);
	Insert(H,99);
	
	Traverse(H);
	
	int m=Delete(H);
	printf("删除的元素为%d\n",m);
	
	Traverse(H);		
	return 0;
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

bool Full(MaxHeap H)
{
	if(H->Size==H->Capacity)
		return true;
	else
		return false;
}

void Insert(MaxHeap H,ElementType item)
{
	if(Full(H))
	{
		printf("最大堆已满");
		return;
	}
	int i;
	i=++H->Size;//i指向插入后堆中最后一个元素的位置 
	//H->Elements[0]是哨兵元素，它不小于堆中的最大元素，控制循环结束 
	for( ;H->Elements[i/2]<item;i/=2)//第一个表达式为空是因为前面已经为i赋了初值 
		H->Elements[i]=H->Elements[i/2];//向下过滤结点，比赋值要快 
	H->Elements[i]=item;//插入元素	
} 

bool Empty(MaxHeap H)
{
	if(H->Size==0)
		return true;
	else
		return false;
}

ElementType Delete(MaxHeap H)
{
	int parent,child;//定义两个下标 
	ElementType MaxItem,temp;//定义一个保存当前要被删除的最大值以及要移动元素的值 
	if(Empty(H))
	{
		printf("最大堆已空");
		return 0;
	}
	MaxItem=H->Elements[1];//取出最大堆中的最大元素(根节点) 
	temp=H->Elements[H->Size--];//temp为当前堆中最后一个元素的值
	for(parent=1;parent*2<=H->Size;parent=child)//第二个表达式的意思是判断当前节点是否有左孩子 
	{
		child=parent*2;
	 	if((child!=H->Size)&&H->Elements[child]<H->Elements[child+1])
		//第一个表达式是判断是否有右孩子，第二个表达式再判断左右孩子的大小
			child++;//child指向左右孩子的较大者
		if(temp>=H->Elements[child])//如果temp比他的孩子中的较大者大则跳出循环 
			break; 
		else//移动temp元素到下一层 
			H->Elements[parent]=H->Elements[child];
	} 
	H->Elements[parent]=temp;
	return MaxItem;
}

void Traverse(MaxHeap H)
{
	int i;
	printf("层序遍历的结果是:\n");
	for(i=1;i<=H->Size;i++)
		printf("%d\n",H->Elements[i]);
}
