#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int a[25][25];
int sx, sy;
int w, h;
int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
int cnt;

struct Node{
	int x, y;
};

bool judge(int x, int y){
	if (x < 0 || y < 0 || x >= h || y >= w || a[x][y] == 1)return true;
	return false;
}

void BFS(){
	Node cur;
	cur.x = sx, cur.y = sy;
	queue<Node> q;
	q.push(cur);
	Node next;
	while (!q.empty()){
		cur = q.front(), q.pop();
		if (a[cur.x][cur.y] == 1)continue;
		++cnt;
		a[cur.x][cur.y] = 1;
		for (int i = 0; i < 4; ++i){
			next.x = cur.x + dir[i][0], next.y = cur.y + dir[i][1];
			if (judge(next.x, next.y))continue;
			q.push(next);
		}
	}
}

int main(){
	char s[30];
	while (cin >> w >> h){
		if (w == 0 && h == 0)break;
		for (int i = 0; i < h; ++i){
			cin >> s;
			for (int j = 0; j < w; ++j){
				if (s[j] == '.')a[i][j] = 0;
				else if (s[j] == '#')a[i][j] = 1;
				else a[i][j] = 0, sx = i, sy = j;
			}
		}
		cnt = 0;
		BFS();
		cout << cnt << endl;
	}
}