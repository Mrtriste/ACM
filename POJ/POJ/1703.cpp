#include <iostream>
using namespace std;

int par[100010];
int r[100010];//0 :the same with fa

int n,m;

void Make(){
	for (int i = 1; i <= n; ++i)
		par[i] = i;
	memset(r, 0, sizeof(r));
}

int find(int x){
	if (x != par[x]){
		int temp = par[x];
		par[x] = find(temp);
		r[x] = (r[x] ^ r[temp]);
	}
	return par[x];
}

void Union(int x, int y){
	int a = find(x), b = find(y);
	if (a != b){
		par[b] = a;
		r[b] = ~(r[x] ^ r[y]);
	}
}

int main(){
	int T; cin >> T;
	char c[2]; int x, y;
	while (T--){
		cin >> n >> m; 
		Make();
		for (int i = 0; i < m; ++i){
			scanf("%s %d %d", c, &x, &y);
			if (c[0] == 'A'){
				int a = find(x), b = find(y);
				if (a != b)puts("Not sure yet.");
				else{
					if (r[x] == r[y])puts("In the same gang.");
					else puts("In different gangs.");
				}
			}
			else Union(x, y);
		}
	}
}