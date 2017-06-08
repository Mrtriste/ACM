#include <iostream>
using namespace std;

char s[32][10] =
{ "auto", "double", "int", "struct", "break", "else", "long", "switch",
"case", "enum", "register", "typedef", "char", "extern", "return", "union",
"const", "float", "short", "unsigned", "continue", "for", "signed", "void",
"default", "goto", "sizeof", "volatile", "do", "if", "while", "static" };

bool isOK(char c){
	if (isdigit(c) || (c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z') || (c == '_'))
		return true;
	return false;
}

bool isGuan(char *t){
	for (int i = 0; i < 32; ++i){
		if (strcmp(t, s[i]) == 0)
			return true;
	}
	return false;
}

int main(){
	char a[60];
	int T; cin >> T; getchar();
	while (T--){
		gets(a);
		if (isdigit(a[0]))
			cout << "no" << endl;
		else if (isGuan(a))
			cout << "no" << endl;
		else{
			bool flag = true;
			for (int i = 0; i < strlen(a); ++i){
				if (!isOK(a[i])){
					flag = false;
					break;
				}
			}
			if (flag)cout << "yes" << endl;
			else cout << "no" << endl;
		}
	}
}