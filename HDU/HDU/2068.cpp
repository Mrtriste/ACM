#include <iostream>
using namespace std;

long long wrong[40];

void init(){
	wrong[0] = 1, wrong[1] = 0;
	wrong[2] = 1, wrong[3] = 2;
	for (int i = 3; i <= 14; ++i)
		wrong[i] = (wrong[i - 1] + wrong[i - 2])*(i - 1);
}

long long C(int m, int n){//Cm,n
	if (n > m - n)n = m - n;
	long long mul=1, div=1;
	for (int i = 0; i < n; ++i){
		mul *= (m - i);
		div *= (n - i);
	}
	return mul / div;
}

int main(){
	int n;
	init();
	while (cin >> n&&n){
		long long res = 0;
		for (int i = (n+1) / 2; i <= n; ++i){
			res += (C(n, i)*wrong[n - i]);
		}
		cout << res << endl;
	}
}