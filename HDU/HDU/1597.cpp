#include<iostream>
#include <math.h>
using namespace std;

int main(){
	int T; cin >> T;
	long long n;
	while (T--){
		cin >> n;
		long long k = ceil((sqrt(8 * n + 1) - 1) / 2);
		int ans;
		ans = (n - (k*(k - 1)) / 2) % 9;
		if (ans == 0)ans += 9;
		cout << ans << endl;
	}
}