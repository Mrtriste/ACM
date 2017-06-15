#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node{
	int v, l, c;
	Node(){}
	Node(int vv, int ll, int cc) :v(vv), l(ll), c(cc){}
	bool operator<(const Node&b)const{
		if (l != b.l)return l > b.l;
		return c > b.c;
	}
};

vector<Node> G[110];
int k, n, m;

int BFS(){
	priority_queue<Node> q;
	Node cur;
	cur.v = 1, cur.l = 0, cur.c = 0;
	q.push(cur);
	while (!q.empty()){
		cur = q.top(), q.pop();
		if (cur.v == n)return cur.l;
		for (int i = 0; i < G[cur.v].size(); ++i){
			int v = G[cur.v][i].v, l = G[cur.v][i].l+cur.l, c = G[cur.v][i].c+cur.c;
			if (c > k)continue;
			q.push(Node(v, l, c));
		}
	}
	return -1;
}

int main(){
	
	cin >> k >> n >> m;
	int s, d, l, c;
	for (int i = 0; i < m; ++i){
		cin >> s >> d >> l >> c;
		G[s].push_back(Node(d, l, c));
		//G[d].push_back(Node(s, l, c));
	}
	cout << BFS() << endl;
	system("pause");
}