#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node5{
	int v;
	int weight;
	Node5(int v, int w) :v(v), weight(w){}
	bool operator<(const Node5&b)const{
		return weight > b.weight;
	}
};

int main1024(){
	int N, M;
	const int maxN = 100 + 10;
	vector<Node5>Graph[maxN];
	bool vis[maxN];
	while (cin >> N >> M){
		if (N == 0)break;
		for (int i = 0; i < maxN; ++i){
			Graph[i].clear();
			vis[i] = false;
		}

		int a, b, c;
		for (int i = 0; i < N; ++i){
			cin >> a >> b >> c;
			Graph[a].push_back(Node5(b, c));
			Graph[b].push_back(Node5(a, c));
		}

		int start = 1;
		priority_queue<Node5> que;
		que.push(Node5(start, 0));
		int dis = 0;
		int cnt = 0;
		while (!que.empty()){
			int u = que.top().v, l = que.top().weight; que.pop();
			if (vis[u])continue;
			vis[u] = true;
			dis += l;
			cnt++;
			for (int i = 0; i < Graph[u].size(); ++i){
				int v = Graph[u][i].v;
				int w = Graph[u][i].weight;
				if (!vis[v])
					que.push(Node5(v, w));

			}
		}
		if (cnt < M)
			cout << "?" << endl;
		else
			cout << dis << endl;

	}
}