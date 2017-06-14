#include <iostream>
using namespace std;

int n;
char a[20];//1 - n-1
char s[5] = { '+', '-','.' };
int cnt = 0;

void DFS(int k, int ans,int pre){//the k-th sign,ans is involved the number after the k-th sign
	if (k == n){
		if (ans == 0){
			++cnt;
			if (cnt > 20)return;
			cout << 1;
			for (int i = 1; i < n; ++i)
				cout << " " << a[i] << " " << i + 1;
			cout << endl;
		}
		return;
	}
	int next;

	a[k] = '+';
	next = k + 1;
	DFS(k + 1, ans+next,next);

	a[k] = '-';
	next = k + 1;
	DFS(k + 1, ans - next, next);

	a[k] = '.';
	if (k < 9)
		next = pre * 10 + k + 1;
	else
		next = pre * 100 + k + 1;
	int i = k - 1;
	while (a[i] == '.'&&i >= 0)--i;
	if (a[i] == '+')
		DFS(k + 1, ans + next - pre, next);
	else if (a[i])
		DFS(k + 1, ans + pre - next, next);

}

int main(){
	cin >> n;
	a[0] = '+';
	DFS(1, 1,1);
	cout << cnt << endl; 
	system("pause");
}