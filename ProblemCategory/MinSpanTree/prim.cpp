//prim算法——最小生成树
//使用优先队列进行了优化
//HDU1233

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node{
	int v, d;
	Node(){}
	Node(int vv, int dd) :v(vv), d(dd){}
	bool operator<(const Node& b)const{
		return d > b.d;
	}
};

int n;
vector<Node> G[110];
bool vis[110];

int BFS(){
	priority_queue<Node> q;
	q.push(Node(1, 0));
	int ans = 0;
	Node cur;
	while (!q.empty()){
		cur = q.top(), q.pop();
		if (vis[cur.v])continue;
		vis[cur.v] = 1;
		ans += cur.d;
		for (int i = 0; i < G[cur.v].size(); ++i){
			int v = G[cur.v][i].v, d = G[cur.v][i].d;
			if (vis[v])continue;
			q.push(Node(v, d));
		}
	}
	return ans;
}

int main(){
	while (cin >> n&&n){
		for (int i = 0; i <= n; ++i)G[i].clear();
		memset(vis, 0, sizeof(vis));
		int a, b, l;
		for (int i = 0; i < (n - 1)*n / 2; ++i){
			scanf("%d%d%d", &a, &b, &l);
			G[a].push_back(Node(b, l));
			G[b].push_back(Node(a, l));
		}

		cout << BFS() << endl;
	}
}