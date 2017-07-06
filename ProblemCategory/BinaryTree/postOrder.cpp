/*思路：要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点P，先将其入栈。
如果P不存在左孩子和右孩子，则可以直接访问它;
或者P存在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。
若非上述两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候，
左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被访问。*/


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