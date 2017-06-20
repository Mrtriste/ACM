//树形DP
//HDU1520

#include <iostream>
using namespace std;

int n;

struct Node{
	int par, son, bro, present, not_present;
	void init(){
		par = son = bro = not_present = 0;
	}

	int max(){
		return present > not_present ? present : not_present;
	}
};

Node node[6010];

void DFS(int r){
	int son = node[r].son;
	while (son){
		DFS(son);
		node[r].present += node[son].not_present;
		node[r].not_present += node[son].max();
		son = node[son].bro;
	}
}

int main(){
	while (cin >> n){
		for (int i = 1; i <= n; ++i){
			scanf("%d", &node[i].present);
			node[i].init();
		}
		int par, son;
		while (scanf("%d%d", &son, &par) && (par + son)){
			node[son].par = par;
			node[son].bro = node[par].son;
			node[par].son = son;
		}
		int root;
		for (int i = 1; i <= n; ++i){
			if (!node[i].par){
				root = i;
				DFS(i);
				break;
			}
		}
		cout << node[root].max() << endl;
	}
}