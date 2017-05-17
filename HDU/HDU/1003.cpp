#include <iostream>
using namespace std;

int n;
int a[100010];

int main(){
	int T; cin >> T;
	for (int e = 1; e <= T; ++e){
		cin >> n;
		
		for (int i = 1; i <= n; ++i)
			cin >> a[i];

		int thisSum = a[1]; int maxSum = a[1];
		int ts = 1, te = 1, start=1, end=1;
		for (int i = 2; i <= n; ++i){
			if (thisSum >= 0){
				thisSum += a[i];
				te = i;
			}
			else if(thisSum<0){
				thisSum = a[i];
				te = ts = i;
			}

			if (maxSum < thisSum){
				maxSum = thisSum;
				start = ts, end = te;
			}
		}
		cout << "Case " << e << ":" << endl;
		cout << maxSum << " " << start << " " << end << endl;
		if (e != T)
			cout << endl;
	}
}