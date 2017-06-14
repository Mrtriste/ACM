#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	int v;
	int d;
	bool operator<(const Node& b)const{
		return d > b.d;
	}
};

bool vis[110];

int main(){
	int n, s, e;
	vector<int> G[110];
	while (cin >> n >> s >> e){
		for (int i = 1; i <= n; ++i)
			G[i].clear();
		int k, t;
		for (int i = 1; i <= n; ++i){
			cin >> k;
			for (int j = 0; j < k; ++j){
				cin >> t;
				G[i].push_back(t);
			}
		}
		memset(vis, 0, sizeof(vis));
		priority_queue<Node> q;
		Node cur, next;
		cur.v = s, cur.d = 0;
		q.push(cur);
		int ans = -1;
		while (!q.empty()){
			cur = q.top(), q.pop();
			if (vis[cur.v])continue;
			vis[cur.v] = 1;
			if (cur.v == e){
				ans = cur.d;
				break;
			}
			for (int i = 0; i < G[cur.v].size(); ++i){
				int v = G[cur.v][i];
				if (vis[v])continue;
				next.v = v;
				next.d = cur.d;
				if (i>0) next.d += 1;
				q.push(next);
			}
		}
		cout << ans << endl;
	}
}