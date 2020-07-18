#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NumSize 20

/*--------------基数排序结构-------------------*/ 
//假设元素最多有MaxDigit个关键字，基数全是同样的Radix 
#define MaxDigit 4
#define Radix 10

//桶元素节点 
typedef struct Node *PtrToNode;
struct Node
{
	int key;
	PtrToNode next;
};

//桶头节点
typedef struct HeadNode Bucket[Radix];
struct HeadNode
{
	PtrToNode head,tail;
};

/*--------------------------------------------*/
 

typedef int ElementType;

ElementType A[NumSize];

//生成随机数 
void Random()
{
	//使用rand前需用初始化函数进行伪随机数序列初始化
	srand(time(NULL));//使用time(NULL)作为随机种子可以获得不同的随机数 
	int i;
	for(i=0;i<NumSize;i++)
		A[i]=rand()%NumSize+1;//求余运算符后的数字要比需求范围值大1 
}

//输出
void output()
{
	for(int i=0;i<NumSize;i++)
		printf("%d ",A[i]);
	printf("\n");
} 
 
//交换
void Swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
} 

//冒泡排序 
void Bubble_sort(ElementType A[],int N)
{
	for(int p=N-1;p>=0;p--)//总共n-1趟 
	{
		bool flag=false;//设置标识位避免无意义的循环判断 
		for(int j=0;j<p;j++)//一趟冒泡 
		{
			if(A[j]>A[j+1])
			{
				Swap(A[j],A[j+1]);
				flag=true;//标识发生了交换 
			}
		}
		if(!flag)
			break;//全程无交换  
	}
}

//直接插入排序
void Insertion_sort(ElementType A[],int N)
{
	for(int p=1;p<N;p++)
	{
		int tmp=A[p];//取出一个数 
		int j=p;
		for(;tmp<A[j-1]&&j>0;j--)//找到这个数合适的位置 
			A[j]=A[j-1];//腾出位置(后移)
		A[j]=tmp;//把合适大小的数放入 
	}
} 

//原始希尔排序
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

