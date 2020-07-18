#include<stdio.h>
#define MAX 100
#define INFINITY 65535 //用65535来代替无穷大

typedef int VertexType;
typedef int EdgeNode;
typedef int Boolean;
Boolean visited[MAX];//访问标志的数组

typedef struct
{
	VertexType vex[MAX];
	EdgeNode arc[MAX][MAX];
	int numVertexs,numEdges;
}MGraph;

void DFS(MGraph G,int i);//邻接矩阵的深度优先递归算法(类似于树的先序遍历) 
void DFSTraverse(MGraph G);//邻接矩阵的深度遍历操作
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
	for(j=0;j<G.numVertexs;j++)//对i的每个领接点j
		if(G.arc[i][j]!=INFINITY&&!visited[j])
			DFS(G,j);
		
}

void DFSTraverse(MGraph G)
{
	int i;
	printf("\n深度优先遍历的顺序为:");
	for(i=0;i<G.numVertexs;i++)
		visited[i]=false;//初始所有顶点都是未访问状态
	for(i=0;i<G.numVertexs;i++)
	{
		if(!visited[i])	
			DFS(G,i);
	} 
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
				G->arc[i][j]=INFINITY;	
		} 
	} 
	//输入无向图边的信息 
	for(i=0;i<G->numEdges;i++)
	{
		printf("输入边的起点序号,终点序号,权值:\n");
		scanf("%d %d %d",&v1,&v2,&w);
		G->arc[v1-1][v2-1]=w;
		G->arc[v2-1][v1-1]=w;//因为是无向图，所以矩阵对称,有向图的话去掉这一步即可	
	} 
}
