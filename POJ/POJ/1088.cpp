////////////////1: 36k 47ms
#include <iostream>
#include <algorithm>
using namespace std;

int a[105][105];
int dp[105][105];
int R, C;
int dir[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };

int DFS(int x,int y){
	if (dp[x][y] > 0)return dp[x][y];
	int xx, yy;
	int mmax = 1;
	for (int i = 0; i < 4; ++i){
		xx = x + dir[i][0], yy = y + dir[i][1];
		if (xx < 0 || yy < 0 || xx >= R || yy >= C)continue;
		if (a[x][y] > a[xx][yy])mmax = max(DFS(xx, yy) + 1, mmax);
	}
	dp[x][y] = mmax;
	return mmax;
}

int main(){
	while (cin >> R >> C){
		for (int i = 0; i < R; ++i){
			for (int j = 0; j < C; ++j){
				cin >> a[i][j];
				dp[i][j] = 0;
			}
		}
		int mmax = 0;
		for (int i = 0; i < R; ++i){
			for (int j = 0; j < C; ++j){
				dp[i][j] = DFS(i, j);
				mmax = max(dp[i][j], mmax);
			}
		}
		cout << mmax << endl;
	}
	system("pause");
}

///////////////////////////////2:  560k 63ms
#include <iostream>
#include <queue>
using namespace std;

int dp[105][105];
int a[105][105];
int R, C;
int dir[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };

struct Node{
	Node(){}
	Node(int xx,int yy,int hh):x(xx),y(yy),h(hh){}
	int x, y;
	int h;
	bool operator<(const Node&n)const{
		return h > n.h;
	}
};

int main(){
	while (cin >> R >> C){
		priority_queue<Node> q;
		for (int i = 0; i < R; ++i){
			for (int j = 0; j < C; ++j){
				cin >> a[i][j];
				q.push(Node(i, j, a[i][j]));
				dp[i][j] = 1;
			}
		}
		Node cur; int mmax = 0, xx, yy;
		while (!q.empty()){
			cur = q.top(), q.pop();
			int m = dp[cur.x][cur.y];
			for (int i = 0; i < 4; ++i){
				xx = cur.x + dir[i][0], yy = cur.y + dir[i][1];
				if (xx < 0 || yy < 0 || xx >= R || yy >= C)continue;
				if (a[cur.x][cur.y] > a[xx][yy])m = max(dp[cur.x][cur.y] + dp[xx][yy], m);
			}
			dp[cur.x][cur.y] = m;
			mmax = max(mmax, m);
		}
		cout << mmax << endl;
	}
}


