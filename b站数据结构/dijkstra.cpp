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
dist[j]用来存放最短路径长度：dist[j]表示源点v到顶点j的最短路径长度
path[]用来存放最短路径：v->j的最短路径 v->u->w->j
则path[j]=w;path[w]=u;path[u]=v 
*/
void Dijkstra(MGraph *G,VertexType v)
{
	int dist[MAXV],path[MAXV];
	int s[MAXV];//初始顶点数组,为1代表已在s中，为0代表没在 
	int mindis,i,j,u;
	for(i=0;i<G->numVertexs;i++)
	{/*dist和path初始化*/ 
		dist[i]=G->arc[v][i];//距离初始化
		s[i]=0;//s[]置空
		if(G->arc[v][i]<INF)//路径初始化 
			path[i]=v;//顶点v到i有边时
		else
			path[i]=-1;//顶点v到i没边时 
	}
	s[v]=1;//源点v放入s中
	for(i=0;i<G->numVertexs;i++)
	{
		mindis=INF;
		for(j=0;j<G->numVertexs;j++)//该循环是找最小路径长度顶点u 
			if(s[j]==0&&dist[j]<mindis)
			{
				u=j;
				mindis=dist[j];
			}
		s[u]=1;//将u加入集合s中
		//调整 
		for(j=0;j<G->numVertexs;j++)//修改不在s中的顶点的距离
			if(s[j]==0)
			{
				if(G->arc[u][j]<INF&&dist[u]+G->arc[u][j]<dist[j])
				{
					dist[j]=dist[u]+G->arc[u][j];
					path[j]=u;
				}	
			} 
		
	}	
	printf("输出最短路径:\n"); 
	Distpath(G,path,v);
}

void Distpath(MGraph *G,int path[MAXV],VertexType v)
{
	int u;
	int k=path[u];
	if(k==-1)
	{
		printf("不存在最短路径\n");
		return;		
	}
	printf("%d",G->vex[u]);
	while(k!=v)
	{
		printf("<--");
		printf("%d",G->vex[k]);
		k=path[k];//逆序推出最短路径 
	}
	printf("-->%d",G->vex[k]);
	
}

void CreatMGraph(MGraph *G)
{
	int i,j,v1,v2,w;
	printf("输入顶点数和边数:\n");
	scanf("%d %d",&G->numVertexs,&G->numEdges);
	//顶点信息存入顶点表 
	for(i=0;i<G->numVertexs;i++)
	{
		printf("请输入第%d个顶点的信息:",i+1); 
		scanf("%d",&G->vex[i]);
	} 
	printf("\n");		
	//邻接矩阵初始化
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
	//输入无向图边的信息 
	for(i=0;i<G->numEdges;i++)
	{
		printf("输入边的起点序号,终点序号,权值:\n");
		scanf("%d %d %d",&v1,&v2,&w);
		G->arc[v1-1][v2-1]=w;
		//G->arc[v2-1][v1-1]=w;//因为是无向图，所以矩阵对称,有向图的话去掉这一步即可	
	} 
}



