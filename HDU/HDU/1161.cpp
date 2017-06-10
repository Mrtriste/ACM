#include <iostream>
using namespace std;

int main(){
	char s[1010];
	while (gets(s) != NULL){
		for (int i = 0; i < strlen(s); ++i){
			if (s[i] >= 'A'&&s[i] <= 'Z')
				s[i] += ('a'-'A');
		}
		cout << s << endl;
	}
}