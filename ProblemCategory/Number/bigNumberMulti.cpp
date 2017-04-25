int main(){
	char a[] = "99999999999999999999999999999999999999";
	char b[] = "999999999999999999999999999999999999999999999999999999999999999";
	short res[10000], tempa[100], tempb[100];//short 防止溢出
	memset(res, 0, sizeof(res));
	memset(tempa, 0, sizeof(tempa));
	memset(tempb, 0, sizeof(tempb));

	int alen = strlen(a), blen = strlen(b),i,j;
	int len = alen + blen;

	for (i = 0; i < alen; ++i)
		tempa[alen - i - 1] = a[i] -'0';
	for (j = 0; j < blen; ++j)
		tempb[blen - j - 1] = b[j] -'0';


	for ( i = 0; i < alen; ++i)
		for (int j = 0; j < blen; ++j)
		res[i + j] += tempa[i] * tempb[j];
		
	int c=0,k;
	for ( i = 0; i < len; ++i){
		cout << int(res[i]) <<" " <<c << ", ";
		k = (res[i]+c) % 10;
		c = (res[i] + c) / 10;
		res[i] = k;
	}

	for ( i = 9999; i >= 0; --i)
		if (res[i] != 0)
			break;

	for (j = i; j >= 0; --j)
		cout << char(res[j] + '0');//+'0'

	system("pause");
	return 0;
}