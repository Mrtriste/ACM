#include <iostream>
using namespace std;

int dp[120010],sum[120010];
int a[7];

int main(){
	int t = 1;
	while (1){
		int s = 0;
		for (int i = 1; i <= 6; ++i){
			cin >> a[i];
			s += a[i]*i;
		}
		if (s == 0)break;
		printf("Collection #%d:\n", t++);
		if (s % 2 == 1){
			printf("Can't be divided.\n\n");
			continue;
		}
		s /= 2;
		memset(dp, 0, sizeof(int)*(s + 10));
		dp[0] = 1;
		for (int i = 1; i <= 6; ++i){
			memset(sum, 0, sizeof(int)*(s + 10));
			for (int j = i; j <= s; ++j){
				if (!dp[j] && dp[j - i] && sum[j - i] < a[i]){
					dp[j] = 1;
					sum[j] = sum[j - i] + 1;
				}
			}
		}
		if (dp[s])printf("Can be divided.\n\n");
		else printf("Can't be divided.\n\n");
	}
}