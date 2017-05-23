#include <iostream>
#include <queue>
using namespace std;

int arr[10][10];
bool vis[10][10][10];
int m, n;
int sx, sy, ex, ey;
int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };

struct Node{
	int x;
	int y;
	int used_time;
	int remain_time;
	bool operator<(const Node&a)const{
		if (used_time != a.used_time)
			return used_time > a.used_time;
		else
			return remain_time < a.remain_time;
	}
};

bool judge(int x, int y){
	if (x < 0 || x >= n || y < 0 || y >= m)return true;
	if (arr[x][y] == 0)return true;
	return false;
}

int BFS(int x, int y){
	priority_queue<Node> q;
	Node cur, temp;
	cur.x = x, cur.y = y, cur.remain_time = 6, cur.used_time = 0;
	q.push(cur);
	arr[x][y] = 0;
	
	while (!q.empty()){
		cur = q.top(); q.pop();
		if (cur.x == ex&&cur.y == ey&&cur.remain_time>0)return cur.used_time;
		if (cur.remain_time > 1){
			for (int i = 0; i < 4; ++i){
				temp.x = cur.x + dir[i][0];
				temp.y = cur.y + dir[i][1];
				temp.used_time = cur.used_time + 1;
				temp.remain_time = cur.remain_time - 1;
				if (temp.remain_time>0 && arr[temp.x][temp.y] == 4){
					temp.remain_time = 6;
				}
				if (judge(temp.x, temp.y) || temp.remain_time == 0 || vis[temp.x][temp.y][temp.remain_time] == 1)continue;
				if (arr[temp.x][temp.y] == 4)
					arr[temp.x][temp.y] = 0;
				vis[temp.x][temp.y][temp.remain_time] = 1;
				q.push(temp);
			}
		}

			
	}
	return -1;
}

int main(){
	int t;cin >> t;
	for (int e = 0; e < t; ++e){
		cin >> n >> m;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				cin >> arr[i][j];
				if (arr[i][j] == 2)
					sx = i, sy = j;
				if (arr[i][j] == 3)
					ex = i, ey = j;
			}
		}
		cout << BFS(sx, sy) << endl;

			
	}
}