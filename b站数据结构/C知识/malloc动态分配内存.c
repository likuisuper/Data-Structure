#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int a[5]={4,10,2,8,6};
	
	int len;
	printf("����������Ҫ���������ĳ���:len=");
	scanf("%d",&len);
	int * pArr=(int *)malloc(sizeof(int) *len);
	//*pArr=4;//������a[0]=4
	//pArr[1]=10;//������a[1]=10
	//printf("%d %d",*pArr,pArr[1]);
	
	int i;
	for(i=0;i<len;++i)
		scanf("%d",&pArr[i]);
				
	for(i=0;i<len;++i)
		printf("%d\n",*(pArr+i));
	
	free(pArr);//��pArr������Ķ�̬�����20���ֽڵ��ڴ��ͷ�
	
	return 0; 
}
