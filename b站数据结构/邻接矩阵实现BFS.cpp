#include<stdio.h>
#include<malloc.h>
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

//一个循环队列 
typedef struct Queue
{
	int *pBase;//数组的地址 
	int front;
	int rear;//指向队尾元素的下一个位置 
}QUEUE;

void init(QUEUE *pQ);
bool empty(QUEUE *pQ);
bool en_queue(QUEUE *pQ,int val);
bool out_queue(QUEUE *pQ,int *val);
void BFS(MGraph G,int i);
void BFSTraverse(MGraph G);
void CreatMGraph(MGraph *G);

int main()
{
	MGraph G;
	CreatMGraph(&G);
	BFSTraverse(G);
	return 0;
}

void init(QUEUE *pQ)
{
	pQ->pBase=(int *)malloc(sizeof(int)*20);
	pQ->front=pQ->rear=0; 
}

bool empty(QUEUE *pQ)
{
	if(pQ->front==pQ->rear)
		return true;
	else
		return false;
}

bool en_queue(QUEUE *pQ,int val)
{
	if((pQ->rear+1)%20==pQ->front)
		return false;
	else
	{
		pQ->pBase[pQ->rear]=val;
		pQ->rear=(pQ->rear+1)%20;
		return true;
	}
}

bool out_queue(QUEUE *pQ,int *val)
{
	if(empty(pQ))
		return false;
	else
	{
		*val=pQ->pBase[pQ->front];
		pQ->front=(pQ->front+1)%20;
		return true;
	}
}

int visited[MAXVEX];//1表示访问过，0表示未访问 
void BFS(MGraph G,int i)
{
	int j;
	QUEUE Q;
	for(i=0;i<G.numVertexs;i++)
		visited[MAXVEX]=0;
	
	init(&Q);
	for(i=0;i<G.numVertexs;i++)
	{
		if(!visited[i])
		{
			visited[i]=1;
			printf("%d",G.vex[i]);//打印顶点 
			en_queue(&Q,i);//将此顶点入队
			while(!empty(&Q))//如果队列不为空
			{
				out_queue(&Q,&i);//队中元素出队
				for(j=0;j<G.numVertexs;j++)
				{
					if(G.arc[i][j]!=INFINITY&&!visited[j])
					{
						visited[j]=1;//将找到的此顶点标记为已访问
						printf("%d",G.vex[j]);//打印顶点
						en_queue(&Q,j);//将找到的此顶点入队						
					}
				} 
			} 
		}
	}	
}

void BFSTraverse(MGraph G)
{
	int i;
	printf("\n广度优先遍历的顺序为:");
	for(i=0;i<G.numVertexs;i++)
	{
		if(visited[i]==0)
			BFS(G,i);
	}
}

//测试 
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
