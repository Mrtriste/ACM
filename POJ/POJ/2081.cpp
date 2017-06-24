#include <iostream>
using namespace std;

bool vis[4000010];
int a[500010];

int main(){
	memset(vis, 0, sizeof(vis));
	a[0] = 0, vis[0] = 1;
	int k = 500000;
	for (int i = 1; i <= k; ++i){
		int t = a[i - 1] - i;
		if (t > 0 && !vis[t])
			a[i] = t, vis[t] = 1;
		else a[i] = a[i - 1] + i, vis[a[i]] = 1;
	}
	//for (int i = 0; i < 20; ++i)
	//	cout << a[i] << " ";
	//for (int i = k; i >= k - 10; --i)
	//	cout << a[i] << endl;
	int s;
	while (cin >> s&&s >= 0){
		cout << a[s] << endl;
	}
	system("pause");
}