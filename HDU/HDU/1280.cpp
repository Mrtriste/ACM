#include <iostream>
using namespace std;

int ha[10010];
int a[3010];

int main(){
	int n, m;
	while (scanf("%d%d", &n, &m)!=EOF){
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		if (m == 0)continue;
		memset(ha, 0, sizeof(ha));
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				ha[a[i] + a[j]]++;
		int i;
		for (i = 10000; i >= 0; --i){
			if (m == 1)break;
			if (ha[i] > 0){
				while (m>1&&ha[i]--){
					printf("%d ", i);
					m--;
				}
			}
		}
		i += 1;
		for (;; --i){
			if (ha[i] != 0){
				printf("%d\n", i);
				break;
			}
		}
	}
}