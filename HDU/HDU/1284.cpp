#include <iostream>
using namespace std;

typedef long long LL;

struct Node{
	LL data[3];
	Node(){
		for (int i = 0; i < 3; ++i)
			data[i] = 0;
	}
	LL getSum(){
		return data[0] + data[1] + data[2];
	}
};

Node dp[32768];

int main(){
	int n;
	dp[1].data[0] = 1;
	dp[2].data[0] = dp[2].data[1] = 1;
	dp[3].data[0] = 2, dp[3].data[2] = 1;
	for (int i = 4; i <= 32768; ++i){
		dp[i].data[0] = dp[i - 1].data[0] + dp[i - 1].data[1] + dp[i - 1].data[2];
		dp[i].data[1] = dp[i - 2].data[1] + dp[i - 2].data[2];
		dp[i].data[2] = dp[i - 3].data[2];
	}
	while (cin >> n){
		cout << dp[n].getSum() << endl;
	}
}