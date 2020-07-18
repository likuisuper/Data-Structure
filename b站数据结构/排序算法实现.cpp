#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NumSize 20

/*--------------��������ṹ-------------------*/ 
//����Ԫ�������MaxDigit���ؼ��֣�����ȫ��ͬ����Radix 
#define MaxDigit 4
#define Radix 10

//ͰԪ�ؽڵ� 
typedef struct Node *PtrToNode;
struct Node
{
	int key;
	PtrToNode next;
};

//Ͱͷ�ڵ�
typedef struct HeadNode Bucket[Radix];
struct HeadNode
{
	PtrToNode head,tail;
};

/*--------------------------------------------*/
 

typedef int ElementType;

ElementType A[NumSize];

//��������� 
void Random()
{
	//ʹ��randǰ���ó�ʼ����������α��������г�ʼ��
	srand(time(NULL));//ʹ��time(NULL)��Ϊ������ӿ��Ի�ò�ͬ������� 
	int i;
	for(i=0;i<NumSize;i++)
		A[i]=rand()%NumSize+1;//����������������Ҫ������Χֵ��1 
}

//���
void output()
{
	for(int i=0;i<NumSize;i++)
		printf("%d ",A[i]);
	printf("\n");
} 
 
//����
void Swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
} 

//ð������ 
void Bubble_sort(ElementType A[],int N)
{
	for(int p=N-1;p>=0;p--)//�ܹ�n-1�� 
	{
		bool flag=false;//���ñ�ʶλ�����������ѭ���ж� 
		for(int j=0;j<p;j++)//һ��ð�� 
		{
			if(A[j]>A[j+1])
			{
				Swap(A[j],A[j+1]);
				flag=true;//��ʶ�����˽��� 
			}
		}
		if(!flag)
			break;//ȫ���޽���  
	}
}

//ֱ�Ӳ�������
void Insertion_sort(ElementType A[],int N)
{
	for(int p=1;p<N;p++)
	{
		int tmp=A[p];//ȡ��һ���� 
		int j=p;
		for(;tmp<A[j-1]&&j>0;j--)//�ҵ���������ʵ�λ�� 
			A[j]=A[j-1];//�ڳ�λ��(����)
		A[j]=tmp;//�Ѻ��ʴ�С�������� 
	}
} 

//ԭʼϣ������
void Shell_sort(ElementType A[],int N)
{
	for(int D=N/2;D>0;D/=2)
	{
		for(int p=D;p<N;p++)
		{
			int tmp=A[p];
			int i=p; 
			for(;i>=D&&A[i-D]>tmp;i-=D)
				A[i]=A[i-D];
			A[i]=tmp;
		}
	}
}

//Hibbard������������
void Hibbard_shell_sort(ElementType A[],int N)
{
	//�������У�2��k�η�Ȼ��-1 
	int add[]={32767,16383,8191,4095,2047,1023,511,255,127,63,31,15,7,3,1,0};
	int i=0;
	for(int D=add[i];D>0;D=add[++i])
	{
		for(int p=D;p<N;p++)
		{
			int tmp=A[p];
			int i=p;
			for(;i>=D&&tmp<A[i-D];i-=D)
				A[i]=A[i-D];
			A[i]=tmp;
		}
	}
}

//Sedgewick������������
void Sedgewick_shell_sort(ElementType A[],int N)
{
	//�������У�9��4��i�η�-9��2��i�η�  ��  4��i�η�-3��2��i�η�+1 
	int add[]={587521,260609,146305,64769,36289,16001,8929,3905,2161,929,505,209,109,41,19,5,1,0}; 
	int i=0;
	for(int D=add[i];D>0;D=add[++i])
	{
		for(int p=D;p<N;p++)
		{
			long tmp=A[p];
			int i=p;
			for(;i>D&&tmp<A[i-D];i-=D)
				A[i]=A[i-D];
			A[i]=tmp;
		}
	}
} 

//��ѡ������

int ScanForMin(ElementType A[],int i,int N)
{
	int k=i,j;//k������СԪ�ص��±�
	for(j=i+1;j<N;j++)
		if(A[j]<A[k])
			k=j;
	return k; 
}

void Selection_sort(ElementType A[],int N)
{
	for(int i=0;i<N;i++)
	{
		int MinPosition=ScanForMin(A,i,N-1);//��A[i]��A[N-1]������СԪ������λ�ø���MinPosition 
		Swap(A[i],A[MinPosition]);//����Ԫ��λ�� 
	}
		
} 

