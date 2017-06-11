//poj 2182
//find the k-th number

#include <iostream>
using namespace std;

int pre[8010];
int len[8010 << 2];

void build(int l, int r, int rt){
	len[rt] = r - l + 1;
	if (l == r)return;
	int mid = (r + l) >> 1;//it's >>1, not 2
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
}

//query the k-th num in the remained num
int query(int k, int l, int r, int rt){//x compares with len
	if (l == r)return l;
	int mid = (l + r) >> 1;
	if (k <= len[rt << 1])return query(k, l, mid, rt << 1);
	//always compare with rt<<1, len[rt<<1] && k-len[rt<<1]
	if (k > len[rt << 1])return query(k - len[rt << 1], mid + 1, r, rt << 1 | 1);//x-len[rt<<1]
}

void clean(int x,int l,int r,int rt){//x is the node --[x]
	if (l == r){
		len[rt]--;
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid)clean(x, l, mid, rt << 1);
	if (x > mid)clean(x, mid + 1, r, rt <<1 | 1);
	len[rt]--;
}

int main(){
	int n; cin >> n;
	pre[1] = 0;
	for (int i = 2; i <= n; ++i)
		scanf("%d", &pre[i]);
	build(1, n, 1);
	int ans[8010];
	for (int i = n; i >= 1; --i){
		ans[i] = query(pre[i]+1, 1, n, 1);
		clean(ans[i], 1, n, 1);
	}
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << endl;
	system("pause");
}