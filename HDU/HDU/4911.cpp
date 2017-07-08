#include <iostream>
using namespace std;

int n, k;
int a[100010];
int temp[100010];
long long cnt;

void mergeSort(int l, int r){
	if (l >= r)return;
	int mid = (l + r) / 2;
	mergeSort(l, mid);
	mergeSort(mid + 1, r);
	int i = l, j = mid + 1, t = 0;;
	while (i <= mid&&j <= r){
		if (a[i] <= a[j])temp[t++] = a[i++];
		else{
			cnt += mid - i + 1;
			temp[t++] = a[j++];
		}
	}

	while (i <= mid)temp[t++] = a[i++];
	while (j <= r)temp[t++] = a[j++];
	for (int s = 0; s < t; ++s)
		a[l + s] = temp[s];
}

int main(){
	while (cin >> n >> k){
		for (int i = 0; i < n; ++i)scanf("%d", &a[i]);
		cnt = 0;
		mergeSort(0, n - 1);
		if (cnt < k)cout << 0 << endl;
		else cout << cnt - k << endl;
	}
}