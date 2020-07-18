#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>//����exit()���� 

//������һ���������ͣ����������͵����ֽ�struct Arr,���������ͺ���������Ա 
struct Arr
{
	int * pBase;//�洢��������ĵ�һ��Ԫ�صĵ�ַ
	int len;//�����������ɵ����Ԫ�صĸ���
	int cnt;//��ǰ������ЧԪ�صĸ��� 
	//int increment �Զ��������� 
};

void init_arr(struct Arr * pArr,int length);//��ʼ�� 
bool append_arr(struct Arr * pArr,int val);//׷�� 
bool insert_arr(struct Arr * pArr,int pos,int val);//pos(λ��)��ֵ��1��ʼ 
bool delete_arr(struct Arr * pArr,int pos,int *pVal);//ɾ��Ԫ�� 
int get(struct Arr * pArr);
bool is_empty(struct Arr * pArr);//�ж��Ƿ�Ϊ�� 
bool is_full();//�ж��Ƿ�Ϊ�� 
void sort_arr(struct Arr * pArr);//����(ð��) 
void show_arr(struct Arr * pArr);//��� 
void inversion_arr(struct Arr * pArr); //���� 

int main(void)
{
	struct Arr arr;
	int val;
	
	init_arr(&arr,6);//���ϵ�ַ�����ܸı�arr��ֵ
	
	show_arr(&arr);
	append_arr(&arr,1);
	append_arr(&arr,2);
	append_arr(&arr,3);
	append_arr(&arr,4);
	append_arr(&arr,5);
	//append_arr(&arr,6);
	
	insert_arr(&arr,6,10);
	show_arr(&arr);
	
	if(delete_arr(&arr,6,&val))
	{
		printf("ɾ���ɹ���\n");
		printf("��ɾ����Ԫ����:%d\n",val);
	}
	else
	{
		printf("ɾ��ʧ�ܣ�\n");
	}
/*	append_arr(&arr,7);
	if(append_arr(&arr,8))
	{
		printf("׷�ӳɹ���\n");
	}
	else
	{
		printf("׷��ʧ�ܣ�\n");
	} 

*/
	show_arr(&arr);	
	
	printf("����֮��������ǣ�\n"); 	
	inversion_arr(&arr);
	show_arr(&arr);	
	
	insert_arr(&arr,6,0);
	printf("����֮��������ǣ�\n");
	sort_arr(&arr);
	show_arr(&arr);
	
	//printf("%d",arr.len);
	
	return 0;
}

void init_arr(struct Arr * pArr,int length)
{
	pArr->pBase=(int *)malloc(sizeof(int) * length);
	if(NULL==pArr->pBase)
	{
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);//��ֹ�������� 
	}
	else//��Ϊ�����ʼ�� 
	{
		pArr->len=length;
		pArr->cnt=0;
	}
	return;
}

bool is_empty(struct Arr * pArr)
{
	if(0==pArr->cnt)
		return true;
	else
		return false;
}

bool is_full(struct Arr * pArr)
{
	if(pArr->cnt==pArr->len)
		return true;
	else
		return false;
}
void show_arr(struct Arr * pArr)
{
	if(is_empty(pArr))//�ж������Ƿ�Ϊ��
	{ 
		printf("����Ϊ�գ�\n");
		//��ʾ�û�����Ϊ��
	} 
	else
	{ 
		//���������Ч���� 
		for(int i=0;i<pArr->cnt;++i)
			printf("%d\t",pArr->pBase[i]);//int *
		printf("\n");
	} 
}

bool append_arr(struct Arr * pArr,int val)
{	
	//��ʱ����false 
	if(is_full(pArr))
		return false;
	
	//����ʱ׷��
	pArr->pBase[pArr->cnt]=val;
	(pArr->cnt)++;//������1
	return true; 
}

bool insert_arr(struct Arr * pArr,int pos,int val)
{
	int i;
	if(is_full(pArr))
		return false; 
	if(pos<1||pos>pArr->cnt+1)//��������λ�ò���ȷ���ͷ���false 
		return false;
	for(i=pArr->cnt-1;i>=pos-1;--i)  
	{
		pArr->pBase[i+1]=pArr->pBase[i]; //Ԫ�غ���
	}
	pArr->pBase[pos-1]=val;//��val����pos-1��λ�� 
	pArr->cnt++;//����󳤶ȼ�1(�Ⱥ����ٲ���) 
	return true;
}

bool delete_arr(struct Arr * pArr,int pos,int *pVal)
{
	int i;
	
	if(is_empty(pArr))
		return false;
	if(pos<1||pos>pArr->cnt)
		return false;
	*pVal=pArr->pBase[pos-1];//��ɾ����ǰ�� 
	for(i=pos;i<pArr->cnt;++i)
	{
		pArr->pBase[i-1]=pArr->pBase[i];//Ԫ��ǰ�� 
	}
	pArr->cnt--;//ɾ���󳤶ȼ�1
	return true; 
}

void inversion_arr(struct Arr * pArr)
{
	int i=0;
	int j=pArr->cnt-1;
	int t;
	while(i<j)
	{
		t=pArr->pBase[i];
		pArr->pBase[i]=pArr->pBase[j];
		pArr->pBase[j]=t;
		++i;
		--j;
	}
	return;	
} 

void sort_arr(struct Arr * pArr)
{
	int i,j,t;
	for(i=0;i<pArr->cnt;++i)
	{
		for(j=i+1;j<pArr->cnt;++j)
		{
			if(pArr->pBase[i]>pArr->pBase[j])
			{
				t=pArr->pBase[i];
				pArr->pBase[i]=pArr->pBase[j];
				pArr->pBase[j]=t;
			}
					
		}
	}
}

 
