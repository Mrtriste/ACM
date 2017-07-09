//#include <iostream>
//using namespace std;
//
//struct BigInteger{
//	int data[20000];
//	int size;
//	BigInteger(){
//		init();
//	}
//
//	void init(){
//		size = 0;
//		memset(data, 0, sizeof(data));
//	}
//
//	void set(char *a){
//		int l = strlen(a), b = 0;
//		while (b < l - 1 && a[b] == '0')b++;
//		for (int i = l - 1,c=1,t=0,k=0; i >= b; --i){
//			t += c*(a[i] - '0');
//			k++;
//			c *= 10;
//			if (k == 4 || b == i){
//				data[size++] = t;
//				t = 0, c = 1, k = 0;
//			}
//		}
//	}
//
//	BigInteger operator*(const BigInteger& A){
//		BigInteger ret;
//		int i, j;
//		for (i = 0; i < size; ++i){
//			int t = 0, c = 0;
//			for (j = 0; j < A.size; ++j){
//				t = c + data[i] * A.data[j] + ret.data[i + j];
//				ret.data[i + j] = t % 10000;
//				c = t / 10000;
//			}
//			if (c != 0)ret.data[i + j] = c;
//		}
//		ret.size = i + j;
//		int l = ret.size-1;
//		while (l>0 && ret.data[l] == 0)l--;
//		ret.size = l+1;
//		return ret;
//	}
//
//	void print(){
//		int l = size - 1;
//		cout << data[l];
//		for (int i = l - 1; i >= 0; --i)
//			printf("%04d", data[i]);
//		cout << endl;
//	}
//};
//
//int main(){
//	char a[50010], b[50010];
//	BigInteger x, y;
//	while (scanf("%s %s",a,b) != EOF){
//		x.init(), y.init();
//		x.set(a), y.set(b);
//		(x*y).print();
//	}
//}

