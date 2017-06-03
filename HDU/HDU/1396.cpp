#include <iostream>
using namespace std;

int main(){
	long long a[510];
	a[1] = 1;
	for (int i = 2; i <= 500; ++i){
		a[i] = a[i - 1]+(3*i+i*i-2)/2;
		for (int j = 2; j <= i / 2; ++j){
			a[i] += (i - j * 2+1);
		}
	}
	int n;
	while (cin >> n)
		cout << a[n] << endl;
}