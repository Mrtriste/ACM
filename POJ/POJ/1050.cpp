#include <iostream>
#include <algorithm>
using namespace std;

int a[101][101];
int dp[101];
int n;

int Make(){
	int mmax = -10000000, sum = 0;
	for (int i = 0; i < n; ++i){
		if (sum < 0)sum = dp[i];
		else sum += dp[i];
		mmax = max(mmax, sum);
	}
	return mmax;
}

int main(){
	while (cin >> n){
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &a[i][j]);
		Make();
		int mmax = -10000000;
		for (int k = 0; k < n; ++k){
			memset(dp, 0, sizeof(dp));
			for (int t = k ; t < n; ++t){
				for (int i = 0; i < n; ++i)
					dp[i] += a[t][i];
				mmax = max(Make(), mmax);
			}
		}
		cout << mmax << endl;
	}
}