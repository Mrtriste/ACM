#include <iostream>
#include <math.h>
using namespace std;

char block[7][7];
int n,m,T;
bool isOut = false;
int direct[4][2] = { { 0, -1 }, { -1, 0 }, { 1, 0 }, { 0, 1 } };
int dx, dy;

void DFS(int x, int y, int t){
	if (isOut)return;
	if (dx==x&&dy==y){
		if (t == T)
			isOut = true;
		return;
	}
	int step = abs(dx - x) + abs(dy - y);
	if (step > T - t)return;
	for (int i = 0; i < 4; ++i){
		int xx=x+ direct[i][0], yy=y + direct[i][1];
		if (xx >= 0 && yy >= 0 && xx < n&&yy < m){
			if ((block[xx][yy] == 'D' || block[xx][yy] == '.')){
				block[xx][yy] = 'X';
				DFS(xx, yy, t + 1);
				block[xx][yy] = '.';
			}
			
		}
	}

}

int main(){
	while (cin >> n >> m >> T){
		if (!n&&!m&&!T)break;
		isOut = false;
		int sx, sy;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				cin >> block[i][j];
				if (block[i][j] == 'S')
					sx = i, sy = j;
				if (block[i][j] == 'D')
					dx = i, dy = j;
			}
		}
		int step = abs(dx - sx) + abs(dy - sy);
		if ( step> T||(step%2!=T%2)){
			cout << "NO" << endl;
			continue;
		}
		DFS(sx, sy, 0);
		if (isOut)cout << "YES" << endl;
		else cout << "NO" << endl;


				

	}
	//system("pause");
	return 0;
}