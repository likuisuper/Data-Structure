#include<stdio.h>
#define MAX 100
#define INFINITY 65535 //��65535�����������

typedef int VertexType;
typedef int EdgeNode;
typedef int Boolean;
Boolean visited[MAX];//���ʱ�־������

typedef struct
{
	VertexType vex[MAX];
	EdgeNode arc[MAX][MAX];
	int numVertexs,numEdges;
}MGraph;

void DFS(MGraph G,int i);//�ڽӾ����������ȵݹ��㷨(�����������������) 
void DFSTraverse(MGraph G);//�ڽӾ������ȱ�������
void CreatMGraph(MGraph *G);
 
int main()
{
	MGraph G;
	CreatMGraph(&G);
	DFSTraverse(G);
	return 0;
} 

void DFS(MGraph G,int i)
{
	int j;
	visited[i]=true;
	printf("%d",G.vex[i]);
	for(j=0;j<G.numVertexs;j++)//��i��ÿ����ӵ�j
		if(G.arc[i][j]!=INFINITY&&!visited[j])
			DFS(G,j);
		
}

void DFSTraverse(MGraph G)
{
	int i;
	printf("\n������ȱ�����˳��Ϊ:");
	for(i=0;i<G.numVertexs;i++)
		visited[i]=false;//��ʼ���ж��㶼��δ����״̬
	for(i=0;i<G.numVertexs;i++)
	{
		if(!visited[i])	
			DFS(G,i);
	} 
}

void CreatMGraph(MGraph *G)
{
	int i,j,v1,v2,w;
	printf("���붥�����ͱ���:\n");
	scanf("%d %d",&G->numVertexs,&G->numEdges);
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
		printf("����ߵ�������,�յ����,Ȩֵ:\n");
		scanf("%d %d %d",&v1,&v2,&w);
		G->arc[v1-1][v2-1]=w;
		G->arc[v2-1][v1-1]=w;//��Ϊ������ͼ�����Ծ���Գ�,����ͼ�Ļ�ȥ����һ������	
	} 
}
