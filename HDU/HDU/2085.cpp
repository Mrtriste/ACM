#include <iostream>
using namespace std;

int main(){
	long long h[40],l[40];
	h[0] = 1; l[0] = 0;
	for (int i = 1; i <= 33; ++i){
		h[i] = 3 * h[i - 1] + 2 * l[i - 1];
		l[i] = h[i - 1] + l[i - 1];
	}
	int n;
	while (cin >> n&&n >= 0){
		cout << h[n] << ", " << l[n] << endl;
	}
}