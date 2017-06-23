//别人的代码就是简洁
#include<cstdio>  
#include<cstring>  

int m, n, p, s[105][505], d[105][505], pre[105][505];
int main()
{
	int i, j;
	scanf("%d%d", &m, &n);
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &s[i][j]);
	for (i = m; i>0; i--)
	{
		for (j = 1; j <= n; j++)
		{
			d[i][j] = d[i + 1][j] + s[i][pre[i][j] = j];
			if (j>1 && d[i][j - 1] + s[i][j]<d[i][j])
				d[i][j] = d[i][pre[i][j] = j - 1] + s[i][j];
		}
		for (j = n - 1; j>0; j--)
			if (j<n&&d[i][j + 1] + s[i][j]<d[i][j])
				d[i][j] = d[i][pre[i][j] = j + 1] + s[i][j];
	}
	d[1][p] = 1999999999;
	for (i = j = 1; j <= n; j++)
		if (d[1][j]<d[1][p])
			p = j;
	while (i <= m)
	{
		printf("%d/n", p);
		if (pre[i][p] == p)
			i++;
		else
			p = pre[i][p];
	}
}

//我的解法
//#include <iostream>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//struct Node{
//	int y;long long d;
//	int px, py;
//	Node(){}
//	Node(int yy, long long dd,int pxx,int pyy) :y(yy), d(dd),px(pxx),py(pyy){}
//	bool operator<(const Node&b)const{
//		return d > b.d;
//	}
//};
//
//struct Point{
//	int x, y;
//	Point(){ x = y = -1; }
//	Point(int xx, int yy) :x(xx), y(yy){}
//};
//
//long long dp[105][505];
//int a[105][505];
//int m, n;
//Point pre[105][505];
//bool vis[505];
//int dir[2] = { -1, 1 };
//
//void print(int x, int y){
//	int xx = pre[x][y].x, yy = pre[x][y].y;
//	if (yy != -1){
//		print(xx, yy);
//		cout << yy << endl;
//	}
//}
//
//int main(){
//	cin >> m >> n;
//	for (int i = 1; i <= m; ++i)
//		for (int j = 1; j <= n; ++j)
//			scanf("%d", &a[i][j]);
//	for (int i = 1; i <= n; ++i)
//		dp[0][i] = 0, pre[1][i].x=1, pre[1][i].y=-1;
//	
//	for (int i = 1; i <= m; ++i){
//		priority_queue<Node> q;
//		memset(vis, 0, sizeof(vis));
//		for (int j = 1; j <= n; ++j){
//			dp[i][j] = dp[i - 1][j]+a[i][j];
//			if (i>1)
//				q.push(Node(j, dp[i][j],i-1,j));
//			else q.push(Node(j, dp[i][j], i, -1));
//		}
//		Node cur; int yy;long long dd;
//		while (!q.empty()){
//			cur = q.top(), q.pop();
//			if (vis[cur.y])continue;
//			vis[cur.y] = 1;
//			dp[i][cur.y] = cur.d, pre[i][cur.y].x = cur.px, pre[i][cur.y].y = cur.py;
//			for (int k = 0; k < 2; ++k){
//				yy = cur.y + dir[k];
//				if (yy<1 || yy>n)continue;
//				if (!vis[yy]&&dp[i][yy] > cur.d + a[i][yy])
//					q.push(Node(yy, cur.d + a[i][yy], i, cur.y));
//			}
//		}
//	}
//
//	//for (int i = 1; i <= m; ++i){
//	//	for (int j = 1; j <= n; ++j){
//	//		cout << pre[i][j].x << " " << pre[i][j].y << " " << dp[i][j] << " ## ";
//	//	}
//	//	cout << endl;
//	//}
//
//	long long mmin = 0x3f3f3f3f3f3f3f3f; int flag;
//	for (int i = 1; i <= n; ++i){
//		if (mmin>dp[m][i]){
//			mmin = dp[m][i];
//			flag = i;
//		}
//	}
//	print(m, flag);
//	cout << flag << endl;
//	system("pause");
//}