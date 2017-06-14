#include <iostream>
#include <queue>
using namespace std;

bool vis[310][310];
int sx, sy, ex,ey;
int n;

int dir[8][2] = { -2, -1, -1, -2, 1, -2, 2, -1, -2, 1, -1, 2, 2, 1, 1, 2 };

struct Node{
	int x, y;
	int d;
};

bool judge(int x, int y){
	if (x < 0 || y < 0 || x >= n || y >= n || vis[x][y])return true;
	return false;
}

int BFS(){
	queue<Node> q;
	Node cur, next;
	cur.x = sx, cur.y = sy, cur.d = 0;
	q.push(cur);
	vis[sx][sy] = 1;
	int xx, yy;
	while (!q.empty()){
		cur = q.front(), q.pop();
		//if (vis[cur.x][cur.y])continue;
		if (cur.x == ex&&cur.y == ey)return cur.d;
		for (int i = 0; i < 8; ++i){
			xx = cur.x + dir[i][0], yy = cur.y + dir[i][1];
			if (judge(xx, yy))continue;
			next.x = xx, next.y = yy, next.d = cur.d + 1;
			vis[next.x][next.y] = 1;
			q.push(next);
		}
	}
}

int main(){
	int T; cin >> T;
	while (T--){
		cin >> n>>sx>>sy>>ex>>ey;
		memset(vis, 0, sizeof(vis));
		int ans = BFS();
		cout << ans << endl;
	}
}