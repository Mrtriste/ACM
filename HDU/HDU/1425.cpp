#include <iostream>
using namespace std;

bool ha[1000010];

int main(){
	int n, m;
	while (cin >> n >> m){
		int a;
		memset(ha, 0, sizeof(ha));
		for (int i = 0; i < n; ++i){
			scanf("%d", &a);
			ha[a + 500000]=true;
		}
		if (m == 0)continue;
		int i;
		for (i = 1000000; i >= 0; --i){
			if (m <= 1)break;
			if (ha[i]){
				printf("%d ", i - 500000);
				ha[i] = false;
				m--;
			}
		}
		i += 1;
		for (;; i--){
			if (ha[i]){
				printf("%d\n", i - 500000);
				break;
			}
		}
	}
}