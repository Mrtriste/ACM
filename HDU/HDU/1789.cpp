#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int ddl;
	int s;
};

bool cmp(const Node&a, const Node&b){
	return a.s > b.s;
}

Node node[1010];
bool vis[1010];

int main(){
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		memset(vis, 0, sizeof(vis));
		int a;
		for (int i = 1; i <= n; ++i){
			cin >> a;
			if (a > n)a = n;
			node[i].ddl = a;
		}

		for (int i = 1; i <= n; ++i){
			cin >> a;
			node[i].s = a;
		}
		sort(node + 1, node + 1 + n, cmp);
		bool flag;
		int red = 0;
		for (int i = 1; i <= n; ++i){
			flag = false;
			for (int j = node[i].ddl; j > 0; --j){
				if (!vis[j]){
					vis[j] = true, flag = true;
					break;
				}
			}
			if (!flag)red += node[i].s;
		}
		cout << red << endl;

	}
}