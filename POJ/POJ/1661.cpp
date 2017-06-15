#include <iostream>
#include <algorithm>
using namespace std;

int dp[1010][2];
int n, x, y, MAX;

struct Node{
	int x[2], y;
	bool operator<(const Node&b){
		return y < b.y;
	}
};

Node a[1010];

int main(){
	int T; cin >> T;
	while (T--){
		cin >> n >> x >> y >> MAX;
		
		for (int i = 0; i < n; ++i)
			cin >> a[i].x[0] >> a[i].x[1] >> a[i].y;
	
		a[n].x[0] = a[n].x[1] = x, a[n].y = y;
		sort(a, a + n + 1);
		memset(dp, 0x3f, sizeof(dp));
		//dp[0][0] = dp[0][1] = a[0].y;
		
		for (int i = 0; i <= n; ++i){
			bool left = false, right = false;
			for (int j = i - 1; j >= 0; --j){
				if (a[i].y - a[j].y > MAX)break;
				if (left&&right)break;
				//cout << a[i].x[0] << " " << a[i].x[1] << " " << a[j].x[0] << " " << a[j].x[1] << endl;
				if (!left&&a[i].x[0] >= a[j].x[0] && a[i].x[0] <= a[j].x[1]){
					dp[i][0] = min(dp[j][0] + abs(a[i].x[0] - a[j].x[0]), dp[j][1] + abs(a[i].x[0] - a[j].x[1])) + a[i].y - a[j].y;
					left = true;
				}
					
				if (!right&&a[i].x[1] >= a[j].x[0] && a[i].x[1] <= a[j].x[1]){
					dp[i][1] = min(dp[j][0] + abs(a[i].x[1] - a[j].x[0]), dp[j][1] + abs(a[i].x[1] - a[j].x[1])) + a[i].y - a[j].y;
					right = true;
				}
			}
			///////there is no platform under a[i], then compared with ground
			if (!left){
				if (a[i].y <= MAX)
					dp[i][0] = a[i].y;
			}
			if (!right){
				if (a[i].y <= MAX)
					dp[i][1] = a[i].y;
			}

			//cout << dp[i][0] << " " << dp[i][1]<<endl;
		}
		cout << min(dp[n][0], dp[n][1]) << endl;
	}
}