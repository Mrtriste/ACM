#include <iostream>
using namespace std;

int dp[2010][2010];

int main(){
	memset(dp, 0, sizeof(dp));
	dp[1][1] = 1;
	for (int i = 2; i <= 2000; ++i){
		for (int j = 1; j <= i; ++j){
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * j) % 1000;
		}
	}
	int ans[2010];
	for (int i = 1; i <= 2000; ++i){
		int res = 0;
		for (int j = 1; j <= i; ++j)
			res += dp[i][j];
		ans[i] = res % 1000;
	}
	int n, C; cin >> C;
	while (C--){
		cin >> n;
		cout << ans[n] << endl;
	}
		
}