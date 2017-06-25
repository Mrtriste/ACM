#include <iostream>
using namespace std;

char s[100010], t[100010];

bool Solve(){
	int pos = 0, lent = strlen(t), lens = strlen(s);
	for (int i = 0; i < lent; ++i){
		if (s[pos] == t[i])pos++;
		if (pos == lens)return true;
	}
	return false;
}

int main(){
	while (scanf("%s%s", s, t) != EOF){
		printf("%s\n",Solve() ? "Yes" : "No");
	}
}
