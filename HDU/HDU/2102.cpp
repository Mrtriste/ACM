#include <iostream>
#include <queue>
#include <math.h>
#include <stdio.h>
using namespace std;
#define wjc

char a[2][12][12];
int m, n,T;
int ex, ey,ez;
int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };

struct Node{
	int x, y, z;
	int t;
};

bool judge(int x, int y, int z,int t){
	if (x < 0 || x >= n || y<0 || y >= m ||a[z][x][y]=='*'|| (t + abs(ex - x) + abs(ey - y))>T)return true;
	return false;
}

bool BFS(){
	Node cur, next;
	cur.x = cur.y = cur.z = cur.t = 0;
	queue<Node> q;
	q.push(cur);
	while (!q.empty()){
		cur = q.front(), q.pop();
		if (a[cur.z][cur.x][cur.y] == '*')continue;
		if (cur.z == ez&&cur.x == ex&&cur.y == ey&&cur.t<=T)return true;
		a[cur.z][cur.x][cur.y] = '*';
		for (int i = 0; i < 4; ++i){
			next.x = cur.x+dir[i][0], next.y =cur.y+ dir[i][1], next.z = cur.z, next.t = cur.t + 1;
			if (judge(next.x, next.y, next.z,next.t))continue;
			if (a[next.z][next.x][next.y] == '#'){
				next.z ^= 1;
				if (a[next.z][next.x][next.y] == '#' || a[next.z][next.x][next.y] == '*')
					continue;
				if (a[next.z][next.x][next.y] == 'P'&&next.t <= T)return true;
			}
			q.push(next);
		}
	}
	return false;
}

int main(){
#ifdef wjc
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int C; cin >> C;
	char s[12];
	while (C-->0){
		cin >> n >> m >> T;
		int i, j;
		for (i = 0; i < n; ++i){
			cin >> s;
			for (j = 0; j < m; ++j){
				a[0][i][j] = s[j];
				if (s[j] == 'P')ez = 0, ex = i, ey = j;
			}
		}
		getchar();
		for (i = 0; i < n; ++i){
			cin >> s;
			for (j = 0; j < m; ++j){
				a[1][i][j] = s[j];
				if (s[j] == 'P')ez = 1, ex = i, ey = j;
			}
		}
		if (BFS())cout << "YES" << endl;
		else cout << "NO" << endl;
			
	}
	system("pasue");
}