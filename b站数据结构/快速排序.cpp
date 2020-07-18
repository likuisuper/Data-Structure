#include<stdio.h>

void QuickSort(int *a,int low,int high);//快速排序
void Swap(int *a,int low,int high);//交换位置 
int FindPos(int *a,int low,int high);//找到第一个元素（枢轴）的位置 

int main()
{
	int a[8]={9,0,8,10,-5,2,13,7};
	int i;
	
	QuickSort(a,0,7);//第二个参数代表数组的第0个位置，第三个参数代表数组的第七个位置 
	
	for(i=0;i<8;++i)
		printf("%d\t",a[i]); 
	
	return 0;
}

void QuickSort(int *a,int low,int high)
{
	int pos;
	if(low<high)
	{
		pos=FindPos(a,low,high);
		QuickSort(a,low,pos-1);
		QuickSort(a,pos+1,high);
	}
}

void Swap(int *a,int low,int high)
{
	int temp=a[low];
	a[low]=a[high];
	a[high]=temp;
} 

/*
快速排序的快慢关键取决于a[1]的关键字在整个序列的位置，太小或者太大都会影响，
所以在采用第一个数作为关键字的基础上，采用三数取中的方法。同时为了减少不必要的
交换，在while循环中使用赋值而不是调用swap方法 
*/ 
int FindPos(int *a,int low,int high)
{
	int val;
	//采用三数取中的方法选取枢轴
	int center=(low+high)/2;
	if(a[low]>a[high])
		Swap(a,low,high);
	if(center>a[low])
		Swap(a,low,high);
	if(center>a[high])
		Swap(a,low,high); 
	val=a[low];
	//上述步骤 
	while(low<high)
	{
		while(low<high&&a[high]>val)
			--high;
		a[low]=a[high];//这里采用赋值而不是交换，即减少了不必要的交换，性能得到提升 
		while(low<high&&a[low]<val)
			++low;
		a[high]=a[low];
	}
	//终止while循环后low和high的值一定是相等的 
	a[low]=val;
	return low;//low也可以改为high,但不能改为val,a[low]或者a[high] 
}
