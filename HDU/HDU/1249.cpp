#include <iostream>
using namespace std;

int main(){
	long long a[10010];
	a[1] = 2;
	for (int i = 2; i <= 10000; ++i)
		a[i] = a[i - 1] + 6 * (i - 1);

	int n, T; cin >> T;
	while (T--){
		cin >> n;
		cout << a[n] << endl;
	}
		
}