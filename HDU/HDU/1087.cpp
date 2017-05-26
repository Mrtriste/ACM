#include <iostream>
#include <algorithm>
using namespace std;

int dp[1010];
int a[1010];

int main(){
	int n;
	while (cin >> n){
		if (n == 0)break;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		dp[0] = a[0] = 0;
		int ans = 0;
		for (int i = 1; i <= n; ++i){
			dp[i] = a[i];
			for (int j = 1; j < i; ++j){
				if (a[i]>a[j] && dp[i] < (a[i] + dp[j]))
					dp[i] = a[i] + dp[j];
			}
			ans = max(dp[i], ans);
		}
		cout << ans << endl;

	}
}