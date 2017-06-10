#include <iostream>
#include <queue>
using namespace std;
#define MOD 1000007

typedef long long LL;

struct Node{
	Node(){}
	Node& operator=(Node &n){
		for (int i = 0; i < 4; ++i)
			x[i] = n.x[i], y[i] = n.y[i];
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 8; ++j)
				s[i][j] = n.s[i][j];
		d = n.d;
		return *this;
	}
	int x[4], y[4];
	int s[4][8];
	int d;
	
};
Node start;
bool vis[MOD];
int goal[4][8] = {
	11, 12, 13, 14, 15, 16, 17, 0,
	21, 22, 23, 24, 25, 26, 27, 0,
	31, 32, 33, 34, 35, 36, 37, 0,
	41, 42, 43, 44, 45, 46, 47, 0
};

LL gethash(Node &t)
{
	int tmp[70], k = 0;
	memset(tmp, 0, sizeof(tmp));
	int i, j;
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<8; j++)
		{
			tmp[k++] = t.s[i][j] / 10;
			tmp[k++] = t.s[i][j] % 10;
		}
	}
	long long hash = 0;
	for (i = 0; i<k; i++)
	{
		hash = hash * 7 + tmp[i];
	}
	hash = (hash & 0x7fffffff) % MOD;
	return hash;
}

bool isGoal(Node &n){
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 8; ++j){
			//cout << n.s[i][j] << " " << goal[i][j] << endl;
			if (n.s[i][j] != goal[i][j])
				return false;
		}
	}
		
			
	return true;
}

int BFS(){
	queue<Node> q;
	q.push(start);
	Node cur;
	while (!q.empty()){
		cur = q.front(), q.pop();
		if (vis[gethash(cur)])continue;
		//cout << cur.d << endl;
		if (isGoal(cur))return cur.d;
		vis[gethash(cur)] = 1;
		for (int i = 0; i < 4; ++i){
			for (int j = 1; j < 8; ++j){
				for (int k = 0; k < 4; ++k){
					//cout << cur.x[k] << " " << cur.y[k] << " " << cur.s[cur.x[k]][cur.y[k]-1] << " --- " << i << " " << j << ":" << cur.s[i][j] << endl;
					if (cur.s[i][j] == cur.s[cur.x[k]][cur.y[k]-1]+1){
						
						Node t=cur;
						t.s[cur.x[k]][cur.y[k]] = cur.s[i][j];
						t.x[k] = i, t.y[k] = j;
						t.s[i][j] = 0;
						t.d = cur.d + 1;
						//cout << "add " << cur.x[k] << " " << cur.y[k] << endl;
						if (vis[gethash(t)])continue;
						//cout << "ddd" << endl;
						q.push(t);
					}
				}
			}
		}
	}
	return -1;
}

int main(){
	int T; cin >> T;
	while (T--){
		int t, cnt = 0;
		start.s[0][0] = 11, start.s[1][0] = 21, start.s[2][0] = 31, start.s[3][0] = 41;
		for (int i = 0; i < 4; ++i){
			for (int j = 1; j < 8; ++j){
				cin >> t;
				if (t % 10 == 1){
					t = 0;
					start.x[cnt] = i, start.y[cnt++] = j;
				}
				start.s[i][j] = t;
				//cout << t << " ";
			}
			//cout << endl;
		}
		start.d = 0;
		memset(vis, 0, sizeof(vis));
		cout << BFS() << endl;

	}
}