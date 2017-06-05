#include <iostream>
using namespace std;

int main(){
	long long a[40];
	a[1] = 2;
	for (int i = 2; i <= 35; ++i)
		a[i] = 3 * a[i - 1] + 2;
	int n;
	while (cin >> n)
		cout << a[n] << endl;
}