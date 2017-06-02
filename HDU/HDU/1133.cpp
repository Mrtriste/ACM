#include<iostream>
using namespace std;

struct BigInteger{
	int digit[200];
	int size;

	BigInteger(){
		init();
	}

	void init(){
		memset(digit, 0, sizeof(digit));
		size = 0;
	}

	void set(const int x){
		init();
		digit[size++] = x;
	}

	BigInteger operator*(const int x){
		BigInteger ret;
		int t, c = 0;
		for (int i = 0; i < size; ++i){
			t = digit[i] * x + c;
			ret.digit[ret.size++] = t % 10000;
			c = t / 10000;
		}
		while (c >= 10000){
			ret.digit[ret.size++] = c % 10000;
			c /= 10000;
		}
		if (c != 0)
			ret.digit[ret.size++] = c;
		return ret;
	}

	BigInteger operator/(const int x){
		BigInteger ret;
		int down = 0;
		for (int i = size - 1; i >= 0; --i){
			ret.digit[i] = (down * 10000 + digit[i])/x;
			down = (down * 10000 + digit[i]) % x;
		}
		int l =size - 1;
		while (ret.digit[l] == 0 && l > 1)
			l--;
		ret.size = l + 1;
		return ret;
	}

	void print(){
		int l = size - 1;
		printf("%d", digit[l]);
		for (int i = l - 1; i >= 0; --i)
			printf("%04d", digit[i]);
	}
};

BigInteger fact[210];

ostream &operator<<(ostream&out, BigInteger& b){
	b.print();
	return out;
}

int main(){
	fact[0].set(1);
	for (int i = 1; i <= 200; ++i)
		fact[i] = fact[i - 1] * i;
	int m, n;
	BigInteger res;
	int cnt = 1;
	while (cin >> m >> n){
		if (m == 0 && n == 0)break;
		printf("Test #%d:\n", cnt++);
		if (n > m){
			cout << 0 << endl;
			continue;
		}
		res = fact[m + n];
		res = res*(m - n + 1) / (m + 1);
		
		cout << res << endl;
	}

}