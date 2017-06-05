#include <iostream>
using namespace std;

long long a[110][110];

int main(){
	int n, p, m, t;
	while (cin >> n >> p >> m >> t){
		memset(a, 0, sizeof(a));
		a[0][p] = 1;
		for (int j = 1; j <= m; ++j){
			for (int i = 1; i <= n; ++i){
				a[j][i] = a[j - 1][i - 1] + a[j - 1][i + 1];
			}
		}
		cout << a[m][t] << endl;
	}
}