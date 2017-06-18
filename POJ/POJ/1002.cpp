#include <iostream>
#include <map>
using namespace std;

int fmt(char a){
	if (a >= '0'&&a <= '9')return a - '0';
	if (a >= 'A'&&a <= 'O')return (a - 'A') / 3 + 2;
	if (a >= 'T'&&a <= 'Y')return (a - 'T') / 3 + 8;
	if (a >= 'P'&&a <= 'S'&&a!='Q')return 7;
	return -1;
}

int main(){
	int n; cin >> n;
	char a[128];
	map<int, int> mp;
	map<int, int>::iterator it;
	for (int i = 0; i < n; ++i){
		cin >> a;
		int  ret = 0;
		for (int j = 0; j < strlen(a); ++j){
			int x = fmt(a[j]);
			if (x >= 0){
				ret = ret*10 + x;
			}
		}
		mp[ret]++;
	}
	bool flag = false;
	for (it = mp.begin(); it != mp.end(); ++it){
		int x = it->first, cnt = it->second;
		if (cnt > 1){
			flag = true;
			printf("%03d-%04d %d\n", x / 10000, x % 10000, cnt);
		}
			
	}
	if (!flag)puts("No duplicates.");
	system("pause");
}