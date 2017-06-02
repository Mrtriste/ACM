#include<iostream>
using namespace std;

struct BigInteger{
	int digit[40];
	int size;
	BigInteger(){
		init();
	}

	void init(){
		memset(digit, 0, sizeof(digit));
		size = 0;
	}

	void set(int x){
		init();
		digit[size++] = x;
	}

	BigInteger operator+(const BigInteger&b){
		BigInteger ret;
		int t,c = 0;
		for (int i = 0; i < size || i<b.size; ++i){
			t = digit[i] + b.digit[i] + c;
			ret.digit[ret.size++] = t % 10000;
			c = t / 10000;
		}
		if (c != 0)ret.digit[ret.size++] = c;

		return ret;
	}

	void print(){
		int l = size - 1;
		printf("%d", digit[l]);
		for (int i = l - 1; i >= 0; --i)
			printf("%04d", digit[i]);
		cout << endl;
	}
	
};

BigInteger f[210];
BigInteger g[210];

int main(){
	f[1].set(1), g[1].set(0);
	for (int i = 2; i <= 200; ++i){
		f[i] = f[i - 1] + g[i - 1];
		g[i] = f[i - 1];
	}
	char a[210]; int T; cin >> T;
	while (T--){
		cin >> a;
		(f[strlen(a)] + g[strlen(a)]).print();
	}
}