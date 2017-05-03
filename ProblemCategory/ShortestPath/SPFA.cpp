//SPFA 单源最短路径算法
//可处理有向负权图 对Bellman-ford的优化

//优化在哪里？
//Bellman-ford在每次循环中，对所有的边都进行松弛，也就是尝试更新每条边终点的dis，
//但是有的点的最短路径没有优化，因此就不需要对以这个点为起点的边进行松弛
//那么我们就用一个队列去记录所有的路径被优化的点，然后从队列中去取这些点，然后去松弛以这个点为起点的所有边


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node3{
	int u, v;
	int weight;
	Node3(int u, int v, int w) :u(u), v(v), weight(w){}
};

int main(){
	//http://www.360doc.com/content/13/1208/22/14357424_335569176.shtml
	int a1[] = { 0, 0, 0, 1, 2, 2, 3, 4, 5, 5, 5,6 };
	int a2[] = { 1, 2, 3, 4, 4, 5, 6, 6, 4, 6, 3,1 };
	//int a3[] = { 24, 8, 15, 6, 7, 3, 4, 9, 2, 3, 5,3 };
	int a3[] = { 24, 8, 15, 6, 7, 3, 4, 9, 2, 3, 5, -30 };

	const int N = 100;
	vector<Node3>Graph[N];
	bool isInVector[N];
	int dis[N];
	int cnt[N];
	for (int i = 0; i < N; ++i){
		dis[i] = 10000000000;
		isInVector[i] = false;
		cnt[i] = 0;
	}

	for (int i = 0; i < 12; ++i)
		Graph[a1[i]].push_back(Node3(a1[i], a2[i], a3[i]));

	int vNum = 7;

	queue<int> que;
	int start = 0;
	dis[start] = 0;
	isInVector[start] = true;
	que.push(start);
	while (!que.empty()){
		int u = que.front(); que.pop();
		isInVector[u] = false;//出队
		for (int i = 0; i < Graph[u].size(); ++i){
			int v = Graph[u][i].v;
			int w = Graph[u][i].weight;
			if (dis[v]>dis[u] + w){//v终点
				dis[v] = dis[u] + w;
				if (isInVector[v] == false){//如果不在队中
					isInVector[v] = true;//进队
					que.push(v);
					cnt[v]++;
					if (cnt[v]>vNum) {
						cout << "there's a negatine loop" << endl;
						system("pause");
						return -1;
					}

				}
			}
		}
	}

	for (int i = 0; i < 7; ++i)
		cout << dis[i] << endl;

	system("pause");
	return 0;
	
}