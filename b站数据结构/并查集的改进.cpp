#include<stdio.h>
#define MaxN 1000 //集合最大元素个数

typedef int ElementType;//默认元素可以用非负整数表示
typedef int SetName;//默认用根节点的下标作为集合名称
typedef ElementType SetType[MaxN];//假设集合下标从0开始，S[0]也代表一个数(节点),就不再需要数据域 


/*--------------------------------按秩归并(对Union的改进)----------------------------*/
/*
1.按树的高度:矮树贴到高树上，树的高度存哪里？S[Root]=-1无意义，让S[Root]=-树高 
*/
void Union1(SetType S,ElementType Root1,ElementType Root2)
{/*这里默认Root1和Root2是不同集合的根节点*/
	if(S[Root2]<S[Root1])//因为树高是负数表示，所以A>B相当于-A<-B
		S[Root1]=Root2;//将Root1这个集合并入到Root2
	else
	{
		if(S[Root1]==S[Root2])
			S[Root1]--;//如果两树等高，则树高++
		S[Root2]=Root1;	
	} 	
}

/*
2.按树的规模:把小树贴到大树上，最后一棵树的规模=两树之和，S[Root]=-元素个数
与路径压缩结合更方便 
*/

void Union2(SetType S,ElementType Root1,ElementType Root2)
{
	if(S[Root2]<S[Root1])
	{
		S[Root2]+=S[Root1];
		S[Root1]=Root2;	
	}
	else
	{
		S[Root1]+=S[Root2];
		S[Root2]=Root1;
	}
}

/*--------------------------------路径压缩(对Find的改进)----------------------------*/
SetName Find(SetType S,ElementType x)
{/*默认集合元素全部初始化为-1*/
	if(S[x]<0)
		return x;
	else
		return S[x]=Find(S,S[x]);
		/*这步做了三件事，1.先找到根 2.把根变成X的父节点 3.再返回根
		这是一个伪递归，非常容易转换成循环，所以编译器自动转换为了循环*/
}

int main()
{
	SetType S;
	S[0]=4;
	S[1]=-6;
	S[2]=4;
	S[3]=1;
	S[4]=3;
	S[5]=2;
	
	S[6]=-3;
	S[7]=6;
	S[8]=6;
	int l=Find(S,5);
	int m=Find(S,8);
	printf("5的根节点的下标为:%d\n",l); 
	printf("8的根节点的下标为:%d\n",m);
	Union2(S,1,6);
	int n=Find(S,8);
	printf("合并之后8的根节点的下标为:%d\n",n);
	return 0;
}
