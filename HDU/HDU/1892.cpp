#include <iostream>
#include <algorithm>
using namespace std;

int C[1010][1010];
int map[1010][1010];

int lowBit(int k){
	return k&-k;
}

void add(int x, int y, int v){
	for (int i = x; i <= 1005; i += lowBit(i))
		for (int j = y; j <= 1005; j += lowBit(j))
			C[i][j] += v;
		
			
}

int query(int x, int y){
	int ret = 0;
	for (int i = x; i > 0; i -= lowBit(i))
		for (int j = y; j > 0; j -= lowBit(j))
			ret += C[i][j];
	return ret;
}

int main(){
	int T; cin >> T; int t = 1;
	while (T--){
		memset(C, 0, sizeof(C));
		for (int i = 1; i <= 1005; ++i)
			for (int j = 1; j <= 1005; ++j){
			map[i][j] = 1;
			C[i][j] = lowBit(i)*lowBit(j);
			//add(i, j, 1);
			}
				
		int Q; cin >> Q;
		char s[2]; int x1, y1, x2, y2, n1;
		printf("Case %d:\n", t++);
		while (Q--){
			scanf("%s", s);
			if (s[0] == 'S'){
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				x1++, y1++, x2++, y2++;
				if (x1 > x2)swap(x1, x2);
				if (y1 > y2)swap(y1, y2);
				int ans = query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1-1, y1-1);
				cout << ans << endl;

			}
			else if (s[0] == 'M'){
				scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2,&n1);
				x1++, y1++, x2++, y2++;
				n1 = min(map[x1][y1], n1);
				map[x1][y1] -= n1, map[x2][y2] += n1;
				add(x1, y1, -n1);
				add(x2, y2, n1);
			}
			else if(s[0]=='A'){
				scanf("%d%d%d", &x1, &y1, &n1);
				x1++, y1++;
				map[x1][y1] += n1;
				add(x1, y1, n1);
			}
			else{
				scanf("%d%d%d", &x1, &y1, &n1);
				x1++, y1++;
				n1 = min(map[x1][y1], n1);
				map[x1][y1] -= n1;
				add(x1, y1, -n1);
			}
		}
	}
}