//大数阶乘

//res*m , return the current res's len
int multi(short res[],int len, int m){
	int temp = 0;
	for (int i = 0; i < len; ++i){
		res[i] = (temp + res[i] * m);//multi first,then plus
		temp = res[i] / 10;
		res[i] %= 10;
	}
	while (temp > 0){//handle remained carry
		res[len++] = temp % 10;
		temp /= 10;
	}
	return len;
}

int main(){
	const int N = 100;
	short res[10000];
	memset(res, 0, sizeof(res));
	//1! = 1
	int len = 1;
	res[0] = 1;

	for (int i = 2; i <= N; ++i)
		len = multi(res, len, i);

	for (int i = len-1; i >=0; --i)
		cout << res[i];


	system("pause");
	return 0;
}