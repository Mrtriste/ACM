//带权并查集

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

//let a->b->c->root => a->root,b->root,c->root
int find(int x){
	if (x != par[x]){
		int temp = par[x];//x's father
		par[x] = find(temp);//let x's father be root
		//modify weight,the temp's father is root
		r[x] = (r[x] ^ r[temp]);
	}
	return par[x];
}

//x->a,y->b  with the relation between a and b, let b->a and modify the r[b] relative to r[a]
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