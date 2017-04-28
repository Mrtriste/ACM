//并查集
//以hdu1232(http://acm.hdu.edu.cn/showproblem.php?pid=1232)为例
//并查集适用于连通块的处理
//核心思想是用一个root节点作为一个集合的代表

#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;
int parent[MAX_SIZE];
bool isVisit[MAX_SIZE];

void makeSet(int n){
	for (int i = 1; i <= n; ++i)
		parent[i] = i;
}

//寻找根节点时同时对路径进行压缩
int find(int x){
	int root = x, t;
	while (root != parent[root])root = parent[root];//all are root
	while (root != x){
		t = parent[x];
		parent[x] = root;//将路径上的每个节点的父节点都设为root
		x = t;
	}
	return x;
}

void unionSet(int a, int b){
	int x = find(a), y = find(b);//union their roots
	if (x != y)
		parent[x] = y;
}

int main(){
	int n, m;
	while (cin >> n >> m){
		makeSet(n);
		int a1, a2;
		while (m-- > 0){
			cin >> a1 >> a2;
			unionSet(a1, a2);
		}
		memset(isVisit, false, sizeof(isVisit));
		for (int i = 1; i <= n; ++i)
			isVisit[find(i)] = true;
		int cnt = 0;
		for (int i = 1; i <= n; ++i)
			if (isVisit[i])cnt++;//标记了多少个根节点，就有多少个连通块
		cout << cnt-1 << endl;//连通块-1就是要搭的“桥”
	}
	return 0;
	
}