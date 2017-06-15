#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
	map<int, int> mp;
	map<int, int> m;
	map<int, int>::iterator it;
	for (int i = 2; i <= 100; ++i)
		m[i*i*i] = i;
	for (int i = 2; i <= 100; i++){
		for (int j = i; j <= 100; ++j){
			int x = i*i*i + j*j*j;
			it = mp.find(x);
			if (it == mp.end()){
				mp[x] = i;
			}
		}
	}
	int n; cin >> n;
	for (int i = 2; i <= n; ++i){
		for (int j = 2; j < i; ++j){
			int x = i*i*i - j*j*j;
			it = mp.find(x);
			if (it != mp.end()){
				int xx = m[i*i*i - j*j*j - it->second * it->second * it->second];
				if (j<=it->second&&it->second<=xx)
				printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, it->second, xx);
			}
		}
	}
	system("pause");
}


//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//
//int main(){
//	map<int, vector<int>> mp;
//	map<int, int> m;
//	map<int, vector<int>>::iterator it;
//	for (int i = 2; i <= 100; ++i)
//		m[i*i*i] = i;
//	for (int i = 2; i <= 100; i++){
//		for (int j = i; j <= 100; ++j){
//			int x = i*i*i + j*j*j;
//			it = mp.find(x);
//			if (it == mp.end()){
//				vector<int> v;
//				v.push_back(i);
//				mp[x] = v;
//			}
//			else{
//				//(it->second).push_back(i);
//			}
//		}
//	}
//	int n; cin >> n;
//	for (int i = 2; i <= n; ++i){
//		for (int j = 2; j < i; ++j){
//			int x = i*i*i - j*j*j;
//			it = mp.find(x);
//			if (it != mp.end()){
//				vector<int> v = it->second;
//				for (int t = 0; t < v.size(); ++t){
//					int xx = m[i*i*i - j*j*j - v[t] * v[t] * v[t]];
//					if (j <= v[t]&&v[t]<=xx)
//						printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, v[t],xx);
//				}
//					
//
//			}
//		}
//	}
//	system("pause");
//}