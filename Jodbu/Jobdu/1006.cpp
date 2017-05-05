#include <iostream>
#include <string>
using namespace std;

bool detect(int a, int b, int c){
	if (b == 1&&a==c)return true;
	b = b - 1;
	c = c - a;
	if (c < 0 || b < 0)return false;
	return detect(a, b, c);
	
}

int main1006(){
	string s;
	while (cin >> s){
		int i;
		int a = 0, b = 0, c = 0;
		int hasZ = 0, hasJ = 0;
		for (i = 0; i < s.length(); ++i){
			if (s[i] == 'z')
				++hasZ;
			if (s[i] == 'j')
				++hasJ;
		}
		if (!(hasJ == 1 && hasZ == 1)){
			cout << "Wrong Answer" << endl;
			continue;
		}
		for (i = 0; i < s.length(); ++i){
			if (s[i] == 'z'){
				hasZ = i;
				break;
			}
			++a;
		}
		for (i++; i < s.length(); ++i){
			if (s[i] == 'j'){
				hasJ = i;
				break;
			}
			++b;
		}
		for (i++; i < s.length(); ++i){
			++c;
		}
		if (hasZ >= hasJ){
			cout << "Wrong Answer" << endl;
			continue;
		}

		if (detect(a, b, c))
			cout << "Accepted" << endl;
		else
			cout << "Wrong Answer" << endl;

	}
	return 0;
}