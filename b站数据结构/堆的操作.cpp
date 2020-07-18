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

MaxHeap Creat(int MaxSize);//���ѵĽ���
bool Full(MaxHeap H);//�ж϶��Ƿ�Ϊ��
void Insert(MaxHeap H,ElementType item);//�ڶ��в���Ԫ��(�����һ��λ�ò���)
bool Empty(MaxHeap H);//�ж϶��Ƿ�Ϊ��
ElementType Delete(MaxHeap H);//�ڶ���ɾ��Ԫ��(�Ӹ��ڵ�ɾ��)
void Traverse(MaxHeap H);//������� 

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
	printf("ɾ����Ԫ��Ϊ%d\n",m);
	
	Traverse(H);		
	return 0;
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
		printf("��������");
		return;
	}
	int i;
	i=++H->Size;//iָ������������һ��Ԫ�ص�λ�� 
	//H->Elements[0]���ڱ�Ԫ�أ�����С�ڶ��е����Ԫ�أ�����ѭ������ 
	for( ;H->Elements[i/2]<item;i/=2)//��һ�����ʽΪ������Ϊǰ���Ѿ�Ϊi���˳�ֵ 
		H->Elements[i]=H->Elements[i/2];//���¹��˽�㣬�ȸ�ֵҪ�� 
	H->Elements[i]=item;//����Ԫ��	
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
	int parent,child;//���������±� 
	ElementType MaxItem,temp;//����һ�����浱ǰҪ��ɾ�������ֵ�Լ�Ҫ�ƶ�Ԫ�ص�ֵ 
	if(Empty(H))
	{
		printf("�����ѿ�");
		return 0;
	}
	MaxItem=H->Elements[1];//ȡ�������е����Ԫ��(���ڵ�) 
	temp=H->Elements[H->Size--];//tempΪ��ǰ�������һ��Ԫ�ص�ֵ
	for(parent=1;parent*2<=H->Size;parent=child)//�ڶ������ʽ����˼���жϵ�ǰ�ڵ��Ƿ������� 
	{
		child=parent*2;
	 	if((child!=H->Size)&&H->Elements[child]<H->Elements[child+1])
		//��һ�����ʽ���ж��Ƿ����Һ��ӣ��ڶ������ʽ���ж����Һ��ӵĴ�С
			child++;//childָ�����Һ��ӵĽϴ���
		if(temp>=H->Elements[child])//���temp�����ĺ����еĽϴ��ߴ�������ѭ�� 
			break; 
		else//�ƶ�tempԪ�ص���һ�� 
			H->Elements[parent]=H->Elements[child];
	} 
	H->Elements[parent]=temp;
	return MaxItem;
}

void Traverse(MaxHeap H)
{
	int i;
	printf("��������Ľ����:\n");
	for(i=1;i<=H->Size;i++)
		printf("%d\n",H->Elements[i]);
}
