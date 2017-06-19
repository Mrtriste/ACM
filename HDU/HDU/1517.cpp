#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	while (cin >> n){
		int f = n;
		while (f > 1){
			f = ceil(f / 9.0);
			if (f <= 1){
				cout << "Stan wins.\n";
				break;
			}
			f = ceil(f / 2.0);
			if (f <= 1){
				cout << "Ollie wins.\n";
				break;
			}
		}

	}
}