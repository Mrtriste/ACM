#include <iostream>
using namespace std;

int arr[500][500];
int arr1[2][500];

int max1458(int a, int b){
	return a > b ? a : b;
}

int LCStr(char* a, char*b){
	arr[0][0] = 0;
	for (int i = 0; i < strlen(a); ++i){
		for (int j = 0; j < strlen(b); ++j){
			if (i == 0)
				arr[i][j+1] = 0;
			if (j == 0)
				arr[i+1][j] = 0;
			if (a[i] == b[j])
				arr[i + 1][j + 1] = arr[i][j] + 1;
			else
				arr[i + 1][j + 1] = max1458(arr[i + 1][j], arr[i][j + 1]);
		}
	}
		
	return arr[strlen(a)][strlen(b)];
}

//滚动数组
int LCStr1(char* a, char*b){
	arr1[0][0] = 0;
	for (int i = 0; i < strlen(a); ++i){
		for (int j = 0; j < strlen(b); ++j){
			int k1 = i % 2;
			int k2 = (i + 1) % 2;
			if (i == 0)
				arr1[i][j + 1] = 0;//注意j+1 arr是到j+1的 arr[strlen(b)]
			if (a[i] == b[j])
				arr1[k2][j + 1] = arr1[k1][j] + 1;
			else
				arr1[k2][j + 1] = max1458(arr1[k2][j], arr1[k1][j + 1]);
			//cout << arr1[k2][j + 1] << " ";
		}
		//cout << endl;
	}
		
	return arr1[strlen(a)%2][strlen(b)];
}

int main1458(){
	char a[500], b[500];
	while (cin >> a >> b){
		cout << LCStr(a, b) << endl;
		//cout << LCStr1(a, b) << endl;
	}
		
	
	return 0;
}