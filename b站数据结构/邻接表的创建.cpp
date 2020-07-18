#include<stdio.h>
#include<malloc.h>
#define MAXVEX 100 

typedef int VertexType;//��������
typedef int EdgeType;//���ϵ�Ȩֵ����(����ͼ���Բ���Ҫ)

//�߱�ڵ� 
typedef struct EdgeNode
{
	int adjvex;//�ڽӵ��򣬴洢�ýڵ��Ӧ���±�
	EdgeType weight;//���ڴ洢Ȩֵ����Ӧ����ͼ���Բ���Ҫ 
	struct EdgeNode *next;//����ָ����һ����� 
}EdgeNode;
 
//�����ڵ� 
typedef struct VertexNode
{
	VertexType data;//�����򣬴洢������Ϣ
	EdgeNode *firstedge;//ָ���һ���ߵ�ָ��(�߱�ͷָ��)  
}VertexNode,AdjList[MAXVEX];//AdjList���ڽӱ����� 

//ͼ�ṹ
typedef struct
{
	AdjList adjlist;
	int numVertexes,numEdges;//ͼ�е�ǰ�������ͱ��� 
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
				printf("��");
				break; 
			}
			printf("%d->",G->adjlist[i].firstedge->adjvex);
			G->adjlist[i].firstedge=G->adjlist[i].firstedge->next;//ָ����� 
		}
		printf("\n");
	}
}



 
