#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int t;
	int interval;
	int num;
	bool operator<(const Node& b)const{
		if (t != b.t)return t > b.t;
		return num > b.num;
	}
};

int main(){
	char s[15];
	priority_queue<Node> q;
	int num, iv;
	Node node;
	while (cin >> s&&s[0]!='#'){
		cin >> num >> iv;
		node.t = node.interval = iv, node.num = num;
		q.push(node);
	}
	int k, cnt = 0;; cin >> k;
	while (cnt++ < k){
		node = q.top(), q.pop();
		cout << node.num << endl;
		node.t += node.interval;
		q.push(node);
	}
	system("pause");
}