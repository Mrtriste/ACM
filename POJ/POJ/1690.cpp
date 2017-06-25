#include <iostream>
using namespace std;

char a[260];

void Detect(int left){
	bool hasMinus = false, inter = false;
	if (left - 1 >= 0 && a[left - 1] == '-')hasMinus = true;
	int cnt = 0,right;
	for (int i = left + 1; i < strlen(a); ++i){
		if (a[i] == '-' || a[i] == '+')inter = true;
		if (a[i] == '(')++cnt;
		if (a[i] == ')'){
			if (cnt == 0){
				right = i; break;
			}
			else cnt--;
		}
	}
	if (!(inter&&hasMinus))a[left] = a[right] = ' ';
}

int main(){
	int T; cin >> T; getchar();
	while (T--){
		gets(a);
		int f=0;
		for (int i = 0; i < strlen(a); ++i)
			if (a[i] != ' ')a[f++] = a[i];
		a[f] = '\0';
		for (int i = 0; i < strlen(a); ++i){
			if (a[i] == '(')Detect(i);
		}
		for (int i = 0; i < strlen(a); ++i)
			if (a[i] != ' ')cout << a[i];
		cout << endl;
	}
}