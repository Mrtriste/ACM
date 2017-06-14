#include <iostream>
#include <queue>
using namespace std;

int a[20];
int start;
bool vis[70000];

struct Node{
	unsigned short s;
	int d;
};

//int change(int x, int i){//wrong!!!!
//	x ^= a[i];
//	if (i - 4 >= 0)x ^= a[i - 4];
//	if (i + 4 <= 15)x ^= a[i + 4];
//	if (i - 1 >= 0)x ^= a[i - 1];
//	if (i + 1 <= 15)x ^= a[i + 1];
//	return x;
//}

int c[16] =   //16种状态转换，对应4*4的翻子位置  
{
	51200, 58368, 29184, 12544,
	35968, 20032, 10016, 4880,
	2248, 1252, 626, 305,
	140, 78, 39, 19
};

int BFS(){
	queue<Node> q;
	Node cur, next;
	cur.s = start; cur.d = 0;
	q.push(cur);
	while (!q.empty()){
		//cout << cur.s << endl;
		cur = q.front(), q.pop();
		if (vis[cur.s])continue;
		vis[cur.s] = 1;
		if (cur.s == 0xffff || cur.s == 0)return cur.d;
		for (int i = 0; i < 16; ++i){
			next.s = cur.s^c[i];//change(cur.s,i);
			next.d = cur.d + 1;
			if (vis[next.s])continue;
			q.push(next);
		}
	}
	return -1;
}

int main(){
	int t = 1;
	for (int i = 0; i < 16; ++i)
		a[i] = t << i;
	char s[10]; 
	while (scanf("%s", s) != EOF){
		start = 0;
		int base = 3;
		for (int i = 0; i < 4; ++i){
			if (s[i] == 'b')start ^= a[base * 4 +3- i];
		}
		for (int j = 0; j < 3; ++j){
			base--;
			scanf("%s", s);
			for (int i = 0; i < 4; ++i){
				if (s[i] == 'b')start ^= a[base * 4 +3- i];
			}
		}
		memset(vis, 0, sizeof(vis));
		int ans = BFS();
		if (ans != -1)cout << ans << endl;
		else cout << "Impossible\n";
	}
}

//#include <iostream>
//using namespace std;
//
//void combine(int *arr,int arr_len,int ch_num,int *result,int remain_num){
//	if (remain_num == 0){
//		for (int i = 0; i < ch_num; ++i)
//			cout << result[i] << " ";
//		cout << endl;
//		return;
//	}
//	for (int i = arr_len; i >= remain_num; --i){//只要给前面留remain_num-1个数选择就好了
//		result[remain_num-1] = arr[i-1];
//		combine(arr, i-1, ch_num, result, remain_num - 1);
//	}		
//}
//
//int main1753(){
//	int arr[6];
//	int result[3];
//	for (int i = 0; i < 6; ++i)
//		arr[i] = i;
//	combine(arr, 6, 3, result,3);
//	system("pause");
//	return 0;
//}