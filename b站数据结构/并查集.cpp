#include<stdio.h>

#define MaxSize 20

typedef struct
{
	int Data;//存值
	int parent;//指向父节点 
}SetType;

//查找
int Find(SetType S[],int x)
{
	int i;
	//找到数组中该值对应的下标 
	for(i=0;i<MaxSize&&S[i].Data!=x;i++);
	if(i>=MaxSize)//如果没有找到，返回-1 
		return -1;
	//找到该节点的根节点下标 
	for( ;S[i].parent>=0;i=S[i].parent);
	return i;//返回根节点在数组中的下标 
} 

//并
void Union(SetType S[],int x1,int x2)
{
	int root1=Find(S,x1);//找到x1的根节点下标
	int root2=Find(S,x2);//找到x2的根节点下标
	//如果根节点的下标不同，说明不是一个集合
	if(root1!=root2)
		S[root2].parent=root1;//将x2挂到x1的集合	
} 

int main()
{
	SetType S[MaxSize];
	S[0].Data=1;
	S[0].parent=-1;
	S[1].Data=2;
	S[1].parent=0;
	S[2].Data=3;
	S[2].parent=-1;
	S[3].Data=4;
	S[3].parent=0;
	S[4].Data=5;
	S[4].parent=2;
	S[5].Data=6;
	S[5].parent=2;
	int x1=Find(S,5);
	printf("%d\n",x1);
	Union(S,2,5);
	int x2=Find(S,5);
	printf("%d\n",x2);
	return 0;
}
