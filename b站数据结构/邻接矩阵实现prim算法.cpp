#include<stdio.h>
#define MAXVEX 100 //最大顶点数 
#define INFINITY 65535 //用65535来代替无穷大

typedef int VertexType;
typedef int EdgeType;

typedef struct
{
	VertexType vex[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexs,numEdges;	
}MGraph;

void CreatMGraph(MGraph *G);
void MST_Prim(MGraph G);

int main()
{
	MGraph G;
	CreatMGraph(&G);
	MST_Prim(G);
	return 0;
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

/*prim算法生成最小生成树*/
void MST_Prim(MGraph G)
{
	int min,i,j,k;//min是为了之后找到一定范围内的最小权值,j是用来做顶点下标循环的变量
				  //k是用来存储最小权值的顶点下标 
	int adjvex[MAXVEX];//保存相关顶点下标
	int lowcost[MAXVEX];//保存相关顶点间边的权值
	int totalWeight=0;//权重值初始为0 
 	lowcost[0]=0;//初始化第一个权值为0,即v0加入生成树,lowcost值为0,就是此顶点的下标已经加入生成树
	adjvex[0]=0;//初始化第一个顶点下标为0
	/*初始化*/ 
	for(i=1;i<G.numVertexs;i++)//循环除下标为0外的全部顶点 
	{
		lowcost[i]=G.arc[0][i];//将vo顶点与之有边的权值存入数组
		adjvex[i]=0;//初始化都为vo的下标
	}
	/*真正生成最小树的部分*/
	for(i=1;i<G.numVertexs;i++)
	{
		min=INFINITY;//初始化最小权值
		j=1;
		k=0;
		/*找到v0顶点与之有边的最小权值，以及最小权值的顶点下标*/
		while(j<G.numVertexs)
		{
			if(lowcost[j]!=0&&lowcost[j]<min)//!=0表示该顶点还没有加到树里
			{
				min=lowcost[j];
				k=j;	
			}
			j++;				
		}
		totalWeight+=min;
		printf("(%d,%d)",adjvex[k],k);//打印当前顶点边中权值最小边(比如此时为(0,1)) 		
		lowcost[k]=0;//将当前顶点的权值设为0，表示该顶点已完成任务
		/*这个循环是为了到下一顶点，然后将该顶点与之有边的权值与上一步得到的lowcost比较大小*/
		for(j=1;j<G.numVertexs;j++)
		{
			if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j]) 
			{/*若下标为k顶点各边权值小于此前这些顶点未被加入生成树时的权值*/
				lowcost[j]=G.arc[k][j];//将较小权值存入lowcost
				adjvex[j]=k;//将下标为k的顶点存入adjvex 
			}
		} 
	}
	printf("\n权值为:%d",totalWeight);
}