/*--------------------------- �鲢����ݹ�ʵ��--------------------------------*/ 
//�鲢 
void Merge(ElementType A[],ElementType tmpA[],int L,int R,int RightEnd)
{//�������A[L]��A[R-1]��A[R]��A[RightEnd]�鲢��һ���������� 
	//L�������ʼλ�ã�R���ұ���ʼλ�ã�RightEnd���ұ���ֹλ��
	int LeftEnd=R-1;//����յ�λ��
	int tmp=L;//�������е���ʼλ��
	int NumElements=RightEnd-L+1;//�鲢���������ں��浼�ؽ��
	while(L<=LeftEnd&&R<=RightEnd)
	{
		if(A[L]<=A[R])
			tmpA[tmp++]=A[L++];//�����Ԫ�ظ��Ƶ�tmpA 
		else
			tmpA[tmp++]=A[R++];//���ұ�Ԫ�ظ��Ƶ�tmpA 
	} 
	while(L<=LeftEnd)
		tmpA[tmp++]=A[L++];//ֱ�Ӹ������ʣ�µ�
	while(R<=RightEnd)
		tmpA[tmp++]=A[R++];//ֱ�Ӹ����ұ�ʣ�µ� 
	for(int i=0;i<NumElements;i++,RightEnd--)//��Ϊ��ʱ��ߵ�λ���Ѿ������仯�����Դ��ұ߿�ʼ 
		A[RightEnd]=tmpA[RightEnd];//�������tmpA[]����A[] 
}

//����
void Msort(ElementType A[],ElementType tmpA[],int L,int RightEnd)
{
	int center;
	if(L<RightEnd)//�������Ԫ��
	{
		center=(L+RightEnd)/2;
		Msort(A,tmpA,L,center);//�ݹ������
		Msort(A,tmpA,center+1,RightEnd);//�ݹ����ұ�
		Merge(A,tmpA,L,center+1,RightEnd);//�ϲ������������� 
	} 
}

//�鲢����
void Merge_sort(ElementType A[],int N) 
{
	ElementType *tmpA;//����ָ�룬�����ظ���malloc��free 
	tmpA=(ElementType *)malloc(sizeof(ElementType)*N);
	if(tmpA!=NULL)
	{
		Msort(A,tmpA,0,N-1);
		free(tmpA);//��ʱ����Ŀռ�Ҫ�ͷ� 
	}
	else
		printf("�ռ䲻��");
}
/*--------------------------- �鲢����ݹ����--------------------------------*/


/*--------------------------- �鲢����ǵݹ�ʵ��--------------------------------*/
void Merge1(ElementType A[],ElementType tmpA[],int L,int R,int RightEnd)
{
	int LeftEnd=R-1;
	int tmp=L;
	int NumElements=RightEnd-L+1;
	while(L<=LeftEnd&&R<=RightEnd)
	{
		if(A[L]<A[R])
			tmpA[tmp++]=A[L++];
		else
			tmpA[tmp++]=A[R++];
	}
	while(L<=LeftEnd)
		tmpA[tmp++]=A[L++];
	while(R<=RightEnd)
		tmpA[tmp++]=A[R++];
}

//�����鲢������������
void Merge_pass(ElementType A[],ElementType tmpA[],int N,int Length)//lengthΪ��ǰ�������г���
{
	int i,j;
	for(i=0;i<=N-2*Length;i+=2*Length)//�Ȱ�ż���Թ鲢���ɶԵģ� 
		Merge1(A,tmpA,i,i+Length,i+2*Length-1);//��A�е�Ԫ�ع鲢��tmpA,��������Ԫ����tmpA�� 
	if(i+Length<N)//�鲢�����������
		Merge1(A,tmpA,i,i+Length,N-1);
	else
		for(j=i;j<N;j++)
			tmpA[j]=A[j];//���ֻʣһ�����У����뵽tmpA��	
}

void Merge_sort1(ElementType A[],int N)
{
	int Length=1;//��ʼ���������г���
	ElementType *tmpA;
	tmpA=(ElementType *)malloc(sizeof(ElementType)*N);
	if(tmpA!=NULL)
	{
		while(Length<N)
		{
			Merge_pass(A,tmpA,N,Length);//���ε������һ�˹鲢
			Length*=2;
			Merge_pass(tmpA,A,N,Length);//�ڶ��˽���ʱ�����е����ݵ���A��
			Length*=2; 
		}
	}
	else
		printf("�ռ䲻��"); 
} 

/*--------------------------- �鲢����ǵݹ����--------------------------------*/

//Ͱ����
void Bucket_sort(ElementType A[],int N)
{
	int i,j;
	int count[20];//��Χ���Ͱ�Ͷ���
	for(i=0;i<20;i++)
		count[i]=0;//��ʼ��
	for(i=0;i<N;i++)
		count[A[i]]++;//ÿ��ֵ����Ͱ��
	//�ռ�
	for(i=0;i<N;i++)
		if(count[i]) 
			for(j=0;j<count[i];j++)
				printf("%d ",i);
 } 

/*--------------------------- ���������λ���ȿ�ʼ--------------------------------*/
int GetDigit(int X,int D)//Ĭ�ϴ�λD=1,��λD<=MaxDigit 
{
	int d,i;
	for(i=1;i<=D;i++)
	{
		d=X%Radix;
		X/=Radix;
	}
	return d; 
}

