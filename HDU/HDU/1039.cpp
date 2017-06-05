#include <iostream>
using namespace std;

int type(char a){
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		return 1;
	return 2;
}

int main(){
	char a[25];
	while (cin >> a){
		if (strcmp(a, "end") == 0)break;
		int len = strlen(a);
		bool vowel = false;
		for (int i = 0; i < len; ++i){
			if (type(a[i])==1){
				vowel = true;
				break;
			}
		}
		if (!vowel){
			printf("<%s> is not acceptable.\n",a);
			continue;
		}

		int b = 0, e = 0;
		bool res = true;
		while (e < len){
			int cnt = 0;
			while (e < len&&a[e] == a[b])
				cnt++, e++;
			if (cnt == 2 && a[b] != 'e'&&a[b] != 'o'){
				res = false;
				break;
			}
			b = e;
		}
		if (!res){
			printf("<%s> is not acceptable.\n", a);
			continue;
		}

		b = e = 0, res = true;
		while (e < len){
			int cnt = 0;
			while (e < len&&type(a[e]) == type(a[b]))
				cnt++, e++;
			if (cnt >=3){
				res = false;
				break;
			}
			b = e;
		}
		if (!res)
			printf("<%s> is not acceptable.\n", a);
		else
			printf("<%s> is acceptable.\n", a);

	}
}