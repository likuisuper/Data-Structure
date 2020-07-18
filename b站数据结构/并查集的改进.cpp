#include<stdio.h>
#define MaxN 1000 //�������Ԫ�ظ���

typedef int ElementType;//Ĭ��Ԫ�ؿ����÷Ǹ�������ʾ
typedef int SetName;//Ĭ���ø��ڵ���±���Ϊ��������
typedef ElementType SetType[MaxN];//���輯���±��0��ʼ��S[0]Ҳ����һ����(�ڵ�),�Ͳ�����Ҫ������ 


/*--------------------------------���ȹ鲢(��Union�ĸĽ�)----------------------------*/
/*
1.�����ĸ߶�:�������������ϣ����ĸ߶ȴ����S[Root]=-1�����壬��S[Root]=-���� 
*/
void Union1(SetType S,ElementType Root1,ElementType Root2)
{/*����Ĭ��Root1��Root2�ǲ�ͬ���ϵĸ��ڵ�*/
	if(S[Root2]<S[Root1])//��Ϊ�����Ǹ�����ʾ������A>B�൱��-A<-B
		S[Root1]=Root2;//��Root1������ϲ��뵽Root2
	else
	{
		if(S[Root1]==S[Root2])
			S[Root1]--;//��������ȸߣ�������++
		S[Root2]=Root1;	
	} 	
}

/*
2.�����Ĺ�ģ:��С�����������ϣ����һ�����Ĺ�ģ=����֮�ͣ�S[Root]=-Ԫ�ظ���
��·��ѹ����ϸ����� 
*/

void Union2(SetType S,ElementType Root1,ElementType Root2)
{
	if(S[Root2]<S[Root1])
	{
		S[Root2]+=S[Root1];
		S[Root1]=Root2;	
	}
	else
	{
		S[Root1]+=S[Root2];
		S[Root2]=Root1;
	}
}

/*--------------------------------·��ѹ��(��Find�ĸĽ�)----------------------------*/
SetName Find(SetType S,ElementType x)
{/*Ĭ�ϼ���Ԫ��ȫ����ʼ��Ϊ-1*/
	if(S[x]<0)
		return x;
	else
		return S[x]=Find(S,S[x]);
		/*�ⲽ���������£�1.���ҵ��� 2.�Ѹ����X�ĸ��ڵ� 3.�ٷ��ظ�
		����һ��α�ݹ飬�ǳ�����ת����ѭ�������Ա������Զ�ת��Ϊ��ѭ��*/
}

int main()
{
	SetType S;
	S[0]=4;
	S[1]=-6;
	S[2]=4;
	S[3]=1;
	S[4]=3;
	S[5]=2;
	
	S[6]=-3;
	S[7]=6;
	S[8]=6;
	int l=Find(S,5);
	int m=Find(S,8);
	printf("5�ĸ��ڵ���±�Ϊ:%d\n",l); 
	printf("8�ĸ��ڵ���±�Ϊ:%d\n",m);
	Union2(S,1,6);
	int n=Find(S,8);
	printf("�ϲ�֮��8�ĸ��ڵ���±�Ϊ:%d\n",n);
	return 0;
}
