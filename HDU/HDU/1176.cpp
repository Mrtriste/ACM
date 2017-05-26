#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int a[100010][13];

int main(){
	int n;
	while (scanf("%d", &n)!=EOF&&n!=0){
		int p, t;
		int maxT = 0;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; ++i){
			scanf("%d%d", &p, &t);
			a[t][p+1]++;
			maxT = max(maxT, t);
		}

		for (int i = maxT; i >=0; --i){
			for (int j = 1; j <= 11; ++j)
				a[i-1][j] += max(a[i][j - 1], max(a[i][j], a[i][j + 1]));
		}
		cout << a[0][6] << endl;
	}
}