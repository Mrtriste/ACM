#include <iostream>
using namespace std;

bool a[110][110];

void set(int x, int y, int l, int v){
	for (int i = x; i <= x + l - 1; ++i)
		for (int j = y; j <= y + l - 1; ++j)
			a[i][j] = v;
}

int query(int x, int y, int l){
	int cnt = 0;
	for (int i = x; i <= x + l - 1; ++i)
		for (int j = y; j <= y + l - 1; ++j)
			if (a[i][j]) ++cnt;
	return cnt;
}

int main(){
	int T; cin >> T;
	char s[10];
	int x, y, l;
	memset(a, 0, sizeof(a));
	while (T--){
		cin >> s >> x >> y >> l;
		if (strcmp(s, "WHITE") == 0)
			set(x, y, l, 0);
		else if (strcmp(s, "BLACK") == 0)
			set(x, y, l, 1);
		else
			cout << query(x, y, l) << endl;
	}
}