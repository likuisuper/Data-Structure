#include<stdio.h>

//˳����� 
int SeqSearch(int *a,int n,int key)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
			return i+1;//�����߼��±�(�������±��1) 
	}
	return 0;	
}

/*˳����ҵ��Ż�:�����ѭ��ÿ�ζ�Ҫ��i�Ƿ�Խ�磬���Ƿ�<n���ж�
�Ż��������������ڱ� 
*/
int SeqSearch2(int *a,int n,int key)
{
	int i;
	a[0]=key;//����a[0]Ϊ�ؼ��֣���֮Ϊ�ڱ�
	i=n;//ѭ��������β��ʼ
	while(a[i]!=key)
	{
		i--;
	}
	return i; //����0��˵������ʧ�ܣ�a[1]-a[n]��û�йؼ��� 
}

int main()
{
	int a[8]={23,30,40,29,50,69,18,85};
	int m=SeqSearch(a,8,13);
	printf("λ��Ϊ:%d\n",m);
	return 0;
} 
