#include <iostream>
#include <algorithm>
using namespace std;

int v[510], w[510];
int dp[10010];

int main(){
	int t; cin >> t;
	while (t--){
		int e, f,n; cin >> e >> f >> n;
		for (int i = 1; i <= n; ++i)
			cin >> v[i] >> w[i];
		int W = f - e;
		for (int i = 0; i <= W; ++i)
			dp[i] = 100000000;
		dp[0] = 0;
		for (int i = 1; i <= n; ++i){
			for (int j = w[i]; j <= W;++j){
				if (dp[j - w[i]] != 100000000)
					dp[j] = min(dp[j - w[i]] + v[i], dp[j]);
			}
		}
		if (dp[W] != 100000000)
			cout << "The minimum amount of money in the piggy-bank is " << dp[W] << "." << endl;
		else
			cout << "This is impossible." << endl;
	}
}