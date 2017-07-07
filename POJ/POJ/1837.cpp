#include <iostream>
using namespace std;

int C, G;
int c[21], w[21];
int dp[21][15001];

int main(){
	while (cin >> C >> G){
		for (int i = 1; i <= C; ++i)cin >> c[i];
		for (int i = 1; i <= G; ++i)cin >> w[i];
		memset(dp, 0, sizeof(dp));
		dp[0][7500] = 1;
		for (int i = 1; i <= G; ++i){
			for (int j = 0; j <= 15000; ++j){
				if (dp[i - 1][j]){
					for (int k = 1; k <= C; ++k)
						dp[i][j + w[i] * c[k]] += dp[i - 1][j];
				}
			}
		}
		cout << dp[G][7500] << endl;
				
	}
}