#include<stdio.h>

void QuickSort(int *a,int low,int high);//��������
void Swap(int *a,int low,int high);//����λ�� 
int FindPos(int *a,int low,int high);//�ҵ���һ��Ԫ�أ����ᣩ��λ�� 

int main()
{
	int a[8]={9,0,8,10,-5,2,13,7};
	int i;
	
	QuickSort(a,0,7);//�ڶ���������������ĵ�0��λ�ã�������������������ĵ��߸�λ�� 
	
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
��������Ŀ����ؼ�ȡ����a[1]�Ĺؼ������������е�λ�ã�̫С����̫�󶼻�Ӱ�죬
�����ڲ��õ�һ������Ϊ�ؼ��ֵĻ����ϣ���������ȡ�еķ�����ͬʱΪ�˼��ٲ���Ҫ��
��������whileѭ����ʹ�ø�ֵ�����ǵ���swap���� 
*/ 
int FindPos(int *a,int low,int high)
{
	int val;
	//��������ȡ�еķ���ѡȡ����
	int center=(low+high)/2;
	if(a[low]>a[high])
		Swap(a,low,high);
	if(center>a[low])
		Swap(a,low,high);
	if(center>a[high])
		Swap(a,low,high); 
	val=a[low];
	//�������� 
	while(low<high)
	{
		while(low<high&&a[high]>val)
			--high;
		a[low]=a[high];//������ø�ֵ�����ǽ������������˲���Ҫ�Ľ��������ܵõ����� 
		while(low<high&&a[low]<val)
			++low;
		a[high]=a[low];
	}
	//��ֹwhileѭ����low��high��ֵһ������ȵ� 
	a[low]=val;
	return low;//lowҲ���Ը�Ϊhigh,�����ܸ�Ϊval,a[low]����a[high] 
}
