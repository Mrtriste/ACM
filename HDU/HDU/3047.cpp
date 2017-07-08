#include <iostream>
using namespace std;

int par[50010], dis[50010];
int n, m;

void Make(){
	for (int i = 1; i <= n; ++i)
		par[i] = i, dis[i] = 0;
}

int find(int x){
	if (x != par[x]){
		int temp = par[x];
		par[x] = find(temp);
		dis[x] = (dis[temp] + dis[x])%300;
	}
	return par[x];
}

bool Union(int x, int y,int d){
	int a = find(x), b = find(y);
	if (a != b){
		par[b] = a;
		dis[b] = d + dis[x] - dis[y];
		return false;
	}
	else{
		if (d % 300 == (dis[y] - dis[x] + 300) % 300)return false;
		return true;
	}
}

int main(){
	while (cin >> n >> m){
		Make();
		int a, b, x, cnt = 0;
		while (m--){
			scanf("%d%d%d", &a, &b, &x);
			if (Union(a, b, x))++cnt;
		}
		cout << cnt << endl;
	}
}