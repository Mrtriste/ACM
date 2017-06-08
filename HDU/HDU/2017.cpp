#include <iostream>
using namespace std;

int main(){
	int T; cin >> T;
	char a[10000];
	while (T--){
		int cnt = 0;
		cin >> a;
		for (int i = 0; i < strlen(a); ++i)
			if (isdigit(a[i]))
				cnt++;
		cout << cnt << endl;
	}
}