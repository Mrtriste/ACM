#include <iostream>
using namespace std;

long long dp[40][40];

int main(){
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= 35; ++i)
		dp[0][i] = 1;
	for (int i = 1; i <= 35; ++i)
		for (int j = i; j <= 35; ++j)
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]);
	int n, cnt = 1;
	while (cin>>n&&n>0){
		cout << cnt++ << " "<<n<<" "<< (dp[n][n] * 2) << endl;
	}
	
}