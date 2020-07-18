#include<stdio.h>
#include<malloc.h>
#define MAXV 100

typedef int VertexType;
typedef int EdgeType;

//边表节点 
typedef struct EdgeNode
{
	int adjvex;//邻接点域
	struct EdgeNode *next;//链域 
}EdgeNode;

//顶点表
typedef struct
{
	VertexType in;//顶点入度 
	VertexType data;//顶点域，存放顶点信息
	EdgeNode *firstedge;//边表头指针 
}VertexNode,AdjList[MAXV];

typedef struct
{
	AdjList adjlist;
 	int numVertexs,numEdges;
}LGraph,*PLGraph;

void CreatLGraph(PLGraph G)
{
	int i,j;
	int vi,vj;//相连接的两个顶点序号
	EdgeNode *s;//边表节点 
	printf("输入顶点数和边数:");
	scanf("%d%d",&G->numVertexs,&G->numEdges); 
	printf("建立顶点表:\n");
	for(i=0;i<G->numVertexs;i++)
	{
		printf("输入第%d个顶点的信息和入度:",i+1);
		scanf("%d %d",&G->adjlist[i].data,&G->adjlist[i].in);//输入顶点信息 
		G->adjlist[i].firstedge=NULL;//将边表置为空表 
	}
	printf("\n打印顶点下标和顶点数据:\n");
	for(i=0;i<G->numVertexs;i++)
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

bool TopSort(PLGraph LG)
{
	EdgeNode *e;
	int i,k,gettop;
	int top=0;//用于指针下标
	int count=0;//用于统计输出顶点的个数
	int *stack;//建栈存储入度为0的顶点
	stack=(int *)malloc(LG->numVertexs*sizeof(int));
	for(i=0;i<LG->numVertexs;i++)
		if(LG->adjlist[i].in==0)
			stack[++top]=i;//将入度为0的顶点入栈
	while(top!=0) 
	{
		gettop=stack[top--];//出栈
		printf("%d->",LG->adjlist[gettop].data);//打印顶点
		count++;//统计输出顶点数
		for(e=LG->adjlist[gettop].firstedge;e;e=e->next)
		{/*对此顶点边表遍历*/
			k=e->adjvex;
			if(!(--LG->adjlist[k].in))//将K号顶点邻接点的入度-1
				stack[++top]=k;//若为0则入栈，以便下次输出 
		} 
	}
	if(count<LG->numVertexs)//如果count小于顶点数，说明存在环 
		return false;
	else
		return true; 
}

int main()
{
	LGraph G;
	CreatLGraph(&G);
	TopSort(&G);
}

