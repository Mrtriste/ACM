//单调队列

#include <stdio.h>
#include <stdlib.h>
const int maxn = 1e5 + 10;
int que[maxn<<1];
int val[maxn<<1];
int nu[maxn<<1];
int n, k;
int main()
{   
    int i, head, tail;
    scanf("%d %d", &n, &k);
	for (i = 1;i <= n;++i) 
	    scanf("%d", &val[i]);

	head = 0, tail = 0;
	for (i = 1;i <= n;++i) {
		while(head < tail && val[i] < val[que[tail - 1]]) tail--;
		while(head < tail && i - que[head] >= k) head++;
		que[tail++] = i;
	}
    return 0;
}