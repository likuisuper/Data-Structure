#include<stdio.h>
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

/*prim�㷨������С������*/
void MST_Prim(MGraph G)
{
	int min,i,j,k;//min��Ϊ��֮���ҵ�һ����Χ�ڵ���СȨֵ,j�������������±�ѭ���ı���
				  //k�������洢��СȨֵ�Ķ����±� 
	int adjvex[MAXVEX];//������ض����±�
	int lowcost[MAXVEX];//������ض����ߵ�Ȩֵ
	int totalWeight=0;//Ȩ��ֵ��ʼΪ0 
 	lowcost[0]=0;//��ʼ����һ��ȨֵΪ0,��v0����������,lowcostֵΪ0,���Ǵ˶�����±��Ѿ�����������
	adjvex[0]=0;//��ʼ����һ�������±�Ϊ0
	/*��ʼ��*/ 
	for(i=1;i<G.numVertexs;i++)//ѭ�����±�Ϊ0���ȫ������ 
	{
		lowcost[i]=G.arc[0][i];//��vo������֮�бߵ�Ȩֵ��������
		adjvex[i]=0;//��ʼ����Ϊvo���±�
	}
	/*����������С���Ĳ���*/
	for(i=1;i<G.numVertexs;i++)
	{
		min=INFINITY;//��ʼ����СȨֵ
		j=1;
		k=0;
		/*�ҵ�v0������֮�бߵ���СȨֵ���Լ���СȨֵ�Ķ����±�*/
		while(j<G.numVertexs)
		{
			if(lowcost[j]!=0&&lowcost[j]<min)//!=0��ʾ�ö��㻹û�мӵ�����
			{
				min=lowcost[j];
				k=j;	
			}
			j++;				
		}
		totalWeight+=min;
		printf("(%d,%d)",adjvex[k],k);//��ӡ��ǰ�������Ȩֵ��С��(�����ʱΪ(0,1)) 		
		lowcost[k]=0;//����ǰ�����Ȩֵ��Ϊ0����ʾ�ö������������
		/*���ѭ����Ϊ�˵���һ���㣬Ȼ�󽫸ö�����֮�бߵ�Ȩֵ����һ���õ���lowcost�Ƚϴ�С*/
		for(j=1;j<G.numVertexs;j++)
		{
			if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j]) 
			{/*���±�Ϊk�������ȨֵС�ڴ�ǰ��Щ����δ������������ʱ��Ȩֵ*/
				lowcost[j]=G.arc[k][j];//����СȨֵ����lowcost
				adjvex[j]=k;//���±�Ϊk�Ķ������adjvex 
			}
		} 
	}
	printf("\nȨֵΪ:%d",totalWeight);
}



