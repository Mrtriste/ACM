#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

struct pNode{
	int x;
	bool operator < (const pNode& n)const{//note: 2 const and yinyong
		return x < n.x; //big->small
	}
};


int mainpriority_queue(){
	////////////////
	priority_queue<pNode> q;
	const int N = 100;
	pNode pn[N];
	for (int i = 0; i < N; ++i)
		pn[i].x = i+10;
	pn[8].x = 1000;
	pn[56].x = 30;
	for (int i = N - 1; i >= 0; --i)
		q.push(pn[i]);
	while (!q.empty()){
		cout << q.top().x << " ";
		q.pop();
	}

	cout << endl << "-----" << endl;

	////////////////
	priority_queue<int, vector<int>, less<int> >qq;//big->small
	//priority_queue<int, vector<int>, greater<int> >qq; //small->big
	for (int i = 0; i < N; ++i)
		qq.push(i);
	while (!qq.empty()){
		cout << qq.top() << " ";
		qq.pop();
	}

	system("pause");
	return 0;

}