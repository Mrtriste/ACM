#include <iostream>
#include <algorithm>
using namespace std;

int dp[2010][1010];
int a[2010];

int main(){
	int n, k;
	
	while (cin >> n >> k){
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		sort(a + 1, a + 1 + n);
		memset(dp, 0x3f, sizeof(dp));
		for (int i = 0; i <2010; ++i)
			dp[i][0] = 0;
		for (int i = 2; i <= n; ++i){
			for (int j = 1; 2*j<=i; ++j)
				dp[i][j] = min(dp[i - 2][j - 1] + (a[i] - a[i - 1])*(a[i] - a[i - 1]), dp[i - 1][j]);
		}
		cout << dp[n][k] << endl;
	}
}