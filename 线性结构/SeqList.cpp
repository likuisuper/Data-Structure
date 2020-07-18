template<class T>
SeqList<T>::SeqList()
{
    length=0;//定义表的长度为0，不能定义length	
}

template<class T> 
SeqList<T>::SeqList(T a[],int n) //有参构造函数
{
	if(n>MaxSize) throw"参数非法";
	int i;
	for(i=0;i<0;i++)
	   data[i]=a[i];
	length=n; 
}

template<class T>//按位查找 
T SeqList<T>::Get(int i)
{
    if(i<1||i>length) throw"参数非法"; 
	return data[i-1];	
}

template<class T>//按值查找 
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
void SeqList<T>::Insert(int i,T x) //插入算法 
{
	if(length>=MaxSize) throw "上溢"; 
	if(i<1||i>length+1) throw "位置错误";
	for(j=length;j>=i;j--) //实现平移的下标比逻辑序号小1 
		data[j]=data[j-1];
	data[i-1]=x;
	length++;	
}

template<class T>
T SeqList<T>::Delete(int i) //删除算法 
{
	if(length==0) throw "下溢";
	if(i<1||i>length) throw "位置错误";
	T x=data[i-1];
	for(int j=i-1;j<=length;j++) //向前平移 
		data[j]=data[j+1];
	length--;
	return x;
}
