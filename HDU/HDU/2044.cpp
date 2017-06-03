#include <iostream>
using namespace std;

int main(){
	long long a[50];
	a[1] = 1,a[0] = 0;
	for (int i = 2; i < 50; ++i)
		a[i] = a[i - 1] + a[i - 2];
	int aa, bb, T; cin >> T;
	while (T--){
		cin >> aa >> bb;
		cout << a[bb - aa+1] << endl;
	}
}