


#include <iostream>
using namespace std;

int arr[500][500];

int max(int a, int b){
	return a > b ? a : b;
}

int LCStr(char* a, char*b){
	for (int i = 0; i < strlen(a); ++i)
		for (int j = 0; j < strlen(b); ++j){
			if (i == 0 || j == 0)
				arr[i][j] = 0;
			if (a[i] == b[j])
				arr[i + 1][j + 1] = arr[i][j] + 1;
			else
				arr[i + 1][j + 1] = max(arr[i + 1][j], arr[i][j + 1]);	
		}
	return arr[strlen(a)][strlen(b)];
}

int main(){
	char a[500], b[500];
	while (cin >> a >> b)
		cout << LCStr(a, b) << endl;
	return 0;
}