#include <iostream>
using namespace std;

int mainGCD(){
	int m = 18 * 13, n = 18 * 97;
	int temp;
	if (m < n)swap(m, n);//let m>n
	while (n != 0){
		if (m < n)swap(m, n);
		temp = m%n;
		m = n;
		n = temp;
	}
	cout << m;
	system("pause");
	return 0;
}