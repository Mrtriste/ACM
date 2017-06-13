#include <iostream>
using namespace std;

char a[110][110];
int n, m;
bool vis[110][110];
int dir[8][2] = { 1, 0, -1, 0, 0, -1, 0, 1, 1, 1, -1, 1, 1, -1, -1, -1 };

bool judge(int x, int y){
	if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || a[x][y] == '.')
		return true;
	return false;
}

void DFS(int x,int y){
	int xx, yy;
	for (int i = 0; i < 8; ++i){
		xx = x + dir[i][0], yy = y + dir[i][1];
		if (judge(xx, yy))continue;
		vis[xx][yy] = 1;
		DFS(xx, yy);
	}
}

int main(){
	while (cin >> n >> m){
		for (int i = 0; i < n; ++i)
			scanf("%s", &a[i]);
		memset(vis, 0, sizeof(vis));
		int cnt = 0;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				if (a[i][j]=='W' && !vis[i][j]){
					++cnt;
					vis[i][j] = 1;
					DFS(i, j);
				}
			}
		}
		cout << cnt << endl;
	}
}