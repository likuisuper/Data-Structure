#include<stdio.h>
#include<malloc.h>
#define MAXVEX 100 //��󶥵���
#define INFINITY 65535 //��65535�����������

typedef int VertexType;
typedef int EdgeType;

typedef struct
{
	VertexType vex[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexs,numEdges;
}MGraph;

//һ��ѭ������ 
typedef struct Queue
{
	int *pBase;//����ĵ�ַ 
	int front;
	int rear;//ָ���βԪ�ص���һ��λ�� 
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

int visited[MAXVEX];//1��ʾ���ʹ���0��ʾδ���� 
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
			printf("%d",G.vex[i]);//��ӡ���� 
			en_queue(&Q,i);//���˶������
			while(!empty(&Q))//������в�Ϊ��
			{
				out_queue(&Q,&i);//����Ԫ�س���
				for(j=0;j<G.numVertexs;j++)
				{
					if(G.arc[i][j]!=INFINITY&&!visited[j])
					{
						visited[j]=1;//���ҵ��Ĵ˶�����Ϊ�ѷ���
						printf("%d",G.vex[j]);//��ӡ����
						en_queue(&Q,j);//���ҵ��Ĵ˶������						
					}
				} 
			} 
		}
	}	
}

void BFSTraverse(MGraph G)
{
	int i;
	printf("\n������ȱ�����˳��Ϊ:");
	for(i=0;i<G.numVertexs;i++)
	{
		if(visited[i]==0)
			BFS(G,i);
	}
}

//���� 
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
				G->arc[i][j]=INFINITY;	
		} 
	} 
	//��������ͼ�ߵ���Ϣ 
	for(i=0;i<G->numEdges;i++)
	{
		printf("����ߵ�������,�յ����,Ȩֵ:\n");
		scanf("%d %d %d",&v1,&v2,&w);
		G->arc[v1-1][v2-1]=w;
		G->arc[v2-1][v1-1]=w;//��Ϊ������ͼ�����Ծ���Գ�,����ͼ�Ļ�ȥ����һ������	
	} 
}
