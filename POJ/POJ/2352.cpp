//Ê÷×´Êý×é
#include <iostream>
using namespace std;
#define N 15010
int c[32010];
int cnt[N];

int lowerBit(int k){
	return k&-k;
}

void add(int x,int v){
	while (x <= 32010){
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


///////////////////////////////Ïß¶ÎÊ÷
//#include <iostream>
//using namespace std;
//
//int num[32010 << 2];
//
//void add(int x, int l, int r, int rt){
//	if (l == r){
//		num[rt]++;
//		return;
//	}
//	int mid = (l + r) >> 1;
//	if (x <= mid)add(x, l, mid, rt << 1);
//	else add(x, mid + 1, r, rt << 1 | 1);
//	num[rt] =num[rt<<1]+num[rt<<1|1];
//}
//
//int query(int x, int l, int r, int rt){
//	if (x == r)return num[rt];
//	int mid = (l + r) >> 1;
//	if (x > mid)return num[rt << 1] + query(x, mid+1, r, rt << 1 | 1);
//	else return query(x, l, mid, rt << 1);
//}
//
//
//int main(){
//	int n; cin >> n;
//	int cnt[15010];
//	memset(num, 0, sizeof(num));
//	memset(cnt, 0, sizeof(cnt));
//	int x, y;
//	for (int i = 0; i < n; ++i){
//		cin >> x >> y;
//		add(x, 0, 32000, 1);
//		//int c = query(x, 0, 32000, 1)-1;
//		cnt[query(x, 0, 32000, 1) - 1]++;
//	}
//	for (int i = 0; i < n; ++i)
//		cout << cnt[i] << endl;
//	system("pause");
//}