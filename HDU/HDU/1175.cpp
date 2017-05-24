#include <iostream>
using namespace std;

int a[1010][1010];
int m, n;
int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

bool flag;
int ex, ey;


bool judge(int x, int y,int i){
	if (ex == x){
		if (ey > y&&i != 3)return true;
		if (ey < y&&i != 2)return true;
	}
	else if(ey==y){
		if (ex > x&&i != 1)return true;
		if (ex < x&&i != 0)return true;
	}
	return false;
}

void DFS(int x, int y,int time,int d){
	if (flag)return;

	int xx, yy, t;
	for (int i = 0; i < 4; ++i){
		t = time,xx = x + dir[i][0], yy = y + dir[i][1];
		if (xx<1 || yy<1 || x>n || y>m)continue;
		if (d != i)
			t = time + 1;
		if (t > 2)continue;
		if (xx == ex&&yy == ey){
			flag = true;
			return;
		}
		if (a[xx][yy] != 0)continue;
		if (t == 2 && (xx != ex&&yy != ey))continue;
		if (t == 2 && judge(xx, yy, i))continue;
		DFS(xx, yy, t, i);
	}
}

int main(){
	while (cin >> n >> m){
		if (n == 0 && m == 0)break;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				cin >> a[i][j];
		int q; cin >> q;
		int x, y;
		for (int e = 0; e < q; ++e){
			cin >> x >> y >> ex >> ey;
			flag = false;
			if (a[x][y] != a[ex][ey]||a[x][y]==0){
				cout << "NO" << endl;
				continue;
			}
			for (int i = 0; i < 4;++i)
				DFS(x, y,0,i);
			if (flag)cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}