//Hibbard增量序列排序
void Hibbard_shell_sort(ElementType A[],int N)
{
	//增量序列：2的k次方然后-1 
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

//Sedgewick增量序列排序
void Sedgewick_shell_sort(ElementType A[],int N)
{
	//增量序列：9×4的i次方-9×2的i次方  或  4的i次方-3×2的i次方+1 
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

//简单选择排序

int ScanForMin(ElementType A[],int i,int N)
{
	int k=i,j;//k保存最小元素的下标
	for(j=i+1;j<N;j++)
		if(A[j]<A[k])
			k=j;
	return k; 
}

void Selection_sort(ElementType A[],int N)
{
	for(int i=0;i<N;i++)
	{
		int MinPosition=ScanForMin(A,i,N-1);//从A[i]到A[N-1]中找最小元，将其位置赋给MinPosition 
		Swap(A[i],A[MinPosition]);//交换元素位置 
	}
		
} 

/*--------------------------- 归并排序递归实现--------------------------------*/ 
//归并 
void Merge(ElementType A[],ElementType tmpA[],int L,int R,int RightEnd)
{//将有序的A[L]到A[R-1]和A[R]到A[RightEnd]归并成一个有序序列 
	//L是左边起始位置，R是右边起始位置，RightEnd是右边终止位置
	int LeftEnd=R-1;//左边终点位置
	int tmp=L;//有序序列的起始位置
	int NumElements=RightEnd-L+1;//归并个数，用于后面导回结果
	while(L<=LeftEnd&&R<=RightEnd)
	{
		if(A[L]<=A[R])
			tmpA[tmp++]=A[L++];//将左边元素复制到tmpA 
		else
			tmpA[tmp++]=A[R++];//将右边元素复制到tmpA 
	} 
	while(L<=LeftEnd)
		tmpA[tmp++]=A[L++];//直接复制左边剩下的
	while(R<=RightEnd)
		tmpA[tmp++]=A[R++];//直接复制右边剩下的 
	for(int i=0;i<NumElements;i++,RightEnd--)//因为此时左边的位置已经发生变化，所以从右边开始 
		A[RightEnd]=tmpA[RightEnd];//将有序的tmpA[]返回A[] 
}

//分治
void Msort(ElementType A[],ElementType tmpA[],int L,int RightEnd)
{
	int center;
	if(L<RightEnd)//如果还有元素
	{
		center=(L+RightEnd)/2;
		Msort(A,tmpA,L,center);//递归解决左边
		Msort(A,tmpA,center+1,RightEnd);//递归解决右边
		Merge(A,tmpA,L,center+1,RightEnd);//合并两段有序序列 
	} 
}

//归并排序
void Merge_sort(ElementType A[],int N) 
{
	ElementType *tmpA;//传进指针，避免重复的malloc和free 
	tmpA=(ElementType *)malloc(sizeof(ElementType)*N);
	if(tmpA!=NULL)
	{
		Msort(A,tmpA,0,N-1);
		free(tmpA);//临时申请的空间要释放 
	}
	else
		printf("空间不足");
}
/*--------------------------- 归并排序递归结束--------------------------------*/


/*--------------------------- 归并排序非递归实现--------------------------------*/
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

//两两归并相邻有序子列
void Merge_pass(ElementType A[],ElementType tmpA[],int N,int Length)//length为当前有序子列长度
{
	int i,j;
	for(i=0;i<=N-2*Length;i+=2*Length)//先把偶数对归并（成对的） 
		Merge1(A,tmpA,i,i+Length,i+2*Length-1);//将A中的元素归并到tmpA,最后有序的元素在tmpA中 
	if(i+Length<N)//归并最后两个子列
		Merge1(A,tmpA,i,i+Length,N-1);
	else
		for(j=i;j<N;j++)
			tmpA[j]=A[j];//最后只剩一个子列，加入到tmpA中	
}

void Merge_sort1(ElementType A[],int N)
{
	int Length=1;//初始化有序子列长度
	ElementType *tmpA;
	tmpA=(ElementType *)malloc(sizeof(ElementType)*N);
	if(tmpA!=NULL)
	{
		while(Length<N)
		{
			Merge_pass(A,tmpA,N,Length);//初次调用完成一趟归并
			Length*=2;
			Merge_pass(tmpA,A,N,Length);//第二趟将临时数组中的数据导回A中
			Length*=2; 
		}
	}
	else
		printf("空间不足"); 
} 

/*--------------------------- 归并排序非递归结束--------------------------------*/

//桶排序
void Bucket_sort(ElementType A[],int N)
{
	int i,j;
	int count[20];//范围多大桶就多少
	for(i=0;i<20;i++)
		count[i]=0;//初始化
	for(i=0;i<N;i++)
		count[A[i]]++;//每个值倒入桶中
	//收集
	for(i=0;i<N;i++)
		if(count[i]) 
			for(j=0;j<count[i];j++)
				printf("%d ",i);
 } 

/*--------------------------- 基数排序次位优先开始--------------------------------*/
int GetDigit(int X,int D)//默认次位D=1,主位D<=MaxDigit 
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
		B[i].head=B[i].tail=NULL;//初始化每个桶为空链表
	for(i=0;i<N;i++)//将原始序列逆序存入初始链表List 
	{
		tmp=(PtrToNode)malloc(sizeof(struct Node));
		tmp->key=A[i];
		tmp->next=List;
		List=tmp;//List即为链表序列的头节点 
	}
	//下面开始排序
	for(D=1;D<=MaxDigit;D++)//对数据的每一位循环处理 
	{
		//下面是分配的过程
		p=List;
		while(p)
		{
			Di=GetDigit(p->key,D);//获得当前元素的当前数字 
			//从List中删除
			tmp=p;
			p=p->next;
			tmp->next=NULL;
			if(B[Di].head==NULL)
				B[Di].head=B[Di].tail=tmp;//插入B[Di]号桶尾
			else
			{
				//这里用的是尾插法
				B[Di].tail->next=tmp;//将表尾节点的指针指向新节点 
				B[Di].tail=tmp;//将当前的新节点定义为表尾节点 
			 } 
		} 
		//下面是收集的过程,即将每条桶链表顺序连接起来，倒回List,需要逆着倒-* 
		List=NULL;//此时list为空 
		for(Di=Radix-1;Di>=0;Di--) 
		{
			if(B[Di].head)//如果桶不为空
			{
				//整桶插入List表头
				B[Di].tail->next=List;
				List=B[Di].head;
				B[Di].head=B[Di].tail=NULL;//清空桶 
			 } 
		} 
	}
	//将List倒入A[]并释放空间
	for(i=0;i<N;i++)
	{
		tmp=List;
		List=List->next;
		A[i]=tmp->key;
		free(tmp);
	} 
} 

/*--------------------------- 基数排序次位优先结束--------------------------------*/

/*--------------------------- 基数排序主位优先开始--------------------------------*/
void MSD(ElementType A[],int L,int R,int D)//对A[L]...A[R]的第D位数进行排序 
{
	int Di,i,j;
	Bucket B;
	PtrToNode tmp,p,List=NULL;
	if(D==0)
		return;//递归终止条件
	for(i=0;i<Radix;i++)
		B[i].head=B[i].tail=NULL;//初始化每个桶为空链表
	for(i=L;i<=R;i++) //将原始序列逆序存入初始链表List 
	{
		tmp=(PtrToNode)malloc(sizeof(struct Node));
		tmp->key=A[i];
		tmp->next=List;
		List=tmp;
	}
	//下面是分配的过程
	p=List;
	while(p)
	{
		Di=GetDigit(p->key,D);//获得当前元素的当前位数字
		//从List中删除
		tmp=p;
		p=p->next;
		//插入B[Di]号桶
		if(B[Di].head==NULL)
			B[Di].tail=tmp;//因为是头插法，下面还要用到B[Di].head,所以此时只写B[Di].tail=tmp 
		tmp->next=B[Di].head;
		B[Di].head=tmp;//头插法 
	}
	//下面是收集的过程
	i=j=L;//i,j记录当前要处理的A[]的左右端下标
	for(Di=0;Di<Radix;Di++)//对于每个桶 
	{
		if(B[Di].head)//将非空的桶倒入A[],递归排序 
		{
			p=B[Di].head;
			while(p)
			{
				tmp=p;
				p=p->next;
				A[j++]=tmp->key;
				free(tmp);
			}
			//递归对该桶数据排序，位数-1
			MSD(A,i,j-1,D-1); 
			i=j;//为下一个桶对应的A[]左端 
		}
	 } 
}

void MSDRadix_sort(ElementType A[],int N)
{
	MSD(A,0,N-1,MaxDigit);
}

/*--------------------------- 基数排序主位优先结束--------------------------------*/

int main()
{
	Random();
	printf("生成随机数:\n");
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
	printf("基数排序的结果:\n");
	output();
	
	return 0;
} 
