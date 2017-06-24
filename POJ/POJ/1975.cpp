#include <iostream>
using namespace std;

int edge[105][105];
int n,m;

int main(){
	int T,a,b; cin >> T;
	while (T--){
		memset(edge, 0, sizeof(edge));
		cin >> n >> m;
		for (int i = 0; i < m; ++i){
			scanf("%d%d", &a, &b);
			edge[a][b] = 1;
		}
		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					edge[i][j] = (edge[i][j] || (edge[i][k] && edge[k][j]));
		int ans=0, small, big;
		for (int i = 1; i <= n; ++i){
			big = small = 0;
			for (int j = 1; j <= n; ++j){
				if (edge[i][j])big++;
				else if (edge[j][i])small++;
			}
			if (big>n / 2 || small > n / 2)ans++;
		}
		cout << ans << endl;

	}
}