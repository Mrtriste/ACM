#include <iostream>
#include <algorithm>
using namespace std;

bool next(char*first, char*last){
	if (first == last || first == last - 1)return false;
	char *i = last - 1;
	while (1){
		char *ii = i;
		i--;
		if (*i < *ii){
			char *j = last;
			while (!(*i < *--j));
			swap(*i, *j);
			reverse(ii, last);
			return true;
		}
		if (i == first)return false;
	}
}

int main(){
	char a[210];
	while (cin >> a){
		sort(a, a + strlen(a));
		puts(a);
		while (next(a, a + strlen(a)))
			puts(a);
		
	}
}