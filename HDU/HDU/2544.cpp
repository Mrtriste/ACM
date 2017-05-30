#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node{
	int v;
	int len;
	bool operator<(const Node&a)const{
		return len > a.len;
	}
};

bool vis[110];
int d[110];

int main(){
	int n, m;
	vector<Node> G[110];
	while (cin >> n >> m){
		if (n == 0 & m == 0)break;
		for (int i = 1; i <= n; ++i)
			G[i].clear();
		memset(d, 0x3f, sizeof(d));
		memset(vis, 0, sizeof(vis));
		int a, b, c;
		Node v1, v2;
		for (int i = 1; i <= m; ++i){
			cin >> a >> b >> c;
			v1.v = b, v1.len = c, v2.v = a, v2.len = c;
			G[a].push_back(v1);
			G[b].push_back(v2);
		}
		int start = 1, v, l;
		priority_queue<Node> q;
		d[start] = 0;
		Node temp;
		temp.v = start, temp.len = 0;
		q.push(temp);
		while (!q.empty()){
			v = q.top().v, q.pop();
			if (vis[v])continue;
			vis[v] = true;
			for (int i = 0; i < G[v].size(); ++i){
				int v2 = G[v][i].v, l2 = G[v][i].len;
				if (!vis[v2] && d[v2] > d[v] + l2){
					d[v2] = d[v] + l2;
					
					temp.v = v2, temp.len = d[v2];
					q.push(temp);
				}
			}
		}

		cout << d[n] << endl;

	}
}