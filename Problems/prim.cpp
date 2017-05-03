#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node1{
	int v;
	int len;
	Node1(int v, int len) :v(v), len(len){}
	bool operator<(const Node1& node)const{
		return len > node.len;
	}
};

int mainprim(){
	
	const int N = 100;
	bool isVisit[N];
	memset(isVisit, false, sizeof(isVisit));
	int dis[N];//存放到达i的最短距离是多少
	memset(dis, 100000000, sizeof(dis));
	vector<Node1> Graph[N];
	int a1[] = { 0, 0, 1, 1, 1, 2, 3, 3, 4, 5, 4 };
	int a2[] = { 1, 3, 3, 2, 4, 4, 4, 5, 5, 6, 6 };
	int a3[] = { 7, 5, 9, 8, 7, 5, 15, 6, 8, 11, 9 };
	for (int i = 0; i < 11; ++i){
		Graph[a1[i]].push_back(Node1(a2[i],a3[i]));
		Graph[a2[i]].push_back(Node1(a1[i], a3[i]));
	}
	//for (int i = 0; i < N; ++i)
	//	dis[i] = 1000000;
	//	//cout << dis[i] << "-";

	priority_queue<Node1> que;
	int start = 2;
	que.push(Node1(start, 0));
	while (!que.empty()){
		int v = que.top().v; int l = que.top().len; que.pop();
		if (isVisit[v])continue;
		isVisit[v] = true;
		cout << l << endl;
		for (int i = 0; i < Graph[v].size(); ++i){
			int len = Graph[v][i].len;
			int v2 = Graph[v][i].v;

			//对v2来说，只有新的到达v2的边比已经加入que的边小，那么它才有资格加入que，否则也只有在后面排着，并不会轮到它
			//不加也可以，加了可以进一步优化
			if (!isVisit[v2]&&dis[v2]>len){
				dis[v2] = len;//记录到达v2最短的距离是多少
				que.push(Node1(v2, len));
				//que 里放的都是与(已经选出的点)连着的node
			}
				
		}
	}

	system("pause");
	return 0;


}