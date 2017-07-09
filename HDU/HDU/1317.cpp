//bellman_ford
#include <iostream>
using namespace std;

struct Edge{
	int u, v;
	Edge(){}
	Edge(int uu, int vv) :u(uu), v(vv){}
};

int n;
Edge edge[10010];
int cnt;
int dis[110], val[110];
bool reach[110][110];

bool bell_ford(){
	dis[1] = 100;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < cnt; ++j){
			int u = edge[j].u, v = edge[j].v;
			int d = val[v];
			if (dis[v] < dis[u] + d&&dis[u] + d>0)dis[v] = dis[u] + d;
		}
	}
	for (int i = 0; i < cnt; ++i){
		int u = edge[i].u, v = edge[i].v;
		int d = val[v];
		if (dis[v] < dis[u] + d&&dis[v]>0&& reach[v][n])return 1;
	}
	return dis[n]>0;
}

int main(){
	while (cin >> n&&n != -1){
		cnt = 0;
		for (int i = 0; i <= n; ++i)dis[i] = -100000000;
		memset(reach, 0, sizeof(reach));
		for (int i = 1; i <= n; ++i){
			int num, b;
			scanf("%d%d", &val[i], &num);
			for (int j = 0; j < num; ++j){
				scanf("%d", &b);
				reach[i][b] = 1;
				edge[cnt++] = Edge(i, b);
			}
		}
		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					if (reach[i][j] || (reach[i][k] && reach[k][j]))reach[i][j] = 1;
		if (!reach[1][n])puts("hopeless");
		else{
			if (bell_ford())puts("winnable");
			else puts("hopeless");
		}

	}
}

//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int n;
//bool reach[110][110];
//vector<int> G[110];
//int dis[110],cnt[110],val[110];
//bool in[110];
//
//bool SPFA(){
//	queue<int> q;
//	q.push(1);
//	dis[1] = 100;
//	int cur;
//	while (!q.empty()){
//		cur = q.front(), q.pop();
//		in[cur] = 0;
//		for (int i = 0; i < G[cur].size(); ++i){
//			int v = G[cur][i];
//			int d = val[v];
//			if (dis[v] < dis[cur] + d){
//				dis[v] = dis[cur] + d;
//				if (!in[v]){
//					q.push(v);
//					in[v] = 1;
//					cnt[v]++;
//					if (cnt[v] >= n)return reach[v][n];
//				}
//			}
//		}
//	}
//	return dis[n]>0;
//}
//
//int main(){
//	while (cin >> n&&n!=-1){
//		memset(reach, 0, sizeof(reach));
//		memset(in, 0, sizeof(in));
//		memset(dis, 0, sizeof(dis));
//		memset(cnt, 0, sizeof(cnt));
//		for (int i = 1; i <= n; ++i)G[i].clear();
//		for (int i = 1; i <= n; ++i){
//			int  num, b;
//			scanf("%d%d", &val[i], &num);
//			for (int j = 0; j < num; ++j){
//				scanf("%d", &b);
//				reach[i][b] = 1;
//				G[i].push_back(b);
//			}
//		}
//		for (int k = 1; k <= n; ++k)
//			for (int i = 1; i <= n; ++i)
//				for (int j = 1; j <= n; ++j)
//					if (reach[i][j] || (reach[i][k] && reach[k][j]))reach[i][j] = 1;
//		if (!reach[1][n])puts("hopeless");
//		else{
//			if (SPFA())puts("winnable");
//			else puts("hopeless");
//		}
//
//	}
//}