//克鲁斯卡尔算法——最小生成树
//核心思想是将图中的每条边排序，每次选一个最小的边，看加入这条边后是否会和已经选的那些点构成环，如果不会的话就将这条边的两个点加入集合
//至于如何判断环，用并查集
//HDU1233

#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int u, v, d;
	Node(){}
	Node(int uu, int vv, int dd) :u(uu), v(vv), d(dd){}
	bool operator<(const Node& n){
		return d < n.d;
	}
};

int n;
int par[110];
Node edge[5010];

void Make(){
	for (int i = 1; i <= 110; ++i)
		par[i] = i;
}

int find(int x){
	int root = x, r;
	while (root != par[root])root = par[root];
	while (x != root){
		r = par[x];
		par[x] = root;
		x = r;
	}
	return root;
}

void Union(int x, int y){
	int a = find(x), b = find(y);
	if (a != b)
		par[a] = b;
}

int main(){
	while (cin >> n&&n){
		Make();
		int a, b, l, cnt = 1,ans=0;
		int m = n*(n - 1) / 2;
		for (int i = 0; i < m; ++i){
			scanf("%d%d%d", &a, &b, &l);
			edge[i] = Node(a, b, l);
		}
		sort(edge, edge + m);
		for (int i = 0; i < m; ++i){
			int u = edge[i].u, v = edge[i].v, d = edge[i].d;
			if (find(u) != find(v)){
				Union(u, v);
				ans += d;
				if (++cnt == n)break;//there are n-1 edges at most
			}
		}
		cout << ans << endl;
	}
}