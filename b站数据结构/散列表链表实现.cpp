#include<stdio.h>
#include<malloc.h>
#include<math.h>

#define MAXTABLESIZE 1000000

typedef int Index;
typedef int ElementType;

//������ṹ 
typedef struct LNode *PtrToLNode;
struct LNode
{
	ElementType Data;
	PtrToLNode Next;
};

typedef PtrToLNode Position;
typedef PtrToLNode List;

typedef struct TblNode *HashTable;//��ϣ��
struct TblNode
{
	int TableSize;//�����󳤶�
	List Heads;//ָ������ͷ�ڵ������ 
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
		p+=2;//��һ������ 
	}
	return p;
}

//������ϣ��
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
	H->Heads=(List)malloc(sizeof(struct LNode)*H->TableSize);//��������ͷ�ڵ�����
	if(H->Heads==NULL)
		printf("out of space");
	//��ʼ����ͷ�ڵ�
	for(i=0;i<H->TableSize;i++)
	{
		//H->Heads[i].Data='\0';//�����򲻴涫����
		H->Heads[i].Next=NULL; 
	}
	return H; 
}

//�������������ϣ����
Index Hash(ElementType key,int TableSize)
{
	return key%TableSize;
}

//����
Position Find(HashTable H,ElementType key)
{
	Position P;
	Index pos;
	pos=Hash(key,H->TableSize);//��ʼɢ��λ��
	P=H->Heads[pos].Next;//�Ӹ�����ĵ�һ���ڵ㿪ʼ
	//��δ��ĩβ����keyδ���ҵ�ʱ
	while(P&&P->Data!=key)	
		P=P->Next;
	return P;//��ʱp����ָ���ҵ��Ľڵ㣬����Ϊnull 
} 

//����
bool Insert(ElementType key,HashTable H)
{
	Position P,NewCell;
	Index pos;
	P=Find(H,key);
	if(!P)//�ؼ���δ�ҵ������Բ��� 
	{
		NewCell=(Position)malloc(sizeof(struct LNode));
		NewCell->Data=key;
		pos=Hash(key,H->TableSize);//��ʼɢ�б��ַ 
		//��NewCell���뵽H->Heads[pos]����ĵ�һ���ڵ�
		NewCell->Next=H->Heads[pos].Next;//���ǽ�NewCellָ��ԭ��H->Heads[pos].nextָ��Ľڵ�
		H->Heads[pos].Next=NewCell;//ָ��ǰ����Ľڵ�NewCell
		return true;	
	}
	else
	{
		printf("�ؼ����Ѵ���\n");
		return false;
	}
} 

//����
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

//��ӡ
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
	printf("������Ҫ����ĸ���:");
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int tmp;
		printf("������Ҫ�������ֵ:");
		scanf("%d",&tmp);//����47,7,29,11,16,92,22,8,3,50,37,89,94,21 
		Insert(tmp,H);
	}
	
	Print(H);
	

}
