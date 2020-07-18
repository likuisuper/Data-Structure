#include<stdio.h>

void Swap(int *a,int *b);
void PercDown(int A[],int p,int N);
void HeapSort(int A[],int N);
 
int main()
{
	int A[8]={55,66,33,44,11,22,88,99};
	HeapSort(A,8);
	for(int i=0;i<8;i++)
		printf("%d\n",A[i]); 
	return 0;
}

//��������Ԫ�ص�ֵ 
void Swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}

//��N��Ԫ�ص���������A[p]Ϊ�����Ӷѵ���Ϊ����
void PercDown(int A[],int p,int N)
{
	int parent,child;
	int temp=A[p];//ȡ�����ڵ�
	for(parent=p;(parent*2+1)<N;parent=child)
	{
		child=parent*2+1;
		if(child!=N-1&&A[child]<A[child+1])
			child++;//childָ�������ӽڵ��еĽϴ��� 
		if(temp>=A[child])
			break;//�ҵ��˺���λ�� 
		else
			A[parent]=A[child]; 
	}
	A[parent]=temp;
 } 

//������ 
void HeapSort(int A[],int N)
{
	int i;
 	//�������� 
 	for(i=N/2-1;i>=0;i--)
 		PercDown(A,i,N);
 	//ɾ�����Ѷ�(�������һ��Ԫ����Ѷ�Ԫ�ػ���,Ȼ���ٽ�������) 
 	for(i=N-1;i>0;i--)
 	{
 		Swap(A[0],A[i]);
 		PercDown(A,0,i);//�����������������N����i,��Ϊ���һ��Ԫ���Ѿ��������ˣ����ٲ���Ƚϣ�����ֻʣi��Ԫ�� 		
	} 
}
