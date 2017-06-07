#include<iostream>
using namespace std;

int main(){
	char low[30], m[100];
	char upper[30];
	while (cin >> low){
		getchar();
		gets(m);
		for (int i = 0; i < 26; ++i){
			upper[i] = low[i] + 'A' - 'a';
		}
		for (int i = 0; i < strlen(m); ++i){
			if (m[i] >= 'a'&&m[i] <= 'z')
				m[i] = low[m[i] - 'a'];
			else if (m[i] >= 'A'&&m[i] <= 'Z')
				m[i] = upper[m[i] - 'A'];
		}
		cout << m << endl;
	}
}