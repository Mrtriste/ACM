#include <iostream>
#include <queue>
#include <string>
using namespace std;

int a[102][102];
bool vis[102][102];
int ex, ey;
int m, n;
int t;
int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };




struct Node{
	int x;
	int y;
	int sec;
	bool operator<(const Node&node)const{
		return sec > node.sec;
	}
};
Node rec[102][102];

int BFS(){
	priority_queue<Node>q;
	Node cur;
	cur.x = cur.y = cur.sec = 0;
	q.push(cur);
	Node temp;
	while (!q.empty()){
		temp = q.top(); q.pop();
		for (int i = 0; i < 4; ++i){
			cur.x = temp.x + dir[i][0];
			cur.y = temp.y + dir[i][1];
			cur.sec = temp.sec + 1 + a[cur.x][cur.y];
			if (cur.x < 0 || cur.y < 0 || cur.x >= n || cur.y >= m)continue;
			if (cur.x == ex&&cur.y == ey){
				rec[cur.x][cur.y].x = temp.x;
				rec[cur.x][cur.y].y = temp.y;
				rec[cur.x][cur.y].sec = temp.sec;
				return cur.sec;
			}
			if (a[cur.x][cur.y] == -1||vis[cur.x][cur.y])continue;
			vis[cur.x][cur.y] = 1;
			rec[cur.x][cur.y].x = temp.x;
			rec[cur.x][cur.y].y = temp.y;
			rec[cur.x][cur.y].sec = temp.sec;
			q.push(cur);
		}
	}
	return -1;
}

void Print(int x, int y){
	int xx = rec[x][y].x, yy = rec[x][y].y;
	if (x == 0 && y == 0)
		return;
	Print(xx, yy);
	cout << (++t) << "s:(" << xx << "," << yy << ")->(" << x << "," << y << ")\n";
	while (a[x][y]){
		cout << (++t) << "s:FIGHT AT (" << x << "," << y << ")\n" ;
		--a[x][y];
	}
	
}

int main(){
	
	while (cin >> n >> m){
		string s;
		for (int i = 0; i < n; ++i){
			cin >> s;
			for (int j = 0; j < s.length(); ++j){
				if (s[j] == '.')a[i][j] = 0;
				else if (s[j] == 'X')a[i][j] = -1;
				else a[i][j] = s[j] - '0';
			}
		}
		ex = n - 1, ey = m - 1;
		memset(vis, 0, sizeof(vis));
		vis[0][0] = 1;
		int ans = BFS();
		if (ans == -1)cout << "God please help our poor hero." << endl;
		else{
			cout << "It takes " << ans << " seconds to reach the target position, let me show you the way." << endl;
			t = 0;
			Print(n - 1, m - 1);
		}
		cout << "FINISH" << endl;

	}
	return 1;
}