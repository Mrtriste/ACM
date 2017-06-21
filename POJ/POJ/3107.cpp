#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 50010;

struct Edge{
	int v, next;
};

int head[maxN];//head[i]表示节点i连接的第一条边的下标是head[i],接下来edge.next是下一条边的下标，edge.v是i连的点
Edge edge[2*maxN];
int n,k=0,mmin=10000000;
int num[maxN], dp[maxN];
bool vis[maxN];

void addEdge(int u, int v){
	edge[k].v = v;
	edge[k].next = head[u];
	head[u] = k++;
}

void DFS(int r){
	vis[r] = 1;
	int maxSon = 0;
	for (int i = head[r]; i != -1; i = edge[i].next){
		int v = edge[i].v;
		if (vis[v])continue;
		DFS(v);
		maxSon = max(maxSon, num[v]);
		num[r] += num[v];
	}
	maxSon = max(maxSon, n - num[r]);
	dp[r] = maxSon;
	mmin = min(mmin, maxSon);
}

int main(){
	cin >> n;
	memset(vis, 0, sizeof(vis));
	memset(head, -1, sizeof(head));
	int u, v;
	for (int i = 1; i <= n; ++i)num[i] = 1;
	for (int i = 0; i < n - 1; ++i){
		scanf("%d%d", &u, &v);
		addEdge(u, v);
		addEdge(v, u);
	}
	DFS(1);
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		if (dp[i] == mmin)num[cnt++] = i;
	cout << num[0];
	for (int i = 1; i < cnt; ++i)
		cout << " " << num[i];
	cout << endl;
	system("pause");
}

