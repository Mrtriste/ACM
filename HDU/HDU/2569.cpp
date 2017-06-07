#include <iostream>
using namespace std;

int main(){
	int dp[45];
	dp[1] = 3, dp[2] = 9;
	for (int j = 3; j <= 40; ++j)
		dp[j] = dp[j - 2] + 2*dp[j - 1];
	int C, n; cin >> C;
	while (C--){
		cin >> n;
		cout << dp[n] << endl;
	}
}