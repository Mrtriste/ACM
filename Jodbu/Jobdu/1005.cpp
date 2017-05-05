#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node{
	int index;
	int GE;
	int GI;
	int a[5];
	Node(){}
	//Node& operator=(const Node& node){
	//	index = node.index;
	//	GE = node.GE;
	//	GI = node.GI;
	//	for (int i = 0; i < 5; ++i)
	//		a[i] = node.a[i];
	//	return *this;
	//}
	Node(const Node&node){
		index = node.index;
		GE = node.GE;
		GI = node.GI;
		for (int i = 0; i < 5; ++i)
			a[i] = node.a[i];
	}
};

bool cmp(const Node& a,const Node& b){
	if ((a.GE + a.GI) > (b.GE + b.GI))
		return true;
	if ((a.GE + a.GI) < (b.GE + b.GI))
		return false;
	return (a.GE > b.GE);
}

bool isEqual(Node &a, Node&b){
	return ((a.GE + a.GI) == (b.GE + b.GI) && a.GE == b.GE);
}

int main1005(){
	int N, M, K;
	int quota[101];
	vector<int> res[101];
	Node appli[100];
	Node last[101];
	while (cin >> N >> M >> K){
		for (int i = 0; i < M; ++i){
			cin >> quota[i];
			res[i].clear();
		}
			
		int ge, gi, ttt;
		for (int i = 0; i < N; ++i){
			cin >> ge >> gi;
			appli[i].index = i;
			appli[i].GE = ge;
			appli[i].GI = gi;

			for (int j = 0; j < K; ++j){
				cin >> ttt;
				appli[i].a[j] = ttt;
			}
		}
		//for (int i = 0; i < N; ++i){
		//	cout << appli[i].GE + appli[i].GI << " " << appli[i].GE << " ";
		//	for (int j = 0; j < K; ++j)
		//		cout << appli[i].a[j] << " ";
		//	cout<< endl;
		//}
			
		sort(appli, appli + N, cmp);
		//cout << "end sort" << endl;
		//for (int i = 0; i < N; ++i){
		//	cout << appli[i].GE + appli[i].GI << " " << appli[i].GE << " ";
		//	for (int j = 0; j < K; ++j)
		//		cout << appli[i].a[j] << " ";
		//	cout << endl;
		//}

		for (int i = 0; i < N; ++i){
			for (int j = 0; j < K; ++j){
				int school = appli[i].a[j];
				//cout << "school:" << school << endl;
				if (res[school].size() < quota[school]){
					res[school].push_back(appli[i].index);
					last[school] = appli[i];
					break;
				}
				else{
					if (isEqual(last[school], appli[i])){
						res[school].push_back(appli[i].index);
						last[school] = appli[i];
						break;
					}
				}
					
			}
		}


		for (int i = 0; i < M; ++i){
			if (res[i].size() > 0){
				sort(res[i].begin(), res[i].end());
				for (int j = 0; j < res[i].size() - 1; ++j){
					cout << res[i][j] << " ";
				}

				cout << res[i][res[i].size() - 1];
			}
			cout << endl;
		}
			

	}
	return 0;
}