#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void setStr(int *a, string &s){
	int cnt = 0;
	for (int i = 0; i < s.length(); ++i)
		if (s[i] == ',')++cnt;
	int t_cnt = cnt;
	int num = 0;
	int index = -1;
	for (int i = 0; i < cnt; ++i){
		for (index++; index < s.length(); ++index){
			if (s[index] == ','){
				a[t_cnt--] = num;
				num = 0;
				break;
			}
			else{
				num = (num * 10 + s[index] - '0');
			}
		}
	}
	for (index++; index < s.length(); ++index){
		num = (num * 10 + s[index] - '0');
	}
	a[0] = num;
	for (int i = cnt + 1; i < 30; ++i)
		a[i] = 0;
}

int main1016(){
	const int primeN = 1000;
	bool isPrime[primeN];
	int prime[primeN];
	memset(isPrime, true, sizeof(isPrime));
	memset(prime, -1, sizeof(prime));

	isPrime[0] = isPrime[1] = false;
	int k = 0;
	for (int i = 0; i < primeN; ++i){
		if (isPrime[i]){
			prime[k++] = i;
			for (int j = i + i; j < primeN; j += i)
				isPrime[j] = false;
		}
	}

	int a[30], b[30];
	string s1, s2;
	while (cin >> s1 >> s2){
		if (s1[0] == '0' || s2[0] == '0')break;
		setStr(a, s1);
		setStr(b, s2);
		int carry = 0;
		for (int i = 0; i < 30; ++i){
			a[i] += (b[i]+carry);
			carry = a[i] / prime[i];
			a[i] %= prime[i];
		}
		int pos;
		for (int i = 29; i >=0; --i){
			if (a[i] != 0){
				pos = i;
				break;
			}
		}

		for (int i = pos; i >0; --i)
			cout << a[i] << ",";
		cout << a[0] << endl;
		
	}

	return 0;
}