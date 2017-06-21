#include <iostream>
using namespace std;

int a[10010],sum[10010], n;
int vis[10010];

int main(){
	while (cin >> n){
		sum[0] = 0;
		int f1=-1, f2=-1, f3=-1;
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; ++i){
			scanf("%d", &a[i]);
			sum[i] = (sum[i - 1] + a[i])%n;
		}
		for (int i = 1; i <= n; ++i){
			if (sum[i] == 0){
				f1 = i; break;
			}
			if (vis[sum[i]]){
				f2 = vis[sum[i]], f3 = i;
				break;
			}
			vis[sum[i]] = i;
		}

		if (f1 != -1){
			cout << f1 << endl;
			for (int i = 1; i <= f1; ++i)
				cout << a[i] << endl;
		}
		if (f2 != -1){
			cout << f3 - f2 << endl;
			for (int i = f2 + 1; i <= f3; ++i)
				cout << a[i] << endl;
		}
	}
}