//扫描线

#include <iostream>
#include <algorithm>
using namespace std;
#define maxN 10000

struct Node{
	double l, r, h;
	int d;
	Node(){}
	Node(double ll, double rr, double hh, int dd) :l(ll), r(rr), h(hh), d(dd){}
	bool operator<(const Node&n){
		return h < n.h;
	}
};

Node seg[maxN];
int sum[maxN<<2];
int ha[maxN];
int mark[maxN];

void updateFather(int l, int r, int rt){
	if (mark[rt]) sum[rt] = ha[r + 1] - ha[l];
	else if (l == r)sum[rt] = 0;
	else sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void update(int L, int R, int d, int l, int r, int rt){
	if (L <= l&&R >= r){
		mark[rt] += d;
		updateFather(l, r, rt);
		return;
	}
	int mid = (l + r) >> 1;
	if (L <= mid)update(L, R, d, l, mid, rt << 1);
	if (R > mid)update(L, R, d, mid + 1, r, rt << 1 | 1);
	updateFather(l, r, rt);
	
}


int main(){
	int a, b, c, d;
	int size = 0;
	while (cin >> a >> b >> c >> d){
		if (a < 0){
			sort(ha, ha + size);
			sort(seg, seg + size);
			int k = 1;//k=1
			for (int i = 1; i < size; ++i)
				if (ha[i] != ha[i - 1])
					ha[k++] = ha[i];
				
			memset(mark, 0, sizeof(mark));
			memset(sum, 0, sizeof(sum));
			double ans = 0;
			for (int i = 0; i < size; ++i){
				int l = lower_bound(ha, ha + k, seg[i].l)-ha;
				int r = lower_bound(ha, ha + k, seg[i].r) - ha-1;
				update(l, r, seg[i].d, 0, k - 1, 1);
				ans += sum[1]*(seg[i+1].h-seg[i].h);//warnings!!!
			}
			cout << ans << endl;
			
			size = 0;
			if (a == -1)continue;
			if (a == -2)break;
		}
		if (a > c)swap(a, c);
		if (b > d)swap(b, d);
		
		ha[size] = a;
		seg[size++] = Node(a, c, b, 1);
		ha[size] = c;
		seg[size++] = Node(a, c, d, -1);

	}
}