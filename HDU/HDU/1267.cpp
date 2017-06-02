//#include <iostream>
//using namespace std;
//
//struct BigInteger{
//	int digit[100];
//	int size;
//	BigInteger(){
//		init();
//	}
//
//	void init(){
//		memset(digit,0,sizeof(digit));
//		size = 0;
//	}
//
//	void set(int x){
//		init();
//		digit[size++] = x;
//	}
//
//	BigInteger operator*(const int x){
//		BigInteger ret;
//		int t, c = 0;
//		for (int i = 0; i < size; ++i){
//			t = digit[i] * x + c;
//			ret.digit[ret.size++] = t % 10000;
//			c = t / 10000;
//		}
//		if (c != 0)
//			ret.digit[ret.size++] = c;
//		return ret;
//	}
//
//	BigInteger operator/(const int x){
//		BigInteger ret;
//		int down = 0, t;
//		for (int i = size - 1; i >= 0; --i){
//			t = (down * 10000 + digit[i]);
//			ret.digit[i] = t / x;
//			down = t %x;
//		}
//		
//		int l = size - 1;
//		while (l>0 && ret.digit[l] == 0)
//			l--;
//		ret.size = l + 1;
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
//
//};
//
//BigInteger C(int m, int n){
//	BigInteger ret;
//	ret.set(1);
//	for (int i = 0; i < n; ++i){
//		ret =ret* (m - i);
//	}
//		
//	for (int i = n; i >= 2; --i)
//		ret =ret/ i;
//	return ret;
//}
//
//int main(){
//	int m, n;
//	while (cin >> m >> n){
//		if (m < n)cout << 0 << endl;
//		else ((C(m + n, m)*(m - n + 1)) / (m + 1)).print();
//	}
//}


#include<iostream>
#include<cstdio>
using namespace std;

long long a[21][21];
void init()
{
	for (int i = 1; i <= 20; i++)
		a[i][0] = 1;
	for (int i = 1; i <= 20; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			a[i][j] = a[i - 1][j] + a[i][j - 1];
		}
	}
}
int main()
{
	init();
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		printf("%lld\n", a[n][m]);
	}
	return 0;
}