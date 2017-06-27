#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

const int maxN = 150010;
long long dp[maxN];
int a[maxN];
int b[maxN];

int getCnt(int x){
	int cnt = 0;
	while (x > 0){
		++cnt;
		x /= 10;
	}
	return cnt;
}

int main(){
	dp[0] = 0;
	dp[1] = a[1] = 1; int m;
	for (int i = 2; i < maxN; ++i){
		a[i] = a[i - 1] + getCnt(i);
		dp[i] = dp[i - 1] + a[i];
		if (dp[i]>2147483647L){
			m = i;
			break;
		}
	}
	b[0] = 0; int base = 9;
	for (int i = 1; i < 10; ++i){
		b[i] = b[i - 1] + base*i;
		base *= 10;
	}

	int T; cin >> T;
	int n, pos, index, k, j, t, r, num;
	while (T--){
		cin >> n;
		pos = lower_bound(dp + 1, dp + m + 1, long long(n))-dp;
		index = n - dp[pos - 1];
		k = lower_bound(b + 1, b + 10, index) - b;
		j = index - b[k - 1];
		t = j / k, r = j%k;
		if (r == 0)r = k;
		num = pow(10.0, k - 1)-1;
		num += t;
		cout << ((num / int(pow(10.0, k - r))) % 10) << endl;
	}

	system("pause");
}