#include <iostream>
using namespace std;

void mergeSort(int a[], int start, int end, int temp[]){
	if (start >= end)return;

	int mid = (start + end) >> 1;
	mergeSort(a, start, mid, temp);
	mergeSort(a, mid + 1, end, temp);

	int k = 0,m = start,n=mid+1;
	while (m <= mid&&n <= end)
		temp[k++] = a[m] > a[n] ? a[n++] : a[m++];
	while (m <= mid)
		temp[k++] = a[m++];
	while (n <= end)
		temp[k++] = a[n++];

	for (int i = 0; i < k; ++i)
		a[start + i] = temp[i];
	
}

int mainmergesort(){
	int a[] = { 10, 4, 7, 3, 5, 6, 8, 1, 9, 2 };
	int len = sizeof(a) / sizeof(int);
	int *temp = new int[len];
	mergeSort(a, 0, len - 1, temp);
	for (int i = 0; i < len; ++i)
		cout << a[i] << " ";
	delete[]temp;
	system("pause");
	return 0;
}