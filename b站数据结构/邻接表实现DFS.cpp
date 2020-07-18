#include<stdio.h>
#include<malloc.h>
#define MAX 100
#define INFINITY 65535 //用65535来代替无穷大

typedef int VertexType;
typedef int EdgeType; 

//边表节点 
typedef struct EdgeNode
{
	int adjvex;//邻接点域，存储该节点对应的下标
	struct EdgeNode *next;//链域，指向下一个结点 
}EdgeNode;
 
//顶点表节点 
typedef struct
{
	VertexType data;//顶点域，存储顶点信息
	EdgeNode *firstedge;//指向第一条边的指针(边表头指针)  
}VertexNode,AdjList[MAX];//AdjList是邻接表类型 

//图结构
typedef struct
{
	AdjList adjlist;
	int numVertexes,numEdges;//图中当前顶点数和边数 
}LGraph;

void DFS(LGraph G,int i);//邻接表的深度优先递归算法
void DFSTraverse(LGraph G);//邻接表的深度遍历操作
void CreatLGraph(LGraph *G);

int main()
{
	LGraph G;
	CreatLGraph(&G);
	
	DFSTraverse(G);
	
	return 0;
}

int visited[MAX];//访问标志的数组
void DFS(LGraph G,int i)
{
	EdgeNode *p; 
	visited[i]=1;
	printf("%d",G.adjlist[i].data);//打印顶点
	p=G.adjlist[i].firstedge;//p指向i的第一条边
	while(!p)
	{
		if(visited[p->adjvex]!=1)
			DFS(G,p->adjvex);
		p=p->next;	
	} 
}

void DFSTraverse(LGraph G)
{
	int i;
	printf("\n深度优先遍历的顺序为:");
	for(i=0;i<G.numVertexes;i++)
		visited[i]=0;//初始所有顶点都是未访问状态
	for(i=0;i<G.numVertexes;i++)
	{
		if(visited[i]!=1)
			DFS(G,i);		
	} 
}

//测试 
void CreatLGraph(LGraph *G)
{
	int i,j;
	int vi,vj;//相连接的两个顶点序号
	EdgeNode *s;//边表节点 
	printf("输入顶点数和边数:");
	scanf("%d%d",&G->numVertexes,&G->numEdges); 
	printf("建立顶点表:\n");
	for(i=0;i<G->numVertexes;i++)
	{
		printf("输入第%d个顶点的信息:",i+1);
		scanf("%d",&G->adjlist[i].data);//输入顶点信息 
		G->adjlist[i].firstedge=NULL;//将边表置为空表 
	}
	printf("\n打印顶点下标和顶点数据:\n");
	for(i=0;i<G->numVertexes;i++)
		printf("顶点下标:%d 顶点数据:%d\n",i,G->adjlist[i].data);
	printf("\n建立边表:\n");
	for(i=0;i<G->numEdges;i++)
	{
		printf("输入相连接的两个顶点下标:");
		scanf("%d%d",&vi,&vj);
		s=(EdgeNode *)malloc(sizeof(EdgeNode));
		s->adjvex=vj;
		//相当于链表中的头插法 
		s->next=G->adjlist[vi].firstedge; 
		G->adjlist[vi].firstedge=s;
		
		s=(EdgeNode *)malloc(sizeof(EdgeNode));
		s->adjvex=vi;
		s->next=G->adjlist[vj].firstedge;
		G->adjlist[vj].firstedge=s;
	} 
}


