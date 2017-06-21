#include <iostream>
#include <algorithm>
using namespace std;

int L[3], C[3],n,s,e;
int a[10010],dp[10010];

int main(){
	cin >> L[0] >> L[1] >> L[2] >> C[0] >> C[1] >> C[2];
	cin >> n >> s >> e;
	memset(dp, 0x3f, sizeof(dp));
	if (s > e)swap(s, e);
	a[1] = 0, dp[s] = 0;
	for (int i = 2; i <= n; ++i)
		scanf("%d", &a[i]);
	
	for (int i = s + 1; i <= e; ++i){
		for (int j = 0; j < 3; ++j){
			if (a[i] - L[j] > a[i - 1])continue;
			int pos = lower_bound(a + s, a + i, a[i] - L[j]) - a;
			dp[i] = min(dp[i], dp[pos] + C[j]);
		}
	}
	cout << dp[e] << endl;
	system("pause");
}