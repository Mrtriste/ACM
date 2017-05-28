#include <iostream>
using namespace std;

int a[110][110];
bool vis[110][110];
int m, n;
int cnt;
int dir[8][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, {1,1} };

bool judge(int x, int y){
	if (x < 0 || y < 0 || x >= m || y >= n)return true;
	return false;
}

void DFS(int x, int y){
	if (vis[x][y])return;
	vis[x][y] = 1;
	int xx, yy;
	for (int i = 0; i < 8; ++i){
		xx = x + dir[i][0], yy = y + dir[i][1];
		if (judge(xx, yy))continue;
		if (a[xx][yy] == 1&&!vis[xx][yy]){
			DFS(xx, yy);
		}
		
	}
}

int main(){
	char s[110];
	while (cin >> m >> n){
		if (m == 0)break;
		for (int i = 0; i < m; ++i){
			cin >> s;
			for (int j = 0; j < n; ++j){
				if (s[j] == '*')a[i][j] = 0;
				else a[i][j] = 1;
			}
		}
		cnt = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				if (a[i][j] == 1 && !vis[i][j]){
					cnt++;
					DFS(i, j);
				}
					
			}
		}
		cout << cnt << endl;
		
	}
}