#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node2{
	int v;
	int len;
	Node2(int v, int len) :v(v), len(len){}
	bool operator<(const Node2& node)const{
		return len > node.len;
	}
};

int maindijkstra(){
	const int N = 100;

	vector<Node2> Graph[N];
	int a1[] = { 0, 0, 1, 1, 1, 2, 3, 3, 4, 5, 4 };
	int a2[] = { 1, 3, 3, 2, 4, 4, 4, 5, 5, 6, 6 };
	int a3[] = { 7, 5, 9, 8, 7, 5, 15, 6, 8, 11, 9 };
	for (int i = 0; i < 11; ++i){
		Graph[a1[i]].push_back(Node2(a2[i], a3[i]));
		Graph[a2[i]].push_back(Node2(a1[i], a3[i]));
	}
	
	bool isVisit[N];
	int dis[N];
	memset(isVisit, false, sizeof(isVisit));
	memset(dis, 100000000, sizeof(dis));
	for (int i = 0; i < N; ++i)
		dis[i] = 10000000;
	int start = 2;
	dis[start] = 0;
	//isVisit[start] = true;//note:can't set here
	priority_queue<Node2> que;
	que.push(Node2(start, 0));
	while (!que.empty()){
		int v = que.top().v, l = que.top().len; que.pop();//this is the prodecue that find the shortest path length amoung the {v-s}
		if (isVisit[v])continue;
		isVisit[v] = true;
		//the new vertex(we call it ver) which joins the set s
		//for the the vertexs which connects with ver,we update the path which pass ver if it is shorter
		for (int i = 0; i < Graph[v].size(); ++i){
			int len = Graph[v][i].len;//edge(v,v2)
			int v2 = Graph[v][i].v;
			if (!isVisit[v2] && dis[v2] > dis[v] + len){
				dis[v2] = dis[v] + len;
				que.push(Node2(v2, dis[v2]));//note:dis[v2] is the path length from start to v2
			}
		}
	}

	for (int i = 0; i < 7; ++i)
		cout << dis[i] << endl;


	system("pause");
	return 0;
}