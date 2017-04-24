//快速幂取模

//(x^n)%m
int main(){
	int x = 2, n = 11,m = 3;
	int res = 1;
	while (n > 0){
		if (n & 1)
			res = (res*x)%m;
		x =(x*x)%m;
		n >>= 1;
	}
	cout << res;
	system("pause");
}