#include <iostream>
#include <algorithm>
using namespace std;

char a[110], b[110];
int dp[110][110];

int getValue(char x, char y){
	if (x > y)swap(x, y);
	if (x == y)return 5;
	if (x == '-'){
		if (y == 'A')return -3;
		if (y == 'C')return -4;
		if (y == 'G')return -2;
		if (y == 'T')return -1;
	}
	if (x == 'A'){
		if (y == 'C')return -1;
		if (y == 'G')return -2;
		if (y == 'T')return -1;
	}
	if (x == 'C'){
		if (y == 'G')return -3;
		if (y == 'T')return -2;
	}
	if(x == 'G')
		if (y == 'T')return -2;
}

int main(){
	int T; cin >> T;
	int la, lb;
	while (T--){
		scanf("%d%s%d%s",&la, a+1,&lb, b+1);
		dp[0][0] = 0;
		for (int i = 1; i <= strlen(a+1); ++i)
			dp[i][0] = dp[i-1][0]+getValue('-', a[i]);
		for (int i = 1; i <= strlen(b+1); ++i)
			dp[0][i] = dp[0][i-1]+getValue('-', b[i]);
		for (int i = 1; i <= strlen(a+1); ++i){
			for (int j = 1; j <= strlen(b+1); ++j){
				int mmax = max(dp[i - 1][j] + getValue(a[i], '-'), dp[i][j - 1] + getValue(b[j], '-'));
				mmax = max(mmax, dp[i - 1][j - 1] + getValue(a[i],b[j]));
				dp[i][j] = mmax;
			} 
		}
		cout << dp[strlen(a+1)][strlen(b+1)] << endl;
	}
}