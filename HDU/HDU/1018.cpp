#include <iostream>
using namespace std;

int main(){
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		double cnt = 0;
		for (int i = 1; i <= n; ++i)
			cnt += (log10(i));
		cout <<int(cnt)+1<< endl;
	}
	return 0;
}