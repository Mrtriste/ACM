#include <iostream>
#include <string>
#include <map>
using namespace std;

string a[110];

bool isCon(char c){
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return false;
	return true;
}

int main(){
	int L, N;
	while (cin >> L >> N){
		string s, t;
		map<string, string> mp;
		for (int i = 0; i < L; ++i){
			cin >> s >> t;
			mp[s] = t;
		}

		map<string, string>::iterator it;
		for (int i = 0; i < N; ++i){
			cin >> s;
			it = mp.find(s);
			int len = s.length();
			if (it != mp.end())
				cout << mp[s] << endl;
			else if (s[len - 1] == 'y'&&isCon(s[len - 2]))
				cout << s.substr(0, len - 1) << "ies" << endl;
			else if (s[len - 1] == 'o' || s[len - 1] == 'x' || s[len - 1] == 's' || (s[len - 2] == 'c'&&s[len - 1] == 'h') || (s[len - 2] == 's'&&s[len - 1] == 'h'))
				cout << s << "es" << endl;
			else
				cout << s << "s" << endl;
		}

	}
}