#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000010];
int maxDP[1000010];
int a[1000010];

int main(){
	int m, n;
	while (cin >> m >> n){
		for (int i = 1; i <= n; ++i)
			cin >> a[i], dp[i] = maxDP[i] = 0;
		dp[0] = 0;
		int maxx;
		for (int j = 1; j <= m; ++j){
			maxx = -200000000;
			for (int i = j; i <= n; ++i){
				dp[i] = max(dp[i - 1], maxDP[i-1]) + a[i];
				maxDP[i - 1] = maxx;
				maxx = max(maxx, dp[i]);
				
			}
		}
		cout << maxx << endl;
	}
	return 0;
}