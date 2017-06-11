//树状数组
//注意他是从1-n的，节点不可以取0

#include <iostream>
using namespace std;
#define N 32010
int c[N];
int cnt[N];

int lowerBit(int k){
	return k&-k;
}

void add(int x,int v){
	while (x <= N){
		c[x] += v; x += lowerBit(x);
	}
}

int query(int x){
	int ret = 0;
	while (x > 0){
		ret += c[x]; x -= lowerBit(x);
	}
	return ret;
}

int main(){
	int n,x,y; cin >> n;
	memset(c, 0, sizeof(c));
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++i){
		cin >> x >> y;
		add(x+1,1);
		cnt[query(x+1) - 1]++;
	}
	for (int i = 0; i < n; ++i)
		cout << cnt[i] << endl;
	system("pause");
}