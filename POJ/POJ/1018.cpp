#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f

int n, m;
int dp[1100];

struct Node{
	int b, p;
	Node(){}
	Node(int bb, int pp) :b(bb), p(pp){}
};

int main(){
	int T; cin >> T;
	while (T--){
		cin >> n;
		int b, p;
		memset(dp, 0x3f, sizeof(dp));
		queue<Node>q; q.push(Node(INF, 0));
		Node cur;
		for (int i = 1; i <= n; ++i){
			cin >> m;
			memset(dp, 0x3f, sizeof(dp));
			for (int j = 0; j < m; ++j){
				cin >> b >> p;
				int qsize = q.size();
				while (qsize--){
					cur = q.front(), q.pop();
					if (cur.b < b)dp[cur.b] = min(dp[cur.b], cur.p + p);
					else dp[b] = min(dp[b], p + cur.p);
					q.push(cur);
				}
			}
			while (!q.empty())q.pop();
			for (int i = 0; i < 1100; ++i)
				if (dp[i] != INF)
					q.push(Node(i, dp[i]));
		}
		float mmax = 0;
		while (!q.empty()){
			cur = q.front(), q.pop();
			mmax = max(mmax, float(cur.b) / cur.p);
		}
		
		printf("%.3f\n", mmax);
	}
}