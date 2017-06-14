#include <iostream>
using namespace std;

int p[30010];
int dis[30010];
int size[30010];

void Make(){
	for (int i = 1; i <= 30000; ++i)
		p[i] = i, size[i] = 1;
	memset(dis, 0, sizeof(dis));
}

int find(int x){
	if (x != p[x]){
		int temp = p[x];
		p[x] = find(temp);
		dis[x] += dis[temp];
	}
	return p[x];
}

void Union(int x, int y){
	int a = find(x), b = find(y);
	p[a] = b;
	dis[a] += size[b];
	size[b] += size[a];
	size[a] = 0;
}


int main(){
	int P; cin >> P;
	char s[2]; int x, y;
	Make();
	while (P--){
		scanf("%s", s);
		if (s[0] == 'M'){
			scanf("%d %d",&x, &y);
			Union(x, y);
		}
		else{
			scanf("%d", &x);
			find(x);
			cout << dis[x] << endl;
		}
	}
}