void LSDRadix_sort(ElementType A[],int N)
{
	int D,Di,i;
	Bucket B;
	PtrToNode tmp,p,List=NULL;
	for(i=0;i<Radix;i++)
		B[i].head=B[i].tail=NULL;//��ʼ��ÿ��ͰΪ������
	for(i=0;i<N;i++)//��ԭʼ������������ʼ����List 
	{
		tmp=(PtrToNode)malloc(sizeof(struct Node));
		tmp->key=A[i];
		tmp->next=List;
		List=tmp;//List��Ϊ�������е�ͷ�ڵ� 
	}
	//���濪ʼ����
	for(D=1;D<=MaxDigit;D++)//�����ݵ�ÿһλѭ������ 
	{
		//�����Ƿ���Ĺ���
		p=List;
		while(p)
		{
			Di=GetDigit(p->key,D);//��õ�ǰԪ�صĵ�ǰ���� 
			//��List��ɾ��
			tmp=p;
			p=p->next;
			tmp->next=NULL;
			if(B[Di].head==NULL)
				B[Di].head=B[Di].tail=tmp;//����B[Di]��Ͱβ
			else
			{
				//�����õ���β�巨
				B[Di].tail->next=tmp;//����β�ڵ��ָ��ָ���½ڵ� 
				B[Di].tail=tmp;//����ǰ���½ڵ㶨��Ϊ��β�ڵ� 
			 } 
		} 
		//�������ռ��Ĺ���,����ÿ��Ͱ����˳����������������List,��Ҫ���ŵ�-* 
		List=NULL;//��ʱlistΪ�� 
		for(Di=Radix-1;Di>=0;Di--) 
		{
			if(B[Di].head)//���Ͱ��Ϊ��
			{
				//��Ͱ����List��ͷ
				B[Di].tail->next=List;
				List=B[Di].head;
				B[Di].head=B[Di].tail=NULL;//���Ͱ 
			 } 
		} 
	}
	//��List����A[]���ͷſռ�
	for(i=0;i<N;i++)
	{
		tmp=List;
		List=List->next;
		A[i]=tmp->key;
		free(tmp);
	} 
} 

/*--------------------------- ���������λ���Ƚ���--------------------------------*/

/*--------------------------- ����������λ���ȿ�ʼ--------------------------------*/
void MSD(ElementType A[],int L,int R,int D)//��A[L]...A[R]�ĵ�Dλ���������� 
{
	int Di,i,j;
	Bucket B;
	PtrToNode tmp,p,List=NULL;
	if(D==0)
		return;//�ݹ���ֹ����
	for(i=0;i<Radix;i++)
		B[i].head=B[i].tail=NULL;//��ʼ��ÿ��ͰΪ������
	for(i=L;i<=R;i++) //��ԭʼ������������ʼ����List 
	{
		tmp=(PtrToNode)malloc(sizeof(struct Node));
		tmp->key=A[i];
		tmp->next=List;
		List=tmp;
	}
	//�����Ƿ���Ĺ���
	p=List;
	while(p)
	{
		Di=GetDigit(p->key,D);//��õ�ǰԪ�صĵ�ǰλ����
		//��List��ɾ��
		tmp=p;
		p=p->next;
		//����B[Di]��Ͱ
		if(B[Di].head==NULL)
			B[Di].tail=tmp;//��Ϊ��ͷ�巨�����滹Ҫ�õ�B[Di].head,���Դ�ʱֻдB[Di].tail=tmp 
		tmp->next=B[Di].head;
		B[Di].head=tmp;//ͷ�巨 
	}
	//�������ռ��Ĺ���
	i=j=L;//i,j��¼��ǰҪ�����A[]�����Ҷ��±�
	for(Di=0;Di<Radix;Di++)//����ÿ��Ͱ 
	{
		if(B[Di].head)//���ǿյ�Ͱ����A[],�ݹ����� 
		{
			p=B[Di].head;
			while(p)
			{
				tmp=p;
				p=p->next;
				A[j++]=tmp->key;
				free(tmp);
			}
			//�ݹ�Ը�Ͱ��������λ��-1
			MSD(A,i,j-1,D-1); 
			i=j;//Ϊ��һ��Ͱ��Ӧ��A[]��� 
		}
	 } 
}

void MSDRadix_sort(ElementType A[],int N)
{
	MSD(A,0,N-1,MaxDigit);
}

/*--------------------------- ����������λ���Ƚ���--------------------------------*/

int main()
{
	Random();
	printf("���������:\n");
	output();
	
	//Bubble_sort(A,NumSize);
	//Insertion_sort(A,NumSize);
	//Shell_sort(A,NumSize);
	//Hibbard_shell_sort(A,NumSize);
	//Sedgewick_shell_sort(A,NumSize);
	//Selection_sort(A,NumSize);
	//Merge_sort(A,NumSize);
	//Merge_sort1(A,NumSize);
	//Bucket_sort(A,NumSize);
	//LSDRadix_sort(A,NumSize);
	MSDRadix_sort(A,NumSize);
	printf("��������Ľ��:\n");
	output();
	
	return 0;
} 
