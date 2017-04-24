#include <iostream>
using namespace std;

int mainpower(){
	int x = 2, n = 11;
	int res = 1;
	while (n > 0){
		if (n & 1)
			res *= x;
		x *= x;
		n >>= 1;
	}
	cout << res;
	system("pause");
	return 0;
}