template <class T>
T LinkList<T>::Get(int i) //��λ���� 
{
	Node<T> *p=first; int j=0;
	while(p!=NULL&&j<i){
		p=p->next;
		j++;
	}
	if(p==NULL) throw "λ�ô���";
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
int LinkList<T>::Locate(T x) //��ֵ���� 
{
	Node<T> *p=first->next; int j=1; //�ӵ�һ���ڵ㿪ʼ����j��1��ʼ 
	while(p!=NULL&&p->data!=x){
		p=p->next;
		j++;
	}
	if(p==NULL) throw "����ʧ��";
	else return j;
}
template <class T>
void LinkList<T>::


