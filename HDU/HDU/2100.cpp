#include <iostream>
using namespace std;

struct XYZ{
	int size;
	int digit[210];
	XYZ(){
		init();
	}
	void init(){
		memset(digit, 0, sizeof(digit));
		size = 0;
	}

	void set(char *a, int len){
		init();
		int first = 0;
		while (first < len - 1 && a[first] == 'A')
			first++;
		for (int i = len - 1; i >= first; --i)
			digit[size++] = a[i] - 'A';
	}

	XYZ operator+(const XYZ& b){
		XYZ ret;
		int t, c = 0;
		for (int i = 0; i < size || i < b.size; ++i){
			t = digit[i] + b.digit[i] + c;
			ret.digit[ret.size++] = t % 26;
			c = t / 26;
		}
		if (c != 0)ret.digit[ret.size++] = c;

		return ret;
	}

	void print(){
		int l = size - 1;
		printf("%c", digit[l] + 'A');
		for (int i = l - 1; i >= 0;--i)
			printf("%c", digit[i] + 'A');
		cout << endl;
	}
};

int main(){
	XYZ a,b;
	char aa[210], bb[210];
	while (cin >> aa >> bb){
		a.set(aa,strlen(aa)), b.set(bb,strlen(bb));
		(a + b).print();
	}
}