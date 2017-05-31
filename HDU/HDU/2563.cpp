#include <stdio.h>
using namespace std;
const int MAX = 25;
int main(void)
{
	int cas;
	int f[MAX];
	f[0] = 1;
	f[1] = 3;
	for (int i = 2; i < MAX; i++)
		f[i] = 2 * f[i - 1] + f[i - 2];
	scanf("%d", &cas);
	while (cas--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", f[n]);
	}
	return 0;
}

//DFS³¬Ê±
//#include<iostream>
//using namespace std;
//
//int n, cnt;
//int a[50][50];
//int dir[3][2] = { 1, 0, 0, -1, 0, 1 };
//int ans[25];
//
//void DFS(int x,int y,int d){
//	if (d == n){
//		cnt += 1; return;
//	}
//	a[x][y] = 1;
//	int xx, yy;
//	for (int i = 0; i < 3; ++i){
//		xx = x + dir[i][0], yy = y+dir[i][1];
//		if (a[xx][yy])continue;
//		DFS(xx, yy, d + 1);
//	}
//	a[x][y] = 0;
//}
//
//int main(){
//	for (n = 0; n <= 20; ++n){
//		cnt = 0;
//		memset(a, 0, sizeof(a));
//		a[25][0] = 1;
//		DFS(25,0,0);
//		ans[n] = cnt;
//	}
//	int C; cin >> C;
//	while (C--){
//		cin >> n;
//		cout << ans[n] << endl;
//	}
//}