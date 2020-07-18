template<class T>
SeqList<T>::SeqList()
{
    length=0;//�����ĳ���Ϊ0�����ܶ���length	
}

template<class T> 
SeqList<T>::SeqList(T a[],int n) //�вι��캯��
{
	if(n>MaxSize) throw"�����Ƿ�";
	int i;
	for(i=0;i<0;i++)
	   data[i]=a[i];
	length=n; 
}

template<class T>//��λ���� 
T SeqList<T>::Get(int i)
{
    if(i<1||i>length) throw"�����Ƿ�"; 
	return data[i-1];	
}

template<class T>//��ֵ���� 
int SeqList<T>::Locate(T x)
{
	for (i=0,i<length,i++)
	if(data[i]==x) return i+1;
	return 0; 
}

template<class T>
int SeqList<T>::GetLength()
{
		
}

template<class T>
void SeqList<T>::Insert(int i,T x) //�����㷨 
{
	if(length>=MaxSize) throw "����"; 
	if(i<1||i>length+1) throw "λ�ô���";
	for(j=length;j>=i;j--) //ʵ��ƽ�Ƶ��±���߼����С1 
		data[j]=data[j-1];
	data[i-1]=x;
	length++;	
}

template<class T>
T SeqList<T>::Delete(int i) //ɾ���㷨 
{
	if(length==0) throw "����";
	if(i<1||i>length) throw "λ�ô���";
	T x=data[i-1];
	for(int j=i-1;j<=length;j++) //��ǰƽ�� 
		data[j]=data[j+1];
	length--;
	return x;
}
