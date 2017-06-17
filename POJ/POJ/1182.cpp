//#include <iostream>
//using namespace std;
//
//int p[50010];
//int r[50010];//0 same, 1 eaten by fa, 2 eat fa
//int n, k;
//
//void Make(){
//	for (int i = 1; i <= n; ++i)
//		p[i] = i;
//	memset(r, 0, sizeof(r));
//}
//
//int find(int x){
//	if (x != p[x]){
//		int fa = p[x];
//		p[x] = find(fa);
//		r[x] = (r[x] + r[fa]) % 3;
//	}
//	return p[x];
//}
//
//bool Union(int x,int y,int d){
//	int fx = find(x), fy = find(y);
//	if (fx == fy){
//		if ((r[fx] - r[fy] + 3) % 3 == d - 1)
//			return true;
//		else
//			return false;
//	}
//	p[fx] = fy;
//	r[fx] = () % 3;
//}
//
//int main(){
//	while (cin >> n >> k){
//		int d, x, y, cnt = 0;
//		for (int i = 0; i < k; ++i){
//			cin >> x >> y;
//			if (x>n || y > n)++cnt;
//			else if (d == 2 && x == y)++cnt;
//			else{
//				
//			}
//		}
//	}
//}