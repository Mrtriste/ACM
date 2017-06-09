#include <iostream>
using namespace std;

int main(){
	char s[60];
	int T; cin >> T;
	for (int e = 1; e <= T; ++e){
		cin >> s;
		for (int i = 0; i < strlen(s); ++i)
			s[i] = ((s[i] - 'A' + 1) % 26 + 'A');
		printf("String #%d\n", e);
		cout << s << endl;
		cout << endl;
	}
}