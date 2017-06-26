#include <iostream>
using namespace std;

char a[100];
int dp[100];

bool greater(int m, int n, int x, int y){
	while (m < n&&a[m] == '0')m++;
	while (x < y&&a[x] == '0')x++;
	if ((n - m) > y - x)return true;
	if (n - m < y-x)return false;
	for (int i = 0; i <= n - m; ++i){
		if (a[m + i] > a[x + i])return true;
		else if(a[m + i] < a[x + i])
			return false;
	}
	return false;
}

int main(){
	while (cin >> (a+1)&&strcmp(a+1, "0")){
		int len = strlen(a + 1);
		dp[1] = 1;
		for (int i = 2; i <= len; ++i){
			dp[i] = i;
			for (int l = 1; l < i; ++l){
				if (greater(i - l+1, i, i - l- dp[i - l] + 1, i - l)){
					dp[i] = l;
					break;
				}
			}
				
		}
		int start = len - dp[len] + 1;
		dp[start] = dp[len];
		for (int i = start - 1; i >= 1; --i){
			if (a[i] == '0'){
				dp[i] = dp[i + 1] + 1;
				continue;
			}
			for (int j = start; j > i; --j){
				if (greater(j, j + dp[j] - 1,i, j - 1)){
					dp[i] = j - i;
					break;
				}
			}
		}
		for (int i = 1; i <= dp[1]; ++i)
			cout << a[i];
		int t = dp[1] + 1;
		while (t <= len){
			cout << ",";
			for (int j = t; j <= t + dp[t] - 1; ++j)
				cout << a[j];
			t = dp[t] + t;
		}
		puts("");
	}
}