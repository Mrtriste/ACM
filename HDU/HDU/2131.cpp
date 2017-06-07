#include <iostream>
using namespace std;

char lower(char c){
	if (c >= 'a' && c <= 'z')
		return c;
	else
		return c - 'A' + 'a';
}

int main(){
	char c, a[210];
	while (cin >> c >> a){
		int cnt = 0;
		for (int i = 0; i < strlen(a); ++i)
			if (lower(a[i])==lower(c))cnt++;
		printf("%.5f\n", float(cnt) / strlen(a));
	}
}