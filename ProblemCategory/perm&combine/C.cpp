//max calculate:C(29,14);

long long C(int m, int n){//Cm,n
	if (n > m - n)n = m - n;
	long long mul=1, div=1;
	for (int i = 0; i < n; ++i){
		mul *= (m - i);
		div *= (n - i);
	}
	cout << mul << " " << div << endl;
	return mul / div;
}