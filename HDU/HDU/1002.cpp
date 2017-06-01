#include <iostream>
#include <string>
using namespace std;

char a[1010];
char b[1010];

#define MAX 300  

struct bigInteger{
	int digit[MAX];
	int size;
	void init(){
		for (int i = 0; i < MAX; ++i){
			digit[i] = 0;
		}
		size = 0;
	}
	void set(char s[]){         //用一个小整数来设置高精度整数  
		init();
		int l = strlen(s);
		for (int i = l - 1, j = 0, t = 0, c = 1; i >= 0; --i){
			t += (s[i] - '0') * c;
			j++;
			c *= 10;
			if (j == 4 || i == 0){
				digit[size++] = t;
				j = 0;  t = 0;  c = 1;
			}
		}
	}
	bigInteger operator + (const bigInteger &A) const{
		bigInteger ret;
		ret.init();
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
		printf("%d", digit[size - 1]);
		for (int i = size - 2; i >= 0; --i)
			printf("%04d", digit[i]);
		cout << endl;
	}
};

ostream& operator<<(ostream& out, bigInteger& b)   //重载输出运算符
{
	int i;
	cout << b.digit[b.size - 1];
	for (i = b.size - 2; i >= 0; i--)
	{
		cout.width(4);
		cout.fill('0');
		cout << b.digit[i];
	}
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
		cout << a << " + " << b << " = " << x;
		//x.print();
		if (cnt != T)cout << endl;
	}
}