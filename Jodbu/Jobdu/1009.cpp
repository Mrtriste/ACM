#include <iostream>
#include <string>
using namespace std;

struct Node3{
	Node3 *left;
	Node3 *right;
	int val;
	Node3(int v) :val(v), left(NULL), right(NULL){}
};

void insert(Node3* &root,int x){//!!!!!!!指针的引用 对指针赋值 而不是对指针里的内容 所以要对指针引用
	Node3* cur = root, *par = NULL;
	if (root == NULL){
		root = new Node3(x);
		return;
	}
	while (cur){
		if (x < cur->val){
			par = cur;
			cur = cur->left;
		}
		else if (x > cur->val){
			par = cur;
			cur = cur->right;
		}
		else
			return;
	}
	if (x > par->val)
		par->right = new Node3(x);
	else
		par->left = new Node3(x);
}

bool isEqual(Node3*node1, Node3*node2){
	if (node1 == NULL&&node2 == NULL){
		return true;
	}
		
	if ((node1 == NULL&&node2 != NULL) ||
		(node1 != NULL&&node2 == NULL))
		return false;
	if (node1->val == node2->val){
		return (isEqual(node1->left, node2->left) && isEqual(node1->right, node2->right));
	}
		
	else
		return false;
}

void destroy(Node3* root){
	if (root){
		destroy(root->left);
		destroy(root->right);
		delete root;
	}
}

int main1009(){
	int n;
	string s1;
	string s2;
	while (cin >> n){
		cin >> s1;
		Node3 *root1 = NULL;
		for (int i = 0; i < s1.length(); ++i)
			insert(root1, s1[i] - '0');

		for (int i = 0; i < n; ++i){
			Node3*root2=NULL;
			cin >> s2;
			for (int j = 0; j < s2.length(); ++j)
				insert(root2, s2[j] - '0');
			if (isEqual(root1, root2))
				cout << "YES" << endl;
			else cout << "NO" << endl;
			destroy(root2);
		}
		destroy(root1);
			
	}
	return 0;
}