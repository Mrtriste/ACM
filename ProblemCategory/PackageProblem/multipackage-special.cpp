//POJ1742 & POJ2392
//use the sum array to record the count that a[i] has been use when arrives the V

#include <iostream>
#include <algorithm>
using namespace std;

int a[110], c[110];
int dp[100010],sum[100010];
int n, m;

int main(){
	while (cin >> n >> m&&n&&m){
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> c[i];
		
		for (int i = 0; i < n; ++i){
			memset(sum, 0, sizeof(sum));
			for (int j = a[i]; j <= m; ++j){
				if (!dp[j] && dp[j - a[i]] && sum[j-a[i]] < c[i]){
					dp[j] = 1;
					sum[j] = sum[j - a[i]] + 1;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= m; ++i)
			if (dp[i])ans++;
		cout << ans << endl;
	}
}