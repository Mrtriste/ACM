#include <iostream>
using namespace std;

#define N 50000
int prime[N];
bool isPrime[N];
int len;

void getPrime(){
	memset(isPrime, 1, sizeof(isPrime));
	len = 0;
	for (int i = 2; i < N; ++i){
		if (isPrime[i]){
			prime[len++] = i;
			for (int j = i + i; j < N; j += i)
				isPrime[j] = 0;
		}
	}
}


int main(){
	getPrime();
	int l, r;
	bool temp[1000100];
	while (cin >> l >> r){
		memset(temp, 1, sizeof(temp));
		for (int i = 0; i <len; ++i){
			int t = prime[i];
			int s = (l - 1) / t + 1, e = r / t;
			for (int j = s; j <= e; ++j){
				if(j>1)temp[j*t - l] = 0;
			}
		}

		int c1, c2, d1=0, d2;
		int mmin = 0xfffffff, mmax = -1;
		int last = -1;
		for (int i = 0; i <= r - l; ++i){
			if (temp[i]){
				if (last!=-1){
					if (mmin > i - last){
						mmin = i - last;
						c1 = last, c2 = i;
					}
					if (mmax < i - last){
						mmax = i - last;
						d1 = last, d2 = i;
					}
				}
				if(i+l!=1)last = i;
			}
		}
		if (mmax == -1)puts("There are no adjacent primes.");
		else printf("%d,%d are closest, %d,%d are most distant.\n", c1+l, c2+l, d1+l, d2+l);
	}
}