#include <iostream>
#include <queue>
using namespace std;

int a[110][110];
int m, n;
int k, sx, sy, ex, ey;
bool flag;

int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
bool vis[110][110];

bool judge(int x, int y){
	if (x<1 || x>m || y<1 || y>n||a[x][y]==1||vis[x][y]==1)return true;
	return false;
}

struct Node{
	int x, y;
	int d;
	int t;
};

//bool judge1(int x, int y, int d){
//	if (d == 0 && (y != ey||ex > x))return true;
//	if (d == 1 && (y != ey||ex < x))return true;
//	if (d == 2 && (x != ex||ey > y))return true;
//	if (d == 3 && (x != ex||ey < y))return true;
//	return false;
//}
//
//void DFS(int x,int y,int d,int t){
//	if (flag)return;
//	if (x == ex&&y == ey&&t <= k){
//		flag = true;
//		return;
//	}
//	int xx, yy, tt;
//	for (int i = 0; i < 4; ++i){
//		xx = x + dir[i][0], yy = y + dir[i][1];
//		tt = t;
//		if (d != i)tt += 1;
//		if (judge(xx, yy))continue;
//		if (tt == k&&judge1(xx, yy, i))continue;
//		a[xx][yy] = 1;
//		DFS(xx, yy, i, tt);
//		a[xx][yy] = 0;
//	}
//}

void BFS(){
	queue<Node> q;
	Node cur, next;
	cur.x = sx, cur.y = sy, cur.d = -1,cur.t=-1,q.push(cur);
	while (!q.empty()){
		cur = q.front(), q.pop();
		if (vis[cur.x][cur.y] == 1)continue;
		if (cur.x == ex&&cur.y == ey&&cur.t<=k){ flag = true; return; }
		vis[cur.x][cur.y] = 1;
		int xx, yy, tt;
		for (int i = 0; i < 4; ++i){
			next.d = i;
			next.t = cur.t;
			if (i != cur.d)next.t++;
			if (next.t>k)continue;
			xx = cur.x, yy = cur.y;
			while (1){
				xx += dir[i][0], yy += dir[i][1];
				if (judge(xx, yy))break;
				next.x = xx, next.y = yy;
				q.push(next);
			}
		}
	}
}

int main(){
	int T; cin >> T;
	char s[110];
	while (T--){
		int i, j;
		cin >> m >> n;
		for (i = 1; i <= m; ++i){
			scanf("%s", s);
			for (j = 1; j <= n; ++j){
				if (s[j - 1] == '.')a[i][j] = 0;
				else a[i][j] = 1;
			}
		}

		cin >> k >> sy >> sx >> ey >> ex;
		flag = false;
		memset(vis, 0, sizeof(vis));
		a[sx][sy] = 1;
		BFS();
		if (flag)cout << "yes" << endl;
		else cout << "no" << endl;

	}
}