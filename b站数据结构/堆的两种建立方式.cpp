#include<stdio.h>
#include<malloc.h>
#define MaxData 10000//�ڱ���ֵ 

typedef int ElementType;

typedef struct Heapstruct
{
	ElementType *Elements;//�洢��Ԫ�ص����� 
	int Size;//�ѵĵ�ǰԪ�ظ���
	int Capacity;//�ѵ�������� 
}HeapStruct,*MaxHeap;

MaxHeap Creat(int MaxSize);//��ʼ����
void PercDown(MaxHeap H,int i);//����
void BuildMaxHeap(MaxHeap H);//����
void Traverse(MaxHeap H);//���� 

/*-----�ڶ��ֲ���ķ���-----*/
void Insert(MaxHeap H,int item);
void Traverse2(MaxHeap H);

int main()
{
	MaxHeap H;
	int MaxSize=100;
	H=Creat(MaxSize);
	int n,i;
	printf("������Ԫ�ظ���\n");
	scanf("%d",&n);
	printf("����Ԫ�ص�ֵ,�������ַ�����\n");
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
	H->Elements=(ElementType *)malloc(sizeof(ElementType)*(MaxSize+1));//��Ϊ�Ǵ�1��ʼ�������
	H->Size=0;
	H->Capacity=MaxSize;
	H->Elements[0]=MaxData;//�����ڱ�Ϊ���ڶ������п���Ԫ�ص�ֵ�������Ժ�������
	return H; 
}

/*
��˵����һ������ʱֻҪ��һ����Ԫ�ذ��ղ��뷽�����뵽�����м�����ɡ�
������ʱ�临�Ӷ���(O(N log N))��������һ�ָ��򵥵ķ�ʽ��ʹ��ʱ�临�Ӷ��½���O(N)��
1.�������Ԫ�ذ�˳�������ȫ������(����)�С�
2.���������ڵ��λ�ã��������ѵ������ԡ�
�����Ĺ��̾��Ǵ����һ�����ڵ㿪ʼ���򵽸��ڵ㣬��һ���½��й��˲���
(ͬɾ�������¹���һ������������Ԫ�ؾ��Ǹ��ڵ㱾���Ԫ��)��
*/ 
void PercDown(MaxHeap H,int i)
{
	int temp,parent,child;
	temp=H->Elements[i];//�õ���ǰ"���ڵ��ֵ"
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
	//��ÿ���к��ӽ��Ľ����Ϊ���ڵ㣬���������������� 
		PercDown(H,i); 
}

void Traverse(MaxHeap H)
{
	int i;
	for(i=1;i<=H->Size;++i)
		printf("%d\n",H->Elements[i]);
} 

/*-------------�ڶ��ַ������ò���ķ�ʽ���뵽�����й������� */
void Insert(MaxHeap H,int item)
{
	if(H->Size==H->Capacity)
		return;
	int i=++H->Size;//ָ���������һ��
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
