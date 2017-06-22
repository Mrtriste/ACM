#include <iostream>
#include <stdio.h>
using namespace std;

int main1019(){
	int a;
	char c1, c2;
	double stack[200];
	char ope[200];
	
	while (scanf("%d",&a)&&a!=0){
		char c = getchar();
		if (a == 0&&c=='\n')break;
		int tail = 0;
		stack[tail++] = (double)a;
		while (scanf("%c %d%c", &c1, &a, &c2)){
			if (c1 == '+'||c1=='-'){
				stack[tail] = (double)a;
				ope[tail++] = c1;
			}
			else if (c1 == '*'){
				stack[tail - 1] = stack[tail - 1] * ((double)a);
			}
			else if (c1 == '/'){
				stack[tail - 1] = stack[tail - 1] / ((double)a);
			}

			if (c2 != ' ')
				break;
		}

		double res = stack[0];
		for (int i = 1; i < tail; ++i){
			if (ope[i] == '+')
				res += stack[i];
			else if (ope[i] == '-')
				res -= stack[i];
		}
		printf("%.2lf\n", res);
	}
	return 0;
}