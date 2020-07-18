#include<stdio.h>

#define MaxSize 20

typedef struct
{
	int Data;//��ֵ
	int parent;//ָ�򸸽ڵ� 
}SetType;

//����
int Find(SetType S[],int x)
{
	int i;
	//�ҵ������и�ֵ��Ӧ���±� 
	for(i=0;i<MaxSize&&S[i].Data!=x;i++);
	if(i>=MaxSize)//���û���ҵ�������-1 
		return -1;
	//�ҵ��ýڵ�ĸ��ڵ��±� 
	for( ;S[i].parent>=0;i=S[i].parent);
	return i;//���ظ��ڵ��������е��±� 
} 

//��
void Union(SetType S[],int x1,int x2)
{
	int root1=Find(S,x1);//�ҵ�x1�ĸ��ڵ��±�
	int root2=Find(S,x2);//�ҵ�x2�ĸ��ڵ��±�
	//������ڵ���±겻ͬ��˵������һ������
	if(root1!=root2)
		S[root2].parent=root1;//��x2�ҵ�x1�ļ���	
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
