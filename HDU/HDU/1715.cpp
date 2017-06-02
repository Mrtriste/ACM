#include <iostream>
using namespace std;

struct BigInteger{
	int digit[100];
	int size;

	BigInteger(){
		init();
	}

	void init(){
		memset(digit, 0, sizeof(digit));
		size = 0;
	}

	void set(int x){
		while (x >= 10000){
			digit[size++] = x % 10000;
			x /= 10000;
		}
		if (x != 0)
			digit[size++] = x;
	}

	BigInteger operator+(const BigInteger&b){
		BigInteger ret;
		int t, c = 0;
		for (int i = 0; i < size; ++i){
			t = digit[i] + c + b.digit[i];
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

ostream& operator<<(ostream&out, BigInteger&b){
	b.print();
	return out;
}

BigInteger data[1010];

int main(){
	data[1].set(1), data[2].set(1);
	for (int i = 3; i < 1010; ++i){
		data[i] = (data[i - 1] + data[i - 2]);
	}

	int n, T; cin >> T;
	while (T--){
		cin >> n;
		cout << data[n] << endl;
	}
		
}