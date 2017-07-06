class Node{
public:
	Node(int v):data(v),left(NULL),right(NULL){}
	Node(char c) :data(c), left(NULL), right(NULL){}
	int data;
	Node *left;
	Node *right;
};

void PreOrder(){
	stack<Node*> s;
	Node*p = root;
	while (p||!s.empty()){
		//每次p达到一个叶节点
		while (p){
			cout << (char)p->data;
			s.push(p);
			p = p->left;
		}
		if (!s.empty()){
			p = s.top(),s.pop();
			p = p->right;
		}
	}
}