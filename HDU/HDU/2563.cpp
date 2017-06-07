#include <iostream>
using namespace std;
int main()
{
	int up[25], left[25];
	up[1] = 1, left[1] = 1;
	for (int i = 2; i <= 20; ++i){
		up[i] = up[i - 1] + 2 * left[i - 1];
		left[i] = up[i - 1] + left[i - 1];
	}
	int C, n; cin >> C;
	while (C--){
		cin >> n;
		cout << (up[n] + 2 * left[n]) << endl;
	}
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