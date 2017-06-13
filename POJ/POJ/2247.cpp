#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 2000000001  

char post[4];

void format(int n){
	int i = n % 10, ii = (n % 100) / 10;
	if (i == 1)strcpy(post, "st");
	else if (i == 2)strcpy(post, "nd");
	else if (i == 3)strcpy(post, "rd");
	else strcpy(post, "th");
	if (i == 1 && ii == 1)strcpy(post, "th");
	if (i == 2 && ii == 1)strcpy(post, "th");
	if (i == 3 && ii == 1)strcpy(post, "th");
}

int main(){
	int a[6000];
	int pos[4] = { 0, 0, 0, 0 };
	int prime[4] = { 2, 3, 5, 7 };
	a[0] = 1;
	for (int i = 1; i < 5842; ++i){
		int mmin = MAX;
		for (int j = 0; j < 4; ++j)
			mmin = min(a[pos[j]] * prime[j],mmin);
		for (int j = 0; j < 4; ++j)
			if (a[pos[j]] * prime[j] == mmin)
				pos[j]++;
		a[i] = mmin;
	}

	int n;
	while (cin >> n&&n){
		format(n);
		printf("The %d%s humble number is %d.\n", n, post, a[n - 1]);
	}
		

}