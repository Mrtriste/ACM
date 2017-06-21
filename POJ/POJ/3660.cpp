#include <iostream>
using namespace std;

int edge[105][105];

int main(){
	int n, m,a,b;
	cin >> n >> m;
	memset(edge, 0, sizeof(edge));
	for (int i = 0; i < m; ++i){
		scanf("%d%d", &a, &b);
		edge[a][b] = 1;
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				edge[i][j] = (edge[i][j] || (edge[i][k] && edge[k][j]));
	int ans = 0;
	for (int i = 1; i <= n; ++i){
		bool flag = true;
		for (int j = 1; j <= n; ++j){
			if (i!=j&&!(edge[i][j] || edge[j][i])){
				flag = false;
				break;
			}
		}
		if (flag)ans++;
	}
	cout << ans << endl;
	system("pause");
}