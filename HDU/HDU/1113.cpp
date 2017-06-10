#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	map<string, string> m;
	string s, t;
	while (cin >> s){
		if (s == "XXXXXX")break;
		t = s;
		sort(t.begin(), t.end());
		m[s] = t;
	}
	while (cin >> s){
		if (s == "XXXXXX")break;
		sort(s.begin(), s.end());
		map<string, string>::iterator it;
		bool flag = false;
		for (it = m.begin(); it != m.end(); ++it){
			if (it->second == s){
				cout << it->first << endl;
				flag = true;
			}
		}
		if (!flag)cout << "NOT A VALID WORD" << endl;
		cout << "******" << endl;
	}
}