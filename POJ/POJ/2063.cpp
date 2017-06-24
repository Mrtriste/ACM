#include <iostream>
#include <algorithm>
using namespace std;

int dp[50010];

struct Node{
	int val, in;
};

Node bond[15];

int main(){
	int T; cin >> T;
	int n,y, d,t,k;
	while (T--){
		cin >> n >> y>>d;
		for (int i = 0; i < d; ++i){
			cin >> t >> k;
			bond[i].val = t / 1000, bond[i].in = k;
		}
		for (int e = 0; e < y; ++e){
			int s = n / 1000;
			memset(dp, 0, sizeof(dp[0])*(s + 5));
			for (int i = 0; i <d; ++i)
				for (int j = bond[i].val; j <= s; ++j)
					dp[j] = max(dp[j - bond[i].val] + bond[i].in, dp[j]);
			n += dp[s];
		}
		cout << n << endl;
	}
}