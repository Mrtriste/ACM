#include <iostream>
using namespace std;

typedef long long ll;

ll dp[55][55];
int a[55][55];
int n, m;

ll GCD(ll a, ll b){
	while (b != 0){
		if (a < b)swap(a, b);
		ll t = a;
		a = b;
		b = t%b;
	}
	return a;
}

int main(){
	while (cin >> n >> m){
		char c = ' '; 
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= i; ++j){
				while (c != '.'&&c!='*')c = getchar();
				a[i][j] = c == '*' ? 1 : 0;
				c = ' ';
			}
		}
		memset(dp, 0, sizeof(dp));
		dp[1][1] = 1ll << n;
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= i; ++j){
				if (a[i][j])dp[i + 1][j] += dp[i][j] / 2, dp[i + 1][j + 1] += dp[i][j] / 2;
				else dp[i + 2][j + 1] = dp[i][j];
			}
		}
		ll gcd = GCD(1ll << n, dp[n + 1][m + 1]);
		ll x = 1ll << n;
		printf("%I64d/%I64d\n", dp[n + 1][m + 1] / gcd, x/ gcd);

	}
	system("pause");
}