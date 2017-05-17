#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int j, f;
	Node(){}

};

bool cmp(const Node &a, const Node &b){
	return (double(a.j) / double(a.f)) > (double(b.j) / double(b.f));
}


int main(){
	int m, n;
	Node node[10010];
	while (cin >> m >> n){
		if (m == -1 && n == -1)break;
		for (int i = 0; i < n; ++i)
			cin >> node[i].j >> node[i].f;
		sort(node, node + n,cmp);
		double sum = 0;
		for (int i = 0; i < n; ++i){
			if (m>=node[i].f){
				m -= node[i].f;
				sum += node[i].j;
			}
			else{
				sum += (double(m)*double(node[i].j) / double(node[i].f));
				break;
			}
		}
		printf("%.3lf\n", sum);
		
	}
}