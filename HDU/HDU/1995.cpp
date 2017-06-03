#include<iostream>
using namespace std;

int main(){
	long long a[65][65];
	for (int i = 1; i <= 60; ++i){
		for (int j = 1; j <= i; ++j){
			if (j == i)a[i][j] = 1;
			else a[i][j] = 2 * a[i - 1][j];
		}
	}
	int n, k, T; cin >> T;
	while (T--){
		cin >> n >> k;
		cout << a[n][k] << endl;
	}
		
}