#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>//包含exit()函数 

//定义了一个数据类型，该数据类型的名字叫struct Arr,该数据类型含有三个成员 
struct Arr
{
	int * pBase;//存储的是数组的第一个元素的地址
	int len;//数组所能容纳的最大元素的个数
	int cnt;//当前数组有效元素的个数 
	//int increment 自动增长因子 
};

void init_arr(struct Arr * pArr,int length);//初始化 
bool append_arr(struct Arr * pArr,int val);//追加 
bool insert_arr(struct Arr * pArr,int pos,int val);//pos(位置)的值从1开始 
bool delete_arr(struct Arr * pArr,int pos,int *pVal);//删除元素 
int get(struct Arr * pArr);
bool is_empty(struct Arr * pArr);//判断是否为空 
bool is_full();//判断是否为满 
void sort_arr(struct Arr * pArr);//排序(冒泡) 
void show_arr(struct Arr * pArr);//输出 
void inversion_arr(struct Arr * pArr); //逆序 

int main(void)
{
	struct Arr arr;
	int val;
	
	init_arr(&arr,6);//加上地址符才能改变arr的值
	
	show_arr(&arr);
	append_arr(&arr,1);
	append_arr(&arr,2);
	append_arr(&arr,3);
	append_arr(&arr,4);
	append_arr(&arr,5);
	//append_arr(&arr,6);
	
	insert_arr(&arr,6,10);
	show_arr(&arr);
	
	if(delete_arr(&arr,6,&val))
	{
		printf("删除成功！\n");
		printf("您删除的元素是:%d\n",val);
	}
	else
	{
		printf("删除失败！\n");
	}
/*	append_arr(&arr,7);
	if(append_arr(&arr,8))
	{
		printf("追加成功！\n");
	}
	else
	{
		printf("追加失败！\n");
	} 

*/
	show_arr(&arr);	
	
	printf("倒置之后的数组是：\n"); 	
	inversion_arr(&arr);
	show_arr(&arr);	
	
	insert_arr(&arr,6,0);
	printf("排序之后的数组是：\n");
	sort_arr(&arr);
	show_arr(&arr);
	
	//printf("%d",arr.len);
	
	return 0;
}

void init_arr(struct Arr * pArr,int length)
{
	pArr->pBase=(int *)malloc(sizeof(int) * length);
	if(NULL==pArr->pBase)
	{
		printf("动态内存分配失败！\n");
		exit(-1);//终止整个程序 
	}
	else//不为空则初始化 
	{
		pArr->len=length;
		pArr->cnt=0;
	}
	return;
}

bool is_empty(struct Arr * pArr)
{
	if(0==pArr->cnt)
		return true;
	else
		return false;
}

bool is_full(struct Arr * pArr)
{
	if(pArr->cnt==pArr->len)
		return true;
	else
		return false;
}
void show_arr(struct Arr * pArr)
{
	if(is_empty(pArr))//判断数组是否为空
	{ 
		printf("数组为空！\n");
		//提示用户数组为空
	} 
	else
	{ 
		//输出数组有效内容 
		for(int i=0;i<pArr->cnt;++i)
			printf("%d\t",pArr->pBase[i]);//int *
		printf("\n");
	} 
}

bool append_arr(struct Arr * pArr,int val)
{	
	//满时返回false 
	if(is_full(pArr))
		return false;
	
	//不满时追加
	pArr->pBase[pArr->cnt]=val;
	(pArr->cnt)++;//自增加1
	return true; 
}

bool insert_arr(struct Arr * pArr,int pos,int val)
{
	int i;
	if(is_full(pArr))
		return false; 
	if(pos<1||pos>pArr->cnt+1)//如果插入的位置不正确，就返回false 
		return false;
	for(i=pArr->cnt-1;i>=pos-1;--i)  
	{
		pArr->pBase[i+1]=pArr->pBase[i]; //元素后移
	}
	pArr->pBase[pos-1]=val;//将val插入pos-1的位置 
	pArr->cnt++;//插入后长度加1(先后移再插入) 
	return true;
}

bool delete_arr(struct Arr * pArr,int pos,int *pVal)
{
	int i;
	
	if(is_empty(pArr))
		return false;
	if(pos<1||pos>pArr->cnt)
		return false;
	*pVal=pArr->pBase[pos-1];//先删除再前移 
	for(i=pos;i<pArr->cnt;++i)
	{
		pArr->pBase[i-1]=pArr->pBase[i];//元素前移 
	}
	pArr->cnt--;//删除后长度减1
	return true; 
}

void inversion_arr(struct Arr * pArr)
{
	int i=0;
	int j=pArr->cnt-1;
	int t;
	while(i<j)
	{
		t=pArr->pBase[i];
		pArr->pBase[i]=pArr->pBase[j];
		pArr->pBase[j]=t;
		++i;
		--j;
	}
	return;	
} 

void sort_arr(struct Arr * pArr)
{
	int i,j,t;
	for(i=0;i<pArr->cnt;++i)
	{
		for(j=i+1;j<pArr->cnt;++j)
		{
			if(pArr->pBase[i]>pArr->pBase[j])
			{
				t=pArr->pBase[i];
				pArr->pBase[i]=pArr->pBase[j];
				pArr->pBase[j]=t;
			}
					
		}
	}
}

 
