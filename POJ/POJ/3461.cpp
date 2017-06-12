#include <iostream>
using namespace std;

char T[1000010], P[10010];
int Next[10010];
int ans;

void MakeNext(){
	int m = strlen(P),i=0,j=-1;
	Next[0] = -1;
	while (i < m){
		if (j == -1 || P[j] == P[i])Next[++i] = ++j;
		else j = Next[j];
	}
}

void KMP(){
	int m = strlen(P), n = strlen(T), i=0, j=0;
	while (i < n){
		if (j == -1 || T[i] == P[j])++i, ++j;
		else j = Next[j];
		if (j == m){
			ans++;
			--i, --j;
			j = Next[j];
		}
	}
}

int main(){
	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		scanf("%s%s", P, T);
		ans = 0;
		MakeNext();
		KMP();
		cout << ans << endl;
	}
}