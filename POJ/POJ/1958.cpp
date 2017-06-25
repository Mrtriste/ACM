#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int f[16], base[16];
	f[1] = 1, f[2] = 3, f[3] = 5, f[4] = 9;
	base[1] = 2;
	for (int i = 2; i <= 12; ++i)
		base[i] = base[i - 1] * 2;
	for (int i = 5 ; i <= 12; ++i){
		int mmin = 0x3f3f3f3f;
		for (int k = 1; k < i; ++k){
			mmin = min(mmin, 2 * f[k] + base[i - k] - 1);
		}
		f[i] = mmin;
	}
	for (int i = 1; i <= 12; ++i)
		cout << f[i] << endl;
	system("pause");
}