#include<stdio.h>
#include<malloc.h>
#include<math.h>

#define MAXTABLESIZE 100000 //定义允许开辟的最大散列长度

typedef int Index;
typedef int ElementType;
typedef Index Position;
typedef enum{
	Legitimate,Empty,Deleted //分别对应有合法元素，空，有已删除元素 
}EntryType;//定义单元状态类型

typedef struct HashEntry
{//哈希表存值单元 
	ElementType data;//存放元素
	EntryType info;//单元状态 
}Cell;

typedef struct HashTbl
{
	int TabSize;//哈希表大小
	Cell *Cells;//哈希表存值单元数组 
}*HashTable;

int NextPrime(int N);//查找素数
HashTable CreatTable(int TableSize);//创建哈希表
Index Hash(int key,int TableSize);//除留余数法求哈希函数
Position Find(HashTable H,ElementType key);//平方探测法查找 
void Insert(HashTable H,ElementType key);//插入元素
void Print(HashTable H);//打印 

int main()
{
	HashTable H=CreatTable(6);
	Insert(H,7);//位置为0 
	Insert(H,8);//位置为1 
	Insert(H,9);//位置为2 
	Insert(H,19);//位置为5 
	Insert(H,15);//位置为1,此时与8冲突，冲突一次时，i+-1的平方都有冲突，冲突2次时，
				//i+2的平方与19冲突，而i-2的平方(即位置为4)没有冲突 
	Print(H);
	
	printf("\n查找元素为15的位置为:%d\n",Find(H,15));
	return 0;
}

int NextPrime(int N)
{
	int p=(N%2)?N+2:N+1;//如果有余数，除不尽，就执行N+2,否则执行N+1,即从大于N的下一个奇数开始
	int i;
	while(p<MAXTABLESIZE)
	{
		for(i=(int)sqrt(p);i>2;i--)
			if(!(p%i))//p不是素数 
				break;
		if(i==2)
			break;
		p+=2;//继续试探下个奇数	
	} 
	return p;
}

HashTable CreatTable(int TableSize)
{
	HashTable H;
	int i;
	if(TableSize>MAXTABLESIZE)
	{
		printf("TableSzie is too big");
		return NULL;
	}
	H=(HashTable)malloc(sizeof(struct HashTbl));
	if(H==NULL)
		printf("out of space");
	H->TabSize=NextPrime(TableSize);//保证哈希表的最大长度是素数
	H->Cells=(Cell *)malloc(sizeof(Cell)*H->TabSize);//初始化单元数组
	if(H->Cells==NULL)
		printf("out of space");
	//初始化单元数组状态
	for(i=0;i<H->TabSize;i++)
		H->Cells[i].info=Empty;
	return H; 
}

Index Hash(int key,int TableSize)
{
	return key%TableSize;
}

Position Find(HashTable H,ElementType key)
{
	Position CurrentPos,NewPos;
	int CNum=0;//记录冲突次数
	CurrentPos=NewPos=Hash(key,H->TabSize);
	//如果当前单元状态不为空且数值不等，则一直做 
	while(H->Cells[NewPos].info!=Empty&&H->Cells[NewPos].data!=key)
	{
		if(++CNum%2)//冲突奇数次发生 
		{
			//相当于di+i*i,i=冲突次数+1/2 
			NewPos=CurrentPos+(CNum+1)/2*(CNum+1)/2;
			//这个循环就是求余，如果越界，就一直减到再次进入边界
			while(H->TabSize<=NewPos)
				NewPos-=H->TabSize;	
		}
		else//冲突偶数次发生 
		{
			//相当于di-i*i,i=冲突次数/2
			NewPos=CurrentPos-CNum/2*CNum/2;
			//如果越界，就一直加到再次进入边界 
			while(NewPos<0) 
				NewPos+=H->TabSize;
		}
	}
	return NewPos; 
}

void Insert(HashTable H,ElementType key)
{
	Position Pos,i;
	Pos=Hash(key,H->TabSize);
	i=Find(H,key);
	//如果单元格状态不是"存在合法元素" 
	if(H->Cells[Pos].info!=Legitimate)
	{
		H->Cells[Pos].info=Legitimate;
		H->Cells[Pos].data=key;//在此插入 
	}
	else 
		H->Cells[i].data=key;//将存在冲突的元素插入到用平方探测法得到的位置中 
} 

void Print(HashTable H)
{
	int i;
	for(i=0;i<H->TabSize;i++)
		printf("%d ",H->Cells[i].data);
}
