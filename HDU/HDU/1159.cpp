#include <iostream>
#include <algorithm>
using namespace std;

char a[10000], b[10000];
int dp[1010][1010];

int main(){
	while (cin >> a >> b){
		int alen = strlen(a), blen = strlen(b);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= alen; ++i){
			for (int j = 1; j <= blen; ++j){
				if (a[i - 1] == b[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		cout << dp[alen][blen] << endl;
	}
}