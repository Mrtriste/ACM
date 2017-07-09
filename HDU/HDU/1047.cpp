#include <iostream>
using namespace std;

struct BigInteger{
	int data[100];
	int size;
	BigInteger(){
		init();
	}
	void init(){
		memset(data, 0, sizeof(data));
		size = 0;
	}

	void set(char *a){
		int l = strlen(a);
		int b = 0;
		while (b < l-1 && a[b] == '0')b++;
		for (int i = l - 1,k=0,c=1,t=0; i >= b; --i){
			t += c*(a[i] - '0');
			k++;
			c *= 10;
			if (k == 4 || i == b){
				data[size++] = t;
				k = 0, c = 1,t=0;
			}
		}
	}

	BigInteger operator+(const BigInteger& A){
		BigInteger ret;
		int t, c = 0;
		for (int i = 0; i < size || i < A.size; ++i){
			t = c + data[i] + A.data[i];
			ret.data[ret.size++] = t % 10000;
			c = t / 10000;
		}
		if (c != 0)
			ret.data[ret.size++] = c;
		return ret;
	}

	void print(){
		int l = size - 1;
		printf("%d", data[l]);
		for (int i = l - 1; i >= 0; --i)
			printf("%04d", data[i]);
		cout << endl;
	}


};

int main(){
	int T; cin >> T;
	while (T--){
		char s[110];
		BigInteger ret; ret.set("0");
		while (scanf("%s", s)!=EOF){
			if (!strcmp(s, "0"))break;
			BigInteger temp;
			temp.set(s);
			ret = ret + temp;
		}
		ret.print();
		if (T != 0)cout << endl;
	}
}