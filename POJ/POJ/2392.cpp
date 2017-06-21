#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int h, a, c;
	bool operator<(const Node&b){
		return a < b.a;
	}
};

Node a[410];
int dp[40010];

int main(){
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		scanf("%d%d%d", &a[i].h, &a[i].a, &a[i].c);
		
	sort(a, a + n);
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < n; ++i){
		for (int k = 0; k < a[i].c; ++k){
			for (int j = a[i].a; j >= a[i].h; --j)
				if (dp[j-a[i].h]!=-1)dp[j] = max(dp[j], dp[j - a[i].h] + a[i].h);
		}
	}
	int mmax = 0;
	for (int i = 0; i < 40010; ++i)
		mmax = max(mmax, dp[i]);
	cout << mmax << endl;
	system("pause");
}

