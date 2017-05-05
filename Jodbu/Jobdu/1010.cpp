#include <iostream>
#include <map> 
#include <string>
using namespace std;

int main1010(){
	map<string, int> mp;
	mp["zero"] = 0; mp["one"] = 1; mp["two"] = 2; mp["three"] = 3; mp["four"] = 4;
	mp["five"] = 5; mp["six"] = 6; mp["seven"] = 7; mp["eight"] = 8; mp["nine"] = 9;
	string s;
	int a = 0, b = 0;
	bool aTurn = true;
	while (cin >> s){
		if (s[0] == '+'){
			aTurn = false;
		}
		else if (s[0] == '='){
			aTurn = true;
			if (a == 0 && b == 0)
				break;
			cout << (a + b) << endl;
			a = b = 0;
		}
		else{
			if (aTurn){
				a = (a * 10 + mp[s]);
			}
			else{
				b = (b * 10 + mp[s]);
			}
		}

	}
	return 0;
}