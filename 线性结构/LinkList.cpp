template <class T>
T LinkList<T>::Get(int i) //按位查找 
{
	Node<T> *p=first; int j=0;
	while(p!=NULL&&j<i){
		p=p->next;
		j++;
	}
	if(p==NULL) throw "位置错误";
	else return p->data;
}

template <class T>
int LinkList<T>::Length()
{
	Node<T> *p=first;int j=0;
	while(p->next!=NULL){
		p=p->next;
		j++
	}
	return j;
}

template <class T>
int LinkList<T>::Locate(T x) //按值查找 
{
	Node<T> *p=first->next; int j=1; //从第一个节点开始，则j从1开始 
	while(p!=NULL&&p->data!=x){
		p=p->next;
		j++;
	}
	if(p==NULL) throw "查找失败";
	else return j;
}
template <class T>
void LinkList<T>::


