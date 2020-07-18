#include<stdio.h>
#include<malloc.h>
#include<math.h>

#define MAXTABLESIZE 100000 //���������ٵ����ɢ�г���

typedef int Index;
typedef int ElementType;
typedef Index Position;
typedef enum{
	Legitimate,Empty,Deleted //�ֱ��Ӧ�кϷ�Ԫ�أ��գ�����ɾ��Ԫ�� 
}EntryType;//���嵥Ԫ״̬����

typedef struct HashEntry
{//��ϣ���ֵ��Ԫ 
	ElementType data;//���Ԫ��
	EntryType info;//��Ԫ״̬ 
}Cell;

typedef struct HashTbl
{
	int TabSize;//��ϣ���С
	Cell *Cells;//��ϣ���ֵ��Ԫ���� 
}*HashTable;

int NextPrime(int N);//��������
HashTable CreatTable(int TableSize);//������ϣ��
Index Hash(int key,int TableSize);//�������������ϣ����
Position Find(HashTable H,ElementType key);//ƽ��̽�ⷨ���� 
void Insert(HashTable H,ElementType key);//����Ԫ��
void Print(HashTable H);//��ӡ 

int main()
{
	HashTable H=CreatTable(6);
	Insert(H,7);//λ��Ϊ0 
	Insert(H,8);//λ��Ϊ1 
	Insert(H,9);//λ��Ϊ2 
	Insert(H,19);//λ��Ϊ5 
	Insert(H,15);//λ��Ϊ1,��ʱ��8��ͻ����ͻһ��ʱ��i+-1��ƽ�����г�ͻ����ͻ2��ʱ��
				//i+2��ƽ����19��ͻ����i-2��ƽ��(��λ��Ϊ4)û�г�ͻ 
	Print(H);
	
	printf("\n����Ԫ��Ϊ15��λ��Ϊ:%d\n",Find(H,15));
	return 0;
}

int NextPrime(int N)
{
	int p=(N%2)?N+2:N+1;//���������������������ִ��N+2,����ִ��N+1,���Ӵ���N����һ��������ʼ
	int i;
	while(p<MAXTABLESIZE)
	{
		for(i=(int)sqrt(p);i>2;i--)
			if(!(p%i))//p�������� 
				break;
		if(i==2)
			break;
		p+=2;//������̽�¸�����	
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
	H->TabSize=NextPrime(TableSize);//��֤��ϣ�����󳤶�������
	H->Cells=(Cell *)malloc(sizeof(Cell)*H->TabSize);//��ʼ����Ԫ����
	if(H->Cells==NULL)
		printf("out of space");
	//��ʼ����Ԫ����״̬
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
	int CNum=0;//��¼��ͻ����
	CurrentPos=NewPos=Hash(key,H->TabSize);
	//�����ǰ��Ԫ״̬��Ϊ������ֵ���ȣ���һֱ�� 
	while(H->Cells[NewPos].info!=Empty&&H->Cells[NewPos].data!=key)
	{
		if(++CNum%2)//��ͻ�����η��� 
		{
			//�൱��di+i*i,i=��ͻ����+1/2 
			NewPos=CurrentPos+(CNum+1)/2*(CNum+1)/2;
			//���ѭ���������࣬���Խ�磬��һֱ�����ٴν���߽�
			while(H->TabSize<=NewPos)
				NewPos-=H->TabSize;	
		}
		else//��ͻż���η��� 
		{
			//�൱��di-i*i,i=��ͻ����/2
			NewPos=CurrentPos-CNum/2*CNum/2;
			//���Խ�磬��һֱ�ӵ��ٴν���߽� 
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
	//�����Ԫ��״̬����"���ںϷ�Ԫ��" 
	if(H->Cells[Pos].info!=Legitimate)
	{
		H->Cells[Pos].info=Legitimate;
		H->Cells[Pos].data=key;//�ڴ˲��� 
	}
	else 
		H->Cells[i].data=key;//�����ڳ�ͻ��Ԫ�ز��뵽��ƽ��̽�ⷨ�õ���λ���� 
} 

void Print(HashTable H)
{
	int i;
	for(i=0;i<H->TabSize;i++)
		printf("%d ",H->Cells[i].data);
}
