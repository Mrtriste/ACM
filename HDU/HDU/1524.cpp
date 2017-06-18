#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> G[1010];
int sg[1010];

int mex(int r){
	if (sg[r] != -1)return sg[r];
	bool temp[1010];
	memset(temp, 0, sizeof(temp));
	for (int i = 0; i < G[r].size(); ++i){
		int v = G[r][i];
		sg[v] = mex(v);
		temp[sg[v]] = 1;
	}
	for (int i = 0;; ++i){
		if (!temp[i]){
			sg[r] = i;
			return i;
		}
	}
}

int main(){
	int x, t,m,n;
	while (cin >> n){
		for (int i = 0; i < n; ++i)
			G[i].clear(), sg[i] = -1;
		for (int i = 0; i < n; ++i){
			cin >> x;
			for (int j = 0; j < x; ++j){
				cin >> t;
				G[i].push_back(t);
			}
		}

		while (cin >> m&&m){
			int ans=0;
			while (m--){
				cin >> t;
				ans ^= mex(t);
			}
			if (ans)puts("WIN");
			else puts("LOSE");
		}
	}
}