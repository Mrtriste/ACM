class Node{
public:
	Node(int v):data(v),left(NULL),right(NULL){}
	Node(char c) :data(c), left(NULL), right(NULL){}
	int data;
	Node *left;
	Node *right;
};

void PostOrder(){
	stack<Node*>s;
	Node* pre = NULL, *p = NULL;
	s.push(root);
	while (!s.empty()){
		p = s.top();
		if ((p->left == NULL&&p->right == NULL) ||
			(pre != NULL && (pre == p->left || pre == p->right))){
			cout << char(s.top()->data);
			s.pop();
			pre = p;
		}
		else{
			if (p->right)
				s.push(p->right);
			if (p->left)
				s.push(p->left);
		}
	}
}