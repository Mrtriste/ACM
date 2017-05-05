#include <iostream>
#include <algorithm> 
using namespace std;

int main1004(){
	int a[1000010];
	int b[1000010];
	int N, M;
	while (cin >> N){
		for (int i = 0; i < N; ++i)
			cin >> a[i];
		cin >> M;
		for (int i = 0; i < M; ++i)
			cin >> b[i];
		int mid = (M + N+1) >> 1;
		int k = 0;
		int m = 0, n = 0;
		int median;
		while (m < N&&n < M&&k++<mid){
			median = (a[m]>b[n] ? b[n++] : a[m++]);
		}
		while (m < N&&k++ < mid)median = a[m++];
		while (n < M&&k++ < mid)median = b[n++];

		cout << median << endl;
	}
	return 0;
}