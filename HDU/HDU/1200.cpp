#include <iostream>
using namespace std;

int main(){
	char s[25][210];
	char t[210];
	int n;
	while (cin>>n){
		if (n == 0)break;
		getchar();
		gets(t);
		for (int i = 0; i < strlen(t) / n; ++i){
			for (int j = 0; j < n; ++j)
				s[i][j] = t[n*i + j];
			if (i % 2 == 1){
				int b = 0, e = n - 1;
				while (b < e){
					swap(s[i][b++], s[i][e--]);
				}
			}
		}
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < strlen(t) / n; ++j){
				cout << s[j][i];
			}
		}
		cout << endl;
	}
}