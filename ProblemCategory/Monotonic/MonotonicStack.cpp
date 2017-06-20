//单调栈
//单调递减栈是向一边忽略比现在小的。
//单调递增栈是向一边是忽略掉比现在高的，到达第一个比现在小的。--最大矩形面积

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