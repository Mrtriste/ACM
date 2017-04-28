#include <iostream>
using namespace std;

//È«ÅÅÁÐ
void perm(int a[],int start,int n){
	if (start >= n-1){
		for (int i = 0; i < n; ++i)
			cout << a[i] << " ";
		cout << endl;
		return;//remember return
	}
	for (int i = start; i < n; ++i){
		swap(a[start], a[i]);
		perm(a,start+1,n);
		swap(a[start], a[i]);
	}
}

int mainperm(){
	int a[] = { 1, 2, 3 };
	perm(a, 0, 3);
	system("pause");
	return 0;
}