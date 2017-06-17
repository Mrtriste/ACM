#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int cnt[410];


int main(){
	int T; cin >> T;
	while (T--){
		int n, aa, bb; cin >> n;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; ++i){
			cin >> aa >> bb;
			if (aa>bb)swap(aa, bb);
			if (aa % 2 == 0)aa -= 1;
			if (bb % 2 == 0)bb -= 1;
			for (int j = aa; j <= bb; j += 2)cnt[j]++;
		}
		int mmax = 0;
		for (int i = 1; i < 400; i += 2)
			mmax = max(mmax, cnt[i]);
		cout << mmax * 10 << endl;
	}
}