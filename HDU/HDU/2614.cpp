#include <iostream>
#include <algorithm>
using namespace std;

int a[20][20];
bool solve[20];
int n;
int mmax;

void DFS(int x,int depth,int time){//has solve x,and the x id the depth-th problem
	mmax = max(mmax, depth);
	for (int i = 0; i < n; ++i){
		if (solve[i]||i==x)continue;
		if (a[x][i] < time)continue;
		solve[i] = 1;
		DFS(i,depth+1,a[x][i]);
		solve[i] = 0;
	}
}

int main(){
	while (cin >> n){
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> a[i][j];
		memset(solve, 0, sizeof(solve));
		mmax = 0;
		solve[0] = 1;
		DFS(0,1,0);
		cout << mmax << endl;
	}
}