#include<stdio.h>
#include<malloc.h>

typedef char VertexType;//�������ͣ����û��Լ�����
typedef int EdgeType;//���ϵ�Ȩֵ�������û��Լ�����

#define MAXVEX 100 //��󶥵���
#define INFINITY 65535 //��65535�����������

typedef struct
{
	VertexType vex[MAXVEX];//�����
	EdgeType arc[MAXVEX][MAXVEX];//�ڽӾ��󣨿ɿ����߱�
	int numVertexs,numEdges;//ͼ�е�ǰ�Ķ������ͱ���	
}MGraph;

void CreatMGraph(MGraph *G);
void Print(MGraph G);

int main()
{
	MGraph G;
	
	CreatMGraph(&G);
	
	Print(G);
	
	return 0;
} 

/*
����һ��ͼ����ʵ���Ǹ������ͱ߱��������ݵĹ��� 
*/ 
void CreatMGraph(MGraph *G)
{
	int i,j,v1,v2,w;
	printf("���붥�����ͱ���:\n");
	scanf("%d%d",&G->numVertexs,&G->numEdges);
	//������Ϣ���붥��� 
	for(i=0;i<G->numVertexs;i++)
	{
		printf("�������%d���������Ϣ:",i+1); 
		scanf("%d",&G->vex[i]);
	} 
	printf("\n");		
	//�ڽӾ����ʼ��
	for(i=0;i<G->numVertexs;i++)
	{
		for(j=0;j<G->numVertexs;j++)
		{
			if(i==j)
				G->arc[i][j]=0;
			else
				G->arc[i][j]=INFINITY;	
		} 
	} 
	//��������ͼ�ߵ���Ϣ 
	for(i=0;i<G->numEdges;i++)
	{
		printf("����ߵ�������,�յ����,Ȩֵ:\n");//�����Ŵ�1��ʼ 
		scanf("%d%d%d",&v1,&v2,&w);
		G->arc[v1-1][v2-1]=w;
		G->arc[v2-1][v1-1]=w;//��Ϊ������ͼ�����Ծ���Գ�,����ͼ�Ļ�ȥ����һ������	
	} 
}

void Print(MGraph G)
{
	int i,j;
	printf("\nͼ�Ķ���Ϊ:");
	for(i=0;i<G.numVertexs;i++)
		printf("%d ",G.vex[i]);
	printf("\n����ڽӾ���Ϊ:\n");
	printf("\t");
	for(i=0;i<G.numVertexs;i++)
		printf("\t%8d",G.vex[i]);
	for(i=0;i<G.numVertexs;i++)
	{
		printf("\n\n%8d",G.vex[i]);
		for(j=0;j<G.numVertexs;j++)
		{
			if(G.arc[i][j]==INFINITY)
				printf("\t%8s","��");
			else
				printf("\t%8d",G.arc[i][j]); 
		}
		printf("\n");
	}
}
