#include <iostream>
using namespace std;

#define maxN 1000000
int sg[maxN];//sg[n]=0 means when faced with n, first must fail

int getLen(int x){
	int cnt = 0;
	while (x > 0)
		x /= 10, cnt++;
	return cnt;
}

void _extend(int x){
	int len = getLen(x), t, p;
	for (int i = 0; i < len; ++i){
		p = pow(10.0, i);
		t = x;
		for (;; t += p){
			if (x != t)
				sg[t] = 1;
			if ((t / p) % 10 == 9)break;
		}
	}
	int y = x, k = 1;
	while (len<6)
	{
		y = y * 10;
		for (int i = 0; i<k; i++)
			sg[y + i] = 1;
		k = k * 10;
		len++;
	}

}

int main(){
	memset(sg, 0, sizeof(sg));
	sg[0] = 1;
	for (int i = 1; i < maxN; ++i)
		if (!sg[i])
			_extend(i);
	char s[10];
	while (scanf("%s", &s) != EOF){
		if (s[0] == '0')printf("Yes\n");
		else{
			int x = atoi(s);
			if (sg[x])printf("Yes\n");
			else printf("No\n");
		}
	}
}