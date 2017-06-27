#include <iostream>
#include <algorithm>
using namespace std;

int dp[105][105];
int c[105][105] = {-1};
char a[105];

void print(int i, int j){
	if (i>j)return;
	if (j == i){
		if (a[i] == '(' || a[i] == ')')cout << "()";
		else cout << "[]";
		return;
	}
	int k = c[i][j];
	if (k<0){
		cout << a[i];
		print(i + 1, j - 1);
		cout << a[j];
	}
	else{
		print(i, k);
		print(k + 1, j);
	}
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (cin>>a){//scanf("%s", a)!=EOF
		//cin >> a;
		int len = strlen(a);
		memset(dp, 0, sizeof(dp));
		memset(c, -1, sizeof(c));
		for (int i = 0; i < len; ++i)
			dp[i][i] = 1;
		for (int l = 1; l < len; ++l){
			for (int i = 0; i + l < len; ++i){
				int j = i + l;//dp[i][j]
				int mmin = 1000;
				for (int k = i; k < j; ++k){
					if (mmin>dp[i][k] + dp[k + 1][j]){
						mmin = dp[i][k] + dp[k + 1][j];
						c[i][j] = k;
					}
				}
				if ((a[i] == '('&&a[j] == ')') || (a[i] == '['&&a[j] == ']')){
					if (mmin>dp[i + 1][j - 1]){
						mmin = dp[i + 1][j - 1];
						c[i][j] = -1;
					}
				}
				dp[i][j] = mmin;
			}
		}
		print(0, len - 1);
		cout << endl;
	}
}