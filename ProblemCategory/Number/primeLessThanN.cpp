//埃拉托斯特尼筛法

//http://www.cnblogs.com/fxplove/articles/2588956.html

int main(){
	const int N = 100;
	int prime[N];
	bool isPrime[N];
	for (int i = 0; i < N; ++i)
		isPrime[i] = true;
	isPrime[0] = isPrime[1] = false;
	int p = 0;
	for (int i = 0; i < N; ++i){//begin from 2
		if (isPrime[i]){
			prime[p++] = i;
			for (int j = i+i; j < N; j += i)//i+i
				isPrime[j] = false;
		}
	}
	for (int i = 0; i < p; ++i)
		cout << prime[i] << " ";
	system("pause");

	return 0;
}