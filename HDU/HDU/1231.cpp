#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int k;
	while (cin >> k){
		if (k == 0)break;
		int a;
		int start, end, s, e, thisSum, maxSum;
		cin >> a;
		int first = a, last = a;
		start = end = s = e = a, thisSum = maxSum = a;
		for (int i = 2; i <= k; ++i){
			cin >> a;
			if (thisSum < 0){
				thisSum = a;
				s = e = a;
			}
			else{
				thisSum += a;
				e = a;
			}

			if (maxSum < thisSum){
				maxSum = thisSum;
				start = s, end = e;
			}
			last = a;
		}
		if (maxSum < 0)
			maxSum = 0, start = first, end = last;
		cout << maxSum << " " << start << " " << end << endl;
	}
}