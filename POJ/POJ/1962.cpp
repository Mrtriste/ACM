#include <iostream>
#include <algorithm>
using namespace std;

int par[20010];
int dis[20010];
int n;

void Make(){
	for (int i = 1; i <= n; ++i){
		par[i] = i;
		dis[i] = 0;
	}
}

int find(int x){
	if (x != par[x]){
		int temp = par[x];
		par[x] = find(temp);
		dis[x] += dis[temp];
	}
	return par[x];
}

void Union(int a, int b){
	par[a] = b;
	dis[a] = abs(a - b) % 1000;
}

int main(){
	int T; cin >> T;
	while (T--){
		cin >> n;
		Make();
		char c[2]; int x, y;
		while (1){
			scanf("%s", c);
			if (c[0] == 'E'){
				scanf("%d", &x);
				find(x);
				printf("%d\n", dis[x]);
			}
			else if (c[0] == 'I'){
				scanf("%d%d", &x, &y);
				Union(x, y);
			}
			else break;
		}
	}
}