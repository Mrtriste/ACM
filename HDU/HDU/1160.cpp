#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct Node{
	int index;
	int w;
	int s;
};

bool cmp(const Node&a, const Node&b){
	if (a.w != b.w)return a.w < b.w;
	else return a.s > b.s;
}

Node a[1010];
int dp[1010];
int path[1010];

int main(){
	int w, s;
	int cnt = 1;
	while (cin >> w >> s){
		a[cnt].w = w, a[cnt].s = s, a[cnt].index = cnt;
		cnt++;
	}
	sort(a + 1, a + cnt, cmp);
	memset(path, 0, sizeof(path));
	int mmax=0, last;
	for (int i = 1; i < cnt; ++i){
		dp[i] = 1;
		for (int j = 1; j < i; ++j){
			if (a[i].w > a[j].w&&a[i].s < a[j].s&&dp[i] < (dp[j] + 1)){
				dp[i] = dp[j] + 1;
				path[i] = j;
			}
		}
		if (mmax < dp[i])mmax = dp[i], last = i;
	}
	cout << mmax << endl;
	stack<int> sta;
	while (last != 0){
		sta.push(a[last].index);
		last = path[last];
	}
	int t;
	while (!sta.empty()){
		t = sta.top(), sta.pop();
		cout << t << endl;
	}

	return 0;

}