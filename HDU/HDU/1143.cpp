#include<iostream>
using namespace std;

int main(){
	long long a[32];
	a[0] = 1; a[2] = 3; a[4] = 11;
	long long s = 0;
	for (int i = 6; i <= 30; i += 2){
		s += a[i - 4];
		a[i] = (3 * a[i - 2] + 2 * s + 2);
	}
	int n;
	while (cin >> n&&n >= 0){
		if (n % 2 == 1)cout<<0 << endl;
		else cout << a[n] << endl;
	}
}