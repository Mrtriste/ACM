#include <iostream>
#include <algorithm>
using namespace std;

int a[110], c[110];
int dp[100010],sum[100010];
int n, m;

int main(){
	while (cin >> n >> m&&n&&m){
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> c[i];
		
		for (int i = 0; i < n; ++i){
			memset(sum, 0, sizeof(sum));
			for (int j = a[i]; j <= m; ++j){
				if (!dp[j] && dp[j - a[i]] && sum[j-a[i]] < c[i]){
					dp[j] = 1;
					sum[j] = sum[j - a[i]] + 1;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= m; ++i)
			if (dp[i])ans++;
		cout << ans << endl;
	}
}


////http://blog.csdn.net/sonpking/article/details/52234759
//#include <iostream>  
//#include <cstring>  
//using namespace std;
//
//const int maxn = 100;
//const int maxm = 100001;
////设前i种硬币组成和为j，第i种还剩的个数为dp[i][j]（不能构成则为负数）,
////那么如果dp[i - 1][j] >= 0(即前i - 1种已经可以加和为j)，则dp[i][j] = c[i](即全部剩下）。
////如果上述不成立并且a[i]<j，那么肯定此时不能加和为j，dp[i][j] = -1。其他情况直接dp[i][j - a[i]] - 1即可。
////因为题中i和i - 1状态不必同时出现，又因为dp[j - a[i]]是向后更新的，所以可以重复利用矩阵，并且更新时正循环
//
//int main()
//{
//	int n, m;
//	int a[maxn], c[maxn], dp[maxm];
//	while (cin >> n >> m){
//		if (!n) break;
//		memset(dp, -1, sizeof(dp));
//		dp[0] = 0;
//		for (int i = 0; i<n; i++) cin >> a[i];
//		for (int i = 0; i<n; i++) cin >> c[i];
//		for (int i = 0; i<n; i++)
//			for (int j = 0; j <= m; j++){    ///j++为正循环  
//			if (dp[j] >= 0) dp[j] = c[i];     ///判断条件中的dp[j]其实是dp[i-1][j]  
//				else if (j<a[i]) dp[j] = -1;
//				else dp[j] = dp[j - a[i]] - 1;
//			}
//		int num = 0;
//		for (int i = m; i >= 1; i--) if (dp[i] >= 0) num++;
//		cout << num << endl;
//	}
//	return 0;
//}
//
/////////////////////TLE
//
////#include <iostream>
////#include <algorithm>
////using namespace std;
////
////int dp[100010];
////int n, m;
////
////void ComPack(int v){
////	for (int i = v; i <= m; ++i)
////		if (dp[i - v] != -1)
////			dp[i] = 0;
////}
////
////void ZeroOnePack(int v){
////	for (int i = m; i >= v; --i)
////		if (dp[i - v] != -1)
////			dp[i] = 0;
////}
////
////void mixPack(int v, int k){
////	if (v*k >= m){
////		ComPack(v);
////		return;
////	}
////	int t = 1;
////	while (k>t){
////		ZeroOnePack(t*v);
////		k -= t;
////		t *= 2;
////	}
////	ZeroOnePack(k*v);
////}
////
////int main(){
////	int a[110], c[110];
////	while (cin >> n >> m&&n){
////		for (int i = 1; i <= n; ++i)
////			scanf("%d", &a[i]);
////		for (int i = 1; i <= n; ++i)
////			scanf("%d", &c[i]);
////		memset(dp, -1, (m+2)*sizeof(dp[0]));
////		dp[0] = 0;
////		for (int i = 1; i <= n; ++i)
////			mixPack(a[i], c[i]);
////		int cnt = 0;
////		for (int i = 1; i <= m; ++i)
////			if (dp[i] != -1)++cnt;
////		cout << cnt << endl;
////	}
////}