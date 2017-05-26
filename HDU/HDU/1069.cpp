#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int x, y, h;
	bool operator>(const Node&a){
		if (x > a.x&&y > a.y)return true;
		return false;
	}
};

bool cmp(const Node& a, const Node& b){
	if (a.x < b.x)return true;
	if (a.x == b.x&&a.y < b.y)return true;
	return false;
}

int n;
Node block[200];
int dp[200];

int main(){
	int c = 1;
	while (cin >> n){
		if (n == 0)break;
		int x, y, z;
		int cnt = 0;
		memset(dp, 0, sizeof(dp));
		block[0].x = block[0].y = block[0].h = 0;
		for (int i = 1; i <= n; ++i){
			cin >> x >> y >> z;
			block[cnt].x = x, block[cnt].y = y, block[cnt++].h = z;
			block[cnt].x = x, block[cnt].y = z, block[cnt++].h = y;
			block[cnt].x = y, block[cnt].y = x, block[cnt++].h = z;
			block[cnt].x = y, block[cnt].y = z, block[cnt++].h = x;
			block[cnt].x = z, block[cnt].y = x, block[cnt++].h = y;
			block[cnt].x = z, block[cnt].y = y, block[cnt++].h = x;
		}
		sort(block, block + cnt, cmp);
		int ans = -1;
		dp[0] = 0;
		for (int i = 1; i <= cnt; ++i){
			int j; dp[i] = block[i].h;
			for (j = i - 1; j >= 0; --j)
				if (block[i] > block[j] && (dp[j] + block[i].h)>dp[i])
					dp[i] = dp[j] + block[i].h;
			ans = max(dp[i], ans);
		}
		cout << "Case "<<c++<<": maximum height = "<<ans << endl;
	}
}