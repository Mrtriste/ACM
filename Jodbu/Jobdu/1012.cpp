#include <iostream>
#include <cstring>
using namespace std;

const int maxN1012 = 1010;
int pre[maxN1012];

void makeSet(){
	for (int i = 0; i < maxN1012; ++i)
		pre[i] = i;
}

int find(int x){
	int root = x, t;
	while (root != pre[root])root = pre[root];
	while (x != root){
		t = pre[x];
		pre[x] = root;
		x = t;
	}
	return root;
}

void Union(int x, int y){
	int a = find(x), b = find(y);
	if (a != b)
		pre[a] = pre[b];
}

int main1012(){
	int N, M;
	bool vis[maxN1012];
	while (cin >> N >> M){
		if (N == 0)break;
		makeSet();
		memset(vis, false, sizeof(vis));
		int x, y;
		for (int i = 0; i < M; ++i){
			cin >> x >> y;
			Union(x, y);
		}
		for (int i = 1; i <= N; ++i)
			vis[find(i)] = true;
		int cnt = 0;
		for (int i = 1; i <= N; ++i)
			if (vis[i])++cnt;
		cout << cnt - 1 << endl;
	}
	return 0;
}