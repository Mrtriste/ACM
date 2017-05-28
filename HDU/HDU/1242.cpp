#include <iostream>
#include <queue>
using namespace std;

int n, m;
int sx, sy, ex, ey;
int a[210][210];
int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

struct Node{
	int x, y;
	int d;
	bool operator<(const Node&a)const{
		return d > a.d;
	}
};

bool judge(int x, int y){
	if (x < 0 || y < 0 || x >= n || y >= m||a[x][y]==-1)return true;
	return false;
}

int BFS(){
	Node cur;
	cur.x = sx, cur.y = sy, cur.d = 0;
	priority_queue<Node> q;
	q.push(cur);
	Node next;
	while (!q.empty()){
		cur = q.top(), q.pop();
		if (a[cur.x][cur.y] == -1)continue;
		if (ex == cur.x&&ey == cur.y)return cur.d;
		for (int i = 0; i < 4; ++i){
			next.x = cur.x + dir[i][0], next.y = cur.y + dir[i][1];
			if (judge(next.x, next.y))continue;
			next.d = cur.d + a[cur.x][cur.y]+1;
			q.push(next);
		}
		a[cur.x][cur.y] = -1;
	}
	return -1;
}


int main(){
	char s[210];
	while (cin >> n >> m){
		for (int i = 0; i < n; ++i){
			cin >> s;
			for (int j = 0; j < m; ++j){
				if (s[j] == '#')a[i][j] = -1;
				else if (s[j] == 'x')a[i][j] = 1;
				else if (s[j] == '.')a[i][j] = 0;
				else if (s[j] == 'r')a[i][j] = 0, sx = i, sy = j;
				else a[i][j] = 0, ex = i, ey = j;
			}
		}

		int ans = BFS();
		if (ans == -1)cout << "Poor ANGEL has to stay in the prison all his life." << endl;
		else cout << ans << endl;
	}
}