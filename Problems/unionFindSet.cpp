#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;
int parent[MAX_SIZE];
bool isVisit[MAX_SIZE];

void makeSet(int n){
	for (int i = 1; i <= n; ++i)
		parent[i] = i;
}

int find(int x){
	int root = x, t;
	while (root != parent[root])root = parent[root];//all are root
	while (root != x){
		t = parent[x];
		parent[x] = root;
		x = t;
	}
	return x;
}

void unionSet(int a, int b){
	int x = find(a), y = find(b);//union their roots
	if (x != y)
		parent[x] = y;
}

int mainunionset(){
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
			if (isVisit[i])cnt++;//how many liantongkuai
		cout << cnt-1 << endl;
	}
	return 0;
	
}