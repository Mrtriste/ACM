#include <iostream>
using namespace std;

int mainpowermod(){
	int x = 2, n = 11, m = 3;
	int res = 1;
	while (n > 0){
		if (n & 1)
			res = (res*x) % m;
		x = (x*x) % m;
		n >>= 1;
	}
	cout << res;
	system("pause");
	return 0;
}