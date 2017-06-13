#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
	int n; cin >> n; getchar();
	map<string, int> mp;
	string s;
	for (int i = 0; i < n; ++i){
		getline(cin, s);
		mp[s] = 0;
	}
		
	int m,score; cin >> m;
	while (m--){
		int rank = 1;
		for (int i = 0; i < n; ++i){
			cin >> score; getchar();
			getline(cin, s);
			mp[s] += score;
		}
		map<string, int>::iterator it;
		for (it = mp.begin(); it != mp.end(); ++it)
			if (it->second>mp["Li Ming"])
				++rank;
		cout << rank << endl;
	}
}