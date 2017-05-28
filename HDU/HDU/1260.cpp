#include <iostream>
#include <algorithm>
using namespace std;

int a[2010];
int b[2010];
int dp[2010];

int main(){
	int n; cin >> n;
	char t[2][3] = { "am", "pm" };
	while (n--){
		int k; cin >> k;
		for (int i = 1; i <= k; ++i)
			cin >> a[i];
		for (int i = 1; i < k; ++i)
			cin >> b[i];

		dp[0]=0,dp[1] = a[1];
		for (int i = 2; i <= k; ++i)
			dp[i] = min(dp[i - 1] + a[i], dp[i - 2] + b[i - 1]);
		int h = dp[k] / 3600;
		int m = (dp[k] - 3600 * h) / 60;
		int s = (dp[k] - 3600 * h - 60 * m);
		h += 8;
		int flag = 0;
		if (h >= 12){
			h -= 12;
			flag = 1;
		}
		printf("%02d:%02d:%02d %s\n", h, m, s, t[flag]);
	}
}