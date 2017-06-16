#include <iostream>
#include <algorithm>
using namespace std;

bool smaller(char a, char b){
	if (tolower(a) != tolower(b))
		return tolower(a) < tolower(b);
	return a < b;
}

bool next(char*first, char* last){
	if (first == last || first == last - 1)
		return false;
	char *i = last - 1;
	while (1){
		char *ii = i;
		i--;
		if (smaller(*i, *ii)){
			char *j = last;
			while (!smaller(*i, *--j));
			swap(*i, *j);
			reverse(ii,last);//last
			return true;
		}
		if (i == first)return false;
	}
}

int main(){
	char a[20];
	int T; cin >> T;
	while (T--){
		cin >> a;
		sort(a, a + strlen(a),smaller);
		printf("%s\n", a);
		while (next(a,a+strlen(a)))
			printf("%s\n", a);
	}
}