#include <iostream>
using namespace std;

int main(){
	int dp[1010][3];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 1; i <= 1000; ++i){
		for (int j = 0; j < 3; ++j){
			dp[i][j] = (dp[i - 1][(j +2) % 3] + dp[i - 1][(j + 1) % 3]) % 10000;
		}
	}
	int n;
	while (cin >> n&&n){
		cout << dp[n][0] << endl;
	}
}