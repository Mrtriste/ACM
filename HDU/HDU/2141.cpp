#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <set>
using namespace std;
#define wjc

int l, n, m;
long long a[510];
long long b[510];
long long c[510];
long long sum[250010];
long long res;
bool flag;

bool binary_search(int left, int right, long long x){
	int mid;
	while (left < right){
		mid = left + ((right - left) >> 1);
		if (sum[mid] >= x)right = mid;
		else left = mid + 1;
	}
	if (sum[left] == x)return true;
	return false;
}

int main(){
#ifdef wjc
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int e = 1;
	while (cin >> l >> n >> m){
		int i, j, k;
		for (i = 0; i < l; ++i)
			cin >> a[i];
		for ( i = 0; i < n; ++i)
			cin >> b[i];
		for ( i = 0; i < m; ++i)
			cin >> c[i];
		sort(a, a + l);
		sort(b, b + n);
		sort(c, c + m);
		int cnt = 0;
		for (i = 0; i < l; ++i)
			for (j = 0; j < n; ++j)
				sum[cnt++]=(a[i] + b[j]);
		sort(sum, sum + cnt);
		long long s; cin >> s; long long r1;
		cout << "Case " << e++ << ":" << endl;
		while (s--){
			cin >> res;
			if (a[0] + b[0] + c[0]>res || a[l - 1] + b[n - 1] + c[m - 1]<res){
				cout << "NO" << endl;
				continue;
			}
			flag = false;
			for (i = 0; i < m; ++i){
				r1 = res - c[i];
				if (r1>sum[cnt - 1])continue;
				if (binary_search(0,cnt-1,r1)){
					flag = true;
					break;
				}
			}
			if (flag)cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}

}