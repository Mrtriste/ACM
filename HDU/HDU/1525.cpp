#include <iostream>
using namespace std;

int main(){
	int a, b;
	while (cin >> a >> b && (a + b)){
		bool flag = true;
		if (a < b)swap(a, b);
		while (1){
			if (a%b == 0 || a / b >= 2)break;
			int t = b;
			b = a - b;
			a = t;
			flag = !flag;
		}
		if (flag)puts("Stan wins");
		else puts("Ollie wins");
	}
}