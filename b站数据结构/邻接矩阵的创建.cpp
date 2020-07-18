#include<stdio.h>
#include<malloc.h>

typedef char VertexType;//顶点类型，由用户自己决定
typedef int EdgeType;//边上的权值类型由用户自己决定

#define MAXVEX 100 //最大顶点数
#define INFINITY 65535 //用65535来代替无穷大

typedef struct
{
	VertexType vex[MAXVEX];//顶点表
	EdgeType arc[MAXVEX][MAXVEX];//邻接矩阵（可看作边表）
	int numVertexs,numEdges;//图中当前的顶点数和边数	
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
构造一个图，其实就是给顶点表和边表输入数据的过程 
*/ 
void CreatMGraph(MGraph *G)
{
	int i,j,v1,v2,w;
	printf("输入顶点数和边数:\n");
	scanf("%d%d",&G->numVertexs,&G->numEdges);
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
		printf("输入边的起点序号,终点序号,权值:\n");//起点序号从1开始 
		scanf("%d%d%d",&v1,&v2,&w);
		G->arc[v1-1][v2-1]=w;
		G->arc[v2-1][v1-1]=w;//因为是无向图，所以矩阵对称,有向图的话去掉这一步即可	
	} 
}

void Print(MGraph G)
{
	int i,j;
	printf("\n图的顶点为:");
	for(i=0;i<G.numVertexs;i++)
		printf("%d ",G.vex[i]);
	printf("\n输出邻接矩阵为:\n");
	printf("\t");
	for(i=0;i<G.numVertexs;i++)
		printf("\t%8d",G.vex[i]);
	for(i=0;i<G.numVertexs;i++)
	{
		printf("\n\n%8d",G.vex[i]);
		for(j=0;j<G.numVertexs;j++)
		{
			if(G.arc[i][j]==INFINITY)
				printf("\t%8s","∞");
			else
				printf("\t%8d",G.arc[i][j]); 
		}
		printf("\n");
	}
}
