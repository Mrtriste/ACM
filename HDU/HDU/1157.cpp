#include <iostream>
using namespace std;

int a[10010];
int n;

void quickSort(int l, int r){
	if (l >= r)return;
	int x = a[l], i = l, j = r;
	while (i < j){
		while (i<j&&a[j]>=x)j--;
		if (i < j)a[i++] = a[j];
		while (i < j&&a[i] < x)i++;
		if (i < j)a[j--] = a[i];
	}
	a[i] = x;
	quickSort(l, i-1);
	quickSort(i + 1, r);
}

int main(){
	while (cin >> n){
		for (int i = 0; i < n; ++i)scanf("%d", &a[i]);
		quickSort(0, n - 1);
		cout << a[n / 2] << endl;
	}
}