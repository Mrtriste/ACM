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


//visit the leaf node
void InOrder(){
	stack<Node*>s;
	Node*p = root;
	//int sum=0;
	while (p || !s.empty()){
		while (p){//p is the root everytime
			//sum += p->data;
			s.push(p);
			p = p->left;
			if(p==NULL){//arrive the leaf node
				//sum is the sum of the path
			}
		}
		if (!s.empty()){
			p = s.top(), s.pop();
			//sum -= p->data;
			cout << char(p->data);
			p = p->right;//p points to the root of the right subtree
		}
	}
}