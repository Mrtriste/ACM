//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int dp[5010];
//int cnt[5010];
//int a[5010];
//int n;
//
//int main(){
//	while (cin >> n){
//		for (int i = 0; i < n; ++i){
//			scanf("%d", &a[i]);
//			dp[i] = 1; cnt[i] = 1;
//		}
//		int maxl = 0,sum=0;
//		for (int i = 0; i < n; ++i){
//			for (int j = i - 1; j >= 0; --j){
//				if (a[i] < a[j]){
//					if (dp[i] < dp[j] + 1){
//						dp[i] = dp[j] + 1;
//						cnt[i] = cnt[j];
//					}
//					else if (dp[i] == dp[j] + 1)
//						cnt[i] += cnt[j];
//					
//				}
//				if (a[i] == a[j]){//dp[i]>=dp[j]
//					if (dp[i] == 1)cnt[i] = 0;
//					break;
//				}
//			}
//			maxl = max(maxl, dp[i]);
//		}
//		for (int i = 0; i < n; ++i){
//			//cout << dp[i] << " " << cnt[i] << endl;
//			if (dp[i] == maxl)sum += cnt[i];
//		}
//			
//		cout <<maxl<<" "<< sum << endl;
//	}
//}