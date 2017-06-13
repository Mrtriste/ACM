#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int parent;
	bool repair;
};
int p[1010][2];
Node node[1010];
vector<int> G[1010];

int find(int x){
	int root = x, t;
	while (node[root].parent != root)root = node[root].parent;
	while (node[x].parent != root){
		t = node[x].parent;
		node[x].parent = root;
		x = t;
	}
	return root;
}

void Union(int x, int y){
	int a = find(x), b = find(y);
	if (a != b)
		node[a].parent = b;
}

int main(){
	int n, d; cin >> n >> d;
	for (int i = 1; i <= n; ++i)
		cin >> p[i][0] >> p[i][1];
	int x, y;
	for (int i = 1; i < n; ++i){
		for (int j = i + 1; j <= n; ++j){
			x = p[i][0] - p[j][0], y = p[i][1] - p[j][1];
			if ((x*x + y*y) <= d*d)
				G[i].push_back(j), G[j].push_back(i);
		}
	}

	for (int i = 1; i <= n; ++i)
		node[i].parent = i, node[i].repair = false;

	char c;
	while (cin >> c){
		if (c == 'O'){
			cin >> x;
			node[x].repair = true;
			for (int i = 0; i < G[x].size(); ++i)
				if (node[G[x][i]].repair)
					Union(x, G[x][i]);
			G[x].clear();
		}
		else{
			cin >> x >> y;
			if (node[x].repair&&node[y].repair && (find(x) == find(y)))puts("SUCCESS");
			else puts("FAIL");
		}
	}
	system("pause");

}