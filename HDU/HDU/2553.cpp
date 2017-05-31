#include <stdio.h>
int n,a[12] = { 0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724 };
int main(){
	while (scanf("%d",&n)&&n)
		printf("%d\n", a[n]);
}
//#include <iostream>
//using namespace std;
//
//int cnt;
//int n;
//bool col[12];
//bool a[12][12];
//
//bool judge(int d, int ii){
//	if (col[ii])return true;
//	int i, j, k;
//	for (i = d - 1,k=1; i >= 1; --i,k++){
//		j = ii - k;
//		if (j >= 1 && a[i][j])return true;
//		j = ii + k;
//		if (j <= n&&a[i][j])return true;
//	}
//	return false;
//}
//
//void DFS(int depth,int ii){
//	if (depth == n){
//		cnt += 1;
//	}
//	a[depth][ii] = 1, col[ii] = 1;
//	for (int i = 1; i <= n; ++i){
//		if (judge(depth+1, i))continue;
//		DFS(depth + 1,i);
//	}
//	a[depth][ii] = 0, col[ii] = 0;
//}
//
//int main(){
//	int ans[12];
//	for (n = 1; n <= 10;++n){
//		cnt = 0;
//		memset(col, 0, sizeof(col));
//		memset(a, 0, sizeof(a));
//		for (int i = 1; i <= n; ++i){
//			DFS(1, i);
//		}
//		ans[n] = cnt;
//	}
//	while (cin >> n){
//		if (n == 0)break;
//		cout << ans[n] << endl;
//	}
//		
//}