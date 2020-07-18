#include<stdio.h>
#include<malloc.h>
#define MAX 100
#define INFINITY 65535 //��65535�����������

typedef int VertexType;
typedef int EdgeType; 

//�߱�ڵ� 
typedef struct EdgeNode
{
	int adjvex;//�ڽӵ��򣬴洢�ýڵ��Ӧ���±�
	struct EdgeNode *next;//����ָ����һ����� 
}EdgeNode;
 
//�����ڵ� 
typedef struct
{
	VertexType data;//�����򣬴洢������Ϣ
	EdgeNode *firstedge;//ָ���һ���ߵ�ָ��(�߱�ͷָ��)  
}VertexNode,AdjList[MAX];//AdjList���ڽӱ����� 

//ͼ�ṹ
typedef struct
{
	AdjList adjlist;
	int numVertexes,numEdges;//ͼ�е�ǰ�������ͱ��� 
}LGraph;

void DFS(LGraph G,int i);//�ڽӱ��������ȵݹ��㷨
void DFSTraverse(LGraph G);//�ڽӱ����ȱ�������
void CreatLGraph(LGraph *G);

int main()
{
	LGraph G;
	CreatLGraph(&G);
	
	DFSTraverse(G);
	
	return 0;
}

int visited[MAX];//���ʱ�־������
void DFS(LGraph G,int i)
{
	EdgeNode *p; 
	visited[i]=1;
	printf("%d",G.adjlist[i].data);//��ӡ����
	p=G.adjlist[i].firstedge;//pָ��i�ĵ�һ����
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
	printf("\n������ȱ�����˳��Ϊ:");
	for(i=0;i<G.numVertexes;i++)
		visited[i]=0;//��ʼ���ж��㶼��δ����״̬
	for(i=0;i<G.numVertexes;i++)
	{
		if(visited[i]!=1)
			DFS(G,i);		
	} 
}

//���� 
void CreatLGraph(LGraph *G)
{
	int i,j;
	int vi,vj;//�����ӵ������������
	EdgeNode *s;//�߱�ڵ� 
	printf("���붥�����ͱ���:");
	scanf("%d%d",&G->numVertexes,&G->numEdges); 
	printf("���������:\n");
	for(i=0;i<G->numVertexes;i++)
	{
		printf("�����%d���������Ϣ:",i+1);
		scanf("%d",&G->adjlist[i].data);//���붥����Ϣ 
		G->adjlist[i].firstedge=NULL;//���߱���Ϊ�ձ� 
	}
	printf("\n��ӡ�����±�Ͷ�������:\n");
	for(i=0;i<G->numVertexes;i++)
		printf("�����±�:%d ��������:%d\n",i,G->adjlist[i].data);
	printf("\n�����߱�:\n");
	for(i=0;i<G->numEdges;i++)
	{
		printf("���������ӵ����������±�:");
		scanf("%d%d",&vi,&vj);
		s=(EdgeNode *)malloc(sizeof(EdgeNode));
		s->adjvex=vj;
		//�൱�������е�ͷ�巨 
		s->next=G->adjlist[vi].firstedge; 
		G->adjlist[vi].firstedge=s;
		
		s=(EdgeNode *)malloc(sizeof(EdgeNode));
		s->adjvex=vi;
		s->next=G->adjlist[vj].firstedge;
		G->adjlist[vj].firstedge=s;
	} 
}


