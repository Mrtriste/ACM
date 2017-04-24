//快速幂
//http://www.cnblogs.com/CXCXCXC/p/4641812.html

//x^n
int main(){
	int x = 2, n = 11;
	int res = 1;
	while (n > 0){
		if (n & 1)
			res *= x;
		x *= x;
		n >>= 1;
	}
	cout << res;
	system("pause");
}