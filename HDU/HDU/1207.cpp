#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int a[65];
	a[1] = 1, a[2] = 3;
	int INF = 0x3f3f3f3f;
	for (int i = 3; i <= 64; ++i){
		int mmin = INF;
		for (int j = 1; j < i; ++j){
			if (mmin>(pow(2.0, j) - 1 + 2 * a[i - j]))
				mmin = pow(2.0, j) - 1 + 2 * a[i - j];
		}
		a[i] = mmin;
	}
	int n;
	while (cin >> n)
		cout << a[n] << endl;
}