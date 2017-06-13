#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int a[310][310];
bool vis[310][310];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int m, n;

struct Node{
	int x, y, h;
	bool operator<(const Node&b)const{
		return h > b.h;
	}
};

bool judge(int x, int y){
	if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y])return true;
	return false;
}

int main(){
	cin >> m >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
		
	priority_queue<Node> q;
	Node cur;
	for (int i = 0; i < m; ++i){
		cur.x = 0, cur.y = i, cur.h = a[0][i], q.push(cur);
		cur.x = n-1, cur.y = i, cur.h = a[n-1][i], q.push(cur);
		vis[0][i] = vis[n - 1][i] = 1;
	}
	for (int i = 1; i <= n - 2; ++i){
		cur.x = i, cur.y = 0, cur.h = a[i][0], q.push(cur);
		cur.x = i, cur.y = m-1, cur.h = a[i][m-1], q.push(cur);
		vis[i][0] = vis[i][m - 1] = 1;
	}
	int ans = 0,xx,yy,h;
	Node next;
	while (!q.empty()){
		cur = q.top(), q.pop();
		for (int i = 0; i < 4; ++i){
			xx = cur.x + dir[i][0], yy = cur.y + dir[i][1];
			if (judge(xx, yy))continue;
			vis[xx][yy] = 1;
			h = a[xx][yy];
			if (h < cur.h)
				ans += cur.h - a[xx][yy], h = cur.h;
			next.x = xx, next.y = yy, next.h = h;
			q.push(next);
		}
	}
	cout << ans << endl;
	system("pause");
}