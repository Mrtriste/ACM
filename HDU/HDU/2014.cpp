#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	double a,mmax, mmin, sum;
	while (cin >> n){
		sum = 0, mmax = 0, mmin = 9999999999999999999;
		for (int i = 0; i < n; ++i){
			cin >> a;
			sum += a;
			mmax = max(a, mmax);
			mmin = min(a, mmin);
		}
		printf("%.2lf\n", (sum - mmax - mmin) / (n-2));
	}
}