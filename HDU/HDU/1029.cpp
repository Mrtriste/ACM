#include <iostream>
using namespace std;

//ע��ans�Ĵ���������������������������
int main(){
	int n; 
	while (cin >> n){
		int v, ans;
		int cnt = 0;
		for (int i = 0; i < n; ++i){
			cin >> v;
			if (cnt == 0){
				ans = v;
				++cnt;
			}
			else{
				if (ans == v)
					++cnt;
				else
					--cnt;
			}
		}
		cout << ans << endl;
	}
	return 0;
}