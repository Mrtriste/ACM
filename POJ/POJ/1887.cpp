#include <iostream>
#include <algorithm>
using namespace std;

int dp[10010];

int binary_search(int left, int right,int x){//the first number < x
	int mid;
	while (left < right){
		mid = left + ((right - left) >> 1);
		if (x > dp[mid])right = mid;
		else left = mid + 1;
	}
	return left;
}

int main(){
	int a, t = 1;;
	while (1){
		scanf("%d", &a);
		if (a == -1)break;
		dp[1] = a; int len = 2;
		while (scanf("%d", &a) && a >= 0){
			if (a <= dp[len - 1]){
				dp[len++] = a; 
				continue;
			}
			int pos = binary_search(1,len-1,a);
			dp[pos] = a;
		}
		printf("Test #%d:\n", t++);
		printf("  maximum possible interceptions: %d\n\n", len - 1);

	}
}