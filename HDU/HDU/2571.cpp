#include <iostream>
#include <algorithm>
using namespace std;

int a[25][1010];
int dp[25][1010];

int main(){
	int T; cin >> T;
	while (T--){
		int n, m; cin >> n >> m;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				cin >> a[i][j];
		for (int i = 1; i <= m; ++i)
			dp[n + 1][i] = -10000;
		for (int i = 1; i <= n; ++i)
			dp[i][m + 1] = -10000;
		
		dp[n][m] = a[n][m];
		for (int i = n; i >= 1; --i){
			for (int j = m; j >= 1; --j){
				dp[i][j] = a[i][j];
				if (i == n&&j == m)continue;
				int t = max(dp[i][j + 1],dp[i+1][j]);
				for (int k = 2; j*k <= m; ++k)
					t = max(t, dp[i][j*k]);
				dp[i][j] += t;
			}

		}
		cout << dp[1][1] << endl;
	}

}