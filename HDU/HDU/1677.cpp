#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int h, w;
};

Node a[20010];
int dp[20010];

bool cmp(const Node&a, const Node&b){
	if (a.w != b.w)return a.w > b.w;
	return a.h < b.h;
}

int binary_search(int left, int right, int x){
	int mid;
	while (left < right){
		mid = left + ((right - left) >> 1);
		if (dp[mid] > x)right = mid;
		else left = mid + 1;
	}
	return left;
}

int main(){
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &(a[i].w), &(a[i].h));
		sort(a, a + n, cmp);
		int len = 1, h, pos;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; ++i){
			h = a[i].h;
			if (h>=dp[len - 1]){
				dp[len++] = h;
				continue;
			}
			pos = binary_search(1, len - 1, h);
			//pos = upper_bound(dp + 1, dp + len, h)-dp;
			dp[pos] = h;
		}
		cout << len - 1 << endl;

	}
}