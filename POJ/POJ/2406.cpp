#include <iostream>
using namespace std;
#define N 1000010

char P[N];
int Next[N];

void MakeNext(){
	int m = strlen(P), i = 0, j = -1;
	Next[0] = -1;
	while (i < m){
		if (j == -1 || P[i] == P[j])Next[++i] = ++j;
		else j = Next[j];
	}
}

int main(){
	while (1){
		scanf("%s", P);
		if (P[0] == '.')break;
		int l = strlen(P);
		MakeNext();
		if ((l % (l - Next[l])) == 0)cout << (l / (l - Next[l])) << endl;
		else cout << 1 << endl;
	}
}