#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	Node(){}
	Node(int vv, int dd) :v(vv), d(dd){}
	int v;
	int d;
	bool operator<(const Node&b)const{
		return d > b.d;
	}
};

int n, m;
bool vis[2010];
vector<Node> G[2010];
int mmax;

void BFS(){
	Node cur, next;
	priority_queue<Node> q;
	cur.v = 1, cur.d = 0;
	q.push(cur);
	while (!q.empty()){
		cur = q.top(), q.pop();
		if (vis[cur.v])continue;
		vis[cur.v] = 1;
		mmax = max(mmax, cur.d);
		for (int i = 0; i < G[cur.v].size(); ++i){
			int v = G[cur.v][i].v, d = G[cur.v][i].d;
			if (vis[v])continue;
			next.v = v, next.d = d;
			q.push(next);
		}
	}
}

int main(){
	while (cin >> n >> m){
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; ++i)
			G[i].clear();
		int a, b, c;
		for (int i = 0; i < m; ++i){
			cin >> a >> b >> c;
			G[a].push_back(Node(b, c));
			G[b].push_back(Node(a, c));
		}
		mmax = 0;
		BFS();
		cout << mmax << endl;

	}
}