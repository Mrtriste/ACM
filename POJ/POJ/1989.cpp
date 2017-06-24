#include <iostream>
using namespace std;

int main(){
	int n,k,t;
	bool vis[10010];
	cin >> n >> k;
	memset(vis, 0, sizeof(vis[0])*(k+5));
	
	int ans = 1,cnt = 0;
	for (int i = 0; i < n; ++i){
		scanf("%d", &t);
		if (!vis[t])
			vis[t] = 1, ++cnt;
		if (cnt == k){
			++ans, cnt = 0;
			memset(vis, 0, sizeof(vis[0])*(k + 5));
		}
	}
	cout << ans << endl;
	system("pause");
}