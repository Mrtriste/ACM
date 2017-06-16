#include <iostream>
#include <algorithm>
using namespace std;

int ans[1501];

void Make(){
	int prime[3] = { 2, 3, 5 };
	int pos[3] = { 0, 0, 0 };
	ans[0] = 1;
	for (int i = 1; i < 1501; ++i){
		int mmin = -1 & 0x7fffffff;
		for (int j = 0; j < 3; ++j)
			mmin = min(mmin, prime[j] * ans[pos[j]]);
		for (int j = 0; j < 3; ++j)
			if (prime[j] * ans[pos[j]] == mmin)
				pos[j]++;
		ans[i] = mmin;
	}
}

int main(){
	int n;
	Make();
	while (cin >> n&&n)
		cout << ans[n-1] << endl;
}