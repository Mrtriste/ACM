#include <iostream>
#include <queue>
using namespace std;

int a[55][55][55];
int A, B, C, T;
int ex, ey,ez;
int dir[6][3] = { { 1, 0, 0 }, { -1, 0, 0 }, { 0, -1, 0 }, { 0, 1, 0 }, { 0, 0, 1 }, { 0, 0, -1 } };

struct Node{
	int x, y, z;
	int d;
	bool operator<(const Node&a)const{
		return d > a.d;
	}
};

bool judge(int x, int y, int z,int t){
	if (x < 0 || y < 0 || z < 0 || x >= A || y >= B || z >= C || a[x][y][z] == 1)return true;
	if ((t + A - 1 - x + B - 1 - y + C - 1 - z) > T)return true;
	return false;
}

int BFS(){
	Node cur;
	cur.x = cur.y = cur.z = cur.d = 0;
	queue<Node> q;
	q.push(cur);
	Node next;
	while (!q.empty()){
		cur = q.front(), q.pop();
		if (cur.x!=0&&cur.y!=0&&cur.z!=0&&a[cur.x][cur.y][cur.z] == 1)continue;
		a[cur.x][cur.y][cur.z] = 1;
		if (ex == cur.x&&ey == cur.y&&ez == cur.z&&cur.d<=T)return cur.d;
		for (int i = 0; i < 6; ++i){
			next.x = cur.x + dir[i][0], next.y = cur.y + dir[i][1], next.z = cur.z + dir[i][2];
			next.d = cur.d + 1;
			if (judge(next.x, next.y, next.z,next.d))continue;
			q.push(next);
		}
	}
	return -1;
}

int main(){
	int K; cin >> K;
	while (K--){
		cin >> A >> B >> C >> T;
		int i, j, k;
		for (i = 0; i < A; ++i)
			for (j = 0; j < B; ++j)
				for (k = 0; k < C; ++k)
					scanf("%d", &a[i][j][k]);
		ex = A - 1, ey = B - 1, ez = C - 1;
		int ans = BFS();
		cout << ans << endl;
	}
}