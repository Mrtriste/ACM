#include <iostream>
#include <algorithm>
using namespace std;

char a[10];

bool next(char *first, char *last){
	char *i= last - 1;
	while (1){
		char *ii = i;
		i--;
		char *i = ii - 1;
		if (*i < *ii){
			char *j = last;
			while (!(*i < *(--j)));
			swap(*i, *j);
			reverse(ii, last);
			return true;
		}
		if (i == first)return false;
	}
}

int main(){
	bool f = false;
	int a1, a2, a3, a4;
	//freopen("out.txt","w", stdout);
	while (1){
		cin >> a1 >> a2 >> a3 >> a4;
		a[0] = a1 + '0', a[1] = a2 + '0', a[2] = a3 + '0',a[3] = a4 + '0';
		if (!strcmp(a, "0000"))break;
		if (f)cout<< endl;;
		if (!f)f = true;
		
		sort(a, a + strlen(a));
		char last = '0';
		if (a[0] != '0'){
			cout << a;
			last = a[0];
		}
		while (next(a, a + strlen(a))){
			if (a[0] == '0')continue;
			else{
				if (a[0] != last){
					if (last == '0')cout << a;
					else cout << endl << a;
					last = a[0];
				}
				else cout <<" "<< a;
			}
		}
		cout << endl;
	}
}