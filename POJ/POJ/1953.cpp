#include <iostream>
using namespace std;

int main(){
	int dp[50][2];
	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i <= 45; ++i){
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	int T,t=1,n; cin >> T;
	while (T--){
		cin >> n;
		printf("Scenario #%d:\n%d\n\n", t++, (dp[n][0] + dp[n][1]));
	}
}