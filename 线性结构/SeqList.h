const int MaxSize=100
template<class T>
class SeqList
{
 pulice:
 	SeqList();
 	SeqList(T a[],int n);
	int GetLength();
	T Get(int i);
	int Locate(T x);
	void Insert(int i,T x);
	T Delete(int i);
private:
    T data[MaxSize];
	int length; 
};
