#include <iostream>
#include <vector>

using namespace std;

void addObj(vector<int> &v, int num,int d){
	int i = 1;
	while (i*2 < num + 1){
		v.push_back(i*d);
		i *= 2;
	}
	v.push_back((num + 1 - i)*d);
}

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main1276(){
	int cash, n, num[11], d[11];
	int f[100001];
	vector<int> obj;
	while (scanf("%d%d", &cash, &n) !=EOF){
		memset(f, 0, sizeof(f));
		for (int i = 0; i < n; ++i){
			scanf("%d%d", &num[i], &d[i]);
			addObj(obj, num[i], d[i]);
		}
		for (int i = 0; i < obj.size(); ++i)
			for (int v = cash; v >= obj[i]; --v){
				f[v] = max(f[v], f[v - obj[i]] + obj[i]);
			}
		
		obj.clear();
		printf("%d\n", f[cash]);
	}
	return 0;
}