#include<iostream>
#include <algorithm>
using namespace std;

char a[500], b[500];

struct BigInteger{
	int digit[110];
	int size;

	BigInteger(){
		init();
	}

	void init(){
		memset(digit, 0, sizeof(digit));
		size = 0;
	}

	void set(int x){
		digit[size++] = x;
	}

	void set(char*a, int len){//isInte part
		init();
		int first = 0;
		
		while (a[first] == '0'&&first < len-1)
			first++;
		
		for (int i = len - 1,k=0,t=0,c=1; i >= first; --i){
			t += (a[i]-'0') * c;
			c *= 10, k++;
			if (k == 4 || i == first){
				digit[size++] = t;
				c = 1, t = 0, k = 0;
			}
		}

	}

	BigInteger operator+(const BigInteger& b){
		BigInteger ret;
		int t, c = 0;
		for (int i = 0; i < size || i < b.size; ++i){
			t = digit[i] + b.digit[i] + c;
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

ostream& operator<<(ostream& out, BigInteger &b){
	b.print();
	return out;
}

struct BigFloat{
	int digit[400];
	int size;
	int carry;

	BigFloat(){
		init();
	}

	void init(){
		memset(digit, 0, sizeof(digit));
		carry = size = 0;
	}

	void set(char *a,int len){
		init();
		for (int i = 0; i < len; ++i)
			digit[size++] = a[i] - '0';
		int l = size - 1;
		while (l > 0&&digit[l] == 0)
			l--;
		size = l + 1;
	}

	BigFloat operator+(const BigFloat&f){
		BigFloat ret;
		int t, c = 0;
		int maxl = max(size, f.size);
		ret.size = maxl;
		for (int i = maxl-1; i>=0; --i){
			t = (digit[i] + f.digit[i] + c);
			ret.digit[i] = t % 10;
			c = t / 10;
		}
		if (c != 0)
			ret.carry = c;
		int l = ret.size - 1;
		while (ret.digit[l] == 0 && l > 0)
			l--;
		ret.size = l + 1;
		return ret;
	}

	void print(){
		for (int i = 0; i < size; ++i)
			printf("%d", digit[i]);
	}
};

struct Num{
	BigInteger bint;
	BigFloat bfloat;
	Num operator+ (Num& a){
		Num ret;
		ret.bfloat = (bfloat + a.bfloat);
		ret.bint.set(ret.bfloat.carry);
		ret.bint = (ret.bint+bint + a.bint);
		return ret;
	}
};

int main(){
	Num numa, numb, res;
	while (scanf("%s%s", a, b)!=EOF){
		int i, j;
		for (i = 0; i < strlen(a); ++i)
			if (a[i] == '.')break;
		numa.bint.set(a, i);
		numa.bfloat.set(a + i + 1, strlen(a) - i - 1);
		for (i = 0; i < strlen(b); ++i)
			if (b[i] == '.')break;
		numb.bint.set(b, i);
		numb.bfloat.set(b + i + 1, strlen(b) - i - 1);

		res = numa + numb;
		res.bint.print();
		if (!(res.bfloat.size == 1 && res.bfloat.digit[0] == 0)&&!(res.bfloat.size==0)){
			printf(".");
			res.bfloat.print();
		}
		cout << endl;

	}
	return 0;
}