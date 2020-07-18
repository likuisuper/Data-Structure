#include<stdio.h>
#include<malloc.h>
#include<math.h>

#define MAXTABLESIZE 1000000

typedef int Index;
typedef int ElementType;

//单链表结构 
typedef struct LNode *PtrToLNode;
struct LNode
{
	ElementType Data;
	PtrToLNode Next;
};

typedef PtrToLNode Position;
typedef PtrToLNode List;

typedef struct TblNode *HashTable;//哈希表
struct TblNode
{
	int TableSize;//表的最大长度
	List Heads;//指向链表头节点的数组 
};

int NextPrime(int N)
{
	int p=(N%2)?N+2:N+1;
	int i;
	while(p<MAXTABLESIZE)
	{
		for(i=(int)sqrt(p);i>2;i--)
			if(!(p%i))
				break;
		if(i==2)
			break;
		p+=2;//下一个奇数 
	}
	return p;
}

//创建哈希表
HashTable CreatTable(int TableSize)
{
	HashTable H;
	int i;
	if(TableSize>MAXTABLESIZE)
	{
		printf("TableSize is too big");
		return NULL;
	}
	H=(HashTable)malloc(sizeof(struct TblNode));
	if(H==NULL)
		printf("out of space");
	H->TableSize=NextPrime(TableSize);
	H->Heads=(List)malloc(sizeof(struct LNode)*H->TableSize);//分配链表头节点数组
	if(H->Heads==NULL)
		printf("out of space");
	//初始化表头节点
	for(i=0;i<H->TableSize;i++)
	{
		//H->Heads[i].Data='\0';//数据域不存东西的
		H->Heads[i].Next=NULL; 
	}
	return H; 
}

//除留余数法求哈希函数
Index Hash(ElementType key,int TableSize)
{
	return key%TableSize;
}

//查找
Position Find(HashTable H,ElementType key)
{
	Position P;
	Index pos;
	pos=Hash(key,H->TableSize);//初始散列位置
	P=H->Heads[pos].Next;//从该链表的第一个节点开始
	//当未到末尾，且key未被找到时
	while(P&&P->Data!=key)	
		P=P->Next;
	return P;//此时p或者指向找到的节点，或者为null 
} 

//插入
bool Insert(ElementType key,HashTable H)
{
	Position P,NewCell;
	Index pos;
	P=Find(H,key);
	if(!P)//关键词未找到，可以插入 
	{
		NewCell=(Position)malloc(sizeof(struct LNode));
		NewCell->Data=key;
		pos=Hash(key,H->TableSize);//初始散列表地址 
		//将NewCell插入到H->Heads[pos]链表的第一个节点
		NewCell->Next=H->Heads[pos].Next;//就是将NewCell指向原来H->Heads[pos].next指向的节点
		H->Heads[pos].Next=NewCell;//指向当前插入的节点NewCell
		return true;	
	}
	else
	{
		printf("关键词已存在\n");
		return false;
	}
} 

//销毁
void DestroyTable(HashTable H)
{
	Position P,tmp;
	int i;
	for(i=0;i<H->TableSize;i++)
	{
		P=H->Heads[i].Next;
		while(P)
		{
			tmp=P->Next;
			free(P);
			P=tmp;
		}
	}
	free(H->Heads);
	free(H);
}

//打印
void Print(HashTable H)
{
	int i;
	for(i=0;i<H->TableSize;i++)
	{
		printf("%d ",i);
		List p=H->Heads[i].Next;
		while(p)
		{
			printf("%d ",p->Data);
			p=p->Next;
		}
		printf("\n");
	}
} 

int main()
{
	HashTable H=CreatTable(9);
	
	int N;
	printf("请输入要插入的个数:");
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int tmp;
		printf("请输入要插入的数值:");
		scanf("%d",&tmp);//插入47,7,29,11,16,92,22,8,3,50,37,89,94,21 
		Insert(tmp,H);
	}
	
	Print(H);
	

}
