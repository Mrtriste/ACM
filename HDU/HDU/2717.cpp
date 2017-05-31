#include <iostream>
#include <queue>
using namespace std;

bool a[100010];
int n, k;

struct Node{
	int x, d;
	bool operator<(const Node& node)const{
		return d > node.d;
	}
};

bool judge(int x){
	if (x<0 || x>100000 || a[x])return true;
	return false;
}

int BFS(){
	Node cur, next;
	cur.x = n, cur.d = 0;
	queue<Node> q;
	q.push(cur);
	while (!q.empty()){
		cur = q.front(), q.pop();
		if (a[cur.x])continue;
		a[cur.x] = 1;
		if (cur.x == k)return cur.d;
		next.d = cur.d + 1;
		for (int i = -1; i <= 1; i += 2){
			next.x = cur.x + i;
			if (judge(next.x))continue;
			q.push(next);
		}
		next.x = cur.x * 2;
		if (!judge(next.x))
			q.push(next);
	}
	return -1;
}

int main(){
	while (cin >> n >> k){
		memset(a, 0, sizeof(a));
		if (n >= k){
			cout << (n - k) << endl;
			continue;
		}
		int ans = BFS();
		cout << ans << endl;
	}
}