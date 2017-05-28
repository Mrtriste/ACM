#include <iostream>
#include <queue>
using namespace std;

bool a[10][10][10];
int sx, sy, sz, ex, ey, ez;
int n;

int dir[6][3] = { { 1, 0, 0 }, { -1, 0, 0 }, { 0, 1, 0 }, { 0, -1, 0 }, { 0, 0, 1 }, { 0, 0, -1 } };

struct Node{
	int x, y, z;
	int d;
	bool operator<(const Node&a)const{
		return d > a.d;
	}
};

bool judge(int x,int y,int z){
	if (x < 0 || y < 0 || z < 0 || x >= n || y >= n || z >= n||a[x][y][z]==1)return true;
	return false;
}

int BFS(){
	Node cur;
	cur.x = sx, cur.y = sy, cur.z = sz, cur.d = 0;
	priority_queue<Node> q;
	q.push(cur);
	Node top, next;
	while (!q.empty()){
		top = q.top(), q.pop();
		if (ex == top.x&&ey == top.y&&ez == top.z)return top.d;
		if (a[top.x][top.y][top.z] == 1)continue;
		a[top.x][top.y][top.z] = 1;
		for (int i = 0; i < 6; ++i){
			next.x = top.x + dir[i][0];
			next.y = top.y + dir[i][1];
			next.z = top.z + dir[i][2];
			if (judge(next.x, next.y, next.z))continue;
			next.d = top.d + 1;
			q.push(next);
		}
	}
	return -1;
}

int main(){
	char s[11];

	while (cin >> s >> n){
		int i, j, k;
		for (i = 0; i < n; ++i){
			for (j = 0; j < n; ++j){
				cin >> s;
				for (k = 0; k < n; ++k){
					if (s[k] == 'X')a[j][k][i] = 1;
					else a[j][k][i] = 0;
				}
			}
		}
		cin >> sy >> sx >> sz >> ey >> ex >> ez;
		cin >> s;
		int ans = BFS();
		if (ans == -1)cout << "NO ROUTE" << endl;
		else cout << n << " " << ans << endl;
			
	}
}