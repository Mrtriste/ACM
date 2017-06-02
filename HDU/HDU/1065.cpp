#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int T; cin >> T;
	double x, y, r;
	int cnt=1, n;
	while (T--){
		cin >> x >> y;
		r = sqrt(x*x + y*y);
		n = (x*x + y*y)*3.1415926 / 100 + 1;
		printf("Property %d: This property will begin eroding in year %d.\n",cnt++,n);
	}
	printf("END OF OUTPUT.\n");
}