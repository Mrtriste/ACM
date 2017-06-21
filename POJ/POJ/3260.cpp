#include <iostream>
#include <algorithm>
using namespace std;

int charge[30010], pay[30010];
int a[110],cnt[110];
int n, t;
const int maxN = 24400;

void ZeroOnePackage(int c,int v){
	for (int i = maxN; i >=c; --i)
		pay[i] = min(pay[i], pay[i - c] + v);
}

void ComPackage(int c){
	for (int i = c; i <= maxN; ++i)
		pay[i] = min(pay[i], pay[i - c] + 1);
}

void multiPackage(int c, int num){
	if (c*num >= maxN){
		ComPackage(c);
		return;
	}
	int k = 1;
	while (k < num){
		ZeroOnePackage(c*k, k);
		num -= k;
		k *= 2;
	}
	ZeroOnePackage(num*c, num);
}

int main(){
	while (cin >> n >> t){
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i)cin >> cnt[i];
		memset(charge, 0x3f, sizeof(charge));
		memset(pay, 0x3f, sizeof(pay));
		charge[0]=pay[0] = 0;
		for (int i = 0; i < n; ++i){
			for (int j = a[i]; j <= maxN; ++j)
				charge[j] = min(charge[j], charge[j - a[i]] + 1);
		}

		for (int i = 0; i < n; ++i)
			multiPackage(a[i], cnt[i]);
		int ans = 0x3f3f3f3f;
		for (int i = t; i <= maxN; ++i)
			ans = min(ans, pay[i] + charge[i - t]);
		if (ans == 0x3f3f3f3f)cout << -1 << endl;
		else cout << ans << endl;
	}
}