#include <iostream>
#include <queue>
using namespace std;

int a[210];
int d[210];
bool vis[210];
int dir[2] = { 1, -1 };
int s, e;
int n;

struct Node{
	int x, d;
};

bool judge(int x){
	if (x < 1 || x > n||vis[x]==1)return true;
	return false;
}

int BFS(){
	queue<Node> q;
	Node cur, next;
	cur.x = s, cur.d = 0;
	q.push(cur);
	
	//d[s] = 0;
	while (!q.empty()){
		cur = q.front(), q.pop();
		if (vis[cur.x])continue;
		if (cur.x == e)return cur.d;
		vis[cur.x] = 1;
		for (int i = 0; i < 2; ++i){
			next.x = cur.x + (dir[i] * a[cur.x]);
			if (judge(next.x))continue;
			next.d= cur.d + 1;
			q.push(next);
		}
	}
	return -1;

}

int main(){
	while (cin >> n){
		if (n == 0)break;
		cin >> s >> e;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		memset(vis, 0, sizeof(vis));
		int ans = BFS();
		cout << ans << endl;
	}
}