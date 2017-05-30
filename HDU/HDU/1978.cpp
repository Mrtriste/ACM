#include <iostream>
using namespace std;

int a[110][110];
int dp[110][110];

int main(){
	int T; cin >> T;
	while (T--){
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				cin >> a[i][j];
		memset(dp, 0, sizeof(dp));
		int v, x, y, s, t;
		dp[n][m] = 1;
		for (int i = n; i >= 1; --i){
			for (int j = m; j >= 1; --j){
				if (i == n&&j == m)continue;
				v = a[i][j];
				for (s = v; s >= 0; --s){
					for (t = v - s; t >= 0; --t){
						if (!(t==0&&s==0)){
							x = i + s, y = j + t;
							if (x <= n&&y <= m)
								dp[i][j] += dp[x][y];
							dp[i][j] %= 10000;
						}
					}
				}
			}
		}
		cout << (dp[1][1] % 10000) << endl;
	}
}