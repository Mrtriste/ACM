#include <iostream>
using namespace std;

int binarySearch(int dp[], int left,int right,int x){
	while (left < right){
		int mid = left + ((right - left) >> 1);
		if (dp[mid] >= x)right = mid;
		else
			left = mid + 1;
	}
	return left;
}

int mainlis(){
	const int N = 100;
	int testArr[] = { 2, 1, 5, 3, 6, 4, 8, 9, 7 };
	int n = 9;
	int a[N];
	int dp[N];
	for (int i = 0; i < n; ++i)
		a[i + 1] = testArr[i];//a[1..n]={}

	////////////////////////
	int maxLen = 1;
	dp[1] = a[1];
	for (int i = 2; i <= n; ++i){
		if (a[i]>dp[maxLen])
			dp[++maxLen] = a[i];
		else{
			int j = binarySearch(dp, 1, maxLen,a[i]);
			dp[j] = a[i];
		}
	}
	cout << maxLen << endl;
	system("pause");
	return 0;

}