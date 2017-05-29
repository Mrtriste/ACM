#include<iostream>
#include <algorithm>
using namespace std;

struct Node{
	char s[12];
};

Node a[10010];

bool cmp(const Node &a,const Node&b){
	return strcmp(a.s, b.s) < 0;
}

int main(){
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i].s;
		sort(a, a + n, cmp);
		bool flag = false;
		int lena, lenb;
		for (int i = 0; i < n-1; ++i){
			if (flag)break;
			lena = strlen(a[i].s), lenb = strlen(a[i + 1].s);
			if (lena > lenb)continue;
			for (int j = 0; j < lena; ++j){
				if (a[i].s[j] != a[i + 1].s[j])break;
				if (j == lena - 1)flag = true;
			}
		}
		if (flag)cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}