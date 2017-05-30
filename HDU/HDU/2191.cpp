#include <iostream>
#include <algorithm>
using namespace std;

int p[110];
int w[110];
int cnt[110];
int dp[110];
int n, m;

void CompletePackage(int v, int c){
	for (int i = c; i <= n; ++i)
		dp[i] = max(dp[i], dp[i - c] + v);
}

void ZeroOnePackage(int v, int c){
	for (int i = n; i >= c; --i)
		dp[i] = max(dp[i], dp[i - c] + v);
}

void MultiPackage(int v, int c, int num){
	if (num*c > n)
		CompletePackage(v, c);
	else{
		int k = 1;
		while (num > k){
			ZeroOnePackage(v*k, c*k);
			num -= k;
			k *= 2;
		}
		ZeroOnePackage(num*v, num*c);
	}
}

int main(){
	int T; cin >> T;
	while (T--){
		 cin >> n >> m;
		 memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= m; ++i)
			cin >> p[i] >> w[i] >> cnt[i];
		for (int i = 1; i <= m; ++i)
			MultiPackage(w[i], p[i], cnt[i]);
		cout << dp[n] << endl;
		
	}
}