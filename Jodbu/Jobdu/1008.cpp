#include <iostream>
#include <queue>
using namespace std;

struct Node2{
	int v;
	int weight;
	int cost;
	Node2(int v, int w, int c) :v(v), weight(w), cost(c){}
	bool operator<(const Node2& node)const{
		if (weight > node.weight)
			return true;
		if (weight == node.weight&&cost > node.cost)
			return true;
		return false;
	}
};

int main1008(){
	const int maxN = 1010;
	int n, m;
	vector<Node2> Graph[maxN];
	int dis[maxN];
	int cost[maxN];
	bool vis[maxN];
	while (cin >> n >> m){
		if (n == 0 && m == 0)break;
		for (int i = 0; i <= n; ++i){
			Graph[i].clear();
			cost[i]=dis[i] = 200000000;
			vis[i] = false;
		}
			
		int a, b, d, p;
		for (int i = 0; i < m; ++i){
			cin >> a >> b >> d >> p;
			Graph[a].push_back(Node2(b, d, p));
			Graph[b].push_back(Node2(a, d, p));
		}

		priority_queue<Node2> que;
		int s, t;
		cin >> s >> t;
		dis[s] = 0;
		cost[s] = 0;
		que.push(Node2(s,0,0));
		while (!que.empty()){
			int v = que.top().v; que.pop();
			if (vis[v])continue;
			vis[v] = true;
			for (int i = 0; i < Graph[v].size(); ++i){
				
				int v2 = Graph[v][i].v;
				int w = Graph[v][i].weight;
				int c = Graph[v][i].cost;
				if (vis[v2] == false){
					
					if (dis[v2]>dis[v] + w){
						dis[v2] = dis[v] + w;
						cost[v2] = cost[v] + c;
						que.push(Node2(v2, dis[v2], cost[v2]));
					}
					if ((dis[v2] == (dis[v] + w)) && (cost[v2] > cost[v] + c)){
						cost[v2] = cost[v] + c;
						que.push(Node2(v2, dis[v2], cost[v2]));
					}
				}
			}
		}

		cout << dis[t] << " " << cost[t] << endl;
	}
	return 0;
}