#include<stdio.h>

//顺序查找 
int SeqSearch(int *a,int n,int key)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
			return i+1;//返回逻辑下标(即数组下标加1) 
	}
	return 0;	
}

/*顺序查找的优化:上面的循环每次都要对i是否越界，即是否<n做判断
优化方法就是设置哨兵 
*/
int SeqSearch2(int *a,int n,int key)
{
	int i;
	a[0]=key;//设置a[0]为关键字，称之为哨兵
	i=n;//循环从数组尾开始
	while(a[i]!=key)
	{
		i--;
	}
	return i; //返回0则说明查找失败，a[1]-a[n]中没有关键字 
}

int main()
{
	int a[8]={23,30,40,29,50,69,18,85};
	int m=SeqSearch(a,8,13);
	printf("位置为:%d\n",m);
	return 0;
} 
