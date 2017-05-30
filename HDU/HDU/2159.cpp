#include <iostream>
#include <algorithm>
using namespace std;

int a[110];
int b[110];
int dp[110][110];

int main(){
	int n, m, k, s;
	while (cin >> n >> m >> k >> s){
		for (int i = 1; i <= k; ++i)
			cin >> a[i] >> b[i];
		int mmin = 100000;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= k; ++i){
			for (int j = b[i]; j <= m; ++j){
				for (int t = 1; t <= s; ++t){
					dp[j][t] = max(dp[j][t], dp[j - b[i]][t - 1] + a[i]);
					if (dp[j][t] >= n)
						mmin = min(mmin, j);
				}
			}
		}
		if (mmin == 100000)
			cout << -1 << endl;
		else
			cout << (m - mmin) << endl;
	}
}

//my solution AC
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct Node{
//	int a, b;
//};
//
//Node node[110];
//int dp[110];
//int cnt[110];
//
//bool cmp(const Node&m, const Node&n){
//	return (m.b > n.b);
//}
//
//int main(){
//	int n, m, k, s;
//	int a, b;
//	while (cin >> n >> m >> k >> s){
//		for (int i = 1; i <= k; ++i){
//			cin >> a >> b;
//			node[i].a = a, node[i].b = b;
//		}
//		sort(node + 1, node + 1 + k, cmp);
//		memset(dp, 0, sizeof(dp));
//		memset(cnt, 0, sizeof(cnt));
//		int mmin = 100000;
//		for (int i = 1; i <= k; ++i){
//			for (int j = node[i].b; j <= m; ++j){
//				if (dp[j] < dp[j - node[i].b] + node[i].a){
//					dp[j] = dp[j - node[i].b] + node[i].a;
//					cnt[j] = cnt[j - node[i].b] + 1;
//				}
//				if (dp[j] >= n&&cnt[j] <= s&&mmin > j)
//					mmin = j;
//			}
//		}
//		if (mmin == 100000)
//			cout << -1 << endl;
//		else
//			cout << (m - mmin) << endl;
//	}
//}