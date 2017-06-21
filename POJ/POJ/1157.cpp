#include <iostream>
#include <algorithm>
using namespace std;

int dp[105][105];
int a[105][105];
int F, V;

int main(){
	while (cin >> F >> V){
		for (int i = 1; i <= F; ++i)
			for (int j = 1; j <= V; ++j)
				scanf("%d", &a[i][j]);
		dp[0][0] = 0;
		for (int i = 1; i <= F; ++i){
			for (int j = 1; j <= V; ++j){
				if (j>i)
					dp[i][j] = max(dp[i - 1][j - 1] + a[i][j], dp[i][j - 1]);
				if (j == i)
					dp[i][j] = dp[i - 1][j - 1] + a[i][j];
			}
		}	
		cout << dp[F][V] << endl;
	}
}