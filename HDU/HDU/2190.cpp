#include <iostream>
using namespace std;

int main(){
	int a[35];
	a[1] = 1; a[2] = 3;
	for (int i = 3; i <= 30; ++i){
		a[i] = 2 * a[i - 2] + a[i - 1];
	}
	int C, n; cin >> C;
	while (C--){
		cin >> n;
		cout << a[n] << endl;
	}
}