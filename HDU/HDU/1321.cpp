#include<iostream>
using namespace std;

int main(){
	char s[80];
	int T; cin >> T; getchar();
	while (T--){
		gets(s);
		int len = strlen(s);
		int b = 0, e = len-1;
		while (b < e)
			swap(s[b++], s[e--]);
		//b = 0, e = 0;
		//while (e < len){
		//	while (e < len&&s[e] != ' ')
		//		e++;
		//	int te = e - 1, tb = b;
		//	while (tb < te)
		//		swap(s[tb++], s[te--]);
		//	while (e < len&&s[e] == ' ')
		//		e++;
		//	b = e;
		//}
		cout << s << endl;
	}
}