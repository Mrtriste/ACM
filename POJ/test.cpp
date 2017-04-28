#include <iostream>
#include <algorithm>
using namespace std;

int maint(){
	
	int aa = 1, bb = 2;
	swap(aa, bb);
	cout << aa << " " << bb << endl;
	int a[10];
	for (int i = 0; i < 10; ++i)
		a[i] = 10-i;
	sort(a, &a[9]);
	for (int i = 0; i < 10; ++i)
		cout << a[i] << " ";
	//int *pe = a - 1;
	//cout << *pe << endl;
	system("pause");
	return 0;
}



