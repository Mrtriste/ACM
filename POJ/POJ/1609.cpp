#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int l, m;
	bool operator<(const Node&n){
		if (l != n.l)return l < n.l;
		return m < n.m;
	}
};

Node a[10010];
int dp[110];
int n;

int main(){
	while (cin >> n){
		if (n == 0){
			cout << "*" << endl; break;
		}
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &(a[i].l), &(a[i].m));
		sort(a, a + n);
		int len = 1; dp[0] = 0;
		for (int i = 0; i < n; ++i){
			if (a[i].m >= dp[len - 1]){
				dp[len++] = a[i].m;
				continue;
			}
			int pos = upper_bound(dp + 1, dp + len, a[i].m) - dp;
			dp[pos] = a[i].m;
		}
		cout << len - 1 << endl;
	}
}