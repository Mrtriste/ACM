#include <iostream>
using namespace std;

int sta[80010];

int main(){
	int n,t; cin >> n;
	long long ans = 0; int top = 0;
	for (int i = 0; i < n; ++i){
		scanf("%d", &t);
		while (top>0 && sta[top - 1] <= t)top--;
		ans += top;
		sta[top++] = t;
	}
	cout << ans << endl;
	system("pause");
}