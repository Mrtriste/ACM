#include <iostream>
using namespace std;

int main(){
	char a[110];
	while (gets(a)){
		bool flag = true;
		for (int i = 0; i < strlen(a); ++i){
			if (flag){
				cout << char(a[i] - ('a' - 'A'));
				flag = false;
				continue;
			}
			cout << a[i];
			if (a[i] == ' ')flag = true;

		}
		cout << endl;
	}
}