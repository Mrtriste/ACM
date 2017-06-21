#include <iostream>
#include <algorithm>
using namespace std;

int e[105][105];
int n;

int main(){
	while (cin >> n&&n){
		memset(e, 0x3f, sizeof(e));
		for (int i = 1; i <= n; ++i)
			e[i][i] = 0;
		int m,a,b;
		for (int i = 1; i <= n; ++i){
			cin >> m;
			for (int j = 0; j < m; ++j){
				cin >> a >> b;
				e[i][a] = b;
			}
		}

		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					e[i][j] = min(e[i][k] + e[k][j],e[i][j]);
		int mmin = 0x3f3f3f3f,flag;
		for (int i = 1; i <= n; ++i){
			int mmax = 0;
			for (int j = 1; j <= n; ++j)
				mmax = max(mmax, e[i][j]);
			if (mmin > mmax){
				flag = i; mmin = mmax;
			}
		}
		cout << flag << " " << mmin << endl;

	}
}