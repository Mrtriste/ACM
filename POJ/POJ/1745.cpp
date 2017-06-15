#include <iostream>
using namespace std;

int n, k;
bool dp[2][110];

int main(){
	while (cin >> n >> k){
		memset(dp, 0, sizeof(dp));
		int a;
		int t = 1;
		dp[t][0] = 1;
		for (int i = 0; i < n; ++i){
			cin >> a;
			t ^= 1;
			for (int i = 0; i < k; ++i)
				dp[t][i] = 0;
			for (int j = 0; j < k; ++j){
				if (dp[t^1][j]){
					dp[t][(j + ((a%k) + k)) % k] = 1;
					dp[t][(j + ((-a) % k + k)) % k] = 1;
					//cout << ((j + ((a%k) + k)) % k) << " " << ((j + ((-a) % k + k)) % k) << "  is true\n";
				}
			}
			//cout << "---" << endl;
		}
		if (dp[t][0]) cout << "Divisible\n";
		else cout << "Not divisible\n";
	}
}