//#include <iostream>
//#include <algorithm>
//using namespace std;
//#define INF 0x3f3f3f3f
//
//int dp[200010];
//int s[110], f[110];
//int n;
//
////�����ڶ�ÿ������ȡ����TSֵ���������ֵ��TF�����ֵ�Ƕ��٣�Ҳ�����ȶ���һ��ά�ȣ�Ȼ�����TS����
//
//int main(){
//	while (cin >> n){
//		for (int i = 1; i <= n; ++i)
//			scanf("%d%d", &s[i], &f[i]);
//		for (int i = 0; i <= 200000; ++i)
//			dp[i] = -INF;
//		dp[100000] = 0;
//		for (int i = 1; i <= n; ++i){
//			if (s[i] < 0 && f[i] < 0)continue;
//			if (s[i] > 0){
//				for (int j = 200000; j >= s[i]; --j)
//					if (dp[j-s[i]] != -INF)
//						dp[j] = max(dp[j], dp[j - s[i]] + f[i]);
//			}
//			else{
//				for (int j = 0; j <= 200000 + s[i]; ++j)
//					if (dp[j - s[i]] != -INF)
//						dp[j] = max(dp[j], dp[j - s[i]] + f[i]);
//			}
//		}
//		int mmax = 0;
//		for (int i = 100000; i <= 200000; ++i)
//			if (dp[i] >= 0)
//				mmax = max(mmax, dp[i] + i - 100000);
//		cout << mmax << endl;
//	}
//}