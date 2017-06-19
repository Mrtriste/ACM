#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
	char in[15], out[15];
	bool vis[15];
	int n;
	while (cin >> n){
		scanf("%s%s", &in, &out);
		stack<char> s;
		queue<int> pro;
		int ip = 0, op = 0;
		bool flag = true;
		memset(vis, 0, sizeof(vis));
		while (op < strlen(out)){
			if (!vis[out[op]-'0']){
				while (op < strlen(out) && ip<strlen(in)&&in[ip] != out[op]){
					vis[in[ip] - '0'] = 1;
					pro.push(1);
					s.push(in[ip]);
					//cout << "push " << in[ip] << endl;
					ip++;
				}
				//cout << "push " << in[ip] << endl;
				//cout << "pop " << in[ip] << endl;
				pro.push(1);
				pro.push(0);
				ip++, op++;
			}
			else{
				if (s.empty() || s.top() != out[op]){
					flag = false;
					cout << "No.\nFINISH\n";
					break;
				}
				else{
					//cout << "pop " << s.top() << endl;
					s.pop();
					pro.push(0);
					++op;
				}
			}
				
		}
		if (flag){
			cout << "Yes.\n";
			while (!pro.empty()){
				int i = pro.front(); pro.pop();
				if (i == 1)cout << "in\n";
				else cout << "out\n";
			}
			cout << "FINISH\n";
		}
		
	}
}