#include <iostream>
using namespace std;

struct Node{
	int pro;
	Node *next[26];
	Node(){
		pro = 0;
		memset(next, NULL, sizeof(next));
	}
};

Node* root;
char s[110];
char dict[8][5] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
int maxP;
char temp[110];
char ans[110];

void add(char *a,int p){
	Node *cur = root; char c;
	for (int i = 0; i < strlen(a); ++i){
		c = a[i];
		if (cur->next[c - 'a'] == NULL)
			cur->next[c - 'a'] = new Node();
		cur->next[c - 'a']->pro += p;
		cur = cur->next[c - 'a'];
	}
}

void query(int t,int pos,Node *r){
	int index = s[t] - '2';
	for (int i = 0; i < strlen(dict[index]); ++i){
		if (r->next[dict[index][i] - 'a']==NULL)continue;
		else temp[t] = dict[index][i];
		if (t == pos){
			if (maxP < r->next[dict[index][i] - 'a']->pro){
				maxP = r->next[dict[index][i] - 'a']->pro;
				strcpy(ans, temp);
				ans[pos + 1] = '\0';
			}
		}
		else query(t + 1, pos, r->next[dict[index][i] - 'a']);
	}
}


int main(){
	int T; cin >> T;
	int v = 1;
	while (T--){
		int n; cin >> n;
		char a[110]; int p;
		root = new Node();
		for (int i = 0; i < n; ++i){
			cin >> a >> p;
			add(a, p);
		}
		printf("Scenario #%d:\n", v++);
		int m; cin >> m;
		while (m--){
			scanf("%s", s);
			for (int i = 0; i < strlen(s) - 1; ++i){
				maxP = 0;
				query(0, i, root);
				if (maxP == 0)puts("MANUALLY");
				else puts(ans);
			}
			puts("");
		}
		puts("");
	}
	system("pause");
}