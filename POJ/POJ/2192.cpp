#include <iostream>
using namespace std;

bool dp[205][205];
char a[205], b[205], c[510];

int main(){
	int T,t=1; cin >> T;
	while (T--){
		scanf("%s%s%s", a, b, c);
		int lena = strlen(a), lenb = strlen(b), lenc = strlen(c);
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 0; i <= lena; ++i){
			for (int j = 0; j <= lenb; ++j){
				if (i + j == 0)continue;
				if (j>0&&dp[i][j - 1] && b[j - 1] == c[i+j - 1])dp[i][j] = 1;
				if (i>0&&dp[i - 1][j] && a[i - 1] == c[i+j - 1])dp[i][j] = 1;
			}
		}
		printf("Data set %d: %s\n", t++, dp[lena][lenb] ? "yes" : "no");
	}
}