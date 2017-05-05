#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void insert(int *a, int x){
	int num = 0;
	if (a[num] == -1){
		a[num] = x;
		return;
	}
	int num1, num2;
	while (a[num]!=-1&&num<=510){
		num1 = num * 2 + 1;
		num2 = num * 2 + 2;
		if (a[num] <x){
			num = num1;
		}
		else if (a[num] >x){
			num = num2;
		}
		else return;
	}
	a[num] = x;
}

int main10091(){
	const int maxN = 1024;
	int src[maxN];
	int tar[maxN];
	int n;
	string s1, s2;
	
	while (cin >> n){
		if (n == 0)break;
		cin >> s1;
		memset(src, -1, sizeof(src));
		for (int i = 0; i < s1.length(); ++i)
			insert(src, s1[i] - '0');

		for (int i = 0; i < n; ++i){
			cin >> s2;
			memset(tar, -1, sizeof(tar));
			for (int j = 0; j < s2.length(); ++j)
				insert(tar, s2[j] - '0');

			bool isEqual = true;
			for (int j = 0; j < 1024; ++j){
				//cout << src[j] << " " << tar[j] << endl;
				if (src[j] != tar[j]){
					isEqual = false;
					break;
				}
			}
			if (isEqual)cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}