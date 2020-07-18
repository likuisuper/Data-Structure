#include<stdio.h>
#include<malloc.h>
#define MAXVEX 100 

typedef int VertexType;//顶点类型
typedef int EdgeType;//边上的权值类型(非网图可以不需要)

//边表节点 
typedef struct EdgeNode
{
	int adjvex;//邻接点域，存储该节点对应的下标
	EdgeType weight;//用于存储权值，对应非网图可以不需要 
	struct EdgeNode *next;//链域，指向下一个结点 
}EdgeNode;
 
//顶点表节点 
typedef struct VertexNode
{
	VertexType data;//顶点域，存储顶点信息
	EdgeNode *firstedge;//指向第一条边的指针(边表头指针)  
}VertexNode,AdjList[MAXVEX];//AdjList是邻接表类型 

//图结构
typedef struct
{
	AdjList adjlist;
	int numVertexes,numEdges;//图中当前顶点数和边数 
}LGraph; 

void CreatLGraph(LGraph *G);
void Print(LGraph *G);

int main()
{
	LGraph G;
	
	CreatLGraph(&G);
	Print(&G);
	return 0;
}

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

void Print(LGraph *G)
{
	int i,j;
	for(i=0;i<G->numVertexes;i++)
	{
		printf("%d->",i);
		while(1)
		{
			if(G->adjlist[i].firstedge==NULL)
			{
				printf("∧");
				break; 
			}
			printf("%d->",G->adjlist[i].firstedge->adjvex);
			G->adjlist[i].firstedge=G->adjlist[i].firstedge->next;//指针后移 
		}
		printf("\n");
	}
}



 
