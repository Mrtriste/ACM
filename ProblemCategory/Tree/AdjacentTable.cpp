//邻接表

#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 50010;

struct Edge{
	int v, next;
};

//head 和edge。next里其实存的都是边的下标，因为总要一个起始的点i，用head的下标表示
int head[maxN];//head[i]表示节点i连接的第一条边的下标是head[i],接下来edge.next是下一条边的下标，edge.v是i连的点
Edge edge[2*maxN];//无向图，要两倍的边，且addEdge()两次
int n,k=0;

void addEdge(int u, int v){
	edge[k].v = v;
	edge[k].next = head[u];
	head[u] = k++;
}

int main(){
	cin >> n;
	memset(head, -1, sizeof(head));
	int u, v;
	for (int i = 0; i < n - 1; ++i){
		scanf("%d%d", &u, &v);
		addEdge(u, v);//add 两次
		addEdge(v, u);
	}
	int r=1;
	//vis nodes connected with r
	//i != -1 because the initial head is -1, then head[i] -> edge[k].next
	for (int i = head[r]; i != -1; i = edge[i].next){
		int v = edge[i].v;
		//do something with v
	}
	system("pause");
}

