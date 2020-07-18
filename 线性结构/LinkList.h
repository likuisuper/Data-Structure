template <class T>
struct Node
{
	T data;
	Node<T> *next;
};

template <class T>
class LinkList
{
public:
	LinkList();//无参构造函数 
	LinkList(T a[],int n); //前插法构造函数 
	～LinkList();
	int Length();
	T Get(int i);
	int Locate(T x); 
	void Insert(int i,T x);
	T Delete(int i);
	void PrintList();
private:
	Node<T> *first; 
}
