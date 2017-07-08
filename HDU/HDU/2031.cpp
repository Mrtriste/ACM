#include <iostream>
using namespace std;

void m2n(int s, char *mNum, int m){
	char *p = mNum;
	while (s > 0){
		int t = s%m;
		if (t<10)*p++ = t + '0';
		else *p++ = t - 10 + 'A';
		s /= m;
	}
	*p-- = '\0';
	char c;
	while (p > mNum){
		c = *p;
		*p-- = *mNum;
		*mNum++ = c;
	}
}

int main(){
	int s, m;
	while (cin >> s >> m){
		bool flag = false;
		if (s < 0){
			flag = true;
			s = -s;
		}
		char a[100];
		m2n(s, a, m);
		if (flag)cout << "-";
		cout << a << endl;
	}
}