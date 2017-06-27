//字典树

#include <iostream>
using namespace std;

struct Node{
	Node(){
		memset(next, NULL, sizeof(next));
		cnt = 0;
	}
	int cnt;
	Node *next[26];
};

void add(Node*root, char *s){
	Node *cur = root;
	for (int i = 0; i < strlen(s); ++i){
		if (cur->next[s[i] - 'a'] == NULL)
			cur->next[s[i]-'a'] = new Node();
		cur->next[s[i] - 'a']->cnt++;
		cur = cur->next[s[i] - 'a'];
	}
}

int search(Node*root, char *s){
	Node *cur = root;
	for (int i = 0; i < strlen(s); ++i){
		if (cur->next[s[i] - 'a'] == NULL)
			return 0;
		else
			cur = cur->next[s[i] - 'a'];
	}
	return cur->cnt;
}

void del(Node *n){
	for (int i = 0; i < 26; ++i)
		if (n->next[i]!=NULL)
			del(n->next[i]);
	delete n;
}



int main(){
	char s[15];
	Node* root = new Node();
	while (gets(s)){
		if (strlen(s)==0)break;
		add(root, s);
	}

	while (cin >> s){
		cout << search(root, s) << endl;
	}
	del(root);
}