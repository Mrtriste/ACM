//最大公约数

//2个数的最大公约数
int main(){
	int m = 18 * 13, n = 18 * 97;
	int temp;
	if (m < n)swap(m, n);//let m>n
	while (n != 0){
		if (m < n)swap(m, n);
		temp = m%n;
		m = n;
		n = temp;
	}
	cout << m;
	system("pause");
	return 0;
}

int GCD(int a,int b)  
{  
    if(b==0) return a;  
    return GCD(b,a%b);  
}  

//n个数的最大公约数,将前一次两个数的最大公约数带入下一次的计算