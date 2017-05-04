#include <iostream>
using namespace std;

int mainbinarysearch(){
	int a[] = { -1, 2, 2, 4, 4, 4, 5, 6, 7 };
	int left = 0, right = 8;
	int x = -3;
	int mid;
	while (left < right){
		mid = left + ((right - left) >> 1);
		if (a[mid] > x)right = mid;// >= lower bound,the first num >= x ;
									// > upper bound ,the first num > x
		else left = mid+1;
	}
	cout << left;
	system("pause");
	return 0;
}

