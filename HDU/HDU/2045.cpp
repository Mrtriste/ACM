#include <iostream>
using namespace std;

//struct BigInteger{
//	int size;
//	int digit[100];
//	BigInteger(){
//		init();
//	}
//
//	void init(){
//		memset(digit, 0, sizeof(digit));
//		size = 0;
//	}
//
//	void set(int x){
//		digit[size++] = x;
//	}
//
//	BigInteger operator+(const BigInteger&b){
//		BigInteger ret;
//		int t, c = 0;
//		for (int i = 0; i < size||i<b.size; ++i){
//			t = digit[i] + b.digit[i] + c;
//			ret.digit[ret.size++] = t % 10000;
//			c = t / 10000;
//		}
//		if (c != 0)ret.digit[ret.size++] = c;
//
//		return ret;
//	}
//
//	void print(){
//		int l = size - 1;
//		printf("%d", digit[l]);
//		for (int i = l - 1; i >= 0; --i)
//			printf("%04d", digit[i]);
//		cout << endl;
//	}
//};

int main(){
	//BigInteger a[60];
	//a[1].set(3); a[2].set(6); a[3].set(6);
	long long a[60];
	a[1] = 3, a[2] = 6, a[3] = 6;
	for (int i = 4; i <= 50; ++i)
		a[i] = (a[i - 1] + a[i - 2] + a[i - 2]);
	int n;
	while (cin >> n){
		//a[n].print();
		cout << a[n] << endl;
	}
}