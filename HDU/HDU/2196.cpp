#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
	int v, w;
	Node(){}
	Node(int vv, int ww) :v(vv), w(ww){}
};

vector<Node> G[10010];
int n;
int dp[10010][3];//0:maxSon 1:SecSon 2:maxPar

void DFS(int r){
	int mmax = 0, sec = 0;
	for (int i = 0; i < G[r].size(); ++i){
		int v = G[r][i].v, w = G[r][i].w;
		DFS(v);
		int temp = dp[v][0] + w;
		if (temp > mmax)
			sec = mmax, mmax = temp;
		else if (temp == mmax || temp > sec)
			sec = temp;
	}
	dp[r][0] = mmax, dp[r][1] = sec;
}

void DFS1(int r){
	for (int i = 0; i < G[r].size(); ++i){
		int v = G[r][i].v, w = G[r][i].w;
		if (dp[v][0] + w == dp[r][0])
			dp[v][2] = max(dp[r][1],dp[r][2]) + w;
		else dp[v][2] = max(dp[r][0], dp[r][2]) + w;
		DFS1(v);
	}
}

int main(){
	while (cin >> n){
		for (int i = 1; i <= n; ++i)
			G[i].clear();
		int p, w;
		for (int i = 2; i <= n; ++i){
			scanf("%d%d", &p, &w);
			G[p].push_back(Node(i, w));
		}
		memset(dp, 0, sizeof(dp));
		DFS(1);
		DFS1(1);
		for (int i = 1; i <= n; ++i)
			cout << max(dp[i][0], dp[i][2]) << endl;
	}
}

