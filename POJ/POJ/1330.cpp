#include <iostream>
#include <set>
using namespace std;

int par[10010];

int common(int a, int b){
	set<int> s;
	while (a > 0){
		s.insert(a);
		a = par[a];
	}
	while (b > 0){
		if (s.find(b) != s.end())
			return b;
		b = par[b];
	}
	return -1;
}

int main(){
	int T; cin >> T;
	while (T--){
		int n,a,b; cin >> n;
		memset(par, 0, sizeof(par));
		for (int i = 0; i < n - 1; ++i){
			cin >> a >> b;
			par[b] = a;
		}
		cin >> a >> b;
		cout << common(a, b) << endl;
	}
}