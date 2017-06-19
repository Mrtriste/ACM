#include <iostream>
using namespace std;

int fac[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 20000 };

int main(){
	int n, m;
	int ans[1010];
	bool vis[1010];
	while (cin >> n >> m){
		int pos = 1;
		if (n >= 9){
			while (n - pos >= 9)
				ans[pos++] = pos;
		}
		memset(vis, 0, sizeof(vis));
		int s = pos;
		m -= 1;
		while (pos <= n){
			int cnt = 0; int c = m / fac[n - pos];
			int i;
			for ( i = s; i <= n; ++i){
				if (!vis[i]&&c == cnt)break;
				if (!vis[i])
					++cnt;
			}
			m %= fac[n - pos];
			vis[i] = 1;
			ans[pos++] = i;
		}

		for (int i = 1; i < n; ++i)
			cout << ans[i] << " ";
		cout <<ans[n]<< endl;

	}
}