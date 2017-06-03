#include <iostream>
using namespace std;

int main(){
	long long ef[45],o[45];
	ef[1] = 2,o[1] = 1;
	for (int i = 2; i < 40; ++i){
		ef[i] = (ef[i - 1] + o[i - 1]) * 2;
		o[i] = ef[i - 1];
	}
	int n;
	while (cin >> n)
		cout << (ef[n] + o[n]) << endl;
}