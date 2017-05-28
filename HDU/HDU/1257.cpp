#include <iostream>
#include <algorithm>
using namespace std;

int a[30010];
int dp[30010];

int binary_search(int left, int right, int v){
	int mid;
	while (left < right){
		mid = left + ((right - left) >> 1);
		if (dp[mid] < v)left = mid+1;
		else right = mid;
	}
	return left;
}

int main(){
	int n;
	while (cin >> n){
		int len = 1;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		dp[0] = 0;
		int p;
		for (int i = 1; i <= n; ++i){
			if (a[i] > dp[len-1]){
				dp[len++] = a[i];
				continue;
			}
			p = binary_search(1, len - 1, a[i]);
		//	p = lower_bound(dp+1, dp + len, a[i]) - dp;
			dp[p] = a[i];
		}
		cout <<(len-1) << endl;
	}
}