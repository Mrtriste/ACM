#include <iostream>
using namespace std;

int main(){
	int dp[11][11];
	for (int i = 0; i <= 10; ++i)
		dp[1][i] = dp[0][i]=1,dp[i][0]=0;
	for (int m = 2; m <= 10; ++m){
		for (int n = 1; n <= 10; ++n){
			if (m < n)
				dp[m][n] = dp[m][m];
			else
				dp[m][n] = dp[m][n - 1] + dp[m - n][n];
		}
	}
	int m, n;
	int t; cin >> t;
	while (t--){
		cin >> m >> n;
		cout << dp[m][n] << endl;
	}
		
}