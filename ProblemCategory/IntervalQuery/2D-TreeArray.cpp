//二维树状数组
//poj1195
//查询[a,b]-[e,d]范围的和

#include <iostream>
using namespace std;

int c[1030][1030];
int n;

int lowerBit(int k){
	return k&-k;
}

void add(int x, int y, int v){
	for (int i = x; i <= n; i += lowerBit(i))
		for (int j = y; j <= n; j += lowerBit(j))
			c[i][j] += v;
	
	//it's wrong, because y will not return to y after a loop
	//while (x <=n){
	//	while (y<=n){
	//		c[x][y] += v; y += lowerBit(y);
	//	}
	//	x += lowerBit(x);
	//}
}

int query(int x, int y){
	int ret = 0;
	for (int i = x; i > 0; i -= lowerBit(i))
		for (int j = y; j > 0; j -= lowerBit(j))
			ret += c[i][j];
	return ret;
}

int main(){
	memset(c, 0, sizeof(c));
	int x,a,b,e,d;
	while (cin >> x){
		if (x == 0) cin >> n;
		else if (x == 3)break;
		else if (x == 1){
			cin >> a >> b >> e;
			add(a+1, b+1, e);			
		}
		else{
			cin >> a >> b >> e >> d;
			a++, b++, e++, d++;
			cout << query(e,d)+query(a-1,b-1)-query(a-1,d)-query(e,b-1) << endl;;
		}
	}
}