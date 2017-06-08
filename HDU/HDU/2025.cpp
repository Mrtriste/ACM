#include <iostream>
using namespace std;

int main(){
	char a[110];
	while (cin >> a){
		char m = 0;
		for (int i = 0; i < strlen(a); ++i)
			if (m < a[i])
				m = a[i];
		for (int i = 0; i < strlen(a); ++i){
			cout << a[i];
			if (a[i] == m)cout << "(max)";
		}
		cout << endl;
	}
}