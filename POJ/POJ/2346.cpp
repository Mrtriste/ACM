#include <iostream>
using namespace std;

int getSum(int x){
	int sum = 0;
	while (x > 0){
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

long long dp[50];
long long ans[10];

int main(){
	int n; int base = 1;
	memset(ans, 0, sizeof(ans));
	for (n = 1; n <= 5; ++n){
		base *= 10;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < base; ++i)
			dp[getSum(i)]++;
		for (int i = 0; i <= 9 * n; ++i)
			ans[n] += dp[i] * dp[i];
	}
	while (cin >> n)
		cout << ans[n / 2] << endl;
}