#include "cstdlib"
struct Node
{
    int data;
    int address;
    Node* prev;
    Node* succ;
    Node(){};
    Node(int d, int a, Node* p, Node* s):data(d),address(a),prev(p),succ(s){};
    Node* insertPrev(int d,int a, Node* p, Node* s);
};

class List
{
private:
    Node* header;
    Node* trailer;
    int _size;
    void init();
public:
    List(){init();};
    ~List();
};

List::List(/* args */)
{
}

List::~List()
{
}
void List::init(){
    header=new Node;
    trailer=new Node;
    _size=0;

    header->prev=NULL;header->succ=trailer;
    trailer->prev=NULL;trailer->succ=NULL;

}
