#include <iostream>
using namespace std;

char a[10][10];
int n, k;
bool col[10];
int cnt;

bool judge(int r, int c){
	if (a[r][c]=='.' || col[c])return true;
	return false;
}

void DFS(int r, int c, int t){//t-th qizi
	if (t == k){
		cnt++;
		return;
	}
	for (int j = r + 1; j <= n - k + t;++j)
		for (int i = 0; i < n; ++i){
			if (judge(j, i))continue;
			col[i] = 1;
			DFS(j, i,t+1);
			col[i] = 0;
		}
}

int main(){
	while (cin >> n >> k&&n > 0){
		for (int i = 0; i < n; ++i)
			scanf("%s", &a[i]);
		cnt = 0;
		for (int j = 0; j <= n - k;++j)
			for (int i = 0; i < n; ++i){
				if (!judge(j,i)){
					col[i] = 1;
					DFS(j, i, 1);
					col[i] = 0;
				}
			}
		cout << cnt << endl;
	}
}