#include <iostream>
using namespace std;

int main(){
	int T; cin >> T;
	char a[10010];
	while (T--){
		scanf("%s", a);
		int b = 0, e = 0, len = strlen(a);
		while (e<len){
			int cnt = 0;
			while (e < len&&a[e] == a[b])
				e++, cnt++;
			if (cnt > 1)
				cout << cnt;
			cout << a[b];
			b = e;//e and b points to the next pos at the same time!!
		}
		cout << endl;
	}
}