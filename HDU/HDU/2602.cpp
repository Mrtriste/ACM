#include <iostream>
#include <algorithm>
using namespace std;

int c[1010];
int v[1010];
int dp[1010];
int n, V;

int main(){
	int T; cin >> T;
	while (T--){
		cin >> n >> V;
		for (int i = 1; i <= n; ++i)
			cin >> v[i];
		for (int i = 1; i <= n; ++i)
			cin >> c[i];
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; ++i){
			for (int j = V; j >= c[i]; --j)
				dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
		}
		cout << dp[V] << endl;
	}
}