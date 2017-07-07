#include <iostream>
#include <algorithm>
using namespace std;

struct Edge{
	int v, next;
};

int head[20010];
Edge edge[40010];
int k,n;
int num[20010];
int mmin, ans;
bool vis[20010];

void addEdge(int u, int v){
	edge[k].v = v;
	edge[k].next = head[u];
	head[u] = k++;
}

void DFS(int r){
	vis[r] = 1;
	int mmax = 0;
	for (int i = head[r]; i != -1; i = edge[i].next){
		int v = edge[i].v;
		if (vis[v])continue;
		DFS(v);
		num[r] += num[v];
		mmax = max(mmax, num[v]);
	}
	mmax = max(mmax, n - num[r]);
	if (mmin > mmax){
		mmin = mmax, ans = r;
	}
}

int main(){
	int T; cin >> T;
	while (T--){
		cin >> n;
		memset(head, -1, sizeof(head));
		memset(vis, 0, sizeof(vis));
		k = 0;
		mmin = 100000000;
		int a, b;
		for (int i = 1; i <= n; ++i)num[i] = 1;
		for (int i = 0; i < n - 1; ++i){
			scanf("%d%d", &a, &b);
			addEdge(a, b);
			addEdge(b, a);
		}
		DFS(1);
		cout << ans << " " << mmin << endl;
	}
}