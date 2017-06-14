#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct Node{
	char a[30];
	int v;
	bool operator<(const Node&b){
		if (v == b.v)return strcmp(a, b.a) < 0;
		return v > b.v;
	}
};

vector<Node> G[110];
int vis[110];

int main(){
	int T; cin >> T;
	for (int e = 1; e <= T; ++e){
		int n; cin >> n;
		for (int i = 0; i < n; ++i)
			G[i].clear();
		map<string, int> mp;
		memset(vis, -1, sizeof(vis));
		string s;
		int cnt = 0;
		map<string, int>::iterator it;
		int index,root; Node cur;
		for (int i = 0; i < n; ++i){
			cin >> s;
			it = mp.find(s);
			if (it == mp.end()){
				index = cnt;
				mp[s] = cnt++;
			}
			else
				index = mp[s];
			if (s == "Ted")root = index;
			cin >> cur.a >> cur.v;
			G[index].push_back(cur);
		}
		vector<Node> ans;
		queue<int> q;
		vis[root] = 100;
		q.push(root);
		string name; int sonage;
		Node d;

		while (!q.empty()){
			int x = q.front(); q.pop();
			int age = vis[x];
			for (int i = 0; i < G[x].size(); ++i){
				name = G[x][i].a, sonage = age-G[x][i].v;
				it = mp.find(name); 
				if (it != mp.end()){
					int t = mp[name];
					vis[t] = sonage;
					q.push(t);
				}
				strcpy(d.a, name.c_str());
				d.v = sonage;
				ans.push_back(d);
			}
		}
		sort(ans.begin(), ans.end());
		cout << "DATASET " << e << endl;
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i].a << " " << ans[i].v << endl;

	}
}