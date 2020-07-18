#include<stdio.h>

int BinarySearch(int *a,int n,int key)
{
	int low=0,high=n-1,mid;
	while(low<=high)//当前区间存在时循环 
	{
		mid=(low+high)/2; 
		if(a[mid]<key)
			low=mid+1;
		else if(a[mid]>key)
			high=mid-1;
		else
			return mid; 
	}
	return 0;
}

int main()
{
	int a[11]={2,3,10,15,20,25,28,29,30,35,40};
	int m=BinarySearch(a,11,25);
	printf("位置为:%d\n",m);
	return 0;
}
