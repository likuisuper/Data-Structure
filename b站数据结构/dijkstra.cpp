#include<stdio.h>
#define INF 65535
#define MAXV 100

typedef int VertexType;
typedef int EdgeType;
typedef struct
{
	VertexType vex[MAXV];
	EdgeType arc[MAXV][MAXV];
	int numVertexs,numEdges;
}MGraph;

void Dijkstra(MGraph *G,VertexType v);
void Distpath(MGraph *G,int path[MAXV],VertexType v);
void CreatMGraph(MGraph *G);

int main()
{
	MGraph G;
	CreatMGraph(&G);
	Dijkstra(&G,0);
}

/*
dist[j]����������·�����ȣ�dist[j]��ʾԴ��v������j�����·������
path[]����������·����v->j�����·�� v->u->w->j
��path[j]=w;path[w]=u;path[u]=v 
*/
void Dijkstra(MGraph *G,VertexType v)
{
	int dist[MAXV],path[MAXV];
	int s[MAXV];//��ʼ��������,Ϊ1��������s�У�Ϊ0����û�� 
	int mindis,i,j,u;
	for(i=0;i<G->numVertexs;i++)
	{/*dist��path��ʼ��*/ 
		dist[i]=G->arc[v][i];//�����ʼ��
		s[i]=0;//s[]�ÿ�
		if(G->arc[v][i]<INF)//·����ʼ�� 
			path[i]=v;//����v��i�б�ʱ
		else
			path[i]=-1;//����v��iû��ʱ 
	}
	s[v]=1;//Դ��v����s��
	for(i=0;i<G->numVertexs;i++)
	{
		mindis=INF;
		for(j=0;j<G->numVertexs;j++)//��ѭ��������С·�����ȶ���u 
			if(s[j]==0&&dist[j]<mindis)
			{
				u=j;
				mindis=dist[j];
			}
		s[u]=1;//��u���뼯��s��
		//���� 
		for(j=0;j<G->numVertexs;j++)//�޸Ĳ���s�еĶ���ľ���
			if(s[j]==0)
			{
				if(G->arc[u][j]<INF&&dist[u]+G->arc[u][j]<dist[j])
				{
					dist[j]=dist[u]+G->arc[u][j];
					path[j]=u;
				}	
			} 
		
	}	
	printf("������·��:\n"); 
	Distpath(G,path,v);
}

void Distpath(MGraph *G,int path[MAXV],VertexType v)
{
	int u;
	int k=path[u];
	if(k==-1)
	{
		printf("���������·��\n");
		return;		
	}
	printf("%d",G->vex[u]);
	while(k!=v)
	{
		printf("<--");
		printf("%d",G->vex[k]);
		k=path[k];//�����Ƴ����·�� 
	}
	printf("-->%d",G->vex[k]);
	
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
				G->arc[i][j]=INF;	
		} 
	} 
	//��������ͼ�ߵ���Ϣ 
	for(i=0;i<G->numEdges;i++)
	{
		printf("����ߵ�������,�յ����,Ȩֵ:\n");
		scanf("%d %d %d",&v1,&v2,&w);
		G->arc[v1-1][v2-1]=w;
		//G->arc[v2-1][v1-1]=w;//��Ϊ������ͼ�����Ծ���Գ�,����ͼ�Ļ�ȥ����һ������	
	} 
}



