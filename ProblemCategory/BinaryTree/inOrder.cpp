class Node{
public:
	Node(int v):data(v),left(NULL),right(NULL){}
	Node(char c) :data(c), left(NULL), right(NULL){}
	int data;
	Node *left;
	Node *right;
};

void InOrder(){
	stack<Node*>s;
	Node*p = root;
	while (p || !s.empty()){
		while (p){//p is the root everytime
			s.push(p);
			p = p->left;
		}
		if (!s.empty()){
			p = s.top(), s.pop();
			cout << char(p->data);
			p = p->right;//p points to the root of the right subtree
		}
	}
}