#include <iostream>
#include <algorithm>
using namespace std;

int n;
int w[50010], h[50010];
int l[50010], r[50010];
int sta[50010];

int main(){
	while (cin >> n&&n !=-1){
		w[0] = 0; h[0] = 0;
		for (int i = 1; i <= n; ++i){
			scanf("%d%d", &w[i], &h[i]);
			
			w[i] += w[i - 1];
		}
			
		int top = 0;
		for (int i = 1; i <= n; ++i){
			while (top>0 && h[sta[top - 1]] >= h[i])top--;
			l[i] = top > 0 ? sta[top - 1] : 0;
			sta[top++] = i;
		}
		top = 0;
		for (int i = n ; i >= 1; --i){
			while (top>0 && h[sta[top - 1]] >= h[i])top--;
			r[i] = top > 0 ? sta[top - 1] -1: n;
			sta[top++] = i;
		}
		int mmax = 0;
		for (int i = 1; i <= n; ++i){
			mmax = max(mmax, h[i] * (w[r[i]] - w[l[i]]));
		}
			
		printf("%d\n", mmax);
	}
}
