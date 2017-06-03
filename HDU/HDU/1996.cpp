#include <iostream>
using namespace std;

int main(){
	long long a[31];
	a[0] = 1; a[1] = 3;
	for (int i = 2; i < 30; ++i)
		a[i] = 3 * a[i - 1];
	int T, n; cin >> T;
	while (T--){
		cin >> n;
		cout << a[n] << endl;
	}
}