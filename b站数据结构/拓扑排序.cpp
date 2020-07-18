#include<stdio.h>
#include<malloc.h>
#define MAXV 100

typedef int VertexType;
typedef int EdgeType;

//�߱�ڵ� 
typedef struct EdgeNode
{
	int adjvex;//�ڽӵ���
	struct EdgeNode *next;//���� 
}EdgeNode;

//�����
typedef struct
{
	VertexType in;//������� 
	VertexType data;//�����򣬴�Ŷ�����Ϣ
	EdgeNode *firstedge;//�߱�ͷָ�� 
}VertexNode,AdjList[MAXV];

typedef struct
{
	AdjList adjlist;
 	int numVertexs,numEdges;
}LGraph,*PLGraph;

void CreatLGraph(PLGraph G)
{
	int i,j;
	int vi,vj;//�����ӵ������������
	EdgeNode *s;//�߱�ڵ� 
	printf("���붥�����ͱ���:");
	scanf("%d%d",&G->numVertexs,&G->numEdges); 
	printf("���������:\n");
	for(i=0;i<G->numVertexs;i++)
	{
		printf("�����%d���������Ϣ�����:",i+1);
		scanf("%d %d",&G->adjlist[i].data,&G->adjlist[i].in);//���붥����Ϣ 
		G->adjlist[i].firstedge=NULL;//���߱���Ϊ�ձ� 
	}
	printf("\n��ӡ�����±�Ͷ�������:\n");
	for(i=0;i<G->numVertexs;i++)
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

bool TopSort(PLGraph LG)
{
	EdgeNode *e;
	int i,k,gettop;
	int top=0;//����ָ���±�
	int count=0;//����ͳ���������ĸ���
	int *stack;//��ջ�洢���Ϊ0�Ķ���
	stack=(int *)malloc(LG->numVertexs*sizeof(int));
	for(i=0;i<LG->numVertexs;i++)
		if(LG->adjlist[i].in==0)
			stack[++top]=i;//�����Ϊ0�Ķ�����ջ
	while(top!=0) 
	{
		gettop=stack[top--];//��ջ
		printf("%d->",LG->adjlist[gettop].data);//��ӡ����
		count++;//ͳ�����������
		for(e=LG->adjlist[gettop].firstedge;e;e=e->next)
		{/*�Դ˶���߱����*/
			k=e->adjvex;
			if(!(--LG->adjlist[k].in))//��K�Ŷ����ڽӵ�����-1
				stack[++top]=k;//��Ϊ0����ջ���Ա��´���� 
		} 
	}
	if(count<LG->numVertexs)//���countС�ڶ�������˵�����ڻ� 
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

