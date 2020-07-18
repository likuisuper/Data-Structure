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
	LinkList();//�޲ι��캯�� 
	LinkList(T a[],int n); //ǰ�巨���캯�� 
	��LinkList();
	int Length();
	T Get(int i);
	int Locate(T x); 
	void Insert(int i,T x);
	T Delete(int i);
	void PrintList();
private:
	Node<T> *first; 
}
