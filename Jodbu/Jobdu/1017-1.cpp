#include <iostream>
#include <algorithm>
using namespace std;

const int maxN10171 = 102;
int pre1[maxN10171];

void makeSet1(){
	for (int i = 0; i < maxN10171; ++i)
		pre1[i] = i;
}

int find1(int x){
	int root = x, t;
	while (root != pre1[root])root = pre1[root];
	while (x!=root){
		t = pre1[x];
		pre1[x] = root;
		x = t;
	}
	return root;
}

void Union1(int x, int y){
	int a = find1(x), b = find1(y);
	if (a != b)
		pre1[a] = b;
}

struct Node2{
	int u;
	int v;
	int weight;
};

bool cmp(const Node2&a, const Node2&b){
	return a.weight < b.weight;
}

int main10171(){
	int N;
	Node2 edge[5060];
	while (cin >> N){
		if (N == 0)break;
		makeSet1();
		int a, b, c;
		int M = N*(N - 1) / 2;
		for (int i = 0; i < M; ++i){
			cin >> a >> b >> c;
			edge[i].u = a;
			edge[i].v = b;
			edge[i].weight = c;
		}

		sort(edge, edge + M, cmp);
		int dis = 0;
		for (int i = 0; i < M; ++i){
			int u = edge[i].u, v = edge[i].v, w = edge[i].weight;
			if (find1(u) != find1(v)){
				Union1(u, v);
				dis += w;
			}
		}
		cout << dis << endl;
	}
	return 0;
}