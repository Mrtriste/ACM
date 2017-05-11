#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node1{
	int v;
	int weight;
	Node1(int v, int w) :v(v), weight(w){}
	bool operator<(const Node1&node)const{
		return weight > node.weight;
	}
};

int main1017(){
	const int maxN = 102;
	int N;
	vector<Node1> Graph[maxN];
	bool vis[maxN];
	while (cin >> N){
		if (N == 0)break;
		for (int i = 0; i < maxN; ++i){
			Graph[i].clear();
			vis[i] = false;
		}
			
		int a, b, c;
		for (int i = 0; i < N*(N - 1) / 2; ++i){
			cin >> a >> b >> c;
			Graph[a].push_back(Node1(b, c));
			Graph[b].push_back(Node1(a, c));
		}
		priority_queue<Node1> que;
		int start = 1;
		que.push(Node1(start, 0));
		int dis = 0;
		while (!que.empty()){
			int u = que.top().v, l = que.top().weight; que.pop();
			if (vis[u])continue;
			vis[u] = true;
			dis += l;
			for (int i = 0; i < Graph[u].size(); ++i){
				int v = Graph[u][i].v;
				int w = Graph[u][i].weight;
				if (!vis[v]){
					que.push(Node1(v, w));
				}
			}
		}
		cout << dis << endl;
	}
	return 0;
}