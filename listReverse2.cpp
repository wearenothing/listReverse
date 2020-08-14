#include <cstdlib>
#include <iostream>	
#include <iomanip>
using namespace std;
struct Node {
	int data;
	int address;
	Node* succ;
	Node() {};
	Node(int d, int a,Node* s) :data(d), address(a),succ(s) {};
	Node* insertSucc(int d, int a);
};

class List {
private:
	int _size;
	
public:
	Node* header;
	Node* trailer;
	List();
	void reverse(int k);
	void printer() const;
};
List::List() {
	header = new Node;
	trailer = new Node;
	header->succ = trailer;
	trailer->succ = NULL;
	_size = 0;
}
Node* reversek(Node* head, int k) {
	if (k < 2)
		return NULL;
	Node* tail = head;
	for (int i = 0; i <= k; i++)
		if (!(tail = tail->succ))
			return NULL;
	Node* prev = head->succ;
	Node* cur = prev->succ;
	while (cur!=tail)
	{
		prev->succ = cur->succ;
		cur->succ = prev;
		head->succ = cur;
		cur = prev->succ;
	}
	return prev;
}
void List::reverse(int k)
{
	Node* f = header;
	while (f = (reversek(f, k)));
}

Node * Node::insertSucc(int d, int a)
{
	Node* x = new Node(d, a, succ);
	succ = x;
	return x;
}



void List::printer() const
{
	
	Node* p = header;
	while ((p = p->succ)!=trailer) {
		
		cout << setfill('0') << setw(5) << p->address << " ";
		cout << p->data << " ";
		if (p->succ != trailer)
			cout << setfill('0') << setw(5) << (p->succ)->address << endl;
		else
			cout << -1 << endl;
	}
}
int main() {
	int Data[100000];
	int Next[100000];
	int begin;
	int N;
	int k;
	cin >> begin >> N >> k;
	while (0 < N--)
	{
		int cur;
		cin >> cur;
		cin >> Data[cur] >> Next[cur];
	}
	List L;
	int q = begin;
	Node* p = L.header;
	p=p->insertSucc(Data[q], q);
	while ((q = Next[q]) >= 0)
		p=p->insertSucc(Data[q], q);
	L.reverse(k);
	L.printer();

	return 0;
}
