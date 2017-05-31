#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;

char a[210][210];
bool vis[210][210];

int dist[210][210];
int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };

struct Node{
	int x, y, d;
	bool operator<(const Node&node)const{
		return d > node.d;
	}
};

bool judge(int x, int y){
	if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y]||a[x][y]=='#')return true;
	return false;
}

void BFS(int x,int y){
	memset(vis, 0, sizeof(vis));
	Node cur, next;
	queue<Node> q;
	cur.x = x, cur.y = y, cur.d = 0;
	q.push(cur);
	while (!q.empty()){
		cur = q.front(), q.pop();
		if (vis[cur.x][cur.y])continue;
		if (a[cur.x][cur.y] == '@'){
			dist[cur.x][cur.y] += cur.d;
		}
		vis[cur.x][cur.y] = 1;
		for (int i = 0; i < 4; ++i){
			next.x = cur.x + dir[i][0], next.y = cur.y + dir[i][1], next.d = cur.d + 1;
			if (judge(next.x, next.y))continue;
			q.push(next);
		}
	}
}

int main(){
	while (cin >> n >> m){
		int i, j;
		memset(dist, 0, sizeof(dist));
		
		for (i = 0; i < n; ++i)
			cin >> a[i];
		
		for (i = 0; i < n; ++i){
			for (j = 0; j < m; ++j){
				if (a[i][j] == 'M')BFS(i, j);
				else if (a[i][j] == 'Y')BFS(i, j);
			}
		}
		int mmin = 0x3f3f3f3f;
		for ( i = 0; i < n; ++i){
			for (j = 0; j < m; ++j){
				if (a[i][j] == '@'&&dist[i][j]!=0)mmin = min(mmin, dist[i][j]);
			}
		}
		cout << 11 * mmin << endl;
	}
}