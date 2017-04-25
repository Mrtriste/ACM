#include<stdio.h>
int main(void) {
	char a[1000];
	int i, x, y, n, k, k1, k2;
	while (scanf("%s", a) != EOF) {
		k1 = 0;
		k2 = 0;
		for (i = 0; i < 1000; i++) {
			if (a[i] == 'z') {
				x = i;
				k1++;
			}
			if (a[i] == 'j') {
				y = i;
				k2++;
			}
			if (a[i] == '\0') {
				n = i - 1;
				break;
			}
		}
		k = y - x - 1;
		if (k1 == 1 && k2 == 1 && k >= 1 && (x * k == n - y))
			printf("Accepted\n");
		else
			printf("Wrong Answer\n");
	}
	return 0;
}
