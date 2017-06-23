#include <iostream>
#include <algorithm>
using namespace std;

int a[10010];
long long dp[10010];

int main(){
	int n;
	while (cin >> n){
		for (int i = 0; i < n; ++i)
			scanf("%lld", &a[i]);
		sort(a, a + n);
		dp[0] = 0;
		for (int i = 1; i < n; ++i)
			dp[i] = dp[i - 1] + i*long long(a[i] - a[i - 1]);
		long long ans = 0;
		for (int i = 1; i < n; ++i)
			ans += dp[i];
		cout << ans * 2 << endl;
	}
}