#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	double Q;
	int N;
	double a[40];
	const int maxN = 3100001;
	int dp[maxN];
	while (cin >> Q >> N){
		if (N == 0)break;
		int m;
		for (int i = 1; i <= N; ++i){
			a[i] = 0;
			cin >> m;
			char type; double num;
			for (int j = 0; j < m; ++j){
				getchar();
				scanf("%c:%lf", &type, &num);
				if ((type<'A' || type>'C') || num > 600){
					a[i] = 0;
					break;
				}
				a[i] += num;
				if (a[i]>1000){
					a[i] = 0;
					break;
				}
			}
			a[i] *= 100;
		}
		int t_max = Q * 100;
		for (int i = 0; i <= t_max; ++i)
			dp[i] = 0;
		for (int i = 1; i <= N; ++i){
			for (int j = t_max; j >= a[i]; --j){
				dp[j] = max(dp[j], int(dp[j - (int)a[i]] + a[i]));
			}
		}
		printf("%.2lf\n", double(dp[t_max]) / 100);


	}
}