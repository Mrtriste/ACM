#include <iostream>
#include <algorithm>
using namespace std;
#define maxN 10010

int k, m, l;
int sg[maxN];
int s[110];

int mex(int x){
	if (sg[x] != -1)return sg[x];
	bool vis[110];
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < k; ++i)
		if (x >= s[i])
			vis[mex(x - s[i])]=1;
	for (int i = 0;; ++i)
		if (!vis[i])
			return sg[x]=i;
}

int main(){
	
	while (cin >> k&&k){
		memset(sg, -1, sizeof(sg));
		for (int i = 0; i < k; ++i)
			cin >> s[i];
		sort(s, s + k);
		cin >> m;
		while (m--){
			cin >> l;
			int ans = 0, t;
			for (int i = 0; i < l; ++i){
				cin >> t;
				ans ^= mex(t);
			}
			if (ans)cout << "W";
			else cout << "L";
		}
		cout << endl;
	}
}