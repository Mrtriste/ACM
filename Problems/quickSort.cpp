#include <iostream>
using namespace std;

void quickSort(int a[], int start, int end){
	if (start >= end)return;
	int left = start, right = end - 1;
	int x = a[end];

	while (left < right){
		while (a[left] < x&&left < right)left++;
		while(a[right] >= x&&left<right)right--;
		swap(a[left], a[right]);
	}
	if (a[left] >= a[end])swap(a[left], a[end]);//not x but a[end]
	else left++;
	quickSort(a, start, left - 1);
	quickSort(a, left + 1, end);
}

int mainquicksort(){
	int a[] = { 10, 4, 7, 3, 5, 6, 8, 1, 9, 2 };
	int len = sizeof(a) / (sizeof(int));
	cout << len << endl;
	quickSort(a, 0,len-1 );
	for (int i = 0; i < len; ++i)
		cout << a[i] << " ";
	system("pause");
	return 0;
}