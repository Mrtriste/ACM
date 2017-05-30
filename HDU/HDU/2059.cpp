#include <iostream>
#include <algorithm>
using namespace std;

int a[110];
float time[110];

int main(){
	int  n;
	float vr, v1, v2, l,c, t;
	while (cin >> l >> n >> c >> t >> vr >> v1 >> v2){
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		a[0] = 0, a[n + 1] = l, time[0] = 0;
		for (int i = 1; i <= n + 1; ++i){
			time[i] = 1000000;
			float chargetime = t, d, use, tt;
			for (int j = i - 1; j >= 0; --j){
				if (j == 0)chargetime = 0;
				d = a[i] - a[j];
				use = c > d ? d : c;
				tt = time[j]+chargetime + (use / v1) + ((d - use) / v2);
				if (tt < time[i]){
					time[i] = tt;
				}
					
			}
		}
		if (time[n + 1] < (l / vr))
			cout << "What a pity rabbit!\n";
		else
			cout << "Good job,rabbit!\n";
	}
}