// max is A(29,14) A(20,20)

long long A(int m, int n){//Cm,n
	long long mul=1, div=1;
	for (int i = 0; i < n; ++i){
		mul *= (m - i);
	}
	return mul / div;
}