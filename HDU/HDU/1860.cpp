#include <iostream>
using namespace std;

int main(){
	int cnt[128];
	char a[10], b[100];
	while (gets(a)){
		if (strcmp(a, "#") == 0)break;
		gets(b);
		memset(cnt, 0,sizeof(cnt));
		for (int i = 0; i < strlen(b); ++i)
			cnt[b[i]]++;
		for (int i = 0; i < strlen(a); ++i)
			cout << a[i] << " " << cnt[a[i]] << endl;
	}
}