#include <iostream>
using namespace std;

int ha[2000010];

int main(){
	int a, b, c, d;
	while (cin >> a >> b >> c >> d){
		if (a > 0 && b > 0 && c > 0 && d > 0){
			printf("%d\n", 0);
			continue;
		}
		if (a < 0 && b < 0 && c < 0 && d < 0){
			printf("%d\n", 0);
			continue;
		}
		memset(ha, 0, sizeof(ha));
		for (int i = 1; i <= 100; ++i)
			for (int j = 1; j <= 100; ++j)
				ha[a*i*i + b*j*j+1000000]++;
		int ans = 0;
		for (int i = 1; i <= 100; ++i)
			for (int j = 1; j <= 100; ++j)
				ans+=ha[-c*i*i - d*j*j+1000000];
		printf("%d\n", ans * 16);

	}
}