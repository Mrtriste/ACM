#include <iostream>
using namespace std;

int dp[11][11];

int main(){
	for (int i = 1; i <= 10; ++i)dp[0][i] = 1;
	for (int i = 1; i <= 10; ++i)dp[i][1] = 1;
	for (int i = 1; i <= 10; ++i){
		for (int j = 2; j <= 10; ++j){
			if (j > i)dp[i][j] = dp[i][i];
			else
				dp[i][j] = dp[i][j - 1] + dp[i - j][j];
		}
	}
	int T,m,n; cin >> T;
	while (T--){
		cin >> m >> n;
		cout << dp[m][n] << endl;
	}
}




//#include <iostream>
//using namespace std;
//
//int main(){
//	int dp[11][11];
//	for (int i = 0; i <= 10; ++i)
//		dp[1][i] = dp[0][i]=1,dp[i][0]=0;
//	for (int m = 2; m <= 10; ++m){
//		for (int n = 1; n <= 10; ++n){
//			if (m < n)
//				dp[m][n] = dp[m][m];
//			else
//				dp[m][n] = dp[m][n - 1] + dp[m - n][n];
//		}
//	}
//	int m, n;
//	int t; cin >> t;
//	while (t--){
//		cin >> m >> n;
//		cout << dp[m][n] << endl;
//	}
//		
//}