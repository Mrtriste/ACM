#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;

int dp[1000];

struct Node{
	int h, l, t;
	bool operator<(const Node& b)const{
		return t < b.t;
	}
};
Node a[35];

int main(){
	int n;
	while (cin >> n&&n > 0){
		int t = 0;
		for (int i = 0; i < n; ++i){
			cin >> a[i].h >> a[i].l >> a[i].t;
			t = max(t, a[i].t);
		}
		memset(dp, 0, sizeof(dp));
		sort(a, a + n);
		for (int i = 0; i < n; ++i){
			for (int j = a[i].t; j-a[i].l>=0; --j)
				dp[j] = max(dp[j], dp[j - a[i].l] + a[i].h);
			for (int j = a[i].t; j <= t; ++j)
				dp[j] = dp[a[i].t];
		}
		cout << dp[t] << endl;
	}
}