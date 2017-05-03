#include <iostream>
#include <vector>
using namespace std;

struct Node4{
	int v;
	int weight;
	Node4(int v, int w) :v(v), weight(w){}
};

int mainbellmanford(){
	const int N = 100;
	int a1[] = { 0, 0, 0, 1, 2, 2, 3, 4, 5, 5, 5, 6 };
	int a2[] = { 1, 2, 3, 4, 4, 5, 6, 6, 4, 6, 3, 1 };
	//int a3[] = { 24, 8, 15, 6, 7, 3, 4, 9, 2, 3, 5, -3 };
	int a3[] = { 24, 8, 15, 6, 7, 3, 4, 9, 2, 3, 5, -30 };
	int vNum = 7, eNum = 12;

	vector<Node4> Graph[N];
	for (int i = 0; i < eNum; ++i)
		Graph[a1[i]].push_back(Node4(a2[i], a3[i]));

	int dis[N];
	for (int i = 0; i < N; ++i)
		dis[i] = 100000000;

	int start = 0;
	dis[start] = 0;

	for (int i = 0; i < vNum; ++i){
		for (int j = 0; j < vNum; ++j){//
			for (int k = 0; k < Graph[j].size(); ++k){
				int v = Graph[j][k].v;
				int w = Graph[j][k].weight;
				if (dis[v]>dis[j] + w)
					dis[v] = dis[j] + w;
			}
		}
	}

	//detect if there's a negative loop
	bool flag = 1;
	for (int j = 0; j < vNum; ++j){
		for (int k = 0; k < Graph[j].size(); ++k){
			int v = Graph[j][k].v;
			int w = Graph[j][k].weight;
			if (dis[v] > dis[j] + w){
				flag = 0;
				break;
			}
		}
	}
	if (flag)
		for (int i = 0; i < vNum; ++i)
			cout << dis[i] << endl;
	else
		cout << "there's negative loop" << endl;
		
			
				

	system("pause");
	return 0;
}