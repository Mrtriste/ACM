#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 100;
int parentK[MAX_SIZE];
struct Edge{
	int start;
	int end;
	int weight;
	bool isSelect;
};

int cmp(const Edge a, const Edge b){
	if (a.weight < b.weight)
		return 1;
	else
		return 0;
}

void makeSet(){
	for (int i = 0; i < MAX_SIZE; ++i)
		parentK[i] = i;
}

int findX(int x){
	int root = x, t;
	while (root != parentK[root])root = parentK[root];
	
	while (root != x){
		t = parentK[x];
		parentK[x] = root;
		x = t;
	}
	return root;
}

void Union(int a,int b){
	int x = findX(a), y = findX(b);
	if (x != y)
		parentK[x] = y;
}

int mainkruscal(){
	Edge edge[MAX_SIZE];
	int vtx[MAX_SIZE];
	int edge_num = 11;
	int vertex_num = 7;

	//http://www.cnblogs.com/qianbixin/p/5005161.html
	//use the graph of above link
	int a1[] = { 0, 0, 1, 1, 1, 2, 3, 3, 4, 5, 4 };
	int a2[] = { 1, 3, 3, 2, 4, 4, 4, 5, 5, 6, 6 };
	int a3[] = { 7, 5, 9, 8, 7, 5, 15, 6, 8, 11, 9 };
	for (int i = 0; i < edge_num; ++i){
		edge[i].start = a1[i];
		edge[i].end = a2[i];
		edge[i].weight = a3[i];
		edge[i].isSelect = false;
	}
	sort(edge, edge + edge_num, cmp);

	makeSet();
	for (int i = 0; i < edge_num; ++i){
		int x = findX(edge[i].start), y = findX(edge[i].end);
		if ( x!=y ){
			Union(edge[i].start, edge[i].end);
			edge[i].isSelect = true;
		}
	}
		
			
	for (int i = 0; i < edge_num; ++i)
		if (edge[i].isSelect)
			cout <<edge[i].start<<" "<<edge[i].end<<" "<< edge[i].weight << endl;

	system("pause");
	return 0;
}