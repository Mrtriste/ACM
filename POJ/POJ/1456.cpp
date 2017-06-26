#include <iostream>
#include <algorithm>
using namespace std;

int par[10010];

struct Node{
	int p, d;
	bool operator<(const Node&n){
		return p > n.p;
	}
};

Node a[10010];

void Make(){
	for (int i = 1; i < 10010; ++i)
		par[i] = i;
}

int find(int x){
	int root = x, t;
	while (root!=par[root])root = par[root];
	while (x != root){
		t = x;
		x = par[x];
		par[t] = root;
	}
	return root;
}

int main(){
	int n;
	while (cin >> n){
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &(a[i].p), &(a[i].d));
		sort(a, a + n);
		Make();
		int mmax = 0;
		for (int i = 0; i < n; ++i){
			int day = find(a[i].d);
			if (day > 0){
				mmax += a[i].p;
				par[day] = day - 1;
			}
		}
		cout << mmax << endl;
	}
}