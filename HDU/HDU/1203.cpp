#include <iostream>
#include <algorithm>
using namespace std;

int a[10010];
float b[10010];
int n, m;
float dp[10010];

int main(){
	while (cin >> n >> m){
		if (n == 0 && m == 0)break;
		for (int i = 1; i <= m; ++i)
			cin >> a[i] >> b[i];
		for (int i = 0; i <= n; ++i)
			dp[i] = 1;
		for (int i = 1; i <= m; ++i){
			for (int j = n; j >= a[i]; --j)
				dp[j] = min(dp[j], dp[j - a[i]] * (1 - b[i]));
		}
		float ans = (1 - dp[n]) * 100;
		printf("%.1f%%\n", ans);
	}
}