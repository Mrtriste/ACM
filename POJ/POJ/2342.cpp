#include <iostream>
#include <algorithm>
using namespace std;

int par[6005], dp[6005][2];
int n;

void DFS(int r){
	for (int i = 1; i <= n; ++i){
		if (par[i] == r){
			DFS(i);
			dp[r][1] += dp[i][0];
			dp[r][0] += max(dp[i][0], dp[i][1]);
		}
	}
}

int main(){
	while (cin >> n){
		memset(dp, 0, sizeof(dp));
		memset(par, 0, sizeof(par));
		for (int i = 1; i <= n; ++i)
			scanf("%d", &dp[i][1]);
		int p, s,root;
		while (scanf("%d%d", &s, &p) && (p + s))
			par[s] = p;
		for (int i = 1; i <= n; ++i){
			if (!par[i]){
				root = i;
				DFS(i);
				break;
			}
		}
		cout << max(dp[root][0], dp[root][1]) << endl;
	}
}