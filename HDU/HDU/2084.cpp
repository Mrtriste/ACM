#include <iostream>
#include <algorithm>
using namespace std;

int a[110][110];

int main(){
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= i; ++j)
				cin >> a[i][j];
		}

		for (int i = n-1; i >= 1; --i)
			for (int j = 1; j <= i; ++j)
				a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
		cout << a[1][1] << endl;
			
	}
}