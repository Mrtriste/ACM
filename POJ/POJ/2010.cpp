#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node{
	int s, f;
};

bool cmp(Node&a, Node&b){
	return a.s < b.s;
}

int n, c, f;
Node a[100010];
int before[100010], after[100010];

int main(){
	cin >> n >> c >> f;
	int k = n / 2;
	for (int i = 0; i < c; ++i)
		scanf("%d %d", &a[i].s, &a[i].f);
	sort(a, a + c, cmp);
	{
		int total = 0; priority_queue<int> q;
		for (int i = 0; i <= k - 1; ++i)
			q.push(a[i].f), total += a[i].f;
		for (int i = k; i <= c - k - 1; ++i){
			before[i] = total;
			if (a[i].f < q.top()){
				total -= q.top(), q.pop();
				q.push(a[i].f), total += a[i].f;
			}
		}
	}
	{
		int total = 0; priority_queue<int> q;
		for (int i = c - 1; i >= c - k; --i)
			q.push(a[i].f), total += a[i].f;
		for (int i = c - k - 1; i >= k; --i){
			after[i] = total;
			if (a[i].f < q.top()){
				total -= q.top(), q.pop();
				q.push(a[i].f), total += a[i].f;
			}
		}
	}
	int ret = -1;
	for (int i = c - k - 1; i >= k; --i){
		if (a[i].f + before[i] + after[i] <= f){
			cout << a[i].s << endl;
			break;
		}
	}
	cout << ret << endl;
	system("pause");
}


//#include <iostream>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//int before[100010];
//int after[100010];
//int n, c, f;
//
//
//pair<int,int> a[100010];
//
//int main(){
//	cin >> n >> c >> f;
//	int k = n / 2;
//	for (int i = 0; i < c; ++i)
//		cin >> a[i].first >> a[i].second;
//	sort(a, a + c);
//
//	{
//		priority_queue<int>q; int total = 0;
//		for (int i = 0; i < c; ++i){
//			before[i] = q.size() == k ? total : 0x3f3f3f3f;
//			q.push(a[i].second); total += a[i].second;
//			if (q.size()>k){
//				total -= q.top(), q.pop();
//			}
//
//		}
//	}
//	{
//		priority_queue<int>q; int total = 0;
//		for (int i = c - 1; i >= 0; --i){
//			after[i] = q.size() == k ? total : 0x3f3f3f3f;
//			q.push(a[i].second); total += a[i].second;
//			if (q.size()>k){
//				total -= q.top(), q.pop();
//			}
//
//		}
//	}
//
//	int ret;
//	for (int i = c - 1; i >= 0; --i){
//		if (before[i] + after[i] + a[i].second <= f){
//			ret = a[i].first;
//			break;
//		}
//	}
//	cout << ret << endl;
//	system("pause");
//}





