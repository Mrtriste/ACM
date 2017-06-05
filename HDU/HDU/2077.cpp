#include <iostream>
using namespace std;

int main(){
	long long a[25];
	a[1] = 2;
	for (int i = 2; i <= 20; ++i)
		a[i] = 3 * a[i - 1] - 2;
	int T,n; cin >> T;
	while (T--){
		cin >> n;
		cout << a[n] << endl;
	}
}