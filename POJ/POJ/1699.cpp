#include <iostream>
#include <algorithm>
using namespace std;

char a[12][22];
int add[12][12];
int n,ans;
bool vis[12];

int ADD(int m, int n){
	int l, i, j, k;
	k = 0;
	for (l = 1; l <= strlen(a[m]) && l <= strlen(a[n]); l++){   //l为两串合并的长度。
		bool sign = true;
		for (i = 0, j = strlen(a[m]) - l; i<l; i++, j++)
			if (a[m][j] != a[n][i]){ sign = false; break; }
		if (sign)k = l;
	}
	return strlen(a[n]) - k;
}


void DFS(int pre,int len,int sum){
	if (sum >= ans)return;
	if (n == len){
		ans = min(ans, sum);
		return;
	}
	for (int i = 0; i < n; ++i){
		if (vis[i])continue;
		vis[i] = true;
		DFS(i, len + 1, sum + add[pre][i]);
		vis[i] = false;
	}
}

int main(){
	int T; cin >> T;
	while (T--){
		cin >> n;
		for (int i = 0; i < n; ++i)
			scanf("%s", a[i]);
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j)
				if (i != j)add[i][j] = ADD(i, j);
		
		memset(vis, 0, sizeof(vis));
		ans = 100000;
		for (int i = 0; i < n; ++i){
			vis[i] = true;
			DFS(i, 1, strlen(a[i]));
			vis[i] = false;
		}
		cout << ans << endl;
	}
}