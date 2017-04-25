//最小公倍数

int main(){
	int m = 18 * 13, n = 18 * 97;
	int mm = m, nn = n;
	int temp;
	if (m < n)swap(m, n);
	while (n != 0){
		if (m < n)swap(m, n);
		temp = m%n;
		m = n;
		n = temp;
	}
	cout << mm*nn / m;
	system("pause");
	return 0;
}