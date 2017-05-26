#include <iostream>
#include <algorithm>
using namespace std;

int dp[250010];
int a[6000];
int cnt, all;

void insert(int v, int m){
	int x = 1;
	while (x*2 < m){
		a[cnt++] = x*v;
		x *= 2;
	}
	a[cnt++] = (m - x + 1)*v;
}

int main(){
	int n; 
	int v, m;
	while (cin >> n){
		if (n < 0)break;
		cnt = 1, all = 0;
		for (int i = 0; i < n; ++i){
			cin >> v >> m;
			all += (v*m);
			insert(v, m);
		}
		int V = (all+1) / 2;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i < cnt; ++i){
			for (int j = V; j >= a[i]; --j){
					dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
			}
		}
		cout << max(all - dp[V], dp[V]) << " " << min(all - dp[V], dp[V]) << endl;

	}

}