#include <iostream>
#include <algorithm>
using namespace std;

int a[105][105];
int temp[105];
int n, w, h, s, t;

int Solve(){
	int m = 0,sum=0;
	for (int i = 1; i <= h; ++i){
		sum += temp[i];
		if (i > t)sum -= temp[i - t];
		m = max(m, sum);
	}
	return m;
}

int main(){
	while (cin >> n&&n){
		cin >> w >> h;
		int x, y;
		memset(a, 0, sizeof(a));
		memset(temp, 0, sizeof(temp));
		for (int i = 0; i < n; ++i){
			scanf("%d%d", &x, &y);
			a[x][y] = 1;
		}
		cin >> s >> t;
		int mmax = 0;
		for (int i = 1; i <= w; ++i){
			for (int j = 1; j <= h; ++j){
				temp[j] += a[i][j];
				if (i > s)temp[j] -= a[i - s][j];
			}
			if (i >= s)mmax = max(mmax, Solve());
		}
		cout << mmax << endl;
	}
}