#include <iostream>
#include <stack>
using namespace std;
#define N 400010

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
	int ans[N], cnt;
	while (scanf("%s", P) != EOF){
		MakeNext();
		cnt = 0;
		int len = strlen(P);
		while (len > 0){
			ans[cnt++] = len;
			len = Next[len];
			
		}
		for (int i = cnt - 1; i >= 1; --i)
			cout << ans[i] << " ";
		cout << ans[0] << endl;
	}
}