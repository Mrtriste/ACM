#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;

struct Node4{
	char id[7];
	char name[10];
	int score;
};

bool cmp1(const Node4&a, const Node4&b){
	int t = strcmp(a.id, b.id);
	if (t != 0)
		return t < 0;
}

bool cmp2(const Node4&a, const Node4&b){
	int t = strcmp(a.name, b.name);
	if (t != 0)
		return t < 0;
	t = strcmp(a.id, b.id);
	if (t!=0)
		return t < 0;
}

bool cmp3(const Node4&a, const Node4&b){
	if (a.score != b.score)
		return a.score < b.score;
	int t = strcmp(a.id, b.id);
	if (t != 0)
		return t < 0;
}

int main1023(){
	int N, C;
	const int maxN = 100000 + 10;
	int cnt = 1;
	Node4 stu[maxN];
	while (cin >> N){
		if (N == 0)break;
		cin >> C;
		for (int i = 0; i < N; ++i)
			cin >> stu[i].id >> stu[i].name >> stu[i].score;
		printf("Case %d:\n", cnt++);
		if (C == 1)
			sort(stu, stu + N, cmp1);
		else if (C==2)
			sort(stu, stu + N, cmp2);
		else if (C == 3)
			sort(stu, stu + N, cmp3);

		for (int i = 0; i < N; ++i)
			cout << stu[i].id << " " << stu[i].name << " " << stu[i].score << endl;
		

	}
	return 0;
}