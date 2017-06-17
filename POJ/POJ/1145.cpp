#include <iostream>
using namespace std;

int DFS(int n){
	int ans,m;
	if (scanf(" ( %d ",&m) == 1){
		ans = DFS(n - m) + DFS(n - m);
		if (ans < 2)ans = 0;
	}
	else ans = !n;
	scanf(" ) ");
	return ans;

}

int main(){
	int n;
	while (scanf("%d", &n)!=EOF){
		puts(DFS(n) > 1 ? "yes" : "no");
	}
}