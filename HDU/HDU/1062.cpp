#include <iostream>
using namespace std;

int main(){
	int T; cin >> T; getchar();
	char a[1010];
	while (T--){
		gets(a);
		int len = strlen(a);
		int b = 0, e = 0;
		while (e < len){
			int tb, te;
			while (e < len&&a[e] != ' ')
				e++;
			tb = b, te = e - 1;
			while (tb < te){
				swap(a[tb], a[te]);
				tb++, te--;
			}
			b =e= e + 1;
		}
		cout << a << endl;
	}
}