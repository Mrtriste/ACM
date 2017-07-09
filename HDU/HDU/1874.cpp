//SPFA
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	int v, d;
	Node(){}
	Node(int vv, int dd) :v(vv), d(dd){}
};

vector<Node> G[210];
int dis[210];
int s, e;
bool in[210];

int SPFA(){
	queue<int> q;
	q.push(s);
	in[s] = 1, dis[s] = 0;
	int cur;
	while (!q.empty()){
		cur = q.front(), q.pop();
		in[cur] = 0;
		for (int i = 0; i < G[cur].size(); ++i){
			int v = G[cur][i].v, d = G[cur][i].d;
			if (dis[v]>dis[cur] + d){
				dis[v] = dis[cur] + d;
				if (!in[v]){
					in[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return -1;
}

int main(){
	int n, m;
	while (cin >> n >> m){
		for (int i = 0; i < n; ++i)G[i].clear();
		memset(dis, 0x3f, sizeof(dis));
		memset(in, 0, sizeof(in));
		int a, b, l;
		for (int i = 0; i < m; ++i){
			scanf("%d%d%d", &a, &b, &l);
			G[a].push_back(Node(b, l));
			G[b].push_back(Node(a, l));
		}
		cin >> s >> e;
		SPFA();
		if (dis[e] < 0x3f3f3f3f)cout << dis[e] << endl;
		else cout << -1 << endl;
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
//vector<Node> G[210];
//bool vis[210];
//
//int n, m,s,e;
//
//int BFS(){
//	priority_queue<Node> q;
//	q.push(Node(s, 0));
//	Node cur;
//	while (!q.empty()){
//		cur = q.top(), q.pop();
//		if (cur.v == e)return cur.d;
//		if (vis[cur.v])continue;
//		vis[cur.v] = 1;
//		for (int i = 0; i < G[cur.v].size(); ++i){
//			int v = G[cur.v][i].v, d = G[cur.v][i].d;
//			if (vis[v])continue;
//			q.push(Node(v, cur.d + d));
//		}
//	}
//
//	return -1;
//}
//
//int main(){
//	while (cin >> n >> m){
//		for (int i = 0; i < n; ++i)G[i].clear();
//		memset(vis, 0, sizeof(vis));
//		int a, b, l;
//		for (int i = 0; i < m; ++i){
//			scanf("%d%d%d", &a, &b, &l);
//			G[a].push_back(Node(b, l));
//			G[b].push_back(Node(a, l));
//		}
//		cin >> s >> e;
//		cout << BFS() << endl;
//	}
//}