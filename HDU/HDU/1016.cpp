#include <iostream>
#include <math.h>
using namespace std;

int n;
int a[20];
bool prime[40];
bool vis[40];

void gePrime(){
	memset(prime, true, sizeof(prime));
	for (int i = 2; i < 40; ++i){
		if (prime[i]){
			for (int j = i + i; j < 40; j += i)
				prime[j] = false;
		}
	}
}


void DFS(int depth){
	if (depth == n){
		if (prime[a[n-1]+a[0]]){
			for (int i = 0; i < n - 1; ++i)
				cout << a[i] << " ";
			cout << a[n - 1] << endl;
		}
		return;
	}
	for (int i = 2; i <= n; ++i){
		if (!vis[i] && prime[a[depth - 1] + i]){
			a[depth] = i;
			vis[i] = 1;
			DFS(depth + 1);
			vis[i] = 0;
		}
	}

}

int main(){
	int t = 1;
	gePrime();
	while (cin >> n){
		cout << "Case " << (t++) << ":" << endl;
		a[0] = 1;
		memset(vis, false, sizeof(vis));
		DFS(1);
		cout << endl;
	}
}