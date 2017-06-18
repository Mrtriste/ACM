#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int b, e;
	Node(){}
	Node(int bb, int ee) :b(bb), e(ee){}
	bool operator<(const Node &n){
		if (e == n.e)return b < n.b;
		return e > n.e;
	}
};

Node node[110];

int main(){
	int n;
	while (cin >> n){
		int p, q; cin >> p >> q;
		int b, e; char s[100];
		for (int i = 0; i < n; ++i){
			scanf("%d%d", &b, &e);
			gets(s);
			node[i] = Node(b, e);
		}
		sort(node, node + n);
		if (q>node[0].e){
			cout << q << endl;
			continue;
		}
		int res = node[0].b;
		bool flag = false;
		for (int i = 1; i < n; ++i){
			if (res <= node[i].e+1){
				res = node[i].b;
			}
			else{
				cout << res - 1 << endl;
				flag = true;
				break;
			}
		}
		if (!flag){
			if (res - 1 >= p)
				cout << res - 1 << endl;
			else
				cout << "Badly!" << endl;
		}
	}
}
