#include <iostream>
using namespace std;

struct BigInteger{
	int digit[600];
	int size;

	BigInteger(){
		init();
	}

	void init(){
		memset(digit, 0, sizeof(digit));
		size = 0;
	}

	void set( int x){
		init();
		while (x >= 10000){
			digit[size++] = x % 10000;
			x /= 10000;
		}
		if (x > 0)
			digit[size++] = x;
	}

	BigInteger operator+(const BigInteger &b){
		BigInteger ret;
		int t, c = 0;
		for (int i = 0; i < size || i<b.size; ++i){
			t = (digit[i] + b.digit[i] + c);
			ret.digit[ret.size++] = t % 10000;
			c = t / 10000;
		}
		if (c != 0)
			ret.digit[ret.size++] = c;

		return ret;
	}

	void print(){
		int l = size - 1;
		printf("%d", digit[l]);
		for (int i = l - 1; i >= 0; --i)
			printf("%04d", digit[i]);
	}
};

ostream& operator<<(ostream& out, BigInteger& b){
	b.print();
	return out;
}

const int maxN = 7300;
BigInteger data[maxN];

int main(){
	int n;
	BigInteger a, b;
	for (int i = 1; i <= 4; ++i)
		data[i].set(1);
	for (int i = 5; i < maxN; ++i){
		data[i] = (data[i - 1] + data[i - 2] + data[i - 3] + data[i - 4]);
		
	}
	while (cin >> n){
		cout << data[n]  << endl;
	}

}