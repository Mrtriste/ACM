#include <iostream>
#include <math.h>
using namespace std;

int prime[10000];
bool isPrime[50010];
int index[50010];

int findBigPrime(int x){
	for (int i = x; i >= 2; --i)
		if (isPrime[i])
			return index[i];
}

int main(){
	int len = 0;
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[2] = 1;
	for (int i = 2; i < 50010; ++i){
		if (isPrime[i]){
			prime[len++] = i;
			index[i] = len - 1;
			for (int j = i + i; j < 50010; j += i)
				isPrime[j] = 0;
		}
	}
	int m, a, b;
	
	while (cin >> m>>a>>b){
		if (m == 0 && a == 0 && b == 0)break;
		int maxP = sqrt(double(m));
		int mmax = 0, p, q;
		for (int i = findBigPrime(maxP); i >= 0; --i){
			for (int j = i;prime[i]*prime[j]<=m;++j){
				if (b*prime[i] >= a*prime[j] && mmax < prime[i] * prime[j])
					mmax = prime[i] * prime[j], p = prime[i], q = prime[j];
			}
		}
		cout << p<<" "<<q << endl;
	}
}