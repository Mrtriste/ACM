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
////��ǰi��Ӳ����ɺ�Ϊj����i�ֻ�ʣ�ĸ���Ϊdp[i][j]�����ܹ�����Ϊ������,
////��ô���dp[i - 1][j] >= 0(��ǰi - 1���Ѿ����ԼӺ�Ϊj)����dp[i][j] = c[i](��ȫ��ʣ�£���
////�����������������a[i]<j����ô�϶���ʱ���ܼӺ�Ϊj��dp[i][j] = -1���������ֱ��dp[i][j - a[i]] - 1���ɡ�
////��Ϊ����i��i - 1״̬����ͬʱ���֣�����Ϊdp[j - a[i]]�������µģ����Կ����ظ����þ��󣬲��Ҹ���ʱ��ѭ��
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
//			for (int j = 0; j <= m; j++){    ///j++Ϊ��ѭ��  
//			if (dp[j] >= 0) dp[j] = c[i];     ///�ж������е�dp[j]��ʵ��dp[i-1][j]  
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