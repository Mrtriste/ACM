int main(){
	char a[20] = "12345";
	char b[20] = "456789";

	char *max = a, *min = b;
	if (strlen(a) < strlen(b)){
		max = b;
		min = a;
	}

	int maxlen = strlen(max)-1;

	for (int i = strlen(min) - 1; i >= 0; --i)
		max[maxlen--] += min[i] - '0'; //maxlen--

	for (int i = strlen(max)-1; i > 0;--i)
		if (max[i] > '9'){
			max[i] -= 10;
			max[i - 1]++;
		}
	if (max[0] > '9'){
		max[0] -= 10;
		cout << '1';
	}
	cout << max;
		
	system("pause");
}