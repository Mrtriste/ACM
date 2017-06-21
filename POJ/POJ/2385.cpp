//dp[i][j]表示前i分钟最多走了j次得到的最多的苹果
#include <iostream>
#include <algorithm>
using namespace std;

int a[1010], n, w;
int dp[1010][35];

int main(){
	while (cin >> n >> w){
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i <= w; ++i)
			dp[0][i] = 0;
		for (int i = 1; i <= n; ++i)
			if (a[i] == 1)dp[i][0] = dp[i - 1][0] + 1;

		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= w; ++j){
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
				dp[i][j] += (j % 2 == a[i] - 1);
				dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			}
		}
		cout << dp[n][w] << endl;
	}
}

////dp[i][j]表示前i分钟只走了j次得到的最多的苹果
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int a[1010],n,w;
//int dp[1010][35];
//
//int main(){
//	while (cin >> n >> w){
//		for (int i = 1; i <= n; ++i)
//			scanf("%d", &a[i]);
//		for (int i = 0; i <= w;++i)
//			dp[0][i] = 0;
//		for (int i = 1; i <= n; ++i)
//			if (a[i] == 1)dp[i][0] =dp[i-1][0]+1;
//		
//		int ans = 0;
//		for (int i = 1; i <= n; ++i){
//			for (int j = 1; j <= w; ++j){
//				dp[i][j] = max(dp[i-1][j], dp[i - 1][j - 1]);
//				dp[i][j] += (((j % 2) + 1) == a[i]);
//				ans = max(dp[i][j], ans);
//			}
//		}
//		cout << ans << endl;
//	}
//}

