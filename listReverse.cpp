#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

struct Node
{
	int data;
	int address;
	Node* prev;
	Node* succ;
	Node() {};
	Node(int d, int a=0, Node* p=NULL, Node* s=NULL) :data(d), address(a), prev(p), succ(s) {};
	Node* insertPrev(int d, int a);
};
void swap(int& a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
Node* reverse_K(Node* f, int k) {
	Node* tail = f;
	int size = k;
	while (0 < k--)
		if (!(tail = tail->succ))
			return NULL;
	Node* oldtail = tail;
	Node* head = f->prev;
	for (int i = 1; i < size; i += 2)
	{
		swap((head = head->succ)->data, (tail = tail->prev)->data);
		swap(head->address, tail->address);
	}
	return oldtail;
}
class List
{
private:
	Node* header;
	Node* trailer;
	int _size;
	void init();
public:
	List() { init(); };
	List(int* arr, int n);
	Node* insertAsLast(int d, int a=0);
	Node* first() const;
	Node* last() const;
	void reverse(int k);
	void printer() const;
};

void List::init() {
	header = new Node;
	trailer = new Node;
	_size = 0;

	header->prev = NULL; header->succ = trailer;
	trailer->prev = header; trailer->succ = NULL;

}

List::List(int * arr, int n)
{
	init();
	for (int i = 0; i < n; i++) {
		insertAsLast(arr[i]);
	}
}

Node * List::insertAsLast(int d, int a)
{
	_size++;
	return trailer->insertPrev(d, a);
}

Node * List::first() const
{
	return header->succ;
}

Node * List::last() const
{
	return trailer->prev;
}

void List::reverse(int k)
{
	Node* f = first();
	while ((f = reverse_K(f, k)));
}

void List::printer() const
{
	int n = _size;
	Node* p = header;
	while (0 < n--) {
		p = p->succ;
		cout << setfill('0') << setw(5) << p->address << " ";
		cout << p->data << " ";
		if (p->succ != trailer)
			cout << setfill('0') << setw(5) << (p->succ)->address << endl;
		else
			cout << -1 << endl;
	}
}

Node * Node::insertPrev(int d, int a)
{
	Node* x = new Node(d, a, prev, this);
	prev->succ = x;
	prev = x;
	return x;
}


int main() {
	/*int arr[] = { 1,2,3,4,5,6 };
	int size = sizeof(arr) / sizeof(int);
	List list(arr,size);
	list.reverse(0);
	list.printer();*/
	int Data[100000];
	int Next[100000];
	int begin;
	int N;
	int k;
	cin >> begin >> N >> k;
	while (0<N--)
	{
		int cur;
		cin >> cur;
		cin >> Data[cur] >> Next[cur];
	}
	List L;
	int q = begin;
	L.insertAsLast(Data[q], q);
	while ((q = Next[q])>=0)
		L.insertAsLast(Data[q], q);
	L.reverse(k);
	L.printer();
	return 0;
}
