#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	char s[60];
	int len;
};

bool cmp(const Node&a, const Node&b){
	return a.len > b.len;
}

int dp[60];
Node a[110];

int getLCM(char *s){
	memset(dp, 0, sizeof(dp));
	int len = 1;
	for (int i = 0; i < strlen(s); ++i){
		if (s[i]>=dp[len - 1]){
			dp[len++] = s[i];
			continue;
		}
		int pos = upper_bound(dp + 1, dp + len, s[i])-dp;
		dp[pos] = s[i];
	}
	return len - 1;
}

int main(){
	int T; cin >> T;
	int n, m;
	for (int e = 0; e < T; ++e){
		cin >> n >> m;
		for (int i = 0; i < m; ++i){
			cin >> a[i].s;
			a[i].len = getLCM(a[i].s);
		}
		sort(a, a + m, cmp);
		for (int i = 0; i < m; ++i)
			cout << a[i].s << endl;
	}
}