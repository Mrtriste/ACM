#include <iostream>
using namespace std;

int main(){
	char s[90], dest[90];
	int T,pos,cnt=1; cin >> T;
	while (T--){
		cin >> pos >> s;
		dest[0] = '\0';
		strncat(dest, s,pos-1);
		strncat(dest, s + pos, strlen(s) - pos);
		cout <<(cnt++)<<" "<< dest << endl;
	}
}