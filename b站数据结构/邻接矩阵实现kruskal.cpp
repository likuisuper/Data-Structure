#include<stdio.h>

#define MAXEDGE 100

#define MAXVERTEX 100

typedef struct Edge

{

	int begin;//�ߵ����

	int end; //�ߵ��յ�

	int wight;//�ߵ�Ȩֵ

}Edge;

typedef struct Graph

{

	char vertex[MAXVERTEX];//����

	Edge edges[MAXEDGE];//��

	int numvertex,numedges;//����ͱߵĸ���

}MGraph;

void CreateGraph(MGraph* G)

{

	printf("�����붥��ͱߵĸ�����\n");

	scanf("%d%d", &G->numvertex, &G->numedges);

	printf("�����붥�㣺\n");

	getchar();//���øú�����ȥ��һϵ�������������ʱ���ûس���

	for (int i = 0; i < G->numvertex; i++)

	{

		scanf("%c", &G->vertex[i]);

	}

	printf("��Ȩֵ��С��������ߣ�vi,vj����Ӧ�������յ���±꣬begin��end�Լ�Ȩֵwight:\n");

	for (int k = 0; k <G->numedges; k++)

	{

		Edge e;

		scanf("%d%d%d", &e.begin, &e.end, &e.wight);

		G->edges[k] = e;

	}

}

int Find(int *parent, int f)

{

	while (parent[f]>0)

	{

		f = parent[f];

	}

	return f;

}

//��С����������³˹�����㷨

void Kruskal(MGraph *G)

{

	

	int parent[MAXVERTEX];//�����С�������Ķ���

	for (int i = 0; i < G->numvertex; i++)

	{

		parent[i] = i;

	}

	int m, n;

	for (int i = 0; i < G->numedges; i++)

	{

		n = Find(parent, G->edges[i].begin);

		m = Find(parent, G->edges[i].end);

		if (n != m)//m=n˵���л�

		{

			parent[n] = m;

			printf("(%d,%d) %d\t", G->edges[i].begin, G->edges[i].end, G->edges[i].wight);//��ӡ�ߺ�Ȩֵ

		}

	}

}

int main()

{

	MGraph G;

	CreateGraph(&G);

	Kruskal(&G);

	

	return 0; 

}

