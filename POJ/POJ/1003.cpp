#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	double a[300];
	a[0] = 0;
	for (int i = 1; i < 300; ++i)
		a[i] = a[i - 1] + 1.0 / (i+1);
	double s;
	while (cin >> s&&s>0){
		int pos = lower_bound(a, a + 300, s) - a;
		printf("%d card(s)\n", pos);
	}
}