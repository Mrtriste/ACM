#include <iostream>
#include <algorithm>
using namespace std;

int a[105][105];

int main(){
	int n;
	while (cin >> n){
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= i; ++j)
				scanf("%d", &a[i][j]);
		for (int i = 0; i < 105; ++i)
			a[n+1][i] = 0;
		for (int i = n; i >= 1; --i)
			for (int j = 1; j <= i; ++j)
				a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
			
		cout << a[1][1] << endl;
	}
}