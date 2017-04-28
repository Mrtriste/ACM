#include <iostream>
using namespace std;

void shellSort(int a[],int n){
	for (int gap = n / 2; gap > 0; gap >>= 1)
		for (int i = gap; i < n; ++i)
			for (int j = i - gap; j >= 0 && a[j + 1] < a[j]; j -= gap)
				swap(a[j + 1], a[j]);
}

int mainshellsort(){
	int a[] = { 10, 4, 7, 3, 5, 6, 8, 1, 9, 2 };
	int len = sizeof(a) / sizeof(int);
	shellSort(a, len);
	for (int i = 0; i < len; ++i)
		cout << a[i] << " ";
	system("pause");
	return 0;
}