#include <iostream>
#include <string>
using namespace std;

char a[1010];
char b[1010];

#define MAX 300  

struct bigInteger{
	int digit[MAX];
	int size;

	bigInteger(){
		for (int i = 0; i < MAX; ++i){
			digit[i] = 0;
		}
		size = 0;
	}

	void set(char s[]){         //用一个小整数来设置高精度整数  
		int b = 0, l = strlen(s) - 1;
		while (s[b] == '0'&&b + 1 <=l)++b;
		for (int i = l, j = 0, t = 0, c = 1; i >= b; --i){
			t += (s[i] - '0') * c;
			j++;
			c *= 10;
			if (j == 4 || i == b){
				digit[size++] = t;
				j = 0;  t = 0;  c = 1;
			}
		}
	}
	bigInteger operator + (const bigInteger &A) const{
		bigInteger ret;
		int carry = 0;
		for (int i = 0; i < size || i < A.size; ++i){
			int t = digit[i] + A.digit[i] + carry;
			carry = t / 10000;
			t = t % 10000;
			ret.digit[ret.size++] = t;
		}
		if (carry != 0){
			ret.digit[ret.size++] = carry;
		}
		return ret;
	}

	void print(){
		int l = size-1;
		printf("%d", digit[l]);
		for (int i = l-1; i >= 0; --i)
			printf("%04d", digit[i]);
		cout << endl;
	}
};

ostream& operator<<(ostream& out, bigInteger& b)   //重载输出运算符
{
	int l = b.size - 1;
	cout << b.digit[l];
	for (int i = l - 1; i >= 0; i--)
		printf("%04d", b.digit[i]);
	return out;
}

int main(){
	int T; cin >> T;
	
	for (int cnt = 1; cnt <= T;++cnt){
		
		cin >> a >> b;
		bigInteger x, y;
		x.set(a), y.set(b);
		x = x + y;
		printf("Case %d:\n", cnt);
		cout << a << " + " << b << " = " << x << endl;
		if (cnt != T)cout << endl;
	}
}