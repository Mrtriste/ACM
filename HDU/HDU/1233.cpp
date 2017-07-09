#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int u, v, d;
	Node(){}
	Node(int uu, int vv, int dd) :u(uu), v(vv), d(dd){}
	bool operator<(const Node& n){
		return d < n.d;
	}
};

int n;
int par[110];
Node edge[5010];

void Make(){
	for (int i = 1; i <= 110; ++i)
		par[i] = i;
}

int find(int x){
	int root = x, r;
	while (root != par[root])root = par[root];
	while (x != root){
		r = par[x];
		par[x] = root;
		x = r;
	}
	return root;
}

void Union(int x, int y){
	int a = find(x), b = find(y);
	if (a != b)
		par[a] = b;
}

int main(){
	while (cin >> n&&n){
		Make();
		int a, b, l, cnt = 1,ans=0;
		int m = n*(n - 1) / 2;
		for (int i = 0; i < m; ++i){
			scanf("%d%d%d", &a, &b, &l);
			edge[i] = Node(a, b, l);
		}
		sort(edge, edge + m);
		for (int i = 0; i < m; ++i){
			int u = edge[i].u, v = edge[i].v, d = edge[i].d;
			if (find(u) != find(v)){
				Union(u, v);
				ans += d;
				if (++cnt == n)break;
			}
		}
		cout << ans << endl;
	}
}


//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//
//struct Node{
//	int v, d;
//	Node(){}
//	Node(int vv, int dd) :v(vv), d(dd){}
//	bool operator<(const Node& b)const{
//		return d > b.d;
//	}
//};
//
//int n;
//vector<Node> G[110];
//bool vis[110];
//
//int BFS(){
//	priority_queue<Node> q;
//	q.push(Node(1, 0));
//	int ans = 0;
//	Node cur;
//	while (!q.empty()){
//		cur = q.top(), q.pop();
//		if (vis[cur.v])continue;
//		vis[cur.v] = 1;
//		ans += cur.d;
//		for (int i = 0; i < G[cur.v].size(); ++i){
//			int v = G[cur.v][i].v, d = G[cur.v][i].d;
//			if (vis[v])continue;
//			q.push(Node(v, d));
//		}
//	}
//	return ans;
//}
//
//int main(){
//	while (cin >> n&&n){
//		for (int i = 0; i <= n; ++i)G[i].clear();
//		memset(vis, 0, sizeof(vis));
//		int a, b, l;
//		for (int i = 0; i < (n - 1)*n / 2; ++i){
//			scanf("%d%d%d", &a, &b, &l);
//			G[a].push_back(Node(b, l));
//			G[b].push_back(Node(a, l));
//		}
//
//		cout << BFS() << endl;
//	}
//}