#include <iostream>
using namespace std;

int main(){
	double sum, a;
	while (cin >> a){
		sum = a;
		for (int i = 0; i < 11; ++i){
			cin >> a;
			sum += a;
		}
		printf("$%.2lf\n", sum / 12);
	}
}