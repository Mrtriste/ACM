#include <iostream>
using namespace std;

int par[910];
bool vis[910];
int cnt[910];

int main(){
	int n,m;
	while (cin >> n){
		memset(par, 0, sizeof(par));
		memset(cnt, 0, sizeof(cnt));
		int x,y;
		for (int i = 0; i < n; ++i){
			scanf(" %d : ( %d )", &x, &m);
			for (int j = 0; j < m; ++j){
				scanf(" %d", &y);
				par[y] = x;
			}
		}
		cin >> m;
		for (int i = 0; i < m; ++i){
			scanf(" ( %d %d )",&x,&y);
			memset(vis, 0, sizeof(vis));
			while (x > 0){
				vis[x] = 1;
				x = par[x];
			}
			while (y > 0){
				if (vis[y]){
					cnt[y]++;
					break;
				}
				else y = par[y];
			}
		}
		for (int i = 1; i <= n; ++i)
			if (cnt[i] > 0)cout << i << ":" << cnt[i] << endl;
	}
}