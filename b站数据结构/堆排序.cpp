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

//交换两个元素的值 
void Swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}

//将N个元素的数组中以A[p]为根的子堆调整为最大堆
void PercDown(int A[],int p,int N)
{
	int parent,child;
	int temp=A[p];//取出根节点
	for(parent=p;(parent*2+1)<N;parent=child)
	{
		child=parent*2+1;
		if(child!=N-1&&A[child]<A[child+1])
			child++;//child指向左右子节点中的较大者 
		if(temp>=A[child])
			break;//找到了合适位置 
		else
			A[parent]=A[child]; 
	}
	A[parent]=temp;
 } 

//堆排序 
void HeapSort(int A[],int N)
{
	int i;
 	//建立最大堆 
 	for(i=N/2-1;i>=0;i--)
 		PercDown(A,i,N);
 	//删除最大堆顶(即把最后一个元素与堆顶元素互换,然后再建立最大堆) 
 	for(i=N-1;i>0;i--)
 	{
 		Swap(A[0],A[i]);
 		PercDown(A,0,i);//这里第三个参数不是N而是i,因为最后一个元素已经排序完了，不再参与比较，所以只剩i个元素 		
	} 
}
