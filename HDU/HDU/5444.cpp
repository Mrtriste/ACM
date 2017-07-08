#include <iostream>
using namespace std;

int n;
int pre[1010], in[1010];

struct Node{
	int data;
	Node *left, *right;
	Node() :data(0), left(NULL), right(NULL){}
};

Node* getRoot(int*preorder, int* inorder, int len){
	if (len == 0)return NULL;
	Node *node = new Node();
	node->data = preorder[0];
	int i = 0;
	for (; i < len; ++i)
		if (inorder[i] == preorder[0])break;
	node->left = getRoot(preorder + 1, inorder, i);
	node->right = getRoot(preorder + 1 + i, inorder + 1 + i, len - i - 1);
	return node;
}

void Find(int q,Node*r){
	if (r==NULL||r->data == q)return;
	if (r->data > q){
		cout << "E";
		Find(q, r->left);
	}
	else{
		cout << "W";
		Find(q, r->right);
	}
}

void Del(Node *node){
	if (node){
		Del(node->left);
		Del(node->right);
		delete node;
	}
}

int main(){
	for (int i = 0; i < 1010; ++i)in[i] = i+1;
	int T; cin >> T;
	while (T--){
		cin >> n;
		for (int i = 0; i < n; ++i)cin >> pre[i];
		Node* root = getRoot(pre, in, n);
		int Q,q; cin >> Q;
		while (Q--){
			cin >> q;
			Find(q,root);
			cout << endl;
		}

	}
}