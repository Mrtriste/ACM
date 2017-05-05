//最大连续子序列和
#include <iostream>
using namespace std;

int main1011(){
	int n;
	int a[10010];
	while (cin >> n){
		if (n == 0)break;
		int maxSum = 0, thisTurn = 0;
		int start = 0, end = 0;
		cin >> a[0];
		maxSum = thisTurn= a[0];/////////////!!!!
		int s = 0, e = 0;//record this sequence start and end
		for (int i = 1; i < n; ++i){
			cin >> a[i];
			if (thisTurn < 0){
				thisTurn = a[i];
				s = e = i;
			}
			else{
				thisTurn += a[i];
				e = i;
			}
			if (maxSum < thisTurn){
				maxSum = thisTurn;
				start = s, end = e;
			}
		}
		if (maxSum >= 0)
			cout << maxSum << " " << a[start] << " " << a[end] << endl;
		else
			cout << 0 << " " << a[0] << " " << a[n - 1] << endl;
	}
	return 0;
}