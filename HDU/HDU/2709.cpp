#include <iostream>
using namespace std;

int dp[1000010];
int c[25];



int main(){
	int k = 1, cnt = 1;
	while (k < 1000000){
		c[cnt++] = k;
		k *= 2;
	}
	memset(dp, 0, sizeof(dp));
	dp[0] = 1; c[0] = 1;
	for (int i = 1; i <cnt; ++i){
		for (int j = c[i]; j <= 1000000; ++j){
			dp[j] += dp[j - c[i]];
			dp[j] %= 1000000000;
		}
	}
	int n;
	while (cin >> n)
		cout << dp[n] << endl;
}

