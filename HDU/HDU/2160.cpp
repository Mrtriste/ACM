#include <iostream>
using namespace std;

int main(){
	int born[30], f[30];
	f[1] = 1; born[1] = 1; born[0] = 0;
	for (int i = 2; i < 20; ++i){
		f[i] = 2 * f[i-1] - born[i-2];
		born[i] = f[i - 1];
	}
	int T, n; cin >> T;
	while (T--){
		cin >> n;
		cout << f[n] << endl;
	}
}