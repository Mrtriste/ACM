#include <iostream>
#include <queue>
using namespace std;

int a[15][15];
int sx, sy, ex, ey;
int dir[8][2] = { { 1, 2 }, { 1, -2 }, { 2, 1 }, { 2, -1 }, { -1, -2 }, { -1, 2 }, { -2, 1 }, {-2,-1} };

struct Node{
	int x, y;
	int d;
};

bool judge(int x, int y){
	if (x <= 0 || y <= 0 || x > 8 || y > 8 || a[x][y] == 1)return true;
	return false;
}

int BFS(){
	Node cur;
	cur.x = sx, cur.y = sy, cur.d = 0;
	queue<Node> q;
	q.push(cur);
	Node next;
	while (!q.empty()){
		cur = q.front(), q.pop();
		if (a[cur.x][cur.y] == 1)continue;
		if (cur.x == ex&&cur.y == ey)return cur.d;
		a[cur.x][cur.y] = 1;
		for (int i = 0; i < 8; ++i){
			next.x = cur.x + dir[i][0], next.y = cur.y + dir[i][1];
			if (judge(next.x, next.y))continue;
			next.d = cur.d + 1;
			q.push(next);
		}

	}
	return -1;
}

int main(){
	char s1[5], s2[5];
	while (cin >> s1 >> s2){
		memset(a, 0, sizeof(a));
		sx = s1[0] - 'a' + 1, sy = s1[1] - '0';
		ex = s2[0] - 'a' + 1, ey = s2[1] - '0';
		int ans = BFS();
		cout << "To get from "<<s1<<" to "<<s2<<" takes "<<ans<<" knight moves." << endl;
	}
}