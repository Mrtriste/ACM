#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int a[22][22];
int m, n;
int sx, sy, ex, ey;

int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

bool getDir(int &x, int &y, int t,int i){
	int f= (a[x][y] + t) % 2;
	if (f == 1&&(i==0||i==1))
		return false;
	if(f==0&&(i==2||i==3))
		return false;
	return true;
}

struct Node{
	int x, y;
	int t;
	bool operator<(const Node&node)const{
		return t > node.t;
	}
};

int BFS(){
	Node node;
	node.x = sx, node.y = sy, node.t = 0;
	priority_queue<Node> q;
	q.push(node);
	Node temp;
	int x, y, t;
	a[sx][sy] = -1;
	while (!q.empty()){
		temp = q.top(), q.pop();
		if (ex == temp.x&&ey == temp.y)return temp.t;
		for (int i = 0; i < 4; ++i){
			x = temp.x + dir[i][0];
			y = temp.y + dir[i][1];
			if (x < 0 || y < 0 || x >= m || y >= n)continue;
			if (a[x][y] == -1)continue;
			if (a[x][y] == 0 || a[x][y] == 1){
				int xx = x + dir[i][0], yy = y + dir[i][1];
				if (xx < 0 || yy < 0 || xx >= m || yy >= n)continue;
				node.x = xx, node.y = yy;
				if (getDir(x, y, temp.t, i)) node.t = temp.t + 2;
				else node.t = temp.t + 1;
				q.push(node);	
			}
			else{
				a[x][y] = -1;
				node.x = x, node.y = y, node.t = temp.t+1;
				q.push(node);
			}

		}
	}
	return -1;
}

int main(){
	while (cin >> m >> n){
		string s;
		for (int i = 0; i < m; ++i){
			cin >> s;
			for (int j = 0; j < s.length(); ++j){
				if (s[j] == 'S')a[i][j] = 2, sx = i, sy = j;
				else if (s[j] == 'T')a[i][j] = 2, ex = i, ey = j;
				else if (s[j] == '*')a[i][j] = -1;
				else if (s[j] == '.')a[i][j] = 2;
				else if (s[j] == '|')a[i][j] = 1;
				else a[i][j] = 0;
			}
		}
		cout << BFS() << endl;
	}
}