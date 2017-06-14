#include <iostream>
using namespace std;
#define N 1000010

char P[N];
int Next[N];
int n;

void MakeNext(){
	int i = 0, j = -1;
	Next[0] = -1;
	while (i < n){
		if (j == -1 || P[i] == P[j])Next[++i] = ++j;
		else j = Next[j];
	}
}

int main(){
	int t = 1;
	while (cin >> n&&n){
		printf("Test case #%d\n", t++);
		scanf("%s", P);
		MakeNext();
		for (int i = 2; i <= n; ++i){
			int x = i / (i - Next[i]);
			if ((i % (i - Next[i])) == 0 && x>1)
				cout << i << " " << x << endl;
		}
		cout << endl;
		
	}
}